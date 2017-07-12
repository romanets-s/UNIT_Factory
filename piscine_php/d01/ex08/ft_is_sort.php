#!/usr/bin/env php
<?php
    function ft_is_sort($arr){
        $as = $arr;
        $rs = $arr;
        asort($as);
        rsort($rs);
        if ($arr === $as || $arr === $rs)
            return (true);
        else
            return (false);
    }
?>