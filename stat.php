<?php

// todo: kezelni a hibakat: nem erkezik input, nem lehet jsont feldolgozni, nem lehet kiirni a logot

$input = file_get_contents('php://input');
$input_decoded = json_decode($input, true);
$save_array = array_merge($input_decoded);
$dataline = json_encode($save_array);

file_put_contents(date("ymd")."stat.txt", date("H:i").$dataline.PHP_EOL, FILE_APPEND);
?>

