<div class="view-ft-commerce-xd-products">
  <div class="view-content">
    <?php if (!empty($products)): ?>
    <?php $closed = TRUE; ?>
    <?php foreach ($products as $i => $product): ?>
      <?php if ($i % 3 == 0): ?>
        <?php $closed = FALSE; ?>
        <div class="views-columns">
      <?php endif; ?>
      <div class="views-row">
        <?php print $product ?>
      </div>
      <?php if ($i % 3 == 2): ?>
        <?php $closed = TRUE; ?>
        </div>
      <?php endif; ?>
    <?php endforeach; ?>
    <?php if (!$closed): ?>
  </div>
  <?php endif; ?>
  <?php endif; ?>
</div>
</div>
