<?php
/**
 * @var $packHeight
 * @var $label
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
