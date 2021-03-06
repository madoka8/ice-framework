
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * Get version of the framework.
 *
 * @package     Ice/Version
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 * @see         http://semver.org (Semantic Versioning 2.0.0)
 */
ZEPHIR_INIT_CLASS(Ice_Version) {

	ZEPHIR_REGISTER_CLASS(Ice, Version, ice, version, ice_version_method_entry, 0);

	zephir_declare_class_constant_long(ice_version_ce, SL("DEV"), 0);

	zephir_declare_class_constant_long(ice_version_ce, SL("ALPHA"), 1);

	zephir_declare_class_constant_long(ice_version_ce, SL("BETA"), 2);

	zephir_declare_class_constant_long(ice_version_ce, SL("RC"), 3);

	zephir_declare_class_constant_long(ice_version_ce, SL("STABLE"), 4);

	zephir_declare_class_constant_long(ice_version_ce, SL("MAJOR"), 1);

	zephir_declare_class_constant_long(ice_version_ce, SL("MINOR"), 0);

	zephir_declare_class_constant_long(ice_version_ce, SL("PATCH"), 37);

	zephir_declare_class_constant_long(ice_version_ce, SL("STAGE"), 4);

	zephir_declare_class_constant_long(ice_version_ce, SL("BUILD"), 1);

	return SUCCESS;

}

/**
 * Get version array.
 *
 * @return array
 */
PHP_METHOD(Ice_Version, current) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	zephir_create_array(return_value, 5, 0 TSRMLS_CC);
	add_assoc_long_ex(return_value, SL("major"), 1);
	add_assoc_long_ex(return_value, SL("minor"), 0);
	add_assoc_long_ex(return_value, SL("patch"), 37);
	add_assoc_long_ex(return_value, SL("stage"), 4);
	add_assoc_long_ex(return_value, SL("build"), 1);
	return;

}

/**
 * Get version string.
 * 
 * 1.0.0-dev
 * 1.0.0-alpha.3
 * 1.0.0-beta.2
 * 1.0.0-rc.5
 * 1.0.0
 *
 * @return string
 */
PHP_METHOD(Ice_Version, get) {

	zval _2$$4, _4$$5, _6$$6;
	int _0;
	zval suffix, _7, _8, _9, _1$$4, _3$$5, _5$$6;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&suffix);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();

	do {
		_0 = 4;
		if (_0 == 0) {
			ZEPHIR_INIT_VAR(&suffix);
			ZVAL_STRING(&suffix, "-dev");
			break;
		}
		if (_0 == 1) {
			ZEPHIR_SINIT_VAR(_1$$4);
			ZVAL_LONG(&_1$$4, 1);
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_CONCAT_SV(&_2$$4, "-alpha.", &_1$$4);
			ZEPHIR_CPY_WRT(&suffix, &_2$$4);
			break;
		}
		if (_0 == 2) {
			ZEPHIR_SINIT_VAR(_3$$5);
			ZVAL_LONG(&_3$$5, 1);
			ZEPHIR_INIT_VAR(&_4$$5);
			ZEPHIR_CONCAT_SV(&_4$$5, "-beta.", &_3$$5);
			ZEPHIR_CPY_WRT(&suffix, &_4$$5);
			break;
		}
		if (_0 == 3) {
			ZEPHIR_SINIT_VAR(_5$$6);
			ZVAL_LONG(&_5$$6, 1);
			ZEPHIR_INIT_VAR(&_6$$6);
			ZEPHIR_CONCAT_SV(&_6$$6, "-rc.", &_5$$6);
			ZEPHIR_CPY_WRT(&suffix, &_6$$6);
			break;
		}
		if (_0 == 4) {
			ZEPHIR_INIT_NVAR(&suffix);
			ZVAL_STRING(&suffix, "");
			break;
		}
	} while(0);

	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 1);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, 37);
	ZEPHIR_CONCAT_VSVSVV(return_value, &_7, ".", &_8, ".", &_9, &suffix);
	RETURN_MM();

}

/**
 * Get version id.
 *
 * [major][minor(2 digits)][patch (2 digits)][stage][build]
 * eg. id for 1.4.12-rc.5 is 1041235
 *
 * @return int
 */
PHP_METHOD(Ice_Version, id) {

	zval id, _0, _1, _2, _3, _5, _6, _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 1);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "%02s");
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_FUNCTION(&_3, "sprintf", &_4, 1, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "%02s");
	ZVAL_LONG(&_2, 37);
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", &_4, 1, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 4);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 1);
	ZEPHIR_INIT_VAR(&id);
	ZEPHIR_CONCAT_VVVVV(&id, &_0, &_3, &_5, &_6, &_7);
	RETURN_MM_LONG(zephir_get_intval(&id));

}

