<?php

/**
 * @file
 * Default theme implementation to present the extDescrip on a product page.
 *
 * Available variables:
 * - $extDescrip: The extDescrip to render.
 * - $label: If present, the string to use as the extDescrip label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the extDescrip represents.
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
