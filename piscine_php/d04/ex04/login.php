<?php
	include('auth.php');
	session_start();
	$_SESSION['loggued_on_user'] = '';
	$error = true;
	if($_POST){
		if($_POST['login'] && $_POST['passwd']){
			if(auth($_POST['login'], $_POST['passwd'])){
				$_SESSION['loggued_on_user'] = $_POST['login'];
				$error = false;
			}
		}
	}
?>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>42chat</title>
</head>
<body>
	<div>hello </div>
	<iframe name="chat" src="chat.php" width="100%" height="550px"></iframe>
	<iframe name="speak" src="speak.php" width="100%" height="50px"></iframe>
	<div></div>
	<div></div>
</body>
</html>
