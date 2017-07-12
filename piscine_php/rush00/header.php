<?php
	session_start();
	/*
		$_SESSION['error_login'];
		$_SESSION['error_create'];
		$_SESSION['login'];
		$_SESSION['user_name'];
		$_SESSION['adm'];
	*/
	$hidden = '';
	if($_SESSION['login'] && $_SESSION['user_name'] && $_SESSION['adm'] == 1){
		$status = "<p>Aдміністратор<p>";
		$hidden = 'hidden';
	}
	else if($_SESSION['login'] && $_SESSION['user_name'] && $_SESSION['adm'] == 0){
		$status = "<p>Зареєстрований користувач<p>";
		$hidden = 'hidden';
	}
	else
		$status = "<p>Гість<p>";

	$form_title = 'Авторизуватися';
	$form_file = 'login.php';
	$form_input = '<label for="passwd">Пароль: </label><input id="passwd" type="password" name="passwd"><br>';
	$form_name = '';
	if($_POST['type'] == 'register'){
		$form_title = 'Реєстрація';
		$form_file = 'create.php';
		$form_name = '<label for="user_name">Ім\'я: </label><input id="user_name" type="text" name="user_name"><br>';
	}
	elseif($_POST['type'] == 'del'){
		$form_title = 'Видалити акаунт';
		$form_file = 'modif.php';
		$form_name = '<label for="del">Видалити акаунт </label><input id="del" type="checkbox" name="del"><br>';
	}
?>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Fresh Air</title>
	<link rel="stylesheet" type="text/css" href="css/styles.css">
	<link rel="shortcut icon" type="image/x-icon" href="img/favicon.ico">
</head>
<body>
<div class="container">
	<header class="head">
		<div class="logo">
			<img src="img/logo.png">
		</div>
		<div class="status">
			<?= $status ?>
		</div>
		<div class="menu">
			<ul>
				<li><a href="index.php" title="">Головна</a></li>
				<li><a href="" title="">Категорії</a></li>
				<li><a href="basket.php" title="">Корзина</a></li>
				<li><a href="kontakty.php" title="">Контакти</a></li>
			</ul>
		</div>
		<div class="login">
			<?php if($_SESSION['error_login']) echo "<p style='color:red;'>Трапилася помилка при авторизації, спробуй інший логін чи пароль.</p>"; $_SESSION['error_login'] = ''; ?>
			<?php if($_SESSION['error_create']) echo "<p style='color:red;'>Трапилася помилка при реєстрації, спробуй інший логін та заповни всі поля.</p>"; $_SESSION['error_create'] = ''; ?>
			<div class="form <?= $hidden ?>">
				<form class="form-top" method="POST" action="adm/<?= $form_file ?>">
					<p><?= $form_title ?></p>
	                    <label for="login">Логін: </label><input id="login" type="text" name="login"><br>
						<?= $form_input ?>
						<?= $form_name ?>
	                    <input type="submit" name="submit" value="OK">
				</form>
				<div class="kostyl">
					<form method="POST">
						<input name="type" type="text" value="login" hidden>
						<input type="submit" value="login">
					</form>
					<form method="POST">
						<input name="type" type="text" value="register" hidden>
						<input type="submit" value="register">
					</form>
					<form method="POST">
						<input type="text" value="del" hidden>
						<input name="type" type="submit" value="del">
					</form>
				</div>
			</div>
			<div>
				<?php if($hidden == 'hidden') echo "<p>Привіт ".$_SESSION['user_name']."!</p><br>".'<a href="adm/logout.php">Вийти з акаунту</a>'; ?>
			</div>
		</div>
	</header>
	<?php if($_SESSION['error_add'] === true) echo "<div class='red'>Щось пішло не так. Спробуй ще раз.</div>"; elseif($_SESSION['error_add'] === false) echo "<div class='green'>Товар успішно доданий!</div>"; $_SESSION['error_add'] = '';?>
<?php if ($_SESSION['adm'] == 1)
	echo '<div class="adm add_item">
		<form enctype="multipart/form-data" method="POST" action="adm/add_item.php">
			<h1>Додати новий товар</h1>
			<div><label>Назва <input type="text" name="name"></label></div>
			<div><label>Ціна<input type="text" name="price"></label></div>
			<div><label>Опис<input type="text" name="desc"></label></div>
			<div><label>Категорія<input type="text" name="category"></label></div>
			<div><label>Фото<input type="file" name="image"></label></div>
			<input type="submit" value="Додати товар">
		</form>
	</div>';
?>
<?php
	$connect = mysqli_connect('localhost', 'root', 'laptop2', 'rush00');
	$data = mysqli_query($connect, "SELECT category FROM products");
	$data = mysqli_fetch_all($data,MYSQLI_ASSOC);
	$cat = array();
	foreach($data as $val)
		$cat[] = $val['category'];
	$data = array_unique($cat);
	echo '<div class="filter_all"><h2>Категорії товарів</h2><div class="filter"><form method="GET">';
	if($_GET){
		foreach ($data as $kk => $value){
				if(array_key_exists($value, $_GET)) {
					echo '<label class="filter-input">' . $value . '<input checked type="checkbox" name="' . $value . '" value="' . $value . '"></label>';
				}
				else {
					echo '<label class="filter-input">' . $value . '<input type="checkbox" name="' . $value . '" value="' . $value . '"></label>';
				}
			}

	}
	else{
		foreach ($data as $value){
			echo '<label class="filter-input">'.$value.'<input type="checkbox" name="'.$value.'" value="'.$value.'"></label>';
		}
	}

	echo '<input type="submit" name="filter" value="Фільтрувати"></form></div></div>';
?>
