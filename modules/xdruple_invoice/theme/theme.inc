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
  $remit_to  = $variables['remitto'];
  $shipments = $variables['shipments'];

  $output = '';
  $output .= '<div class="order-logo">';
  $output .= theme('image', array(
    'path' => theme_get_setting('logo_path') ? theme_get_setting('logo_path') : theme_get_setting('logo'),
  ));
  $output .= '</div>';
  $variables['logo'] = $output;

  $output = '';
  $output .= '<div class="order-remit-to-address-wrapper">';
  $output .= '<div class="order-remit-to-address">' . str_replace("\n", "<br />", $remit_to->address) . '</div>';
  $output .= '</div>';
  $variables['remit_to_address'] = $output;

  $output = '';
  $output .= '<div class="order-header-message-wrapper">';
  $output .= '<div class="order-header-customer">' . $invoice->customer['name'] . '</div>';
  $output .= '<div class="order-header-message">' . t('Thank you for ordering from @site.  Please keep a copy of this invoice for your records.', array(
      '@site' => variable_get('site_name'),
    )) . '</div>';
  $output .= '</div>';
  $variables['header_message'] = $output;

  $invoice_date           = new DateTime($invoice->invoiceDate);
  $order_date             = new DateTime($invoice->orderDate);
  $due_date               = new DateTime($invoice->dueDate);
  $header_table           = array(
    'rows' => array(),
  );
  $header_table['rows'][] = array(t('Invoice #'), $invoice->number);
  $header_table['rows'][] = array(t('Invoice date'), $invoice_date->format('Y-m-d'));
  $header_table['rows'][] = array(t('Account #'), $order->customer['number']);
  $header_table['rows'][] = array(t('Sales order #'), $invoice->orderNumber);
  $header_table['rows'][] = array(t('Order date'), $order_date->format('Y-m-d'));
  $header_table['rows'][] = array(t('PO #'), $order->customerPurchaseOrderNumber);
  $header_table['rows'][] = array(
    'data'  => array(t('Due date'), $due_date->format('Y-m-d')),
    'class' => 'order-due-date',
  );
  $header_table['rows'][] = array(
    'data'  => array(t('Total Due'), _xdruple_commerce_currency_format($invoice->balance, $currency)),
    'class' => 'order-header-total-due',
  );

  $output = '';
  $output .= '<div class="order-header-wrapper">';
  $output .= theme('table', $header_table);
  $output .= '</div>';
  $variables['header_table'] = $output;

  $billing_address = array();
  if (!empty($invoice->billtoName)) {
    $billing_address[] = $invoice->billtoName;
  }
  if (!empty($invoice->billtoAddress1)) {
    $billing_address[] = $invoice->billtoAddress1;
  }
  if (!empty($invoice->billtoAddress2)) {
    $billing_address[] = $invoice->billtoAddress2;
  }
  if (!empty($invoice->billtoAddress3)) {
    $billing_address[] = $invoice->billtoAddress3;
  }
  $billing_address[] = $invoice->billtoCity . ', ' . $invoice->billtoState . ' ' . $invoice->billtoPostalCode;
  if (!empty($invoice->billtoCountry)) {
    $billing_address[] = $invoice->billtoCountry;
  }
  if (!empty($invoice->billtoPhone)) {
    $billing_address[] = $invoice->billtoPhone;
  }

  $output = '';
  $output .= '<div class="order-bill-to-address-wrapper">';
  $output .= '<div class="order-bill-to-address-title">' . t('Billing information') . '</div>';
  $output .= '<address>' . implode('<br />', $billing_address) . '</address>';
  $output .= '</div>';
  $variables['billing_info'] = $output;

  $shipping_address = array();
  if (!empty($order->shiptoName)) {
    $shipping_address[] = $order->shiptoName;
  }
  if (!empty($order->shiptoAddress1)) {
    $shipping_address[] = $order->shiptoAddress1;
  }
  if (!empty($order->shiptoAddress2)) {
    $shipping_address[] = $order->shiptoAddress2;
  }
  if (!empty($order->shiptoAddress3)) {
    $shipping_address[] = $order->shiptoAddress3;
  }
  $shipping_address[] = $order->shiptoCity . ', ' . $order->shiptoState . ' ' . $order->shiptoPostalCode;
  if (!empty($order->shiptoCountry)) {
    $shipping_address[] = $order->shiptoCountry;
  }
  if (!empty($order->shiptoContactPhone)) {
    $shipping_address[] = $order->shiptoContactPhone;
  }

  $output = '';
  $output .= '<div class="order-ship-to-address-wrapper">';
  $output .= '<div class="order-ship-to-address-title">' . t('Shipping information') . '</div>';
  $output .= '<address>' . implode('<br />', $shipping_address) . '</address>';
  $output .= '</div>';
  $variables['shipping_info'] = $output;

  $line_items_table = array(
    'header' => array(
      t('SKU #'),
      t('Description'),
      t('Quantity'),
      t('UOM'),
      t('Unit Price'),
      t('Ext. Price'),
    ),
    'rows'   => array(),
  );
  foreach ($order->lineItems as $line) {
    $line_items_table['rows'][] = array(
      _xdruple_commerce_product_format($line['item']),
      $line['item']['description1'],
      number_format(round($line['quantity'], 2), 2),
      $line['priceUnit'],
      _xdruple_commerce_currency_format($line['price'], $currency),
      _xdruple_commerce_currency_format($line['extendedPrice'], $currency),
    );
  }
  $output = '';
  $output .= '<div class="order-line-items-wrapper">';
  $output .= theme('table', $line_items_table);
  $output .= '</div>';
  $variables['line_items_table'] = $output;

  $credits               = $order->allocatedCredit + $order->authorizedCredit + $order->outstandingCredit;
  $total_table           = array(
    'rows' => array(),
  );
  $total_table['rows'][] = array(t('Subtotal'), _xdruple_commerce_currency_format($order->subtotal, $currency));
  $total_table['rows'][] = array(t('Freight'), _xdruple_commerce_currency_format($order->freight, $currency));
  $total_table['rows'][] = array(t('Misc Charge'), _xdruple_commerce_currency_format($order->miscCharge, $currency));
  $total_table['rows'][] = array(t('Tax'), _xdruple_commerce_currency_format($order->taxTotal, $currency));
  $total_table['rows'][] = array(t('Less Credits'), _xdruple_commerce_currency_format($credits * -1, $currency));
  $total_table['rows'][] = array(t('Total Due'), _xdruple_commerce_currency_format($order->balance, $currency));
  $total_table['rows'][] = array(t('Payment Terms'), $order->terms);
  $output                = '';
  $output .= '<div class="order-total-wrapper">';
  $output .= theme('table', $total_table);
  $output .= '</div>';
  $variables['order_total'] = $output;

  $output = '';
  $output .= '<div class="order-footer-message-wrapper">';
  $output .= '<div class="order-footer-message">' . t('Thank you, <br /> The @site Team', array(
      '@site' => variable_get('site_name'),
    )) . '</div>';
  $output .= '</div>';
  $variable['footer_message'] = $output;

  if (!empty($order->orderNotes)) {
    $output = '';
    $output .= '<div class="order-notes-wrapper">';
    $output .= '<div class="order-notes-title">' . t('Notes') . '</div>';
    $output .= '<div class="order-notes-content">' . $order->orderNotes . '</div>';
    $output .= '</div>';
    $variables['notes'] = $output;
  }

  $tracking_numbers = array();
  if (!empty($shipments)) {
    foreach ($shipments as $shipment) {
      $tracking_numbers[] = _xdruple_commerce_tracking_format($shipment->trackingNumber);
    }
    $output = '';
    $output .= '<div class="invoice-tracking-info">';
    $output .= '<div class="invoice-tracking-content">' . t('Tracking numbers') . '</div>';
    $output .= '<div class="invoice-tracking-content">' . theme('item_list', array(
        'items'      => $tracking_numbers,
        'type'       => 'ul',
        'attributes' => array(
          'class' => 'invoice-tracking-list',
        ),
      )) . '</div>';
    $output .= '</div>';
    $variables['tracking'] = $output;
  }
}
