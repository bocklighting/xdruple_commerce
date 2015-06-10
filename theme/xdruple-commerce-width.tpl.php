<?php
/**
 * @var $productWidth
 * @var $label
 */
?>
<?php if ($productWidth): ?>
  <div class="commerce-product-width">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $productWidth; ?>
  </div>
<?php endif; ?>
