#!/usr/bin/env php
<?php
	function ft_split($arg){
		$res = preg_split("/[\s]+/", trim($arg));
		sort($res);
		return ($res);
	}
    if ($argc > 1){
        $arr = array();
	    foreach ($argv as $key => $item)
	    	if ($key != 0)
                array_push($arr, $item);
        $tmp = implode(' ', $arr);
        $arr = ft_split($tmp);    
        foreach ($arr as $key => $item)
            echo $item."\n";
    }
?>