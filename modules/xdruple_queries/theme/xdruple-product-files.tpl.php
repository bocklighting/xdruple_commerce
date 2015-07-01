<?php
/**
 * @var string $classes
 * @var string $attributes
 */
?>
<?php if (!empty($files)): ?>
  <div class="<?php print $classes ?>"<?php print $attributes ?>>
    <?php if (!empty($title)): ?>
      <div class="panel-heading">
        <h4 class="panel-title"><?php print $title ?></h4>
      </div>
    <?php endif; ?>
    <ul class="list-group">
      <?php foreach ($files as $file): ?>
        <li class="list-group-item">
          <?php print drupal_render($file); ?>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
<?php endif; ?>
