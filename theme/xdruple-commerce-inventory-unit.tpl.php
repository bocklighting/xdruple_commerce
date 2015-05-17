<?php
/**
 * @var $inventoryUnit
 * @var $label
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
