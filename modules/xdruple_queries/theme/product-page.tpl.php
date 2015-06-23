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
      <?php if (!empty($entity)): ?>
        <?php print drupal_render($entity) ?>
      <?php endif; ?>
    </div>
    <div class="col-lg-4">
      <?php if (!empty($context)): ?>
        <?php print drupal_render($context) ?>
      <?php endif; ?>
    </div>
    <?php if (!empty($characteristics)): ?>
      <div class="col-lg-12">
        <?php if (!empty($characteristics_title)): ?>
          <h4><?php print $characteristics_title ?></h4>
        <?php endif; ?>
        <?php print drupal_render($characteristics) ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($bottom)): ?>
      <div class="col-lg-12">
        <?php print drupal_render($bottom); ?>
      </div>
    <?php endif; ?>
  </div>
</div>
