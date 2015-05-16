<?php
/**
 * @var $prodLength
 * @var $label
 */
?>
<?php if ($prodLength): ?>
  <div class="commerce-product-length">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $prodLength; ?>
  </div>
<?php endif; ?>
