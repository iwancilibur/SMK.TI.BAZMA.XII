<?php
    require "koneksidb.php";
    $data = query("SELECT * FROM tb_dashboard")[0];

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Check if the form is submitted
        if (isset($_POST["relay1"])) {
            // Toggle relay1 in the database
            $status = $data["relay1"] == 1 ? 0 : 1;
            mysqli_query($koneksi, "UPDATE tb_dashboard SET relay1 = $status");
            // Setelah selesai aksi, arahkan ke file tertentu
            header("Location: index.php");
            exit; // Pastikan untuk keluar dari script setelah menggunakan header
        } elseif (isset($_POST["relay2"])) {
            // Toggle relay2 in the database
            $status = $data["relay2"] == 1 ? 0 : 1;
            mysqli_query($koneksi, "UPDATE tb_dashboard SET relay2 = $status");
            // Setelah selesai aksi, arahkan ke file tertentu
            header("Location: index.php");
            exit; // Pastikan untuk keluar dari script setelah menggunakan header
        }
    }
?>