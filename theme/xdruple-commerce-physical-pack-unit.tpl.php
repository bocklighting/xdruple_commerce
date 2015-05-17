<?php
/**
 * @var $physicalPackUnit
 * @var $label
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
