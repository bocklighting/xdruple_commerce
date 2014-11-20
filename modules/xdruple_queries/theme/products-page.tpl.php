<div class="subcategories-list">
  <?php if (!empty($subcategories)): ?>
    <h3><?php print t("Subcategories") ?></h3>
    <?php print $subcategories; ?>
  <?php endif; ?>
</div>
<div class="view-ft-commerce-xd-products">
  <div class="view-content">
    <?php if (!empty($columns)): ?>
      <h3><?php print t("Products") ?></h3>
      <?php foreach ($columns as $column): ?>
        <div class="views-columns row">
          <?php foreach ($column as $product): ?>
            <div class="views-row col-lg-4">
              <?php print $product ?>
            </div>
          <?php endforeach; ?>
        </div>
      <?php endforeach; ?>
    <?php endif; ?>
  </div>
</div>
