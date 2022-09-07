<?php
$z[0]=Array("global","",120,146);
$z[0][4]=array();
$z[0][4]['name']="cfg_webname";
$z[1]=Array("global","",205,231);
$z[1][4]=array();
$z[1][4]['name']="cfg_webname";
$z[2]=Array("global","",240,266);
$z[2][4]=array();
$z[2][4]['name']="cfg_webname";
$z[3]=Array("global","",325,351);
$z[3][4]=array();
$z[3][4]['name']="cfg_webname";
$z[4]=Array("global","",360,386);
$z[4][4]=array();
$z[4][4]['name']="cfg_webname";
$z[5]=Array("global","",649,674);
$z[5][4]=array();
$z[5][4]['name']="cfg_cmsurl";
$z[6]=Array("channelartlist","\r\n          <li id=\"navbar-category-3\" class=\"li-cate-3\"><a href=\"{dede:field name='typeurl'/}\">{dede:field name='typename'/}</a>\r\n          {dede:field name=typeid runphp=\"yes\"}\r\n    global \$dsql;\r\n    \$sql = \"SELECT id From `#@__arctype` WHERE reid='@me' And ishidden<>1 order by sortrank asc limit 0, 100 \";\r\n    \$row = \$dsql->GetOne(\$sql);\r\n    @me=is_array(\$row)?'\r\n            <ul class=\"sub-menu\">\r\n            ':'';\r\n      {/dede:field}\r\n              {dede:channel type='son' noself='yes'}\r\n              <li id=\"navbar-category-8\" class=\"li-cate-8\"><a href=\"[field:typelink/]\">[field:typename/]</a></li>\r\n              {/dede:channel}\r\n            {dede:field name=typeid runphp=\"yes\"}\r\n      global \$dsql; \$sql = \"SELECT id From `#@__arctype` WHERE reid='@me' And ishidden<>1 order by\r\n      sortrank asc limit 0, 100 \";\r\n      \$row = \$dsql->GetOne(\$sql);\r\n      @me=is_array(\$row)?'\r\n    </ul>\r\n    ':'';\r\n    {/dede:field}\r\n          </li>\r\n          ",1216,2242);
$z[6][4]=array();
$z[6][4]['row']="6";
$z[6][4]['typeid']="top";
$z[7]=Array("type","<a href=\"[field:typelink /]\" target=\"_blank\" class=\"a transition\"><i class=\"fa fa-heart\"></i>[field:typename /]</a>",2303,2453);
$z[7][4]=array();
$z[7][4]['typeid']="22";

?>