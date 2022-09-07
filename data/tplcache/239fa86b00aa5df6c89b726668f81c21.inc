<div class="part" id="cate2" data-title="{dede:field name='typename'/}">
        <p class="tt sticky"> <strong>{dede:field name='typename'/}</strong> <a title="更多{dede:field name='typename'/}" href="{dede:field name='typeurl'/}">更多+</a> </p>
        <div class="items">
          <div class="row">
            {dede:arclist row='8' titlelen='60'}
            <div class="col-xs-6 col-sm-4 col-md-3">
              <div class="item"> <a class="link" target="_blank" href="[field:link/]" rel="nofollow"><i class="autoleft fa fa-angle-right" title="直达网站"></i></a> <a class="a" href="[field:arcurl/]" title="[field:title/]" target="_blank"> <img src="[field:litpic/]" alt="[field:title/]" title="[field:title/]">
                <h3>[field:title/]</h3>
                <p>[field:description function='cn_substr(@me,100)'/]...</p>
                </a> </div>
            </div>
            {/dede:arclist}
          </div>
        </div>
      </div>