<?php
	session_start();
	$_SESSION['error_add'] = true;
	if($_POST){
		if($_POST['name'] && is_numeric($_POST['price']) && $_POST['desc'] && $_POST['category']){
			$connect = mysqli_connect('localhost', 'root', 'laptop2', 'rush00');
			$name = $_POST['name'];
			$price = $_POST['price'];
			$desc = $_POST['desc'];
			$cat = $_POST['category'];
			$img = file_get_contents($_FILES['image']['tmp_name']);
			$img = mysqli_real_escape_string($connect, $img);
			mysqli_query($connect, "INSERT INTO products(name, description, price, category, photo) values ('$name', '$desc', '$price', '$cat', '$img')");
			$connect->close();
			$_SESSION['error_add'] = false;
		}
	}
	header('Location: ../index.php');
?>