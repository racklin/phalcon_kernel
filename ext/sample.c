
/*
  +------------------------------------------------------------------------+
  | Sample Extensions                                                      |
  +------------------------------------------------------------------------+
  | Author: racklin@gmail.com
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

zend_class_entry *phalcon_sample_hello_ce;

ZEND_DECLARE_MODULE_GLOBALS(sample)

PHP_MINIT_FUNCTION(sample){


	if(!zend_ce_serializable){
		fprintf(stderr, "Phalcon Error: Interface Serializable was not found");
		return FAILURE;
	}
	if(!zend_ce_iterator){
		fprintf(stderr, "Phalcon Error: Interface Iterator was not found");
		return FAILURE;
	}
	if(!spl_ce_SeekableIterator){
		fprintf(stderr, "Phalcon Error: Interface SeekableIterator was not found");
		return FAILURE;
	}
	if(!spl_ce_Countable){
		fprintf(stderr, "Phalcon Error: Interface Countable was not found");
		return FAILURE;
	}
	if(!zend_ce_arrayaccess){
		fprintf(stderr, "Phalcon Error: Interface ArrayAccess was not found");
		return FAILURE;
	}
        if(!spl_ce_InvalidArgumentException) {
		fprintf(stderr, "Phalcon Error: InvalidArgumentException was not found");
		return FAILURE;
        }

	/** Init globals */
	ZEND_INIT_MODULE_GLOBALS(sample, php_phalcon_init_globals, NULL);

	PHALCON_REGISTER_CLASS(Sample, Hello, sample_hello, phalcon_sample_hello_method_entry, 0);
	zend_declare_property_null(phalcon_sample_hello_ce, SL("messages"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(sample){
	if (PHALCON_GLOBAL(active_memory) != NULL) {
		phalcon_clean_shutdown_stack(TSRMLS_C);
	}
	return SUCCESS;
}

PHP_RINIT_FUNCTION(sample){
	return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(sample){
	if (PHALCON_GLOBAL(active_memory) != NULL) {
		phalcon_clean_shutdown_stack(TSRMLS_C);
	}
	return SUCCESS;
}

zend_module_entry sample_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	PHP_PHALCON_EXTNAME,
	NULL,
	PHP_MINIT(sample),
	PHP_MSHUTDOWN(sample),
	PHP_RINIT(sample),
	PHP_RSHUTDOWN(sample),
	NULL,
#if ZEND_MODULE_API_NO >= 20010901
	PHP_PHALCON_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SAMPLE
ZEND_GET_MODULE(sample)
#endif

