<?php
/**
 * @var $notes
 * @var $label
 */
?>
<?php if ($notes): ?>
  <div class="commerce-product-notes">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $notes; ?>
  </div>
<?php endif; ?>
