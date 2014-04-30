<?php

/**
 * @file
 * Default theme implementation to present the weightUnit on a product page.
 *
 * Available variables:
 * - $weightUnit: The weightUnit to render.
 * - $label: If present, the string to use as the weightUnit label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the weightUnit represents.
 */
?>
<?php if ($weightUnit): ?>
  <div class="commerce-product-weight-unit">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $weightUnit; ?>
  </div>
<?php endif; ?>
