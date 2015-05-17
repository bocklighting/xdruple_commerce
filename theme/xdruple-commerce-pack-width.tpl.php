<?php
/**
 * @var $packWidth
 * @var $label
 */
?>
<?php if ($packWidth): ?>
  <div class="commerce-product-pack-width">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $packWidth; ?>
  </div>
<?php endif; ?>
