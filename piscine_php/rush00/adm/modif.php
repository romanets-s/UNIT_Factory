<?php
	session_start();
	if($_POST){
		if($_POST['login'] && $_POST['passwd'] && $_POST['del'] == 'on'){
			$error = false;
			$connect = mysqli_connect('localhost', 'root', 'laptop2', 'rush00');
			$users =  mysqli_query($connect, "SELECT id, login, pass, user_name, adm FROM users");
			$users = mysqli_fetch_all($users, MYSQLI_ASSOC);
			if($users) {
				foreach($users as $user)
					if($user['login'] == $_POST['login'] && $user['pass'] == hash('whirlpool', $_POST['passwd'])){
						$id = $user['id'];
						mysqli_query($connect, "DELETE FROM users WHERE id=$id");

					}
			}
			$connect->close();
		}
	}
	header('Location: logout.php');
?>