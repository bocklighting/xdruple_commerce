<?php
/**
 * @var $packageLength
 * @var $label
 */
?>
<?php if ($packageLength): ?>
  <div class="commerce-product-pack-length">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $packageLength; ?>
  </div>
<?php endif; ?>
