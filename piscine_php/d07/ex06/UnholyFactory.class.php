<?php
	class UnholyFactory{
		public $army;

		public function __construct(){
			$this->army = array();
		}
		public function absorb ($obj) {
			if (get_parent_class($obj) === "Fighter"){
				if ($this->army[$obj->type])
					echo "(Factory already absorbed a fighter of type " . $obj->type . ")" . PHP_EOL;
				else {
					$this->army[$obj->type] = $obj;
					echo "(Factory absorbed a fighter of type " . $obj->type . ")" . PHP_EOL;
				}
			}
			else
				echo "(Factory can't absorb this, it's not a fighter)" . PHP_EOL;
		}
		public function fabricate($obj) {
			foreach ($this->army as $key => $value)
				if ($key === $obj) {
					echo "(Factory fabricates a fighter of type " . $obj . ")" . PHP_EOL;
					return $this->army[$obj];
				}
			echo "(Factory hasn't absorbed any fighter of type " . $obj . ")" . PHP_EOL;
			return NULL;
		}
	}
?>