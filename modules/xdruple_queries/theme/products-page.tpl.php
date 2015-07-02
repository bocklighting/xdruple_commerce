<?php if (!empty($subcategories)): ?>
  <div class="subcategories-list">
    <h3><?php print t("Subcategories") ?></h3>
    <?php print $subcategories; ?>
  </div>
<?php endif; ?>
<?php if (!empty($columns)): ?>
  <div class="view-ft-commerce-xd-products">
    <div class="view-content">
      <?php if (!empty($subcategories)): ?>
        <h3><?php print t("Products") ?></h3>
      <?php endif; ?>
      <?php foreach ($columns as $column): ?>
        <div class="views-columns row">
          <?php foreach ($column as $product): ?>
            <div class="views-row col-lg-4">
              <?php print drupal_render($product); ?>
            </div>
          <?php endforeach; ?>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
<?php endif; ?>
