/*-
 * Copyright (c) 2015-2016 Yandex LLC
 * Copyright (c) 2015-2016 Andrey V. Elsukov <ae@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $FreeBSD: releng/11.1/sys/netpfil/ipfw/nat64/nat64stl.h 304046 2016-08-13 16:09:49Z ae $
 */

#ifndef	_IP_FW_NAT64STL_H_
#define	_IP_FW_NAT64STL_H_

struct nat64stl_cfg {
	struct named_object	no;

	uint16_t		map64;	/* table with 6to4 mapping */
	uint16_t		map46;	/* table with 4to6 mapping */

	struct in6_addr		prefix6;/* IPv6 prefix */
	uint8_t			plen6;	/* prefix length */
	uint8_t			flags;	/* flags for internal use */
#define	NAT64STL_KIDX		0x0100
#define	NAT64STL_46T		0x0200
#define	NAT64STL_64T		0x0400
#define	NAT64STL_FLAGSMASK	(NAT64_LOG) /* flags to pass to userland */
	char			name[64];
	nat64_stats_block	stats;
};

VNET_DECLARE(uint16_t, nat64stl_eid);
#define	V_nat64stl_eid	VNET(nat64stl_eid)
#define	IPFW_TLV_NAT64STL_NAME	IPFW_TLV_EACTION_NAME(V_nat64stl_eid)

int ipfw_nat64stl(struct ip_fw_chain *chain, struct ip_fw_args *args,
    ipfw_insn *cmd, int *done);

#endif

