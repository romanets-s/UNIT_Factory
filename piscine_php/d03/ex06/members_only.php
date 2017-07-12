<?php
if (!($_SERVER['PHP_AUTH_USER'])) {
    header('WWW-Authenticate: Basic realm="My Realm"');
    header('HTTP/1.0 401 Unauthorized');
}
if ($_SERVER['PHP_AUTH_USER'] == "zaz" && $_SERVER['PHP_AUTH_PW'] == "Ilovemylittleponey"){
    $pic = base64_encode(file_get_contents('../img/42.png'));
    $i = 1;
}
?>
<html>
<body>
    <?php if($i == 1){ ?>
        Hello Zaz
        <br />
        <img src='data:image/png;base64,<?php echo $pic; ?>'
    <?php }else ?>
        That area is accessible for members only
</body>
</html>