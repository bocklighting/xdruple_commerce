<?php
/**
 * @var $packageWidth
 * @var $label
 */
?>
<?php if ($packageWidth): ?>
  <div class="commerce-product-pack-width">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $packageWidth; ?>
  </div>
<?php endif; ?>
