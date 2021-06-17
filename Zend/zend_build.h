/*
   +----------------------------------------------------------------------+
   | Zend Engine                                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) Zend Technologies Ltd. (http://www.zend.com)           |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.00 of the Zend license,     |
   | that is bundled with this package in the file LICENSE.               |
   +----------------------------------------------------------------------+
   | Authors: Stanislav Malyshev <stas@zend.com>                          |
   +----------------------------------------------------------------------+
*/

#ifndef ZEND_BUILD_H
#define ZEND_BUILD_H

#define ZEND_TOSTR_(x) #x
#define ZEND_TOSTR(x) ZEND_TOSTR_(x)

#ifdef ZTS
#define ZEND_BUILD_TS ",TS"
#else
#define ZEND_BUILD_TS ",NTS"
#endif

#if ZEND_DEBUG
#define ZEND_BUILD_DEBUG ",debug"
#else
#define ZEND_BUILD_DEBUG
#endif

#if defined(ZEND_WIN32) && defined(PHP_COMPILER_ID)
#define ZEND_BUILD_SYSTEM "," PHP_COMPILER_ID
#else
#define ZEND_BUILD_SYSTEM
#endif

/* for private applications */
#define ZEND_BUILD_EXTRA

#endif
