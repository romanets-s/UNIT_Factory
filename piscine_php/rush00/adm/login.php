<?php
	session_start();
	$_SESSION['error_login'] = true;
	function auth($login, $passwd){
		$connect = mysqli_connect('localhost', 'root', 'laptop2', 'rush00');
		$users =  mysqli_query($connect, "SELECT id, login, pass, user_name, adm FROM users");
		$users = mysqli_fetch_all($users, MYSQLI_ASSOC);
		foreach($users as $user)
			if($user['login'] == $login && $user['pass'] == hash('whirlpool', $passwd)){
				$_SESSION['user_name'] = $user['user_name'];
				$_SESSION['adm'] = $user['adm'];
				$connect->close();
				return true;
			}
		$connect->close();
		return false;
	}
	$_SESSION['login'] = '';
	if($_POST){
		if($_POST['login'] && $_POST['passwd']){
			if(auth($_POST['login'], $_POST['passwd'])){
				$_SESSION['login'] = $_POST['login'];
				$_SESSION['error_login'] = false;
			}
		}
	}
	header('Location: ../index.php');
?>
