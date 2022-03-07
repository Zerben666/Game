<?php
//这是获取你的IP地址的PHP程序
if ($_SERVER['SERVER_ADDR']=="::1") {
	echo "localhost";
}else{
	echo $_SERVER['SERVER_ADDR'];
}
?>