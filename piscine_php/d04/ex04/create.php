<?php
	if($_POST){
		$dir = '../private';
		$file = '/passwd';
		$error = false;
		if(!file_exists($dir))
			mkdir($dir);
		if($_POST['login'] != '' && $_POST['passwd'] != '' && $_POST['submit'] == 'OK'){
			$data = unserialize(file_get_contents($dir.$file));
			if($data)
				foreach($data as $user)
					if($user['login'] == $_POST['login'])
						$error = true;
			if($error === false){
				$data[] = array('login' => $_POST['login'], 'passwd' => hash('whirlpool', $_POST['passwd']));
				file_put_contents($dir.$file, serialize($data));
			}
		}
		else
			$error = true;
		if($error === false){
			echo "OK\n";
			header('Location: index.html');
		}
		else
			echo "ERROR\n";
	}
?>