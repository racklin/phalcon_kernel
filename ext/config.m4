PHP_ARG_ENABLE(sample, whether to enable sample, [ --enable-sample   Enable sample])

if test "$PHP_SAMPLE" = "yes"; then
  AC_DEFINE(HAVE_SAMPLE, 1, [Whether you have Sample])
  PHP_NEW_EXTENSION(sample, sample.c kernel/main.c kernel/fcall.c kernel/require.c kernel/debug.c kernel/assert.c kernel/object.c kernel/array.c kernel/operators.c kernel/concat.c kernel/exception.c kernel/memory.c hello.c, $ext_shared)
fi
