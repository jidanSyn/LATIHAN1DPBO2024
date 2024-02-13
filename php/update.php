<?php
// Include necessary files
include_once("DataController.php");
include_once("AnggotaDPR.php");

// Initialize variables
$id = null;
$name = "";
$field = "";
$electoral_district = "";
$position = "";
$party = "";

// Check if ID is provided in the URL
if (isset($_POST["id"])) {
    // Retrieve the ID from the URL
    $id = $_POST["id"];
    // Retrieve data for the specified ID
    $data_controller = new DataController();
    $data = $data_controller->getDataById($id); // Implement this method in your DataController class

    $_SESSION['currentUpdating'] = $data;
    

    // Check if data exists for the given ID
    if ($data) {
        // Populate variables with data values
        $name = $data->get_name();
        $field = $data->get_field();
        $electoral_district = $data->get_electoral_district();
        $position = $data->get_position();
        $party = $data->get_party();
    } else {
        // Data not found for the given ID, handle accordingly (e.g., display error message)
    }
}

?>

<!DOCTYPE html>
<html>
<head>
    <title>Update Data</title>
</head>
<body>
    <h2>Update Data</h2>
    <form action="process.php" method="post">
        <input type="hidden" name="action" value="update">
        <input type="hidden" name="id" value="<?php echo $id; ?>">
        <label>Name:</label><br>
        <input type="text" name="name" value="<?php echo $name; ?>"><br>
        <label>Field:</label><br>
        <input type="text" name="field" value="<?php echo $field; ?>"><br>
        <label>Electoral District:</label><br>
        <input type="text" name="electoral_district" value="<?php echo $electoral_district; ?>"><br>
        <label>Position:</label><br>
        <input type="text" name="position" value="<?php echo $position; ?>"><br>
        <label>Party:</label><br>
        <input type="text" name="party" value="<?php echo $party; ?>"><br><br>
        <button type="submit">Update</button>
    </form>
</body>
</html>
