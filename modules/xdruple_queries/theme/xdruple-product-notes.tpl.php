<?php
/**
 * @var string $classes
 * @var string $attributes
 */
?>
<?php if (!empty($notes)): ?>
  <div class="<?php print $classes ?>"<?php print $attributes ?>>
    <?php if (!empty($title)): ?>
        <h4><?php print $title ?></h4>
    <?php endif; ?>
    <div class="well well-sm">
      <?php print $notes ?>
    </div>
  </div>
<?php endif; ?>
