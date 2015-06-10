<?php
/**
 * @var $physicalPackageUnit
 * @var $label
 */
?>
<?php if ($physicalPackageUnit): ?>
  <div class="commerce-physical-pack-unit">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $physicalPackageUnit; ?>
  </div>
<?php endif; ?>
