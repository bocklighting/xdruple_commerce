<?php
/**
 * @var $weightUnit
 * @var $label
 */
?>
<?php if ($weightUnit): ?>
  <div class="commerce-product-weight-unit">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $weightUnit; ?>
  </div>
<?php endif; ?>
