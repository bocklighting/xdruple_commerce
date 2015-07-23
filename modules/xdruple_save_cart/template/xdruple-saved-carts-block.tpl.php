<?php
/**
 * @var string $classes
 * @var string $attributes
 * @var string $title_attributes
 * @var string $content_attributes
 */
?>
<?php if (!empty($content)): ?>
  <div class="<?php print $classes ?>"<?php print $attributes ?>>
    <?php if (!empty($title)): ?>
      <div<?php print $title_attributes ?>>
        <h3 class="panel-title"><?php print $title; ?></h3>
      </div>
    <?php endif; ?>
    <div<?php print $content_attributes ?>>
      <?php print $content ?>
    </div>
  </div>
<?php endif; ?>
