#!/usr/bin/php
<?php
    if ($argc == 2){
        $str = trim($argv[1]);
        if (($n = strspn($str, "1234567890"))){
            while ($n--){
                $num1[$n] = $str[$n];
                $str[$n] = ' ';
            }
            ksort($num1);
            $num1 = implode('', $num1);
            $str = trim($str);
            $n = strlen($str);
            $num2;
            while ($n-- && is_numeric($str[$n])){
                if (is_numeric($str[$n]))
                    $num2[$n] = $str[$n];
                $str[$n] = ' ';
            }
            if ($num2){
                ksort($num2);
                $num2 = implode('', $num2);
            }
            else{
                echo "Syntax Error\n";
                return ;
            }
            $str = trim($str);
            if(strlen($str) == 1){
                if ($str == "+")
                    echo $num1 + $num2."\n";
                else if ($str == "-")
                    echo $num1 - $num2."\n";
                else if ($str == "*")
                    echo $num1 * $num2."\n";
                else if ($str == "/")
                    echo $num1 / $num2."\n";
                else if ($str == "%")
                    echo $num1 % $num2."\n";
            }
            else{
                echo "Syntax Error\n";
                return ;
            }
        }
        else
            echo "Syntax Error\n";
    }
    else
        echo "Incorrect Parameters\n";
?>