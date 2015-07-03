<?php
/**
 * @var string $classes
 * @var string $attributes
 * @var array  $context
 */
?>
<div class="<?php print $classes ?>"<?php print $attributes ?>>
  <div class="row">
    <?php if (!empty($subtitle)): ?>
      <div class="col-lg-12">
        <?php print drupal_render($subtitle); ?>
      </div>
    <?php endif; ?>
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
  <?php if (!empty($extra)): ?>
    <div class="row">
      <div class="col-lg-12">
        <?php print drupal_render($extra) ?>
      </div>
    </div>
  <?php endif; ?>
</div>
