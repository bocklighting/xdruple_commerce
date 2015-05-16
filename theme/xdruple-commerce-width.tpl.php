<?php
/**
 * @var $prodWidth
 * @var $label
 */
?>
<?php if ($prodWidth): ?>
  <div class="commerce-product-width">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $prodWidth; ?>
  </div>
<?php endif; ?>
