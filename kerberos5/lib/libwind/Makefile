#$FreeBSD: releng/11.1/kerberos5/lib/libwind/Makefile 275022 2014-11-25 09:57:42Z bapt $

LIB=	wind
LDFLAGS=	-Wl,--no-undefined
VERSION_MAP= ${KRB5DIR}/lib/wind/version-script.map
LIBADD=	com_err roken

INCS=	wind.h \
	wind_err.h

SRCS=	bidi.c \
	bidi_table.c \
	combining.c \
	combining_table.c \
	doxygen.c \
	errorlist.c \
	errorlist_table.c \
	ldap.c \
	map.c \
	map_table.c \
	normalize.c \
	normalize_table.c \
	punycode.c \
	stringprep.c \
	utf8.c

SRCS+=	wind_err.c \
	wind_err.h

CFLAGS+=-I${KRB5DIR}/lib/roken -I.

.include <bsd.lib.mk>

.PATH: ${KRB5DIR}/lib/wind
