<?php

/**
 * @file
 * Default theme implementation to present the prodHeight on a product page.
 *
 * Available variables:
 * - $prodHeight: The prodHeight to render.
 * - $label: If present, the string to use as the prodHeight label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the prodHeight represents.
 */
?>
<?php if ($prodHeight): ?>
  <div class="commerce-product-height">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $prodHeight; ?>
  </div>
<?php endif; ?>
