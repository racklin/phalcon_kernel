<?php
dl("sample.so");

class Hello2 {

    public $messages = null;

    public function __construct() {
        $this->messages = array();
    }

    public function addMessage($m) {
        $this->messages[] = $m;
    }

}


// benchmark c-ext version

$start1 = microtime(true);

for ($i =0; $i < 5000; $i++) {
    $t = new Sample\Hello();
    for ($j=0; $j < 100; $j++) {
        $t->addMessage("test");
    }
}

$end1 = microtime(true);

echo "phalcon c version ms = ". ($end1-$start1) . "\n";

// benchmark php version

$start2 = microtime(true);

for ($i =0; $i < 5000; $i++) {
    $t = new Hello2();
    for ($j=0; $j < 100; $j++) {
        $t->addMessage("test");
    }
}

$end2 = microtime(true);

echo "php version ms       = ". ($end2-$start2) . "\n";

?>
