# $FreeBSD: releng/11.1/sys/modules/glxiic/Makefile 319182 2017-05-30 04:11:12Z ngie $

#CFLAGS+=	-DGLXIIC_DEBUG

.PATH:	${SRCTOP}/sys/dev/glxiic
KMOD=	glxiic
SRCS=	glxiic.c
SRCS+=	device_if.h bus_if.h pci_if.h iicbus_if.h

.include <bsd.kmod.mk>
