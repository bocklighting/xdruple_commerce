<?php

/**
 * @var $dimensionUnit
 * @var $label
 */
?>
<?php if ($dimensionUnit): ?>
  <div class="commerce-product-dimension-unit">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $dimensionUnit; ?>
  </div>
<?php endif; ?>
