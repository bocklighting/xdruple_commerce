<?php

/**
 * @file
 * Default theme implementation to present the prodWidth on a product page.
 *
 * Available variables:
 * - $prodWidth: The prodWidth to render.
 * - $label: If present, the string to use as the prodWidth label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the prodWidth represents.
 */
?>
<?php if ($prodWidth): ?>
  <div class="commerce-product-width">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $prodWidth; ?>
  </div>
<?php endif; ?>
