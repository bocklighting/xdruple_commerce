<!-- RemitTo Table -->
<div>
<?php if (!empty($remitto_table)): ?>
  <?php print $remitto_table ?>
<?php endif; ?>
</div>

<!-- Header Message -->
<div>
<?php if (!empty($customer)): ?>
  <h1><?php print $customer ?>,</h1>
<?php endif; ?>
<?php if (!empty($header_mgs)): ?>
  <p><?php print $header_mgs ?></p>
<?php endif; ?>
</div>

<!-- Header Table -->
<div>
<?php if (!empty($header_table)): ?>
  <?php print $header_table ?>
<?php endif; ?>
</div>


<!-- Address Table -->
<div>
<?php if (!empty($addr_table)): ?>
  <?php print $addr_table ?>
<?php endif; ?>
</div>


<!-- Line Items Table -->
<div>
<?php if (!empty($lines_table)): ?>
  <?php print $lines_table ?>
<?php endif; ?>
</div>


<!-- Total Table -->
<div>
<?php if (!empty($total_table)): ?>
  <?php print $total_table ?>
<?php endif; ?>
</div>

<!-- Tracking -->
<div>
  <h2>Tracking:</h2>
  <?php foreach ($tracking as $tracknumber): ?>
    <div>
      <span><?php print $tracknumber ?></span>
    </div>
  <?php endforeach; ?>
</div>

<!-- Footer Message -->
<div>
  <span>Thank you,</span><br />
<?php if (!empty($customer)): ?>
  <span>The <?php print $customer ?> Team</span>
<?php endif; ?>
<?php if (!empty($notes)): ?>
  <h2>Notes:</h2>
  <p><?php print $notes ?></p>
<?php endif; ?>
</div>
