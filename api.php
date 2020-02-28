<?php 
$keyWord = $_GET["i"];
$page = $_GET["q"];
if(isset($page)&&isset($keyWord)){
	if(!is_numeric($page)){
		exit();
	}
}else{
	exit();
}
//构造请求json字符串
$queryWord = "{\"searchWords\":[{\"fieldList\":[{\"fieldCode\":\"\",\"fieldValue\":\"$keyWord\"}]}],\"filters\":[],\"limiter\":[],\"sortField\":\"relevance\",\"sortType\":\"desc\",\"pageSize\":20,\"pageCount\":$page,\"locale\":\"\",\"first\":true}";

//使用字符串请求
$url = "http://opac.cust.edu.cn:8080/opac/ajax_search_adv.php";
$headf = "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:68.0) Gecko/20100101 Firefox/68.0";
$ch = curl_init($url);
$option = array('Accept: application/json, text/javascript, */*; q=0.01','Content-Type: application/json');
curl_setopt($ch,CURLOPT_POST,true);
curl_setopt($ch,CURLOPT_RETURNTRANSFER,1);
curl_setopt($ch,CURLOPT_POSTFIELDS,$queryWord);
curl_setopt($ch,CURLOPT_USERAGENT,$headf);
curl_setopt($ch,CURLOPT_HTTPHEADER,$option);
echo curl_exec($ch);
curl_close($ch);
?>