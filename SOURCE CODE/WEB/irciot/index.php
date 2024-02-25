<?php
    require "koneksidb.php";
    $data = query("SELECT * FROM tb_dashboard")[0];
?>

<!doctype html>
<html lang="en">

<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css"
        integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">

    <!-- Font Awesome -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.5.0/css/font-awesome.min.css" />

    <title>Dashboard Monitoring</title>

</head>

<body class="bg-dark">

    <center>

        <div>
            <img class="img-fluid responsive-sm mt-3" src="img/interactiverobotics.png" alt="Responsive image"
                style="width:200px; height:200px;">
        </div>


        <h5 class="text-white">REALTIME DASHBOARD MONITORING</h5>
        <div class="card-body bg-dark text-light">
            <h3><?= $data["waktu"]; ?></h3>
            <form action="tampildata.php" method="POST">
                <button type="submit">BUKA LOG DATA</button>
            </form>
            <br>
            <form action="load-control.php" method="POST">
                <!-- Button to toggle relay1 -->
                <button type="submit" name="relay1"
                    class="btn <?= $data["relay1"] == 1 ? 'btn-success' : 'btn-danger' ?>">
                    <?= $data["relay1"] == 1 ? 'Relay 1 ON' : 'Relay 1 OFF' ?>
                </button>
                <!-- Button to toggle relay2 -->
                <button type="submit" name="relay2"
                    class="btn <?= $data["relay2"] == 1 ? 'btn-success' : 'btn-danger' ?>">
                    <?= $data["relay2"] == 1 ? 'Relay 2 ON' : 'Relay 2 OFF' ?>
                </button>
            </form>
            
        </div>
        <!-- Mengambil Data realtime pada File load-input.php -->
        <div class="load-input"></div>

        <footer class="py-3">
            <div class="container">
                <p class="m-0 text-center text-light">Copyright &copy;2020 iwan cilibur | Interactive Robotics</p>
            </div>
        </footer>

    </center>

    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js"
        integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo"
        crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js"
        integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1"
        crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"
        integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM"
        crossorigin="anonymous"></script>

    <!-- My Javascript/jQuery -->
    <script src="js/jquery-3.4.1.min.js"></script>
    <script src="js/script.js"></script>

    <!-- Sweet Alert -->
    <script src="js/sweetalert2.all.min.js"></script>

</body>

</html>
