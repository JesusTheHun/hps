/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_hps.h"

#include "array_pos_grep.h"

/* True global resources - no need for thread safety here */
static int le_hps;

/* {{{ proto zval array_pos_grep(string haystack, array needleArray)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(hps_array_pos_grep)
{
    zend_string *haystack;
    zval *needleArray;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "Sa", &haystack, &needleArray) == FAILURE) {
        return;
    }

    array_pos_grep(haystack, needleArray);
}
/* }}} */


/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(hps)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "hps support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ hps_functions[]
 *
 * Every user visible function must have an entry in hps_functions[].
 */
const zend_function_entry hps_functions[] = {
	PHP_FE(hps_array_pos_grep,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in hps_functions[] */
};
/* }}} */

/* {{{ hps_module_entry
 */
zend_module_entry hps_module_entry = {
	STANDARD_MODULE_HEADER,
	"hps",
	hps_functions,
	NULL,
	NULL,
	NULL,
	NULL,
	PHP_MINFO(hps),
	PHP_HPS_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_HPS
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE();
#endif
ZEND_GET_MODULE(hps)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
