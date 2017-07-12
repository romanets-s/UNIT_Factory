#!/usr/bin/env php
<?php
	if ($argc == 2){
		$arr = explode(' ', $argv[1]);
		$tmp = array();
		foreach ($arr as $key => $item)
			if (!empty($item))
				array_push($tmp, $item);
		$arr = implode(' ', $tmp);
		echo $arr."\n";
	}
?>