#ifndef HAVE_ARRAY_POS_GREP_H
#define HAVE_ARRAY_POS_GREP_H

extern zend_module_entry hps_module_entry;
#define phpext_hps_ptr &hps_module_entry

zval array_pos_grep(zend_string *haystack, zval *needleArray);

#endif