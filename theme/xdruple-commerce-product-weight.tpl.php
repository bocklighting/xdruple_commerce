<?php
/**
 * @var $productWeight
 * @var $label
 */
?>
<?php if ($productWeight): ?>
  <div class="commerce-product-product-weight">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $productWeight; ?>
  </div>
<?php endif; ?>
