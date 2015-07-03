<?php
/**
 * @var string $classes
 * @var string $attributes
 * @var array  $images
 */
?>
<?php if (!empty($images)): ?>
  <div class="<?php print $classes ?>"<?php print $attributes ?>>
    <?php foreach ($images as $image): ?>
      <?php print drupal_render($image); ?>
    <?php endforeach; ?>
  </div>
<?php endif; ?>
