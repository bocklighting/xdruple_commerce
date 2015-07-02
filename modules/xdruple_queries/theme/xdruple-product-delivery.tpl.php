<?php
/**
 * @var string $classes
 * @var string $attributes
 * @var array  $info
 */
?>
<?php if (!empty($info)): ?>
  <div class="<?php print $classes ?>"<?php print $attributes ?>>
    <?php if (!empty($title)): ?>
      <div class="panel-heading">
        <h4 class="panel-title"><?php print $title ?></h4>
      </div>
    <?php endif; ?>
    <?php print drupal_render($info); ?>
  </div>
<?php endif; ?>
