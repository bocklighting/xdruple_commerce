<?php
/**
 * @var string $classes
 * @var string $attributes
 */
?>
<?php if (!empty($links)): ?>
  <div class="<?php print $classes ?>"<?php print $attributes ?>>
    <?php if (!empty($title)): ?>
      <h4><?php print $title ?></h4>
    <?php endif; ?>
    <ul class="list-group list-group-condensed">
      <?php foreach ($links as $link): ?>
        <li class="list-group-item">
          <?php print drupal_render($link); ?>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
<?php endif; ?>
