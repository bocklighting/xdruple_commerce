<?php if (isset($img)): ?>
  <div class="views-field views-field-erp-url-image-field">
    <span class="field-content"><?php print $img ?></span>
  </div>
<?php endif; ?>
<?php if (!empty($title)): ?>
  <div class="views-field views-field-title">
    <span class="field-content"><?php print $title ?></span>
  </div>
<?php endif; ?>
<?php if (!empty($subTitle)): ?>
  <div class="views-field views-field-subTitle">
    <span class="field-content"><?php print $subtitle ?></span>
  </div>
<?php endif; ?>
<?php if (!empty($price)): ?>
  <div class="views-field views-field-commerce-price">
    <span class="field-content"><?php print $price ?></span>
  </div>
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
