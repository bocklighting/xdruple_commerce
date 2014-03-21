<div class="view-ft-commerce-xd-products">
  <div class="view-content">
    <?php if (!empty($columns)): ?>
      <?php foreach ($columns as $column): ?>
        <div class="views-columns">
          <?php foreach ($column as $product): ?>
            <div class="views-row">
              <?php print $product ?>
            </div>
          <?php endforeach; ?>
        </div>
      <?php endforeach; ?>
    <?php endif; ?>
  </div>
</div>
