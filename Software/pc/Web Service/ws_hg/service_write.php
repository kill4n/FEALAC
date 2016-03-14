<?php  
$json = file_get_contents('php://input');
$obj = json_decode($json);
//Save
$con = mysql_connect('localhost','root','') 
       or die('Cannot connect to the DB');
mysql_select_db('hg_conc',$con);

mysql_query("INSERT INTO concentracion (fecha, concentration)
VALUES ('".$obj->{'UserName'}."', '".$obj->{'FullName'}."')");

mysql_close($con);
/*
  $posts = array(1);
    header('Content-type: application/json');
    echo json_encode(array('posts'=>$posts)); */
?>