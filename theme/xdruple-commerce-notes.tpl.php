<?php

/**
 * @file
 * Default theme implementation to present the notes on a product page.
 *
 * Available variables:
 * - $notes: The notes to render.
 * - $label: If present, the string to use as the notes label.
 *
 * Helper variables:
 * - $product: The fully loaded product object the notes represents.
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
