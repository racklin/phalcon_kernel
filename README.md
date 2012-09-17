Sample C extension base on Phalcon kernel
=====================

Get Started
-----------

### Linux/Unix/Mac

On a Unix based platform you can easily compile and install the extension from
sources.

#### Requirements
We need some packages previously installed.

* PHP 5.x development resources
* GCC compiler

Ubuntu:

    sudo apt-get install php5-devel php5-mysql gcc make

Suse:

    yast2 -i php5-pear php5-dev libmysqlclient gcc make autoconf2.13

Compilation
-----------

Follow these instructions to generate a binary extension for your platform:
     # cd ext/
     # export CFLAGS="-O2 -fno-delete-null-pointer-checks"
     # phpize
     # ./configure --enable-validationkit
     # make
     # sudo make install

Add extension to your php.ini

     extension=sample.so

Finally restart the webserver


Phalcon PHP Framework
-----------
Phalcon PHP is a web framework delivered as a C extension providing high performance and lower resource consumption.

http://phalconphp.com

