#!/bin/sh
#-
# Copyright (c) 2013 Dag-Erling Smørgrav
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#
# $FreeBSD: releng/11.1/usr.sbin/unbound/local-setup/local-unbound-setup.sh 295535 2016-02-11 17:37:02Z des $
#

#
# Configuration variables
#
user=""
unbound_conf=""
forward_conf=""
lanzones_conf=""
control_conf=""
control_socket=""
workdir=""
confdir=""
chrootdir=""
anchor=""
pidfile=""
resolv_conf=""
resolvconf_conf=""
service=""
start_unbound=""
forwarders=""

#
# Global variables
#
self=$(basename $(realpath "$0"))
bkext=$(date "+%Y%m%d.%H%M%S")

#
# Set default values for unset configuration variables.
#
set_defaults() {
	: ${user:=unbound}
	: ${workdir:=/var/unbound}
	: ${confdir:=${workdir}/conf.d}
	: ${unbound_conf:=${workdir}/unbound.conf}
	: ${forward_conf:=${workdir}/forward.conf}
	: ${lanzones_conf:=${workdir}/lan-zones.conf}
	: ${control_conf:=${workdir}/control.conf}
	: ${control_socket:=/var/run/local_unbound.ctl}
	: ${anchor:=${workdir}/root.key}
	: ${pidfile:=/var/run/local_unbound.pid}
	: ${resolv_conf:=/etc/resolv.conf}
	: ${resolvconf_conf:=/etc/resolvconf.conf}
	: ${service:=local_unbound}
	: ${start_unbound:=yes}
}

#
# Verify that the configuration files are inside the working
# directory, and if so, set the chroot directory accordingly.
#
set_chrootdir() {
	chrootdir="${workdir}"
	for file in "${unbound_conf}" "${forward_conf}" \
	    "${lanzones_conf}" "${control_conf}" "${anchor}" ; do
		if [ "${file#${workdir%/}/}" = "${file}" ] ; then
			echo "warning: ${file} is outside ${workdir}" >&2
			chrootdir=""
		fi
	done
	if [ -z "${chrootdir}" ] ; then
		echo "warning: disabling chroot" >&2
	fi
}

#
# Scan through /etc/resolv.conf looking for uncommented nameserver
# lines that don't point to localhost and return their values.
#
get_nameservers() {
	while read line ; do
		local bareline=${line%%\#*}
		local key=${bareline%% *}
		local value=${bareline#* }
		case ${key} in
		nameserver)
			case ${value} in
			127.0.0.1|::1|localhost|localhost.*)
				;;
			*)
				echo "${value}"
				;;
			esac
			;;
		esac
	done
}

#
# Scan through /etc/resolv.conf looking for uncommented nameserver
# lines.  Comment out any that don't point to localhost.  Finally,
# append a nameserver line that points to localhost, if there wasn't
# one already, and enable the edns0 option.
#
gen_resolv_conf() {
	local localhost=no
	local edns0=no
	while read line ; do
		local bareline=${line%%\#*}
		local key=${bareline%% *}
		local value=${bareline#* }
		case ${key} in
		nameserver)
			case ${value} in
			127.0.0.1|::1|localhost|localhost.*)
				localhost=yes
				;;
			*)
				echo -n "# "
				;;
			esac
			;;
		options)
			case ${value} in
			*edns0*)
				edns0=yes
				;;
			esac
			;;
		esac
		echo "${line}"
	done
	if [ "${localhost}" = "no" ] ; then
		echo "nameserver 127.0.0.1"
	fi
	if [ "${edns0}" = "no" ] ; then
		echo "options edns0"
	fi
}

#
# Boilerplate
#
do_not_edit() {
	echo "# This file was generated by $self."
	echo "# Modifications will be overwritten."
}

