<?php
/**
 * @var string $link
 * @var int    $count
 * @var string $title
 * @var string $amount
 */
?>
<div class="btn-group">
  <a href="<?php print $link ?>" class="btn btn-primary">
    <?php if ($count == 0): ?>
      <div class="empty-cart"><span class="my-cart"><?php print $title ?></span></div>
    <?php else: ?>
      <span class="my-cart"><?php print $title ?>:</span>
      <span class="count"><?php print $count ?></span>
      <span class="amount"><?php print $amount ?></span>
    <?php endif; ?>
  </a>
</div>
