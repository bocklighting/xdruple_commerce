<?php

/**
 * @var $extendedDescription
 * @var $label
 */
?>
<?php if ($extendedDescription): ?>
  <div class="commerce-product-ext-descrip">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $extendedDescription; ?>
  </div>
<?php endif; ?>
