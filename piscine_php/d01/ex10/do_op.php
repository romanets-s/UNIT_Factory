#!/usr/bin/php
<?php
    if ($argc == 4){
        $res = array();
        foreach ($argv as $key => $item)
            if (!empty($item))
                array_push($res, trim($item));
        array_shift($res);
        if ($res[1] == "+")
            echo $res[0] + $res[2]."\n";
        else if ($res[1] == "-")
            echo $res[0] - $res[2]."\n";
        else if ($res[1] == "*")
            echo $res[0] * $res[2]."\n";
        else if ($res[1] == "/")
            echo $res[0] / $res[2]."\n";
        else if ($res[1] == "%")
            echo $res[0] % $res[2]."\n";
    }
    else
        echo "Incorrect Parameters\n";
?>