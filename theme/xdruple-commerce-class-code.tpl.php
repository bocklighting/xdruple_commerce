<?php

/**
 * @var $classCode
 * @var $label
 */
?>
<?php if ($classCode): ?>
  <div class="commerce-product-class-code">
    <?php if ($label): ?>
      <div class="commerce-product-title-label">
        <?php print $label; ?>
      </div>
    <?php endif; ?>
    <?php print $classCode; ?>
  </div>
<?php endif; ?>
