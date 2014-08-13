<?php

/**
 * @file
 * Default theme implementation to present the physicalPackUnit on a product page.
 *
 * Available variables:
 * - $physicalPackUnit: The physicalPackUnit to render.
 * - $label: If present, the string to use as the physicalPackUnit label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the physicalPackUnit represents.
 */
?>
<?php if ($physicalPackUnit): ?>
  <div class="commerce-physical-pack-unit">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $physicalPackUnit; ?>
  </div>
<?php endif; ?>
