<?php
/**
 * @var string  $image
 * @var integer $product_id
 * @var string  $attributes
 * @var array   $thumbnail_attributes_array
 * @var string  $title_attributes
 */
?>
<div<?php print $attributes ?>>
  <div<?php print drupal_attributes($thumbnail_attributes_array) ?>>
    <?php if (!empty($image)): ?>
      <?php print $image ?>
    <?php endif; ?>
  </div>
  <div<?php print $title_attributes ?>>
    <?php if (!empty($title)): ?>
      <?php print $title ?>
    <?php endif ?>
  </div>
</div>
