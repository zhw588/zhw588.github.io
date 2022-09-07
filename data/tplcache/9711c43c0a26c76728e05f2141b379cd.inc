<li id="navbar-category-3" class="li-cate-3"><a href="{dede:field name='typeurl'/}">{dede:field name='typename'/}</a>
          {dede:field name=typeid runphp="yes"}
    global $dsql;
    $sql = "SELECT id From `#@__arctype` WHERE reid='@me' And ishidden<>1 order by sortrank asc limit 0, 100 ";
    $row = $dsql->GetOne($sql);
    @me=is_array($row)?'
            <ul class="sub-menu">
            ':'';
      {/dede:field}
              {dede:channel type='son' noself='yes'}
              <li id="navbar-category-8" class="li-cate-8"><a href="[field:typelink/]">[field:typename/]</a></li>
              {/dede:channel}
            {dede:field name=typeid runphp="yes"}
      global $dsql; $sql = "SELECT id From `#@__arctype` WHERE reid='@me' And ishidden<>1 order by
      sortrank asc limit 0, 100 ";
      $row = $dsql->GetOne($sql);
      @me=is_array($row)?'
    </ul>
    ':'';
    {/dede:field}
          </li>