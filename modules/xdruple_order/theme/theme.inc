<?php

/**
 * @keeps theme callback
 */

/**
 * Preprocess variables for order-page.tpl.php
 */
function template_preprocess_order_page(&$variables) {
  $order     = $variables['order'];
  $currency  = $variables['currency'];
  $remitto   = $variables['remitto'];
  $logo      = theme_get_setting('logo_path') ? theme_get_setting('logo_path') : theme_get_setting('logo');

  // Build header_msg.
  $header_cust                 = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'h1',
      '#attributes' => array(
        'class' => 'order-header-cust',
        ),
      '#value' => $order->customer['name'] . ',',
    ),
  ));
  $header_msg                  = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'p',
      '#attributes' => array(
        'class' => 'order-header-msg-txt',
        ),
      '#value' => t('Thank you for ordering from @cust.', array(
                    '@cust' => $order->customer['name']
                  )),
    ),
  ));
  $header_msg_wrapper          = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'order-header-msg-wrapper',
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
        'class' => 'order-remitto-wrapper',
        ),
      '#value' => theme('table', $remitto_table),
    ),
  ));
  $variables['remitto_table']  = $remitto_wrapper;

  // Build header_table.
  $header_table = array(
    'rows'   => array(),
  );
  $header_table['rows'][]      = array('Sales Order #:', $order->number);
  $order_date                  = new DateTime($order->orderDate);
  $header_table['rows'][]      = array('Order Date:', $order_date->format('Y-m-d'));
  $header_table['rows'][]      = array('Account #:', $order->customer['number']);
  $header_table['rows'][]      = array('PO #:', $order->customerPurchaseOrderNumber);
  $sched_date                  = new DateTime($order->scheduleDate);
  $header_table['rows'][]      = array('Scheduled Date:', $sched_date->format('Y-m-d'));
  $header_table['rows'][]      = array('', '');
  $header_table['rows'][]      = array('Total Due:', _xdruple_commerce_currency_format($order->balance, $currency));
  $header_wrapper              = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'order-header-wrapper',
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
  if (!empty($order->billtoName)) {
    $billing_addr[] = $order->billtoName;
  }
  if (!empty($order->billtoAddress1)) {
    $billing_addr[] = $order->billtoAddress1;
  }
  if (!empty($order->billtoAddress2)) {
    $billing_addr[] = $order->billtoAddress2;
  }
  if (!empty($order->billtoAddress3)) {
    $billing_addr[] = $order->billtoAddress3;
  }
  $billing_addr[] = $order->billtoCity . ', ' . $order->billtoState . ' ' . $order->billtoPostalCode;
  if (!empty($order->billtoCountry)) {
    $billing_addr[] = $order->billtoCountry;
  }
  if (!empty($order->billtoPhone)) {
    $billing_addr[] = $order->billtoPhone;
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
        'class' => 'order-addr-wrapper',
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
  foreach ($order->lineItems as $line) {
    $lines_table['rows'][]     = array(
      _xdruple_commerce_product_format($line['item']),
      $line['item']['description1'],
      number_format(round($line['quantity'], 2), 2),
      $line['priceUnit'],
      _xdruple_commerce_currency_format($line['price'], $currency),
      _xdruple_commerce_currency_format($line['extendedPrice'], $currency),
    );
  }
  $lines_wrapper              = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'order-line-items-wrapper',
        ),
      '#value' => theme('table', $lines_table),
    ),
  ));
  $variables['lines_table']   = $lines_wrapper;


  // Build total_table.
  $total_table = array(
    'rows'   => array(),
  );
  $total_table['rows'][]       = array('Subtotal:', _xdruple_commerce_currency_format($order->subtotal, $currency));
  $total_table['rows'][]       = array('Freight:', _xdruple_commerce_currency_format($order->freight, $currency));
  $total_table['rows'][]       = array('Misc Charge:', _xdruple_commerce_currency_format($order->miscCharge, $currency));
  $total_table['rows'][]       = array('Tax:', _xdruple_commerce_currency_format($order->taxTotal, $currency));
  $credits                     = $order->allocatedCredit + $order->authorizedCredit + $order->outstandingCredit;
  $total_table['rows'][]       = array('Less Credits:', _xdruple_commerce_currency_format($credits * -1, $currency));
  $total_table['rows'][]       = array('Total Due:', _xdruple_commerce_currency_format($order->balance, $currency));
  $total_table['rows'][]       = array('Payment Terms:', $order->terms);
  $total_wrapper               = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'order-total-wrapper',
        ),
      '#value' => theme('table', $total_table),
    ),
  ));
  $variables['total_table']    = $total_wrapper;

  // Build footer_msg.
  $footer_msg                  = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'p',
      '#attributes' => array(
        'class' => 'order-footer-msg-txt',
        ),
      '#value' => 'Thank you,' . '<br />' . t('The @cust Team', array('@cust' => $order->customer['name'])),
    ),
  ));
  $footer_msg_wrapper          = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'order-footer-msg-wrapper',
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
        'class' => 'order-notes-header',
        ),
      '#value' => 'Notes:',
    ),
  ));
  $notes                       = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'p',
      '#attributes' => array(
        'class' => 'order-notes-txt',
        ),
      '#value' => $order->orderNotes,
    ),
  ));
  $notes_wrapper               = theme ('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => 'order-notes-wrapper',
        ),
      '#value' => $notes_header . $notes,
    ),
  ));
  $variables['notes']          = $notes_wrapper;
}