#
# Generate resolvconf.conf so it updates forward.conf in addition to
# resolv.conf.  Note "in addition to" rather than "instead of",
# because we still want it to update the domain name and search path
# if they change.  Setting name_servers to "127.0.0.1" ensures that
# the libc resolver will try unbound first.
#
gen_resolvconf_conf() {
	local style="$1"
	do_not_edit
	echo "resolv_conf=\"/dev/null\" # prevent updating ${resolv_conf}"
	if [ "${style}" = "dynamic" ] ; then
		echo "unbound_conf=\"${forward_conf}\""
		echo "unbound_pid=\"${pidfile}\""
		echo "unbound_service=\"${service}\""
		# resolvconf(8) likes to restart rather than reload
		echo "unbound_restart=\"service ${service} reload\""
	else
		echo "# Static DNS configuration"
	fi
}

#
# Generate forward.conf
#
gen_forward_conf() {
	do_not_edit
	echo "forward-zone:"
	echo "        name: ."
	for forwarder ; do
		if expr "${forwarder}" : "^[0-9A-Fa-f:.]\{1,\}$" >/dev/null ; then
			echo "        forward-addr: ${forwarder}"
		else
			echo "        forward-host: ${forwarder}"
		fi
	done
}

#
# Generate lan-zones.conf
#
gen_lanzones_conf() {
	do_not_edit
	echo "server:"
	echo "        # Unblock reverse lookups for LAN addresses"
	echo "        unblock-lan-zones: yes"
	echo "        insecure-lan-zones: yes"
}

#
# Generate control.conf
#
gen_control_conf() {
	do_not_edit
	echo "remote-control:"
	echo "        control-enable: yes"
	echo "        control-interface: ${control_socket}"
	echo "        control-use-cert: no"
}

#
# Generate unbound.conf
#
gen_unbound_conf() {
	do_not_edit
	echo "server:"
	echo "        username: ${user}"
	echo "        directory: ${workdir}"
	echo "        chroot: ${chrootdir}"
	echo "        pidfile: ${pidfile}"
	echo "        auto-trust-anchor-file: ${anchor}"
	echo ""
	if [ -f "${forward_conf}" ] ; then
		echo "include: ${forward_conf}"
	fi
	if [ -f "${lanzones_conf}" ] ; then
		echo "include: ${lanzones_conf}"
	fi
	if [ -f "${control_conf}" ] ; then
		echo "include: ${control_conf}"
	fi
	if [ -d "${confdir}" ] ; then
		echo "include: ${confdir}/*.conf"
	fi
}

#
# Replace one file with another, making a backup copy of the first,
# but only if the new file is different from the old.
#
replace() {
	local file="$1"
	local newfile="$2"
	if [ ! -f "${file}" ] ; then
		echo "${file} created"
		mv "${newfile}" "${file}"
	elif ! cmp -s "${file}" "${newfile}" ; then
		local oldfile="${file}.${bkext}"
		echo "original ${file} saved as ${oldfile}"
		mv "${file}" "${oldfile}"
		mv "${newfile}" "${file}"
	else
		echo "${file} not modified"
		rm "${newfile}"
	fi
}

#
# Print usage message and exit
#
usage() {
	exec >&2
	echo "usage: $self [options] [forwarder ...]"
	echo "options:"
	echo "    -n          do not start unbound"
	echo "    -a path     full path to trust anchor file"
	echo "    -C path     full path to additional configuration directory"
	echo "    -c path     full path to unbound configuration file"
	echo "    -f path     full path to forwarding configuration"
	echo "    -O path     full path to remote control socket"
	echo "    -o path     full path to remote control configuration"
	echo "    -p path     full path to pid file"
	echo "    -R path     full path to resolvconf.conf"
	echo "    -r path     full path to resolv.conf"
	echo "    -s service  name of unbound service"
	echo "    -u user     user to run unbound as"
	echo "    -w path     full path to working directory"
	exit 1
}

