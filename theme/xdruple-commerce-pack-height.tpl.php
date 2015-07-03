<?php
/**
 * @var $packageHeight
 * @var $label
 */
?>
<?php if ($packageHeight): ?>
  <div class="commerce-product-pack-height">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $packageHeight; ?>
  </div>
<?php endif; ?>
