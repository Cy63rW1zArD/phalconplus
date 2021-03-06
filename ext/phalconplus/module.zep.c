
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Module) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus, Module, phalconplus, module, phalconplus_module_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalconplus_module_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Module, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *di;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &di);



	zephir_update_property_this(this_ptr, SL("di"), di TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerautoloaders", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerservices", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Module, registerAutoloaders) {

}

PHP_METHOD(PhalconPlus_Module, registerServices) {

}

