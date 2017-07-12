#!/usr/bin/env php
<?php
	function ft_split($arg){
		$res = preg_split("/[\s]+/", trim($arg));
		sort($res);
		return ($res);
	}
?>