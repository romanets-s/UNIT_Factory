<?php
	include('auth.php');
	session_start();
	$_SESSION['loggued_on_user'] = '';
	$error = true;
	if($_GET){
		if($_GET['login'] && $_GET['passwd']){
			if(auth($_GET['login'], $_GET['passwd'])){
				$_SESSION['loggued_on_user'] = $_GET['login'];
				$error = false;
			}
		}
	}
	if($error === true)
		echo "ERROR\n";
	else
		echo "OK\n";
?>