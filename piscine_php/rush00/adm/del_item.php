<?php
	session_start();
	$_SESSION['error_del'] = true;
	if($_POST){
		$connect = mysqli_connect('localhost', 'root', 'laptop2', 'rush00');
		$item =  mysqli_query($connect, "SELECT id FROM products");
		$item = mysqli_fetch_all($item, MYSQLI_ASSOC);
		$id = $_POST['id'];
		foreach($item as $key) {
			if($key['id'] == $id) {
				mysqli_query($connect, "DELETE from products WHERE id = '$id'");
				$_SESSION['error_del'] = false;
			}
		}
	}
	header('Location: ../index.php');
?>