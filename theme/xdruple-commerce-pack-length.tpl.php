<?php
/**
 * @var $packLength
 * @var $label
 */
?>
<?php if ($packLength): ?>
  <div class="commerce-product-pack-length">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $packLength; ?>
  </div>
<?php endif; ?>
