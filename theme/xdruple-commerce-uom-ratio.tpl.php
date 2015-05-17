<?php
/**
 * @var $uomRatio
 * @var $label
 */
?>
<?php if ($uomRatio): ?>
  <div class="commerce-product-uom-ratio">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $uomRatio; ?>
  </div>
<?php endif; ?>
