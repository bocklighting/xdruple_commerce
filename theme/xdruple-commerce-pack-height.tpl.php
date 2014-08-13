<?php

/**
 * @file
 * Default theme implementation to present the packHeight on a product page.
 *
 * Available variables:
 * - $packHeight: The packHeight to render.
 * - $label: If present, the string to use as the packHeight label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the packHeight represents.
 */
?>
<?php if ($packHeight): ?>
  <div class="commerce-product-pack-height">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $packHeight; ?>
  </div>
<?php endif; ?>
