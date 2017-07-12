<?php
	class NightsWatch implements IFighter {
		public function recruit($obj){
			if($obj instanceof IFighter)
				$obj->fight();
		}
		public function fight(){

		}
	}
?>