<div class="xdruple-print xdruple-print-order row">
  <?php if (!empty($logo)): ?>
    <?php print $logo; ?>
  <?php endif; ?>

  <?php if (!empty($remit_to_address)): ?>
    <?php print $remit_to_address ?>
  <?php endif; ?>

  <?php if (!empty($header_table)): ?>
    <?php print $header_table ?>
  <?php endif; ?>

  <?php if (!empty($header_message)): ?>
    <?php print $header_message ?>
  <?php endif; ?>

  <?php if (!empty($billing_info)): ?>
    <?php print $billing_info ?>
  <?php endif; ?>

  <?php if (!empty($shipping_info)): ?>
    <?php print $shipping_info ?>
  <?php endif; ?>

  <?php if (!empty($line_items_table)): ?>
    <?php print $line_items_table ?>
  <?php endif; ?>

  <?php if (!empty($order_total)): ?>
    <?php print $order_total ?>
  <?php endif; ?>

  <?php if (!empty($footer_message)): ?>
    <?php print $footer_message ?>
  <?php endif; ?>

  <?php if (!empty($notes)): ?>
    <?php print $notes ?>
  <?php endif; ?>
</div>
