<?php

/**
 * @file
 * Default theme implementation to present the uomRatio on a product page.
 *
 * Available variables:
 * - $weightUnit: The uomRatio to render.
 * - $label: If present, the string to use as the uomRatio label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the uomRatio represents.
 */
?>
<?php if ($uomRatio): ?>
  <div class="commerce-product-uom-ratio">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $uomRatio; ?>
  </div>
<?php endif; ?>
