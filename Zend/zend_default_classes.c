/*
   +----------------------------------------------------------------------+
   | Zend Engine                                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) Zend Technologies Ltd. (http://www.zend.com)           |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.00 of the Zend license,     |
   | that is bundled with this package in the file LICENSE.               |
   +----------------------------------------------------------------------+
   | Authors: Sterling Hughes <sterling@php.net>                          |
   |          Marcus Boerger <helly@php.net>                              |
   +----------------------------------------------------------------------+
*/

#include "zend.h"
#include "zend_API.h"
#include "zend_attributes.h"
#include "zend_builtin_functions.h"
#include "zend_interfaces.h"
#include "zend_exceptions.h"
#include "zend_closures.h"
#include "zend_generators.h"
#include "zend_weakrefs.h"
#include "zend_enum.h"
#include "zend_fibers.h"

ZEND_API void zend_register_default_classes(void)
{
	zend_register_interfaces();
	zend_register_default_exception();
	zend_register_iterator_wrapper();
	zend_register_closure_ce();
	zend_register_generator_ce();
	zend_register_weakref_ce();
	zend_register_attribute_ce();
	zend_register_enum_ce();
	zend_register_fiber_ce();
}
