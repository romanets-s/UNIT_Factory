<?php
	class Jaime extends Lannister{
		public function sleepWith($name){
			if($name instanceof Lannister){
				if(get_class($name) == "Cersei")
					print "With pleasure, but only in a tower in Winterfell, then." . PHP_EOL;
				else
					print "Not even if I'm drunk !" . PHP_EOL;
			}else{
				print "Let's do this." . PHP_EOL;
			}
		}
	}
?>