#
# Main
#
main() {
	umask 022

	#
	# Parse and validate command-line options
	#
	while getopts "a:C:c:f:no:p:R:r:s:u:w:" option ; do
		case $option in
		a)
			anchor="$OPTARG"
			;;
		C)
			confdir="$OPTARG"
			;;
		c)
			unbound_conf="$OPTARG"
			;;
		f)
			forward_conf="$OPTARG"
			;;
		n)
			start_unbound="no"
			;;
		O)
			control_socket="$OPTARG"
			;;
		o)
			control_conf="$OPTARG"
			;;	
		p)
			pidfile="$OPTARG"
			;;
		R)
			resolvconf_conf="$OPTARG"
			;;
		r)
			resolv_conf="$OPTARG"
			;;
		s)
			service="$OPTARG"
			;;
		u)
			user="$OPTARG"
			;;
		w)
			workdir="$OPTARG"
			;;
		*)
			usage
			;;
		esac
	done
	shift $((OPTIND-1))
	set_defaults

	#
	# Get the list of forwarders, either from the command line or
	# from resolv.conf.
	#
	forwarders="$@"
	if [ -z "$forwarders" ] ; then
		echo "Extracting forwarders from ${resolv_conf}."
		forwarders=$(get_nameservers <"${resolv_conf}")
		style=dynamic
	else
		style=static
	fi

	#
	# Generate forward.conf.
	#
	if [ -z "${forwarders}" ] ; then
		echo -n "No forwarders found in ${resolv_conf##*/}, "
		if [ -f "${forward_conf}" ] ; then
			echo "using existing ${forward_conf##*/}."
		else
			echo "unbound will recurse."
		fi
	else
		local tmp_forward_conf=$(mktemp -u "${forward_conf}.XXXXX")
		gen_forward_conf ${forwarders} | unexpand >"${tmp_forward_conf}"
		replace "${forward_conf}" "${tmp_forward_conf}"
	fi

	#
	# Generate lan-zones.conf.
	#
	local tmp_lanzones_conf=$(mktemp -u "${lanzones_conf}.XXXXX")
	gen_lanzones_conf | unexpand >"${tmp_lanzones_conf}"
	replace "${lanzones_conf}" "${tmp_lanzones_conf}"

	#
	# Generate control.conf.
	#
	local tmp_control_conf=$(mktemp -u "${control_conf}.XXXXX")
	gen_control_conf | unexpand >"${tmp_control_conf}"
	replace "${control_conf}" "${tmp_control_conf}"

	#
	# Generate unbound.conf.
	#
	local tmp_unbound_conf=$(mktemp -u "${unbound_conf}.XXXXX")
	set_chrootdir
	gen_unbound_conf | unexpand >"${tmp_unbound_conf}"
	replace "${unbound_conf}" "${tmp_unbound_conf}"

	#
	# Start unbound, unless requested not to.  Stop immediately if
	# it is not enabled so we don't end up with a resolv.conf that
	# points into nothingness.  We could "onestart" it, but it
	# wouldn't stick.
	#
	if [ "${start_unbound}" = "no" ] ; then
		# skip
	elif ! service "${service}" enabled ; then
		echo "Please enable $service in rc.conf(5) and try again."
		return 1
	elif ! service "${service}" restart ; then
		echo "Failed to start $service."
		return 1
	fi

	#
	# Rewrite resolvconf.conf so resolvconf updates forward.conf
	# instead of resolv.conf.
	#
	local tmp_resolvconf_conf=$(mktemp -u "${resolvconf_conf}.XXXXX")
	gen_resolvconf_conf "${style}" | unexpand >"${tmp_resolvconf_conf}"
	replace "${resolvconf_conf}" "${tmp_resolvconf_conf}"

	#
	# Finally, rewrite resolv.conf.
	#
	local tmp_resolv_conf=$(mktemp -u "${resolv_conf}.XXXXX")
	gen_resolv_conf <"${resolv_conf}" | unexpand >"${tmp_resolv_conf}"
	replace "${resolv_conf}" "${tmp_resolv_conf}"
}

main "$@"
