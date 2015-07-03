<?php
/**
 * @var $physicalProductUnit
 * @var $label
 */
?>
<?php if ($physicalProductUnit): ?>
  <div class="commerce-product-physical-prod-unit">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $physicalProductUnit; ?>
  </div>
<?php endif; ?>
