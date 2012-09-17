
/*
  +------------------------------------------------------------------------+
  | Sample Extension                                                       |
  +------------------------------------------------------------------------+
  | Authors: Rack Lin <racklin@gmail.com>
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_sample_hello_ce;

PHP_METHOD(Phalcon_Sample_Hello, __construct);
PHP_METHOD(Phalcon_Sample_Hello, addMessage);
PHP_METHOD(Phalcon_Sample_Hello, addMessage2);


ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_sample_hello_sayhello, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()


PHALCON_INIT_FUNCS(phalcon_sample_hello_method_entry){
	PHP_ME(Phalcon_Sample_Hello, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Sample_Hello, addMessage, arginfo_phalcon_sample_hello_sayhello, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Sample_Hello, addMessage2, arginfo_phalcon_sample_hello_sayhello, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

