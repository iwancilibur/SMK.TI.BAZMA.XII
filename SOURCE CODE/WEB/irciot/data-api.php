<?php 
	require "koneksidb.php";

	$ambilnamadevice	= $_GET["namadevice"];
	$ambilsuhu		 	= $_GET["suhu"];
	$ambilkelembaban  	= $_GET["kelembaban"];
	$tgl				= date("Y-m-d h:i:s");

	//UPDATE DATA REALTIME PADA TABEL tb_monitoring
	$sql      = "UPDATE tb_dashboard SET 
				waktu	= '$tgl',namadevice	= '$ambilnamadevice',suhu	= '$ambilsuhu', kelembaban	= '$ambilkelembaban'";
	$koneksi->query($sql);
			
	//INSERT DATA REALTIME PADA TABEL tb_save  	 
	$sqlsave = "INSERT INTO tb_simpan (waktu, namadevice,suhu,kelembaban)
	VALUES ('" . $tgl . "', '" . $ambilnamadevice . "', '" . $ambilsuhu . "', '" . $ambilkelembaban . "')";
	$koneksi->query($sqlsave);	 

	//MENJADIKAN JSON DATA
	$response = query("SELECT * FROM tb_dashboard")[0];
	$result = json_encode($response);
	echo $result;



 ?>