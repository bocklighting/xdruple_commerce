<?php

/**
 * @file
 * Default theme implementation to present the physicalProdUnit on a product page.
 *
 * Available variables:
 * - $physicalProdUnit: The physicalProdUnit to render.
 * - $label: If present, the string to use as the physicalProdUnit label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the physicalProdUnit represents.
 */
?>
<?php if ($physicalProdUnit): ?>
  <div class="commerce-product-physical-prod-unit">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $physicalProdUnit; ?>
  </div>
<?php endif; ?>
