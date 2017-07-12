<?php
	session_start();
	$_SESSION['error_create'] = true;
	if($_POST){
		if($_POST['login'] != '' && $_POST['passwd'] != ''){
			$error = false;
			$connect = mysqli_connect('localhost', 'root', 'laptop2', 'rush00');
			$users =  mysqli_query($connect, "SELECT id, login, pass, user_name, adm FROM users");
			$users = mysqli_fetch_all($users, MYSQLI_ASSOC);
			if($users){
				foreach($users as $user)
					if($user['login'] == $_POST['login'])
						$error = true;
			}
			if($error === false){
				$login = $_POST['login'];
				$passwd =  hash('whirlpool', $_POST['passwd']);
				$user = $_POST['user_name'];
				mysqli_query($connect, "INSERT into users(login, pass, user_name) values ('$login', '$passwd', '$user')");
				$_SESSION['login'] = $login;
				$_SESSION['user_name'] = $user;
				$_SESSION['adm'] = 0;
				$_SESSION['error_create'] = false;
			}
			$connect->close();
		}
	}
	header('Location: ../index.php');
?>