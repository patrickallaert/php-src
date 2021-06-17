/*
   +----------------------------------------------------------------------+
   | Zend Engine                                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) Zend Technologies Ltd. (http://www.zend.com)           |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.00 of the Zend license,     |
   | that is bundled with this package in the file LICENSE.               |
   +----------------------------------------------------------------------+
   | Authors: David Soria Parra <david.soriaparra@sun.com>                |
   +----------------------------------------------------------------------+
*/

#ifndef	_ZEND_DTRACE_H
#define	_ZEND_DTRACE_H

#ifndef ZEND_WIN32
# include <unistd.h>
#endif

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef HAVE_DTRACE
ZEND_API extern zend_op_array *(*zend_dtrace_compile_file)(zend_file_handle *file_handle, int type);
ZEND_API extern void (*zend_dtrace_execute)(zend_op_array *op_array);
ZEND_API extern void (*zend_dtrace_execute_internal)(zend_execute_data *execute_data, zval *return_value);

ZEND_API zend_op_array *dtrace_compile_file(zend_file_handle *file_handle, int type);
ZEND_API void dtrace_execute_ex(zend_execute_data *execute_data);
ZEND_API void dtrace_execute_internal(zend_execute_data *execute_data, zval *return_value);
#include <zend_dtrace_gen.h>

void dtrace_error_notify_cb(int type, zend_string *error_filename, uint32_t error_lineno, zend_string *message);

#endif /* HAVE_DTRACE */

#ifdef	__cplusplus
}
#endif

#endif	/* _ZEND_DTRACE_H */
