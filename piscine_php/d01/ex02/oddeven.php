#!/usr/bin/env php
<?php
	echo "Enter a number: ";
	while (fscanf(STDIN, "%s\n", $n)){
		if (is_numeric($n)){
			if (($n % 2) == 0)
				echo "The number $n is even\n";
			else
				echo "The number $n is odd\n";
		}
		else
			echo "'$n' is not a number\n";
		unset($n);
		echo "Enter a number: ";
	}
?>