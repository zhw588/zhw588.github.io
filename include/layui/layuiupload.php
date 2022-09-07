<?php
/**
 * layuiupload上传
 *
 * @version        $Id: layuiupload.php 1 16:22 2019年12月14日 kira $
 * @package        DedeCMS.kira修改
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */
require_once(dirname(__FILE__)."/../common.inc.php");
require_once(dirname(__FILE__)."/../userlogin.class.php");
require_once(dirname(__FILE__)."/../memberlogin.class.php");
require_once(dirname(__FILE__)."/../image.func.php");
//检验用户登录状态
$userid = 0;
$rank = -1;
$isAdmin = FALSE;
$cuserLogin = new userLogin();
if($cuserLogin->getUserID() <=0 )
{
	$keeptime = isset($keeptime) && is_numeric($keeptime) ? $keeptime : -1;
	$cfg_ml = new MemberLogin($keeptime);

	if($cfg_ml->IsLogin())
	{
	   $userid = $cfg_ml->M_ID;
	   $rank = $cfg_ml->fields['matt'];
	}
}
else
{
	$userid = $cuserLogin->getUserID();
	$rank = $cuserLogin->getUserRank();
}
if($rank == 10) $isAdmin = TRUE;

//删除图片
if($dopost == 'del')
{
	$id = (isset($id) && is_numeric($id)) ? $id : 0;
	if($id==0 || $userid==0) die();
	$row = $dsql->GetOne("SELECT url FROM `#@__uploads` WHERE aid=$id AND mid=$userid");
	if(is_array($row))
	{
		$truefile = $cfg_basedir.$row['url'];
		if(@file_exists($truefile)) @unlink($truefile);
		$dsql->ExecuteNoneQuery("DELETE FROM #@__uploads WHERE aid='".$id."'");
	}
	exit();
}

$file_name = $_FILES['file']['name'];
$file_type = $_FILES['file']['type'];
$file_tmp = $_FILES["file"]["tmp_name"];
$file_error = $_FILES["file"]["error"];
$file_size = $_FILES["file"]["size"];

if(empty($file_tmp) || !is_uploaded_file($file_tmp))
{
	exit(json_encode(array('code'=>0, 'msg'=>'未上传图片')));
}
else
{
	if($file_error > 0)
	{
		exit(json_encode(array('code'=>0, 'msg'=>$file_error)));
	}
	if(!$isAdmin && $file_size > $cfg_mb_upload_size * 1024)
	{
		exit(json_encode(array('code'=>0, 'msg'=>'你上传的文件超出系统大小限制')));
	}
	$file_name = trim(preg_replace("#[ \r\n\t\*\%\\\/\?><\|\":]{1,}#", '', $file_name));
	if(!preg_match("#\.(".$cfg_imgtype.")#i", $file_name))
	{
		exit(json_encode(array('code'=>0, 'msg'=>'你所上传的图片类型不在许可列表')));
	}
	$sparr = Array("image/pjpeg", "image/jpeg", "image/gif", "image/png", "image/xpng", "image/wbmp");
	$file_type = strtolower(trim($file_type));
	if(!in_array($file_type, $sparr))
	{
		exit(json_encode(array('code'=>0, 'msg'=>'上传的图片格式错误，请使用JPEG、GIF、PNG、WBMP格式的其中一种')));
	}
	$nowtme = time();
	$fs = explode('.', $file_name);
	$sname = $fs[count($fs)-1];
	$alltypes = explode('|', $cfg_imgtype);
	if(!in_array(strtolower($sname), $alltypes))
	{
		exit(json_encode(array('code'=>0, 'msg'=>'你所上传的文件类型不被允许')));
	}
	if(preg_match("/(php|pl|cgi|asp|aspx|jsp|php5|php4|php3|shtm|shtml|js)$/", $sname))
	{
		exit(json_encode(array('code'=>0, 'msg'=>'你上传的文件为系统禁止的类型')));
	}
	if(!$isAdmin)
	{
		$filedir = $cfg_user_dir.'/'.$userid;
	}
	else
	{
		$filedir = $cfg_image_dir.'/'.MyDate($cfg_addon_savetype, $nowtme);
	}
	if(!is_dir($cfg_basedir.$filedir))
	{
		MkdirAll($cfg_basedir.$filedir, $cfg_dir_purview);
		CloseFtp();
	}
	$filename = $userid.'-'.dd2char($nowtme.'-'.mt_rand(1000,9999));
	$fileurl = $filedir.'/'.$filename.'.'.$sname;
	$fullfileurl = $cfg_basedir.$fileurl;
	move_uploaded_file($file_tmp, $fullfileurl) or die(json_encode(array('code'=>0, 'msg'=>'上传文件失败')));
	@unlink($file_tmp);
    if(in_array($file_type, $cfg_photo_typenames))
    {
        WaterImg($fullfileurl, 'up');
    }
	$arcid = (isset($arcid) && is_numeric($arcid)) ? $arcid : 0;
	$title = $filename.'.'.$sname;
	$info = '';
	$sizes[0] = 0; $sizes[1] = 0;
	$sizes = getimagesize($fullfileurl, $info);
	$imgwidthValue = $sizes[0];
	$imgheightValue = $sizes[1];
	$imgsize = filesize($fullfileurl);
	$inquery = "INSERT INTO `#@__uploads`(arcid,title,url,mediatype,width,height,playtime,filesize,uptime,mid) VALUES ('$arcid','$title','$fileurl','1','$imgwidthValue','$imgheightValue','0','$sizes','$nowtme','$userid'); ";
	$dsql->ExecuteNoneQuery($inquery);
    $id = $dsql->GetLastID();
    AddMyAddon($id, $fileurl);
	exit(json_encode(array('code'=>1, 'msg'=>'上传成功', 'img'=>$fileurl, 'id'=>$id)));
}