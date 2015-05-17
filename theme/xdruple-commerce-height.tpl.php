<?php
/**
 * @var $prodHeight
 * @var $label
 */
?>
<?php if ($prodHeight): ?>
  <div class="commerce-product-height">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $prodHeight; ?>
  </div>
<?php endif; ?>
