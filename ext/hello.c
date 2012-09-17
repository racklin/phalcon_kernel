
/*
  +------------------------------------------------------------------------+
  |  Sample Extension
  +------------------------------------------------------------------------+
     Authors:  Rack Lin <racklin@gmail.com>
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "sample.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"
#include "ext/spl/spl_exceptions.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

/**
 * $hello = new Sample\Hello();
 * $msg  = $hello->sayHello('hello');
 *
 */

PHP_METHOD(Phalcon_Sample_Hello, __construct){

        PHALCON_MM_GROW();

        PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Sample_Hello, sayHello){

        zval *message = NULL;
        PHALCON_MM_GROW();

        if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &message) == FAILURE) {
            PHALCON_MM_RESTORE();
            RETURN_NULL();
        }

        if (!message) {
            PHALCON_INIT_VAR(message);
            ZVAL_STRING(message, "hello world!", 1);
        }

        php_printf("Sample\\Hello::sayHello %s \n", Z_STRVAL_P(message));

        RETURN_CCTOR(message);
}

