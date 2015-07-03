<?php
/**
 * @var $productLength
 * @var $label
 */
?>
<?php if ($productLength): ?>
  <div class="commerce-product-length">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $productLength; ?>
  </div>
<?php endif; ?>
