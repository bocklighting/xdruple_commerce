<?php

/**
 * @file
 * Default theme implementation to present the priceUnit on a product page.
 *
 * Available variables:
 * - $priceUnit: The priceUnit to render.
 * - $label: If present, the string to use as the priceUnit label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the priceUnit represents.
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
