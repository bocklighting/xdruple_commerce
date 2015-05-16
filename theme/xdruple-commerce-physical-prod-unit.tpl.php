<?php
/**
 * @var $physicalProdUnit
 * @var $label
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
