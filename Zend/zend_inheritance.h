/*
   +----------------------------------------------------------------------+
   | Zend Engine                                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) Zend Technologies Ltd. (http://www.zend.com)           |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.00 of the Zend license,     |
   | that is bundled with this package in the file LICENSE.               |
   +----------------------------------------------------------------------+
   | Authors: Andi Gutmans <andi@php.net>                                 |
   |          Zeev Suraski <zeev@php.net>                                 |
   +----------------------------------------------------------------------+
*/

#ifndef ZEND_INHERITANCE_H
#define ZEND_INHERITANCE_H

#include "zend.h"

BEGIN_EXTERN_C()

ZEND_API void zend_do_implement_interface(zend_class_entry *ce, zend_class_entry *iface);
ZEND_API void zend_do_inheritance_ex(zend_class_entry *ce, zend_class_entry *parent_ce, bool checked);

#define zend_do_inheritance(ce, parent_ce) \
	zend_do_inheritance_ex(ce, parent_ce, 0)

ZEND_API zend_class_entry *zend_do_link_class(zend_class_entry *ce, zend_string *lc_parent_name, zend_string *key);

void zend_verify_abstract_class(zend_class_entry *ce);
void zend_build_properties_info_table(zend_class_entry *ce);
zend_class_entry *zend_try_early_bind(zend_class_entry *ce, zend_class_entry *parent_ce, zend_string *lcname, zval *delayed_early_binding);

ZEND_API extern zend_class_entry* (*zend_inheritance_cache_get)(zend_class_entry *ce, zend_class_entry *parent, zend_class_entry **traits_and_interfaces);
ZEND_API extern zend_class_entry* (*zend_inheritance_cache_add)(zend_class_entry *ce, zend_class_entry *proto, zend_class_entry *parent, zend_class_entry **traits_and_interfaces, HashTable *dependencies);

END_EXTERN_C()

#endif
