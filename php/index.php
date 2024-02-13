<?php
include_once ("AnggotaDPR.php");

session_start();

$_SESSION['currentUpdating'] = null;

if (isset($_GET['status'])  ) {

    if($_GET['status'] == 1) {
        
        // Display JavaScript alert message
        echo "<script>alert('Data successfully created');</script>";
    } else if($_GET["status"] == 2) {
        echo "<script>alert('Data successfully updated');</script>";
    }
}


# ceritanya ini database abal abalnya, disimpen di session

if (!isset($_SESSION['listDPR'])) {
    $kaladin = new AnggotaDPR(
        "WR1",
        "Kaladin Stormblessed",
        "Department of Defense",
        "Hearthstone",
        "Highmarshall",
        "Windrunners"
    );
    
    
    $shallan = new AnggotaDPR(
        "LW1",
        "Shallan Davar",
        "Department of Information",
        "Veden",
        "Member",
        "Lightweavers"
    );
    
    $dalinar = new AnggotaDPR(
        "BS1",
        "Dalinar Kholin",
        "Department of Defense",
        "Kholinar",
        "Highking",
        "Bondsmiths"
    );
    // Set a session variable
    $_SESSION['listDPR'] = array($kaladin, $shallan, $dalinar);;
}

?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CRUD Application</title>
    <style>
        table {
            width: 100%;
            border-collapse: collapse;
        }

        table, th, td {
            border: 1px solid black;
            padding: 8px;
        }

        th {
            background-color: #f2f2f2;
        }
    </style>
</head>
<body>

<h2>Data Table</h2>

<table>
    <thead>
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Field</th>
            <th>Electoral District</th>
            <th>Position</th>
            <th>Party</th>
            <th>Actions</th>
        </tr>
    </thead>
    <tbody>
        <!-- PHP code to fetch and display data from the database -->
        <?php
        // Replace this part with actual PHP code to fetch data from the database
        // Example:
        
        $listDPR = $_SESSION['listDPR'];

        foreach ($listDPR as $row) {
        ?>
            <tr>

            <td><?=$row->get_id();?></td>
            <td><?=$row->get_name();?></td>
            <td><?=$row->get_field();?></td>
            <td><?=$row->get_electoral_district();?></td>
            <td><?=$row->get_position();?></td>
            <td><?=$row->get_party();?></td>
            <td>
                <!-- <button>Edit</button><button>Delete</button> -->
                 <!-- Edit button -->
                 <form action="update.php" method="post" style="display: inline;">
                    <input type="hidden" name="id" value="<?=$row->get_id(); ?>">
                    <button type="submit">Edit</button>
                </form>
                
                <!-- Delete button -->
                <form action="process.php" method="post" style="display: inline;">
                    <input type="hidden" name="id" value="<?=$row->get_id(); ?>">
                    <input type="hidden" name="action" value="delete">
                    <button type="submit">Delete</button>
                </form>
            </td>

            </tr>
        <?php
        }
        ?>
    </tbody>
</table>

<h2>Add New Data</h2>

<form method="POST" action="process.php">
    <label for="id">ID:</label><br>
    <input type="text" id="id" name="id"><br>
    <label for="name">Name:</label><br>
    <input type="text" id="name" name="name"><br>
    <label for="field">Field:</label><br>
    <input type="text" id="field" name="field"><br>
    <label for="electoral_district">Electoral District:</label><br>
    <input type="text" id="electoral_district" name="electoral_district"><br>
    <label for="position">Position:</label><br>
    <input type="text" id="position" name="position"><br>
    <label for="party">Party:</label><br>
    <input type="text" id="party" name="party"><br><br>
    <input type="hidden" name="action" value="create">
    <input type="submit" value="Submit">
</form>

</body>
</html>
