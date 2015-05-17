<?php

/**
 * @var $extDescrip
 * @var $label
 */
?>
<?php if ($extDescrip): ?>
  <div class="commerce-product-ext-descrip">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $extDescrip; ?>
  </div>
<?php endif; ?>
