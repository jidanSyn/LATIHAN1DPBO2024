<?php

include("DataController.php");
include_once("AnggotaDPR.php");


if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Print the entire POST payload
    $data_controller = new DataController();

    echo "<pre>";
    print_r($_POST);
    echo "</pre>";
    $type;
    switch($_POST['action']) {
        case 'create':
            $data_controller->create($_POST['id'], $_POST['name'], $_POST['field'], $_POST['electoral_district'], $_POST['position'], $_POST['party']);
            echo "<script>alert('Data successfully created');</script>";
            $type = 1;
            break;
        case 'edit':
            
            break;
        case 'delete':
            $data_controller->destroy($_POST['id']);
            break;
        default:
            $type = 0;
            break;
    }

    header('Location: index.php?success='.(string)$type);
}

?>