<?php

/**
 * @file
 * Default theme implementation to present the packLength on a product page.
 *
 * Available variables:
 * - $packLength: The packLength to render.
 * - $label: If present, the string to use as the packLength label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the packLength represents.
 */
?>
<?php if ($packLength): ?>
  <div class="commerce-product-pack-length">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $packLength; ?>
  </div>
<?php endif; ?>
