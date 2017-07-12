<?php
	if($_POST){
		$dir = '../private';
		$file = '/passwd';
		$error = true;
		$id = false;
		if($_POST['login'] != '' && $_POST['oldpw'] != '' && $_POST['newpw'] != '' && $_POST['submit'] == 'OK'){
			$data = unserialize(file_get_contents($dir.$file));
			if($data)
				foreach($data as $key => $user)
					if($user['login'] == $_POST['login'])
						$id = $key;
			if($id !== false){
				if($data[$id]['passwd'] == hash('whirlpool', $_POST['oldpw'])){
					$data[$id]['passwd'] = hash('whirlpool', $_POST['newpw']);
					file_put_contents($dir.$file, serialize($data));
					$error = false;
				}
			}
		}
		if($error === true)
			echo "ERROR\n";
		else
			echo "OK\n";
	}
?>