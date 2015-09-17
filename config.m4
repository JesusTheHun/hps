PHP_ARG_ENABLE(hps, whether to enable hps support,
Make sure that the comment is aligned:
[  --enable-hps           Enable hps support])

if test "$PHP_HPS" != "no"; then
  PHP_NEW_EXTENSION(hps, hps.c array_pos_grep.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
