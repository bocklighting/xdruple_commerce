<?php
/**
 * @var $packageWeight
 * @var $label
 */
?>
<?php if ($packageWeight): ?>
  <div class="commerce-product-package-weight">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $packageWeight; ?>
  </div>
<?php endif; ?>
