<?php

/**
 * @file
 * Default theme implementation to present the productWeight on a product page.
 *
 * Available variables:
 * - $productWeight: The productWeight to render.
 * - $label: If present, the string to use as the productWeight label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the productWeight represents.
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
