<?php

/**
 * @file
 * Default theme implementation to present the inventoryUnit on a product page.
 *
 * Available variables:
 * - $inventoryUnit: The inventoryUnit to render.
 * - $label: If present, the string to use as the inventoryUnit label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the inventoryUnit represents.
 */
?>
<?php if ($inventoryUnit): ?>
  <div class="commerce-product-inventory-unit">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $inventoryUnit; ?>
  </div>
<?php endif; ?>
