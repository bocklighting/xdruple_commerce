<?php

/**
 * @file
 * Default theme implementation to present the dimensionUnit on a product page.
 *
 * Available variables:
 * - $dimensionUnit: The dimensionUnit to render.
 * - $label: If present, the string to use as the dimensionUnit label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the dimensionUnit represents.
 */
?>
<?php if ($dimensionUnit): ?>
  <div class="commerce-product-dimension-unit">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $dimensionUnit; ?>
  </div>
<?php endif; ?>
