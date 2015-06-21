<?php
/**
 * @var string $classes
 * @var string $attributes
 * @var string $label
 * @var string $price
 * @var string $unit
 */
?>
<?php if ($price): ?>
  <div class="<?php print $classes ?>"<?php print $attributes ?>>
    <?php if ($label): ?>
      <div class="field-label"><?php print $label ?>:&nbsp;</div>
    <?php endif; ?>
    <div class="field-item">
      <span><?php print $price ?></span>
      <?php if ($unit): ?>
        <small>/&nbsp;<?php print $unit ?></small>
      <?php endif; ?>
    </div>
  </div>
<?php endif; ?>
