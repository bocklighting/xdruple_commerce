<?php
/**
 * @var $productHeight
 * @var $label
 */
?>
<?php if ($productHeight): ?>
  <div class="commerce-product-height">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $productHeight; ?>
  </div>
<?php endif; ?>
