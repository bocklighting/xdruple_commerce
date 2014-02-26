<?php

/**
 * @file
 * Default theme implementation to present the subTitle on a product page.
 *
 * Available variables:
 * - $subTitle: The subTitle to render.
 * - $label: If present, the string to use as the subTitle label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the subTitle represents.
 */
?>
<?php if ($subTitle): ?>
  <div class="commerce-product-sub-title">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $subTitle; ?>
  </div>
<?php endif; ?>
