<?php
/**
 * @var string $classes
 * @var string $attributes
 */
?>
<div class="<?php print $classes ?>"<?php print $attributes ?>>
  <?php if (!empty($entity_view)): ?>
    <?php print $entity_view ?>
  <?php endif; ?>
</div>
