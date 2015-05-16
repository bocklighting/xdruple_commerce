<?php
/**
 * @var $productCategory
 * @var $label
 */
?>
<?php if ($productCategory): ?>
  <div class="commerce-product-product-category">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $productCategory; ?>
  </div>
<?php endif; ?>
