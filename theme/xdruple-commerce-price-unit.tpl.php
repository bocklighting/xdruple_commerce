<?php
/**
 * @var $priceUnit
 * @var $label
 */
?>
<?php if ($priceUnit): ?>
  <div class="commerce-product-price-unit">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $priceUnit; ?>
  </div>
<?php endif; ?>
