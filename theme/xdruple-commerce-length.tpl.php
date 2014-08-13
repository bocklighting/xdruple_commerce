<?php

/**
 * @file
 * Default theme implementation to present the prodLength on a product page.
 *
 * Available variables:
 * - $prodLength: The prodLength to render.
 * - $label: If present, the string to use as the prodLength label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the prodLength represents.
 */
?>
<?php if ($prodLength): ?>
  <div class="commerce-product-length">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $prodLength; ?>
  </div>
<?php endif; ?>
