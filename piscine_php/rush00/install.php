<?php
$connection_1 = mysqli_connect('localhost', 'root', 'laptop2');
if (!$connection_1){
    die("Connection failed: " . mysqli_connect_error());
}
//$sql_1 = "CREATE DATABASE IF NOT EXISTS rush00";
mysqli_query($connection_1, "CREATE DATABASE IF NOT EXISTS rush00");
mysqli_close($connection_1);

session_start();
$work_conection = mysqli_connect('localhost', 'root', 'laptop2', 'rush00');
if (!$work_conection){
    die("Connection failed: " . mysqli_connect_error());
}

mysqli_query($work_conection, 'CREATE TABLE IF NOT EXISTS users(
        id INT UNSIGNED AUTO_INCREMENT NOT NULL PRIMARY KEY,
        login VARCHAR(255),
        pass VARCHAR(255) NOT NULL,
        user_name VARCHAR(255),
        adm ENUM(\'0\', \'1\') DEFAULT \'0\')');

mysqli_query($work_conection, 'CREATE TABLE IF NOT EXISTS products(       
        id INT UNSIGNED AUTO_INCREMENT NOT NULL PRIMARY KEY,
        name VARCHAR (255),
        description VARCHAR (255),
        price FLOAT UNSIGNED NOT NULL,
        category VARCHAR (255),
        photo MEDIUMBLOB)');

mysqli_close($work_conection);
?>