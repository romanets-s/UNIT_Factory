<?php
    session_start();
    if($_GET && $_GET['submit'] == 'OK'){
	    $_SESSION = array('login' => $_GET['login'], 'passwd' => $_GET['passwd']);
    }
?>
<html>
    <body>
        <form method="GET">
            Username: <input type="text" name="login" value="<?= $_SESSION['login'] ?>">
            <br>
            Password: <input type="login" name="passwd" value="<?= $_SESSION['passwd'] ?>">
            <input type="submit" name="submit" value="OK">
        </form>
    </body>
</html>
