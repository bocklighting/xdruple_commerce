<?php
/**
 * @var string $classes
 * @var string $attributes
 * @var array  $context
 */
?>
<div class="<?php print $classes ?>"<?php print $attributes ?>>
  <div class="row">
    <div class="col-lg-8">
      <?php if (!empty($content)): ?>
        <?php print drupal_render($content) ?>
      <?php endif; ?>
    </div>
    <div class="col-lg-4">
      <?php if (!empty($actions)): ?>
        <?php print drupal_render($actions) ?>
      <?php endif; ?>
      <?php if (!empty($context)): ?>
        <?php print drupal_render($context) ?>
      <?php endif; ?>
    </div>
  </div>
  <div class="row">
    <?php if (!empty($extra)): ?>
      <div class="col-lg-12">
        <?php print drupal_render($extra) ?>
      </div>
    <?php endif; ?>
  </div>
</div>
