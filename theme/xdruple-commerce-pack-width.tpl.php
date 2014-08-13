<?php

/**
 * @file
 * Default theme implementation to present the packWidth on a product page.
 *
 * Available variables:
 * - $packWidth: The packWidth to render.
 * - $label: If present, the string to use as the packWidth label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the packWidth represents.
 */
?>
<?php if ($packWidth): ?>
  <div class="commerce-product-pack-width">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $packWidth; ?>
  </div>
<?php endif; ?>
