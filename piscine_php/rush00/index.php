<?php require_once "install.php"; ?>
<?php include('header.php'); ?>
    <main>
	    <div class="item">
        <?php
	        $connect = mysqli_connect('localhost', 'root', 'laptop2', 'rush00');
	        $data = mysqli_query($connect, "SELECT name, description, price, photo, category, id FROM products");
	        $data = mysqli_fetch_all($data,MYSQLI_ASSOC);
            $i = 0;
	        if(!$_GET || ($_GET['filter'] == 'Фільтрувати' && count($_GET) == 1)){
		        foreach ($data as $value){
					        if($value['photo'] == NULL) {
						        $photo = 'img/not_img.png';
					        }
					        else {
						        $photo = 'data:image/jpeg;base64,' . base64_encode($value['photo']);
					        }
					        if ($i == 0){
						        echo '<div class="clearfix">';
					        }
					        echo '<div class="products"><div class="prod_img"><img src="'.$photo.'"/></div>
	            <div class="desc_prod"><p class="name">'.$value["name"].'</p><p class="price">'.$value["price"].'  ₳</p>
	                <p class="desc">'.$value["description"].'</p><p class="category">Категорія: '.$value["category"].'</p>
	                <form   method="post">Кількість товару: <input name="count" class="count_product" type="text" size="5"/><br/>
                    <input name="id" type="text" value="'.$value["id"].'" hidden><button type="submit" class="signg_btn" >В корзину</button>
                    </form>
	                </div>';
			        if ($_SESSION['adm'] == 1) echo '<form class="del_item" method="POST" action="adm/del_item.php"><p style="display: inline-block; vertical-align: top; margin: 10px 5px 0 0;">Видалити товар</p><input hidden name="id" type="text" value="' . $value['id'] . '"><input type="submit" name="del_item" value="X"></form>';
			        echo '</div>';

			        $i++;
					        if ($i == 4){
						        echo '</div>';
						        $i = 0;
					        }
			           }
	        }
	        else{
		        foreach ($data as $value){
			        foreach($_GET as $key => $item){
				        if($value['category'] == $item){
					        if($value['photo'] == NULL)
						        $photo = 'img/not_img.png';
					        else
						        $photo = 'data:image/jpeg;base64,'.base64_encode($value['photo']);
					        if ($i == 0){
						        echo '<div class="clearfix">';
					        }
					        echo '<div class="products">
							<div class="prod_img"><img src="'.$photo.'"/></div>
	                        <div class="desc_prod"><p class="name">'.$value["name"].'</p><p class="price">'.$value["price"].'  ₳</p>
	                        <p class="desc">'.$value["description"].'</p><p class="category">Категорія: '.$value["category"].'</p>
	                        <form   method="post">Кількість товару: <input name="count" class="count_product" type="number" size="5"/><br/>
                            <input name="id" type="text" value="'.$value["id"].'" hidden><button type="submit" class="signg_btn" >В корзину</button>
                            </form>
	                        </div>';
					        if ($_SESSION['adm'] == 1) echo '<form class="del_item" method="POST" action="adm/del_item.php"><p style="display: inline-block; vertical-align: top; margin: 10px 5px 0 0;">Видалити товар</p><input hidden name="id" type="text" value="' . $value['id'] . '"><input type="submit" name="del_item" value="X"></form>';
					        echo '</div>';
					        $i++;
					        if ($i == 4){
						        echo '</div>';
						        $i = 0;
					        }
				        }
			        }
		        }
	        }

        ?>
	    </div>
    </main>
<?php

    $id_array = array();
    foreach ($_SESSION['product'] as $item)
    {
        $id_array[] = $item['id'];
    }
    if ($_POST['id'] && $_POST['count'] && is_numeric($_POST['count']))
    {
        if (!in_array($_POST['id'], $id_array))
        {
            $add_array = array('id' => $_POST['id'], 'count' => $_POST['count']);
            $_SESSION['product'][] = $add_array;
        }
        else
        {
            for ($i = 0; $i < count($_SESSION['product']); $i++)
            {
                if ($_SESSION['product'][$i]['id'] == $_POST['id'])
                    $_SESSION['product'][$i]['count'] += $_POST['count'];
            }
        }
    }
?>
<?php include('footer.php'); ?>