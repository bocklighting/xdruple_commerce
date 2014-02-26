<?php

/**
 * @file
 * Default theme implementation to present the productCategory on a product page.
 *
 * Available variables:
 * - $productCategory: The productCategory to render.
 * - $label: If present, the string to use as the productCategory label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the productCategory represents.
 */
?>
<?php if ($productCategory): ?>
  <div class="commerce-product-product-category">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $productCategory; ?>
  </div>
<?php endif; ?>
