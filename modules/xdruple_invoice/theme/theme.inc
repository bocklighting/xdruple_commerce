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


  // Build header_msg.
  $header_cust                 = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'h1',
      '#attributes' => array(
        'class' => 'invoice-header-cust',
        ),
      '#value' => $invoice->customer['name'] . ',',
    ),
  ));
  $header_msg                  = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'p',
      '#attributes' => array(
        'class' => 'invoice-header-msg-txt',
        ),
      '#value' => t('Thank you for ordering from @cust. Please keep a copy of this invoice for your records.', array(
                    '@cust' => $invoice->customer['name']
                  )),
    ),
  ));
  $header_msg_wrapper          = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'invoice-header-msg-wrapper',
        ),
      '#value' => $header_cust . $header_msg,
    ),
  ));
  $variables['header_msg']     = $header_msg_wrapper;


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
  $remitto_table['rows'][]     = array(theme('image', $remitto_img), theme('item_list', $remitto_addr));
  $remitto_wrapper             = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'invoice-remitto-wrapper',
        ),
      '#value' => theme('table', $remitto_table),
    ),
  ));
  $variables['remitto_table']  = $remitto_wrapper;


  // Build header_table.
  $header_table = array(
    'rows'   => array(),
  );
  $header_table['rows'][]      = array('Invoice #:', $invoice->number);
  $invoice_date                = new DateTime($invoice->invoiceDate);
  $header_table['rows'][]      = array('Invoice Date:', $invoice_date->format('Y-m-d'));
  $header_table['rows'][]      = array('Account #:', $order->customer['number']);
  $header_table['rows'][]      = array('Sales Order #:', $invoice->orderNumber);
  $order_date                  = new DateTime($invoice->orderDate);
  $header_table['rows'][]      = array('Order Date:', $order_date->format('Y-m-d'));
  $header_table['rows'][]      = array('PO #:', $order->customerPurchaseOrderNumber);
  $header_table['rows'][]      = array('', '');
  $due_date                    = new DateTime($invoice->dueDate);
  $header_table['rows'][]      = array('Due Date:', $due_date->format('Y-m-d'));
  $header_table['rows'][]      = array('Total Due:', _xdruple_commerce_currency_format($invoice->balance, $currency));
  $header_wrapper              = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'invoice-header-wrapper',
        ),
      '#value' => theme('table', $header_table),
    ),
  ));
  $variables['header_table']   = $header_wrapper;


  // Build addr_table.
  $addr_table = array(
    'header' => array(),
    'rows'   => array(),
  );
  $addr_table['header']        = array(
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
  $addr_table['rows'][]        = array(theme('item_list', $billing_list), theme('item_list', $shipping_list));
  $addr_wrapper                = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'invoice-addr-wrapper',
        ),
      '#value' => theme('table', $addr_table),
    ),
  ));
  $variables['addr_table']     = $addr_wrapper;


  // Build lines_table.
  $lines_table = array(
    'header' => array(),
    'rows'   => array(),
  );
  $lines_table['header']       = array(
    'SKU#',
    'Description',
    'Quantity',
    'UOM',
    'Unit Price',
    'Ext. Price',
  );
  foreach ($invoice->lineItems as $line) {
    $lines_table['rows'][]     = array(
      _xdruple_commerce_product_format($line['item']),
      $line['item']['description1'],
      number_format(round($line['quantity'], 2), 2),
      $line['priceUnit'],
      _xdruple_commerce_currency_format($line['price'], $currency),
      _xdruple_commerce_currency_format($line['extendedPrice'], $currency),
    );
  }
  $lines_wrapper               = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'invoice-line-items-wrapper',
        ),
      '#value' => theme('table', $lines_table),
    ),
  ));
  $variables['lines_table']    = $lines_wrapper;


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
  $total_wrapper               = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'invoice-total-wrapper',
        ),
      '#value' => theme('table', $total_table),
    ),
  ));
  $variables['total_table']    = $total_wrapper;


  // Build tracking.
  $tracking_header             = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'h2',
      '#attributes' => array(
        'class' => 'invoice-tracking-header',
        ),
      '#value' => 'Tracking:',
    ),
  ));
  $tracking_nums = array();
  foreach ($shipments as $shipment) {
    $tracking_nums[] = _xdruple_commerce_tracking_format($shipment->trackingNumber);
  }
  $tracking_list = array(
    'items'  => $tracking_nums,
    'type'   => 'ul',
    'attributes' => array(
      'class' => 'invoice-tracking-number',
    ),
  );
  $tracking_wrapper            = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'invoice-tracking-wrapper',
        ),
      '#value' => $tracking_header . theme('item_list', $tracking_list),
    ),
  ));
  $variables['tracking']       = $tracking_wrapper;

  // Build footer_msg.
  $footer_msg                  = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'p',
      '#attributes' => array(
        'class' => 'invoice-footer-msg-txt',
        ),
      '#value' => 'Thank you,' . '<br />' . t('The @cust Team', array('@cust' => $invoice->customer['name'])),
    ),
  ));
  $footer_msg_wrapper          = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'invoice-footer-msg-wrapper',
        ),
      '#value' => $footer_msg,
    ),
  ));
  $variables['footer_msg']     = $footer_msg_wrapper;

  // Build notes.
  $notes_header                = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'h2',
      '#attributes' => array(
        'class' => 'invoice-notes-header',
        ),
      '#value' => 'Notes:',
    ),
  ));
  $notes                       = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'p',
      '#attributes' => array(
        'class' => 'invoice-notes-txt',
        ),
      '#value' => $invoice->notes,
    ),
  ));
  $notes_wrapper               = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'invoice-notes-wrapper',
        ),
      '#value' => $notes_header . $notes,
    ),
  ));
  $variables['notes']          = $notes_wrapper;
}
