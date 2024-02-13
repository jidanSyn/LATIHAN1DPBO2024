<?php

class AnggotaDPR {
    private $id = "";
    private $name = "";
    private $field = "";
    private $electoral_district = "";
    private $position = "";
    private $party = "";
    
    public function __construct($id, $name="", $field="", $electoral_district="", $position="", $party="") {
        $this->id = $id;
        $this->name = $name;
        $this->field = $field;
        $this->electoral_district = $electoral_district;
        $this->position = $position;
        $this->party = $party;
    }

    public function set_id($id) {
        $this->id = $id;
    }

    public function set_name($name) {
        $this->name = $name;
    }

    public function set_field($field) {
        $this->field = $field;
    }
    public function set_electoral_district($electoral_district) {
        $this->electoral_district = $electoral_district;
    }

    public function set_position($position) {
        $this->position = $position;
    }

    public function set_party($party) {
        $this->party = $party;
    }

    public function get_id() {
        return $this->id;
    }
    public function get_name() {
        return $this->name;
    }
    public function get_field() {
        return $this->field;
    }
    public function get_electoral_district() {
        return $this->electoral_district;
    }
    public function get_position() {
        return $this->position;
    }
    public function get_party() {
        return $this->party;
    }

}

?>