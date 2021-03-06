# $FreeBSD: releng/11.1/sys/boot/Makefile.inc 319024 2017-05-28 01:08:46Z ngie $

.include <bsd.own.mk>

SSP_CFLAGS=

.if ${MACHINE_CPUARCH} == "arm"
# Do not generate movt/movw, because the relocation fixup for them does not
# translate to the -Bsymbolic -pie format required by self_reloc() in loader(8).
# Also, the fpu is not available in a standalone environment.
.if ${COMPILER_VERSION} < 30800
CFLAGS.clang+=	-mllvm -arm-use-movt=0
.else
CFLAGS.clang+=	-mno-movt
.endif
CFLAGS.clang+=  -mfpu=none
.endif

# The boot loader build uses dd status=none, where possible, for reproducible
# build output (since performance varies from run to run). Trouble is that
# option was recently (10.3) added to FreeBSD and is non-standard. Only use it
# when this test succeeds rather than require dd to be a bootstrap tool.
DD_NOSTATUS!=(dd status=none count=0 2> /dev/null && echo status=none) || true
DD=dd ${DD_NOSTATUS}
