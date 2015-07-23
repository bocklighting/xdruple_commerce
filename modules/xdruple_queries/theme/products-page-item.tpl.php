<?php if (isset($img)): ?>
  <div class="views-field views-field-xt-url-image-field">
    <span class="field-content thumbnail"><?php print $img ?></span>
  </div>
<?php endif; ?>
<?php if (!empty($title)): ?>
  <div class="views-field views-field-title">
    <span class="field-content"><?php print $title ?></span>
  </div>
<?php endif; ?>
<?php if (!empty($subtitle)): ?>
  <?php print $subtitle ?>
<?php endif; ?>
<?php if (!empty($price)): ?>
  <h4 class="views-field views-field-commerce-price">
    <span class="field-content"><?php print $price ?></span>
  </h4>
<?php endif; ?>
<?php if (!empty($read_more)): ?>
  <div class="views-field views-field-nothing">
  <span class="field-content">
    <?php print $read_more ?>
  </span>
  </div>
<?php endif; ?>
<?php if (!empty($add_to_cart)): ?>
  <div class="views-field views-field-add-to-cart-form">
  <span class="field-content">
    <?php print $add_to_cart ?>
  </span>
  </div>
<?php endif; ?>
