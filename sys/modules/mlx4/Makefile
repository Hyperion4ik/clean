# $FreeBSD: releng/11.1/sys/modules/mlx4/Makefile 319182 2017-05-30 04:11:12Z ngie $
.PATH:  ${SRCTOP}/sys/ofed/drivers/net/mlx4

KMOD=	mlx4
SRCS=	device_if.h bus_if.h vnode_if.h pci_if.h \
	opt_inet.h opt_inet6.h \
	alloc.c catas.c cmd.c cq.c eq.c \
	fw.c icm.c intf.c main.c mcg.c mr.c \
	pd.c port.c profile.c qp.c reset.c sense.c \
	srq.c resource_tracker.c sys_tune.c

CFLAGS+= -I${SRCTOP}/sys/ofed/drivers/net/mlx4
CFLAGS+= -I${SRCTOP}/sys/ofed/include
CFLAGS+= -I${SRCTOP}/sys/compat/linuxkpi/common/include

.include <bsd.kmod.mk>

CFLAGS+= -Wno-cast-qual -Wno-pointer-arith

CWARNFLAGS.mcg.c=	-Wno-unused
