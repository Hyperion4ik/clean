#	@(#)Makefile	8.1 (Berkeley) 6/9/93
# $FreeBSD: releng/11.1/usr.bin/vgrind/Makefile 291348 2015-11-26 01:14:40Z bdrewery $

PROG=	vfontedpr
SRCS=	regexp.c vfontedpr.c
SCRIPTS=vgrind.sh
FILES=	vgrindefs.src vgrindefs.src.db tmac.vgrind
FILESNAME_vgrindefs.src=	vgrindefs
FILESNAME_vgrindefs.src.db=	vgrindefs.db
FILESDIR=	${SHAREDIR}/misc
FILESDIR_tmac.vgrind=	${SHAREDIR}/tmac
MAN=	vgrind.1 vgrindefs.5

WARNS?=	3

BINDIR=	${LIBEXECDIR}
SCRIPTSDIR=/usr/bin

CLEANFILES= vgrindefs.src.db

.include <bsd.endian.mk>
.if ${TARGET_ENDIANNESS} == "1234"
CAP_MKDB_ENDIAN= -l
.elif ${TARGET_ENDIANNESS} == "4321"
CAP_MKDB_ENDIAN= -b
.else
CAP_MKDB_ENDIAN=
.endif

vgrindefs.src.db: vgrindefs.src
	cap_mkdb ${CAP_MKDB_ENDIAN} -f vgrindefs.src ${.ALLSRC}

.include <bsd.prog.mk>
