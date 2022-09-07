<?php
$z[0]=Array("field","",54,82);
$z[0][4]=array();
$z[0][4]['name']="typeurl";
$z[1]=Array("field","",84,113);
$z[1][4]=array();
$z[1][4]['name']="typename";
$z[2]=Array("field","\r\n    global \$dsql;\r\n    \$sql = \"SELECT id From `#@__arctype` WHERE reid='@me' And ishidden<>1 order by sortrank asc limit 0, 100 \";\r\n    \$row = \$dsql->GetOne(\$sql);\r\n    @me=is_array(\$row)?'\r\n            <ul class=\"sub-menu\">\r\n            ':'';\r\n      ",129,432);
$z[2][4]=array();
$z[2][4]['name']="typeid";
$z[2][4]['runphp']="yes";
$z[3]=Array("channel","\r\n              <li id=\"navbar-category-8\" class=\"li-cate-8\"><a href=\"[field:typelink/]\">[field:typename/]</a></li>\r\n              ",448,632);
$z[3][4]=array();
$z[3][4]['type']="son";
$z[3][4]['noself']="yes";
$z[4]=Array("field","\r\n      global \$dsql; \$sql = \"SELECT id From `#@__arctype` WHERE reid='@me' And ishidden<>1 order by\r\n      sortrank asc limit 0, 100 \";\r\n      \$row = \$dsql->GetOne(\$sql);\r\n      @me=is_array(\$row)?'\r\n    </ul>\r\n    ':'';\r\n    ",646,923);
$z[4][4]=array();
$z[4][4]['name']="typeid";
$z[4][4]['runphp']="yes";

?>