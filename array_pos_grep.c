#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"

#include "ext/standard/info.h"
#include "ext/standard/basic_functions.h"
#include "zend_smart_str.h"
#include "ext/standard/php_string.h"

#include "php_hps.h"

#include "array_pos_grep.h"

zval array_pos_grep(zend_string *haystack, zval *needleArray) {

    zval *needle;
    size_t haystack_len;
    zend_string *string_key;
    zend_ulong num_key;
    zval *entry;
    zval *returnme;
    char *found;

    haystack_len = ZSTR_LEN(haystack);

    if (haystack_len == 0) {
        php_error_docref(NULL, E_WARNING, "Empty haystack");
        RETURN_FALSE;
    }

    if (zend_hash_num_elements(Z_ARRVAL_P(needleArray)) == 0) {
        RETURN_FALSE;
    }

    array_init(returnme);

    ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(needleArray), num_key, string_key, needle) {

        if (!Z_STRLEN_P(needle)) {
            php_error_docref(NULL, E_WARNING, "Empty needle");
            continue;
        }

        if (Z_STRLEN_P(needle) > haystack_len) {
            continue;
        }

        found = (char*)php_memnstr(
            ZSTR_VAL(haystack),
            Z_STRVAL_P(needle),
            Z_STRLEN_P(needle),
            ZSTR_VAL(haystack) + haystack_len
        );

        if (Z_REFCOUNTED_P(needle)) {
            Z_ADDREF_P(needle);
        }

        if (found) {
            zval pos;
            ZVAL_LONG(&pos, found - ZSTR_VAL(haystack));
            ZVAL_MAKE_REF(&pos);

            zend_hash_update(Z_ARRVAL_P(returnme), Z_STR_P(needle), &pos);
        }

    } ZEND_HASH_FOREACH_END();

    return returnme;
}