# $FreeBSD: releng/11.1/sys/boot/efi/fdt/Makefile 296706 2016-03-11 23:45:51Z bdrewery $

.include <src.opts.mk>

.PATH: ${.CURDIR}/../../common

LIB=		efi_fdt
INTERNALLIB=
WARNS?=		6

SRCS=		efi_fdt.c

CFLAGS+=	-ffreestanding -msoft-float
.if ${MACHINE_CPUARCH} == "aarch64"
CFLAGS+=	-mgeneral-regs-only
.endif

CFLAGS+=	-I${.CURDIR}/../../../../lib/libstand/

# EFI library headers
CFLAGS+=	-I${.CURDIR}/../include
CFLAGS+=	-I${.CURDIR}/../include/${MACHINE}

# libfdt headers
CFLAGS+=	-I${.CURDIR}/../../fdt

# Pick up the bootstrap header for some interface items
CFLAGS+=	-I${.CURDIR}/../../common -I${.CURDIR}/../../.. -I.

machine: .NOMETA
	ln -sf ${.CURDIR}/../../../${MACHINE}/include machine

CLEANFILES+=	machine

.include <bsd.lib.mk>

beforedepend ${OBJS}: machine
