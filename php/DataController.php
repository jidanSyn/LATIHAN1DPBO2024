<?php

include_once("AnggotaDPR.php");

session_start();

class DataController {
    public function __construct() {}
    public function create($id, $name, $field, $electoral_district, $position, $party) {
        $_SESSION['listDPR'][] = new AnggotaDPR($id, $name, $field, $electoral_district, $position, $party);
    }

    public function getIndexById($id) {

        $index = 0;
        $listDPR = $_SESSION['listDPR'];
        foreach($listDPR as $dpr) {
            if($dpr->get_id() == $id) {
                return $index;
            }
            $index++;
        }
        return null;
    }
    public function getDataById($id) {

        $listDPR = $_SESSION['listDPR'];
        foreach($listDPR as $dpr) {
            if($dpr->get_id() == $id) {
                return $dpr;
            }
            
        }
        return null;
    }
    public function show($id) {}
    public function update($data, $name, $field, $electoral_district, $position, $party) {

        $data->set_name($name);
        $data->set_field($field);
        $data->set_electoral_district($electoral_district);
        $data->set_position($position);
        $data->set_party($party);

    }
    public function destroy($id) {
        $index = $this->getIndexById($id);
        echo "<script>console.log('$index');</script>";

        array_splice($_SESSION['listDPR'], $index, 1);
    }
    
}

?>

