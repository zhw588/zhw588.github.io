<div class="part" id="cate19" data-title="{dede:field name='typename'/}">
        <p class="tt sticky"> <strong>{dede:field name='typename'/}</strong> <a title="更多{dede:field name='typename'/}" href="{dede:field name='typeurl'/}">更多+</a> </p>
        <div class="items">
          <div class="row">
            {dede:arclist row='8' titlelen='60'}
            <div class="col-xs-6 col-sm-4 col-md-3">
              <div class="item art-item transition"> <a class="art-a" href="[field:arcurl/]" title="[field:title/]" target="_blank"> <img class="img-cover" src="[field:litpic/]" alt="[field:title/]" title="[field:title/]"> </a>
                <h3 class="art-title"><a class="" href="[field:arcurl/]" title="[field:title/]" target="_blank">[field:title/]</a></h3>
                <p>[field:description function='cn_substr(@me,100)'/]...</p>
              </div>
            </div>
            {/dede:arclist}
          </div>
        </div>
      </div>