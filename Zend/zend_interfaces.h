/*
   +----------------------------------------------------------------------+
   | Zend Engine                                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) Zend Technologies Ltd. (http://www.zend.com)           |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.00 of the Zend license,     |
   | that is bundled with this package in the file LICENSE.               |
   +----------------------------------------------------------------------+
   | Authors: Marcus Boerger <helly@php.net>                              |
   +----------------------------------------------------------------------+
*/

#ifndef ZEND_INTERFACES_H
#define ZEND_INTERFACES_H

#include "zend.h"
#include "zend_API.h"

BEGIN_EXTERN_C()

extern ZEND_API zend_class_entry *zend_ce_traversable;
extern ZEND_API zend_class_entry *zend_ce_aggregate;
extern ZEND_API zend_class_entry *zend_ce_iterator;
extern ZEND_API zend_class_entry *zend_ce_arrayaccess;
extern ZEND_API zend_class_entry *zend_ce_serializable;
extern ZEND_API zend_class_entry *zend_ce_countable;
extern ZEND_API zend_class_entry *zend_ce_stringable;

typedef struct _zend_user_iterator {
	zend_object_iterator     it;
	zend_class_entry         *ce;
	zval                     value;
} zend_user_iterator;

ZEND_API zval* zend_call_method(zend_object *object, zend_class_entry *obj_ce, zend_function **fn_proxy, const char *function_name, size_t function_name_len, zval *retval, uint32_t param_count, zval* arg1, zval* arg2);

#define zend_call_method_with_0_params(obj, obj_ce, fn_proxy, function_name, retval) \
	zend_call_method(obj, obj_ce, fn_proxy, function_name, sizeof(function_name)-1, retval, 0, NULL, NULL)

#define zend_call_method_with_1_params(obj, obj_ce, fn_proxy, function_name, retval, arg1) \
	zend_call_method(obj, obj_ce, fn_proxy, function_name, sizeof(function_name)-1, retval, 1, arg1, NULL)

#define zend_call_method_with_2_params(obj, obj_ce, fn_proxy, function_name, retval, arg1, arg2) \
	zend_call_method(obj, obj_ce, fn_proxy, function_name, sizeof(function_name)-1, retval, 2, arg1, arg2)

ZEND_API void zend_user_it_rewind(zend_object_iterator *_iter);
ZEND_API zend_result zend_user_it_valid(zend_object_iterator *_iter);
ZEND_API void zend_user_it_get_current_key(zend_object_iterator *_iter, zval *key);
ZEND_API zval *zend_user_it_get_current_data(zend_object_iterator *_iter);
ZEND_API void zend_user_it_move_forward(zend_object_iterator *_iter);
ZEND_API void zend_user_it_invalidate_current(zend_object_iterator *_iter);

ZEND_API void zend_user_it_new_iterator(zend_class_entry *ce, zval *object, zval *iterator);
ZEND_API zend_object_iterator *zend_user_it_get_new_iterator(zend_class_entry *ce, zval *object, int by_ref);

ZEND_API void zend_register_interfaces(void);

ZEND_API int zend_user_serialize(zval *object, unsigned char **buffer, size_t *buf_len, zend_serialize_data *data);
ZEND_API int zend_user_unserialize(zval *object, zend_class_entry *ce, const unsigned char *buf, size_t buf_len, zend_unserialize_data *data);

ZEND_API int zend_class_serialize_deny(zval *object, unsigned char **buffer, size_t *buf_len, zend_serialize_data *data);
ZEND_API int zend_class_unserialize_deny(zval *object, zend_class_entry *ce, const unsigned char *buf, size_t buf_len, zend_unserialize_data *data);

ZEND_API zend_result zend_create_internal_iterator_zval(zval *return_value, zval *obj);

END_EXTERN_C()

#endif /* ZEND_INTERFACES_H */
