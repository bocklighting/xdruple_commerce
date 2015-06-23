<?php
/**
 * @var string $classes
 * @var string $attributes
 * @var array  $context
 */
?>
<div class="<?php print $classes ?>"<?php print $attributes ?>>
  <div class="row">
    <div class="col-lg-9">
      <?php if (!empty($content)): ?>
        <?php print drupal_render($content) ?>
      <?php endif; ?>
    </div>
    <div class="col-lg-3">
      <?php if (!empty($actions)): ?>
        <?php print drupal_render($actions) ?>
      <?php endif; ?>
    </div>
    <?php if (!empty($details)): ?>
      <div class="col-lg-12">
        <?php print drupal_render($details) ?>
      </div>
    <?php endif; ?>
  </div>
</div>
