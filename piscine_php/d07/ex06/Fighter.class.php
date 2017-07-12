<?php
	abstract class Fighter{
		public $type = "";

		public function __construct($target){
			$this->type = $target;
		}
		abstract public function fight($target) ;
	}
?>