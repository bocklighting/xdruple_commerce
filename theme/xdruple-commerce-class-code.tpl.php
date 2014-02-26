<?php

/**
 * @file
 * Default theme implementation to present the classCode on a product page.
 *
 * Available variables:
 * - $classCode: The classCode to render.
 * - $label: If present, the string to use as the classCode label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the classCode represents.
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
