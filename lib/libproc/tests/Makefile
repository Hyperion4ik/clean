# $FreeBSD: releng/11.1/lib/libproc/tests/Makefile 316386 2017-04-02 02:14:44Z asomers $

ATF_TESTS_C+=	proc_test

PROGS=		target_prog
SRCS_target_prog=	target_prog.c
BINDIR_target_prog=	${TESTSDIR}

WARNS?=		6
LIBADD=	elf proc rtld_db util

# Ensure that symbols aren't stripped from the test program, as they're needed
# for testing symbol lookup.
STRIP=

.include <bsd.test.mk>
