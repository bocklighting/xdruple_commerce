<?php

/**
 * @keeps theme callback
 */

/**
 * Preprocess variables for invoice-page.tpl.php
 */
function template_preprocess_invoice_page(&$variables) {
  $invoice   = $variables['invoice'];
  $currency  = $variables['currency'];
  $order     = $variables['order'];
  $remitto   = $variables['remitto'];
  $shipments = $variables['shipments'];
  $logo      = theme_get_setting('logo_path') ? theme_get_setting('logo_path') : theme_get_setting('logo');

  // Format Messages.
  $variables['customer']        = $invoice->customer['name'];
  $variables['header_mgs']      = t('Thank you for ordering from @cust. Please keep a copy of this invoice for your records.', array(
                                    '@cust' => $invoice->customer['name']
                                  ));

  // Build remitto_table.
  $remitto_img = array(
    'path'   => $logo,
  );
  $remitto_addr = array(
    'items'  => explode("\n", $remitto->address),
    'type'   => 'ul',
  );
  array_unshift($remitto_addr['items'], $remitto->name);
  $remitto_table = array(
    'rows'   => array(),
  );
  $remitto_table['rows'][]      = array(theme('image', $remitto_img), theme('item_list', $remitto_addr));
  $variables['remitto_table']   = theme('table', $remitto_table);

  // Build header_table.
  $header_table = array(
    'rows'   => array(),
  );
  $header_table['rows'][]       = array('Invoice #:', $invoice->number);
  $invoice_date                 = new DateTime($invoice->invoiceDate);
  $header_table['rows'][]       = array('Invoice Date:', $invoice_date->format('Y-m-d'));
  $header_table['rows'][]       = array('Account #:', $order->customer['number']);
  $header_table['rows'][]       = array('Sales Order #:', $invoice->orderNumber);
  $order_date                   = new DateTime($invoice->orderDate);
  $header_table['rows'][]       = array('Order Date:', $order_date->format('Y-m-d'));
  $header_table['rows'][]       = array('PO #:', $order->customerPurchaseOrderNumber);
  $header_table['rows'][]       = array('', '');
  $due_date                     = new DateTime($invoice->dueDate);
  $header_table['rows'][]       = array('Due Date:', $due_date->format('Y-m-d'));
  $header_table['rows'][]       = array('Total Due:', _xdruple_commerce_currency_format($invoice->balance, $currency));
  $variables['header_table']    = theme('table', $header_table);


  // Build addr_table.
  $addr_table = array(
    'header' => array(),
    'rows'   => array(),
  );
  $addr_table['header']         = array(
    'Billing Information',
    'Shipping Information',
  );

  // Format Billing Info.
  $billing_addr = array();
  if (!empty($invoice->billtoName)) {
    $billing_addr[] = $invoice->billtoName;
  }
  if (!empty($invoice->billtoAddress1)) {
    $billing_addr[] = $invoice->billtoAddress1;
  }
  if (!empty($invoice->billtoAddress2)) {
    $billing_addr[] = $invoice->billtoAddress2;
  }
  if (!empty($invoice->billtoAddress3)) {
    $billing_addr[] = $invoice->billtoAddress3;
  }
  $billing_addr[] = $invoice->billtoCity . ', ' . $invoice->billtoState . ' ' . $invoice->billtoPostalCode;
  if (!empty($invoice->billtoCountry)) {
    $billing_addr[] = $invoice->billtoCountry;
  }
  if (!empty($invoice->billtoPhone)) {
    $billing_addr[] = $invoice->billtoPhone;
  }

  // Format Shipping Info.
  $shipping_addr = array();
  if (!empty($order->shiptoName)) {
    $shipping_addr[] = $order->shiptoName;
  }
  if (!empty($order->shiptoAddress1)) {
    $shipping_addr[] = $order->shiptoAddress1;
  }
  if (!empty($order->shiptoAddress2)) {
    $shipping_addr[] = $order->shiptoAddress2;
  }
  if (!empty($order->shiptoAddress3)) {
    $shipping_addr[] = $order->shiptoAddress3;
  }
  $shipping_addr[] = $order->shiptoCity . ', ' . $order->shiptoState . ' ' . $order->shiptoPostalCode;
  if (!empty($order->shiptoCountry)) {
    $shipping_addr[] = $order->shiptoCountry;
  }
  if (!empty($order->shiptoContactPhone)) {
    $shipping_addr[] = $order->shiptoContactPhone;
  }

  $billing_list = array(
    'items'  => $billing_addr,
    'type'   => 'ul',
  );
  $shipping_list = array(
    'items'  => $shipping_addr,
    'type'   => 'ul',
  );
  $addr_table['rows'][]      = array(theme('item_list', $billing_list), theme('item_list', $shipping_list));
  $variables['addr_table']   = theme('table', $addr_table);


  // Build lines_table.
  $lines_table = array(
    'header' => array(),
    'rows'   => array(),
  );
  $lines_table['header']     = array(
    'SKU#',
    'Description',
    'Quantity',
    'UOM',
    'Unit Price',
    'Ext. Price',
  );
  foreach ($invoice->lineItems as $line) {
    $lines_table['rows'][]    = array(
      _xdruple_commerce_product_format($line['item']),
      $line['item']['description1'],
      number_format(round($line['quantity'], 2), 2),
      $line['priceUnit'],
      _xdruple_commerce_currency_format($line['price'], $currency),
      _xdruple_commerce_currency_format($line['extendedPrice'], $currency),
    );
  }
  $variables['lines_table']   = theme('table', $lines_table);


  // Build total_table.
  $total_table = array(
    'rows'   => array(),
  );
  $total_table['rows'][]       = array('Subtotal:', _xdruple_commerce_currency_format($invoice->subtotal, $currency));
  $total_table['rows'][]       = array('Freight:', _xdruple_commerce_currency_format($invoice->freight, $currency));
  $total_table['rows'][]       = array('Misc Charge:', _xdruple_commerce_currency_format($invoice->miscCharge, $currency));
  $total_table['rows'][]       = array('Tax:', _xdruple_commerce_currency_format($invoice->taxTotal, $currency));
  $credits                     = $invoice->allocatedCredit + $invoice->authorizedCredit + $invoice->outstandingCredit;
  $total_table['rows'][]       = array('Less Credits:', _xdruple_commerce_currency_format($credits * -1, $currency));
  $total_table['rows'][]       = array('Total Due:', _xdruple_commerce_currency_format($invoice->balance, $currency));
  $total_table['rows'][]       = array('Payment Terms:', $invoice->terms['code']);
  $variables['total_table']    = theme('table', $total_table);


  // Format Tracking.
  $variables['tracking']      = array();
  foreach ($shipments as $shipment) {
    $variables['tracking'][] = _xdruple_commerce_tracking_format($shipment->trackingNumber);
  }

  $variables['notes']      = $invoice->notes;
}
