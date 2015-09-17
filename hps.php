<?php

$haystack = 'A man walks into a bar';

$r = hps_array_pos_grep($haystack, array('man', 'bar', 'vegetables'));

echo "\n\n";
var_dump($r);
echo "\n\n";

?>
