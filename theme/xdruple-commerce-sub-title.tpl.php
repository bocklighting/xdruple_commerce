<?php
/**
 * @var $subTitle
 * @var $label
 */
?>
<?php if ($subTitle): ?>
  <div class="commerce-product-sub-title">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $subTitle; ?>
  </div>
<?php endif; ?>
