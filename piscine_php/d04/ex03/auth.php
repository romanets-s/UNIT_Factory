<?php
	function auth($login, $passwd){
		$dir = '../private';
		$file = '/passwd';
		$data = unserialize(file_get_contents($dir.$file));
		foreach($data as $user)
			if($user['login'] == $login && $user['passwd'] == hash('whirlpool', $passwd))
				return true;
		return false;
	}
?>