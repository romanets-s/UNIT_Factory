#!/usr/bin/env php
<?php
    function cmp($ac, $ab){
        if (ctype_alpha($ac) || ctype_alpha($ab)){
            if (ctype_alpha($ac) && ctype_alpha($ab))
                return (strcasecmp($ac, $ab));
            if (ctype_alpha($ac))
                return (-1);
            else
                return (1);
        }
        if (is_numeric($ac) || is_numeric($ab)){
            if (is_numeric($ac) && is_numeric($ab))
                return ($ac - $ab);
            if (is_numeric($ac))
                return (-1);
            else
                return (1);
        }
        return (ord($ac) - ord($ab));
    }
    function ft_sort($a, $b){
        $n = 0;
        while ($a[$n] && $b[$n]){
            if (($res = cmp($a[$n], $b[$n])))
                return ($res);
            $n++;
        }
        return (strlen($a) - strlen($b));
    }
    if ($argc > 1){
        array_shift($argv);
        $tmp = implode($argv, ' ');
        $tmp = explode(' ', $tmp);
        uasort($tmp, 'ft_sort');
        foreach ($tmp as $key => $item)
            echo $item."\n";
    }
?>