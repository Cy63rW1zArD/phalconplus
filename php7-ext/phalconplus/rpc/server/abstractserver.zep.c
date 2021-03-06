
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
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(PhalconPlus_RPC_Server_AbstractServer) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\RPC\\Server, AbstractServer, phalconplus, rpc_server_abstractserver, phalconplus_rpc_server_abstractserver_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalconplus_rpc_server_abstractserver_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_rpc_server_abstractserver_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalconplus_rpc_server_abstractserver_ce, SL("phpOnly"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_rpc_server_abstractserver_ce, SL("eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_RPC_Server_AbstractServer, __construct) {

}

PHP_METHOD(PhalconPlus_RPC_Server_AbstractServer, callByParams) {

	zval _18, _3$$4, _20$$8, _26$$8, _23$$9, _24$$9;
	zend_class_entry *_16, *_8$$5;
	zend_bool _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *service_param = NULL, *method_param = NULL, *request = NULL, request_sub, __$true, __$false, serviceClass, _0, _1, serviceObj, response, e, _15, _17, tmp$$4, param$$4, paramClass$$4, _4$$4, _5$$4, _6$$5, _7$$5, _9$$6, _10$$6, _11$$6, _12$$7, _13$$7, _14$$7, _19$$8, _21$$8, _25$$8, _27$$8, _28$$8, _22$$9, _29$$11;
	zval service, method, _30$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&request_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&serviceClass);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&serviceObj);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&tmp$$4);
	ZVAL_UNDEF(&param$$4);
	ZVAL_UNDEF(&paramClass$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &service_param, &method_param, &request);

	if (UNEXPECTED(Z_TYPE_P(service_param) != IS_STRING && Z_TYPE_P(service_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'service' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(service_param) == IS_STRING)) {
		zephir_get_strval(&service, service_param);
	} else {
		ZEPHIR_INIT_VAR(&service);
		ZVAL_EMPTY_STRING(&service);
	}
	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_EMPTY_STRING(&method);
	}


	ZEPHIR_INIT_VAR(&serviceClass);
	ZVAL_STRING(&serviceClass, "");
	ZEPHIR_INIT_VAR(&_1);
	zephir_ucfirst(&_1, &service);
	ZEPHIR_INIT_NVAR(&serviceClass);
	ZEPHIR_CONCAT_VS(&serviceClass, &_1, "Service");
	_2 = Z_TYPE_P(request) == IS_OBJECT;
	if (_2) {
		_2 = zephir_instance_of_ev(request, phalconplus_base_protobuffer_ce TSRMLS_CC);
	}
	if (_2) {
		if (1) {
			zephir_update_property_zval(this_ptr, SL("phpOnly"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("phpOnly"), &__$false);
		}
	} else if (Z_TYPE_P(request) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&tmp$$4);
		array_init(&tmp$$4);
		ZEPHIR_CPY_WRT(&tmp$$4, request);
		ZEPHIR_INIT_VAR(&param$$4);
		object_init_ex(&param$$4, zephir_get_internal_ce(SL("reflectionparameter")));
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_create_array(&_3$$4, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_3$$4, &serviceClass);
		zephir_array_fast_append(&_3$$4, &method);
		ZVAL_LONG(&_4$$4, 0);
		ZEPHIR_CALL_METHOD(NULL, &param$$4, "__construct", NULL, 2, &_3$$4, &_4$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$4, &param$$4, "getclass", NULL, 3);
		zephir_check_call_status();
		if (zephir_is_true(&_5$$4)) {
			ZEPHIR_CALL_METHOD(&_6$$5, &param$$4, "getclass", NULL, 3);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&paramClass$$4, &_6$$5, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(request);
			zephir_fetch_safe_class(&_7$$5, &paramClass$$4);
			_8$$5 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_7$$5), Z_STRLEN_P(&_7$$5), ZEND_FETCH_CLASS_AUTO);
			object_init_ex(request, _8$$5);
			if (zephir_has_constructor(request TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, request, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(NULL, request, "softclone", NULL, 0, &tmp$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_9$$6);
			object_init_ex(&_9$$6, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_VAR(&_10$$6);
			zephir_json_encode(&_10$$6, request, 0 );
			ZEPHIR_INIT_VAR(&_11$$6);
			ZEPHIR_CONCAT_SVSVSV(&_11$$6, "Service class:method definition is invalid. Detail: ", &service, " : ", &method, ". Request: ", &_10$$6);
			ZEPHIR_CALL_METHOD(NULL, &_9$$6, "__construct", NULL, 7, &_11$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$6, "phalconplus/RPC/Server/AbstractServer.zep", 29 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(&_12$$7);
		object_init_ex(&_12$$7, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_13$$7);
		zephir_json_encode(&_13$$7, request, 0 );
		ZEPHIR_INIT_VAR(&_14$$7);
		ZEPHIR_CONCAT_SV(&_14$$7, "Your input is not allowed. Request: ", &_13$$7);
		ZEPHIR_CALL_METHOD(NULL, &_12$$7, "__construct", NULL, 7, &_14$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_12$$7, "phalconplus/RPC/Server/AbstractServer.zep", 32 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&serviceObj);
	zephir_fetch_safe_class(&_15, &serviceClass);
	_16 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_15), Z_STRLEN_P(&_15), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&serviceObj, _16);
	if (zephir_has_constructor(&serviceObj TSRMLS_CC)) {
		zephir_read_property(&_17, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &serviceObj, "__construct", NULL, 0, &_17);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_18);
	zephir_create_array(&_18, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_18, &serviceObj);
	zephir_array_fast_append(&_18, &method);
	if (zephir_is_callable(&_18 TSRMLS_CC)) {
		zephir_read_property(&_19$$8, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_20$$8);
		zephir_create_array(&_20$$8, 3, 0 TSRMLS_CC);
		zephir_array_fast_append(&_20$$8, &service);
		zephir_array_fast_append(&_20$$8, &method);
		zephir_array_fast_append(&_20$$8, request);
		ZEPHIR_INIT_VAR(&_21$$8);
		ZVAL_STRING(&_21$$8, "backend-server:beforeExecute");
		ZEPHIR_CALL_METHOD(NULL, &_19$$8, "fire", NULL, 0, &_21$$8, this_ptr, &_20$$8);
		zephir_check_call_status();

		/* try_start_1: */

			ZEPHIR_INIT_VAR(&_22$$9);
			ZEPHIR_INIT_VAR(&_23$$9);
			zephir_create_array(&_23$$9, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&_23$$9, &serviceObj);
			zephir_array_fast_append(&_23$$9, &method);
			ZEPHIR_INIT_VAR(&_24$$9);
			zephir_create_array(&_24$$9, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_24$$9, request);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_22$$9, &_23$$9, &_24$$9);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CPY_WRT(&response, &_22$$9);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_21$$8);
			ZVAL_OBJ(&_21$$8, EG(exception));
			Z_ADDREF_P(&_21$$8);
			if (zephir_instance_of_ev(&_21$$8, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_21$$8);
				zephir_throw_exception_debug(&e, "phalconplus/RPC/Server/AbstractServer.zep", 43 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_read_property(&_25$$8, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_26$$8);
		zephir_create_array(&_26$$8, 3, 0 TSRMLS_CC);
		zephir_array_fast_append(&_26$$8, &service);
		zephir_array_fast_append(&_26$$8, &method);
		zephir_array_fast_append(&_26$$8, request);
		ZEPHIR_INIT_VAR(&_27$$8);
		ZVAL_STRING(&_27$$8, "backend-server:afterExecute");
		ZEPHIR_CALL_METHOD(NULL, &_25$$8, "fire", NULL, 0, &_27$$8, this_ptr, &_26$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_27$$8);
		zephir_read_property(&_28$$8, this_ptr, SL("phpOnly"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE(&_28$$8)) {
			ZEPHIR_CPY_WRT(&_27$$8, &response);
		} else {
			ZEPHIR_CALL_METHOD(&_27$$8, &response, "toarray", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_CCTOR(&_27$$8);
	} else {
		ZEPHIR_INIT_VAR(&_29$$11);
		object_init_ex(&_29$$11, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_30$$11);
		ZEPHIR_CONCAT_SVSV(&_30$$11, "Service:method not found. Detail: ", &service, " : ", &method);
		ZEPHIR_CALL_METHOD(NULL, &_29$$11, "__construct", NULL, 7, &_30$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_29$$11, "phalconplus/RPC/Server/AbstractServer.zep", 48 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

}

/**
 *
 * @param array rawData
 * <code> 
 *     rawData = ["service":"Demo", "method":"demo", "args": <ProtoBuffer>, "logId": "234fdfaf3334"]
 * </code>
 * @return <ProtoBuffer>
 * @throw \Exception
 *
 */
PHP_METHOD(PhalconPlus_RPC_Server_AbstractServer, callByObject) {

	zend_bool _7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rawData_param = NULL, service, method, request, response, logId, message, _4, _6, _8, _9, _14, _16, _18, _19, _0$$3, _1$$3, _2$$4, _3$$4, _10$$7, _11$$7, _12$$7, _13$$7, _20$$8, _21$$8, _22$$8, _23$$8;
	zval rawData, _5, _15, _17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawData);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&logId);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rawData_param);

	zephir_get_arrval(&rawData, rawData_param);


	ZEPHIR_INIT_VAR(&logId);
	ZVAL_STRING(&logId, "");
	ZEPHIR_INIT_VAR(&message);
	ZVAL_STRING(&message, "");
	ZEPHIR_OBS_VAR(&service);
	if (!(zephir_array_isset_string_fetch(&service, &rawData, SL("service"), 0))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVS(&_1$$3, "service ", &service, " not exists");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 7, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalconplus/RPC/Server/AbstractServer.zep", 67 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&method);
	if (!(zephir_array_isset_string_fetch(&method, &rawData, SL("method"), 0))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_SVS(&_3$$4, "method ", &method, " not exists");
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 7, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalconplus/RPC/Server/AbstractServer.zep", 71 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&request);
	if (!(zephir_array_isset_string_fetch(&request, &rawData, SL("args"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "args not exists", "phalconplus/RPC/Server/AbstractServer.zep", 75);
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(&_5, &service);
	zephir_array_fast_append(&_5, &method);
	zephir_array_fast_append(&_5, &rawData);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "backend-server:requestCheck");
	ZEPHIR_CALL_METHOD(NULL, &_4, "fire", NULL, 0, &_6, this_ptr, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_6);
	zephir_fast_trim(&_6, &service, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(&service, &_6);
	ZEPHIR_INIT_NVAR(&_6);
	zephir_fast_trim(&_6, &method, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(&method, &_6);
	_7 = ZEPHIR_IS_EMPTY(&service);
	if (!(_7)) {
		_7 = ZEPHIR_IS_EMPTY(&method);
	}
	if (_7) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "service:method(args) must exists. All of them!!!", "phalconplus/RPC/Server/AbstractServer.zep", 84);
		return;
	}
	ZEPHIR_OBS_NVAR(&logId);
	if (zephir_array_isset_string_fetch(&logId, &rawData, SL("logId"), 0)) {
	}
	zephir_read_property(&_8, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "logger");
	ZEPHIR_CALL_METHOD(&_9, &_8, "has", NULL, 0, &_6);
	zephir_check_call_status();
	if (zephir_is_true(&_9)) {
		ZEPHIR_INIT_VAR(&_10$$7);
		zephir_json_encode(&_10$$7, &request, 0 );
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_SVSVSVSV(&message, "RPC Request - logId: ", &logId, ", invoke: ", &service, "::", &method, ", args: ", &_10$$7);
		zephir_read_property(&_11$$7, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_13$$7);
		ZVAL_STRING(&_13$$7, "logger");
		ZEPHIR_CALL_METHOD(&_12$$7, &_11$$7, "get", NULL, 0, &_13$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_12$$7, "log", NULL, 0, &message);
		zephir_check_call_status();
	}
	zephir_read_property(&_14, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_15);
	zephir_create_array(&_15, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(&_15, &service);
	zephir_array_fast_append(&_15, &method);
	zephir_array_fast_append(&_15, &request);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "backend-server:beforeDispatch");
	ZEPHIR_CALL_METHOD(NULL, &_14, "fire", NULL, 0, &_6, this_ptr, &_15);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "callbyparams", NULL, 0, &service, &method, &request);
	zephir_check_call_status();
	zephir_read_property(&_16, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_17);
	zephir_create_array(&_17, 4, 0 TSRMLS_CC);
	zephir_array_fast_append(&_17, &service);
	zephir_array_fast_append(&_17, &method);
	zephir_array_fast_append(&_17, &request);
	zephir_array_fast_append(&_17, &response);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "backend-server:afterDispatch");
	ZEPHIR_CALL_METHOD(NULL, &_16, "fire", NULL, 0, &_6, this_ptr, &_17);
	zephir_check_call_status();
	zephir_read_property(&_18, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "logger");
	ZEPHIR_CALL_METHOD(&_19, &_18, "has", NULL, 0, &_6);
	zephir_check_call_status();
	if (zephir_is_true(&_19)) {
		ZEPHIR_INIT_VAR(&_20$$8);
		zephir_json_encode(&_20$$8, &response, 0 );
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_SVSVSVSV(&message, "RPC Response - logId: ", &logId, ", invoke: ", &service, "::", &method, ", response: ", &_20$$8);
		zephir_read_property(&_21$$8, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_23$$8);
		ZVAL_STRING(&_23$$8, "logger");
		ZEPHIR_CALL_METHOD(&_22$$8, &_21$$8, "get", NULL, 0, &_23$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_22$$8, "log", NULL, 0, &message);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&response);

}

