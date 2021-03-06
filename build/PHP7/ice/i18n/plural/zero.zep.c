
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * Plural rules for the following locales and languages:
 * 
 * Locales: ak am bh fil tl guw hi ln mg nso ti wa
 * 
 * Rules:
 *  one → n in 0..1;
 *  other → everything else
 * 
 * Reference CLDR Version 21 (2012-03-01 03:27:30 GMT)
 * @see  http://unicode.org/repos/cldr-tmp/trunk/diff/supplemental/language_plural_rules.html
 * @see  http://unicode.org/repos/cldr/trunk/common/supplemental/plurals.xml
 *
 * @package     Ice/I18n
 * @category    Plural rules
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_I18n_Plural_Zero) {

	ZEPHIR_REGISTER_CLASS(Ice\\I18n\\Plural, Zero, ice, i18n_plural_zero, ice_i18n_plural_zero_method_entry, 0);

	zend_class_implements(ice_i18n_plural_zero_ce TSRMLS_CC, 1, ice_i18n_plural_pluralinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_I18n_Plural_Zero, getCategory) {

	zend_bool _0;
	zval *count_param = NULL;
	int count;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	zephir_fetch_params(0, 1, 0, &count_param);

	count = zephir_get_intval(count_param);


	_0 = count == 0;
	if (!(_0)) {
		_0 = count == 1;
	}
	if (_0) {
		RETURN_STRING("one");
	} else {
		RETURN_STRING("other");
	}

}

