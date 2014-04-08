<!-- RemitTo Table -->
<div>
  <table>
    <tr>
      <td>
      <?php if (!empty($remitto_logo)): ?>
        <img src="<?php print $remitto_logo ?>" />
      <?php endif; ?>
      </td>
      <td>
        <span><?php print $remitto_name ?></span><br />
      <?php foreach ($remitto_addr as $remitto_line): ?>
        <span><?php print $remitto_line ?></span><br />
      <?php endforeach; ?>
      </td>
    </tr>
  </table>
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
  <table>
  <?php if (!empty($invoice_num)): ?>
    <tr>
      <td>Invoice #:</td>
      <td><?php print $invoice_num ?></td>
    </tr>
  <?php endif; ?>
  <?php if (!empty($invoice_date)): ?>
    <tr>
      <td>Invoice Date:</td>
      <td><?php print $invoice_date ?></td>
    </tr>
  <?php endif; ?>
  <?php if (!empty($account_num)): ?>
    <tr>
      <td>Account #:</td>
      <td><?php print $account_num ?></td>
    </tr>
  <?php endif; ?>
  <?php if (!empty($order_num)): ?>
    <tr>
      <td>Sales Order #:</td>
      <td><?php print $order_num ?></td>
    </tr>
  <?php endif; ?>
  <?php if (!empty($order_date)): ?>
    <tr>
      <td>Order Date:</td>
      <td><?php print $order_date ?></td>
    </tr>
  <?php endif; ?>
  <?php if (!empty($po_num)): ?>
    <tr>
      <td>PO #:</td>
      <td><?php print $po_num ?></td>
    </tr>
  <?php endif; ?>
    <tr>
      <!-- Spacer before total -->
      <td></td>
      <td></td>
    </tr>
  <?php if (!empty($due_date)): ?>
    <tr>
      <td>Due Date:</td>
      <td><?php print $due_date ?></td>
    </tr>
  <?php endif; ?>
  <?php if (!empty($total_due)): ?>
    <tr>
      <td>Total Due:</td>
      <td><?php print $total_due ?></td>
    </tr>
  <?php endif; ?>
  </table>
</div>


<!-- Address Table -->
<div>
  <table>
    <tr>
      <th>Billing Information</th>
      <th>Shipping Information</th>
    </tr>
    <tr>
      <td>
      <?php foreach ($billing_info as $bill_line): ?>
        <span><?php print $bill_line ?></span><br />
      <?php endforeach; ?>
      </td>
      <td>
      <?php foreach ($shipping_info as $ship_line): ?>
        <span><?php print $ship_line ?></span><br />
      <?php endforeach; ?>
      </td>
    </tr>
  </table>
</div>


<!-- Line Items Table -->
<div>
  <table>
    <tr>
      <th>SKU#</th>
      <th>Description</th>
      <th>Quantity   </th>
      <th>UOM</th>
      <th>Unit Price</th>
      <th>Ext. Price</th>
    </tr>
  <?php foreach ($line_items as $line): ?>
    <tr>
      <td><?php print $line['sku'] ?></td>
      <td><?php print $line['descrip'] ?></td>
      <td><?php print $line['qty'] ?></td>
      <td><?php print $line['uom'] ?></td>
      <td><?php print $line['price'] ?></td>
      <td><?php print $line['ext_price'] ?></td>
    </tr>
  <?php endforeach; ?>
  </table>
</div>


<!-- Total Table -->
<div>
  <table>
  <?php if (!empty($subtotal)): ?>
    <tr>
      <td>Subtotal:</td>
      <td><?php print $subtotal ?></td>
    </tr>
  <?php endif; ?>
  <?php if (!empty($freight)): ?>
    <tr>
      <td>Freight:</td>
      <td><?php print $freight ?></td>
    </tr>
  <?php endif; ?>
  <?php if (!empty($misc)): ?>
    <tr>
      <td>Misc Charge:</td>
      <td><?php print $misc ?></td>
    </tr>
  <?php endif; ?>
  <?php if (!empty($tax)): ?>
    <tr>
      <td>Tax:</td>
      <td><?php print $tax ?></td>
    </tr>
  <?php endif; ?>
  <?php if (!empty($credits)): ?>
    <tr>
      <td>Less Credits:</td>
      <td><?php print $credits ?></td>
    </tr>
  <?php endif; ?>
  <?php if (!empty($total_due)): ?>
    <tr>
      <td>Total Due:</td>
      <td><?php print $total_due ?></td>
    </tr>
  <?php endif; ?>
  <?php if (!empty($terms_code)): ?>
    <tr>
      <td>Payment Terms:</td>
      <td><?php print $terms_code ?></td>
    </tr>
  <?php endif; ?>
  </table>
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
