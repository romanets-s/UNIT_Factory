<?php include('header.php'); ?>
<?php
session_start();
$connect = mysqli_connect('localhost', 'root', 'laptop2', 'rush00');
$data = mysqli_query($connect, "SELECT name, description, price, photo, id, category FROM products");
$data = mysqli_fetch_all($data,MYSQLI_ASSOC);
$product = $_SESSION['product'];
$success = 0;
    $id_delele = $_POST['back'];
for ($i = 0; $i < count($product); $i++)
{
    if ($product[$i]['id'] == $id_delele)
        unset($product[$i]);
}
    sort($product);
    $_SESSION['product'] = $product;

$count = count($product);
$real_price = 0;
if ($_POST['buy'])
{
    if (($_SESSION['login'] && $_SESSION['user_name']) != 0)
        $success = 1;
}
foreach ($data as $value)
{
	if($value['photo'] == NULL)
		$photo = 'img/not_img.png';
	else
		$photo = 'data:image/jpeg;base64,'.base64_encode($value['photo']);
	$iter = 0;
	while ($iter < $count)
	{
		if ($product[$iter]['id'] == $value['id'] && $success !== 1)
		{
            $real_price += ($product[$iter]['count'] * $value['price']);
			echo '<div class="Xproducts" id="qwerty">
	            <div class="Xprod_img">
	                <img class="XXprod_img" src="' . $photo . '"/>
	            </div>
	            <div class="desc_prod">
	                <p class="name">'.$value["name"].'</p>
	                <p class="price">'.$value["price"].'  ₳</p>
	                <p class="desc">'.$value["description"].'</p>
	                <p class="desc">Кількість '.$product[$iter]['count'].'</p>
	                <p class="category">Категорія: '.$value["category"].'</p>
	                <form   method="post">
                    <input name="back" type="text" value="'.$product[$iter]['id'].'" hidden>
                    <button type="submit" class="signg_btn" >Відхилити</button>
                    </form>
	            </div>
	        </div>';
		}
		$iter++;
	}
}
?>
<div class="pay_block">
    <p>Ціна: <?php echo ''.$real_price.''?><p>
    <form method="post">
        <input name="buy" type="text" value="1" hidden>
        <button class="buy_button" type="submit"" >Купити</button>
    </form>
</div>
<?php
    if ($_POST['buy'])
    {
        if (($_SESSION['login'] && $_SESSION['user_name']) != 0)
            echo '<div class="result"><h2>Ти успішно купив</h2></div>';
        else
            echo '<div class="result"><h2>Залогінься</h2></div>';
    }
?>
<?php include('footer.php'); ?>
