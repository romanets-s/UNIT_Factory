#!/usr/bin/env php
<?php
    if($argc > 1){
    	$res = array();
    	$array = explode(' ', $argv[1]);
    	foreach ($array as $key)
    		if (!empty($key))
    			array_push($res, $key);
        array_push($res, $res[0]);
        unset($res[0]);
        $array = implode(' ', $res);
        echo $array."\n";
    }
?>