<?php

/**
 * @file
 * Default theme implementation to present the packageWeight on a product page.
 *
 * Available variables:
 * - $packageWeight: The packageWeight to render.
 * - $label: If present, the string to use as the packageWeight label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the packageWeight represents.
 */
?>
<?php if ($packageWeight): ?>
  <div class="commerce-product-package-weight">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $packageWeight; ?>
  </div>
<?php endif; ?>
