
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"

/**
 * Phalcon\Forms\Manager
 *
 * Manages forms whithin the application. Allowing the developer to access them from
 * any part of the application
 */


/**
 * Phalcon\Forms\Manager initializer
 */
PHALCON_INIT_CLASS(Phalcon_Forms_Manager){

	PHALCON_REGISTER_CLASS(Phalcon\\Forms, Manager, forms_manager, phalcon_forms_manager_method_entry, 0);

	zend_declare_property_null(phalcon_forms_manager_ce, SL("_forms"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Forms_Manager, create){

	zval *name = NULL, *entity = NULL, *form;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &name, &entity) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!name) {
		PHALCON_INIT_VAR(name);
	}
	
	if (!entity) {
		PHALCON_INIT_VAR(entity);
	}
	
	PHALCON_INIT_VAR(form);
	object_init_ex(form, phalcon_forms_form_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(form, "__construct", entity);
	
	RETURN_CTOR(form);
}

/**
 * Returns a form by its name
 *
 * @param string $name
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Manager, get){


	
}

