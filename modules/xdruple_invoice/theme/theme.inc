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
  $variables['remitto_logo']    = $logo;
  $variables['remitto_name']    = $remitto->name;
  $variables['remitto_addr']    = explode("\n", $remitto->address);
  $variables['customer']        = $invoice->customer['name'];
  $variables['header_mgs']      = t('Thank you for ordering from @cust. Please keep a copy of this invoice for your records.', array(
                                    '@cust' => $invoice->customer['name']
                                  ));

  // Format Header.
  $variables['invoice_num']     = $invoice->number;
  $invoice_date                 = new DateTime($invoice->invoiceDate);
  $variables['invoice_date']    = $invoice_date->format('Y-m-d');
  $variables['account_num']     = $invoice->customer['number'];
  $variables['order_num']       = $invoice->orderNumber;
  $order_date                   = new DateTime($invoice->orderDate);
  $variables['order_date']      = $order_date->format('Y-m-d');
  $variables['po_num']          = $order->customerPurchaseOrderNumber;
  $due_date                     = new DateTime($invoice->dueDate);
  $variables['due_date']        = $due_date->format('Y-m-d');

  // Format Billing Info.
  $variables['billing_info'] = array();
  if (!empty($invoice->billtoName)) {
    $variables['billing_info'][] = $invoice->billtoName;
  }
  if (!empty($invoice->billtoAddress1)) {
    $variables['billing_info'][] = $invoice->billtoAddress1;
  }
  if (!empty($invoice->billtoAddress2)) {
    $variables['billing_info'][] = $invoice->billtoAddress2;
  }
  if (!empty($invoice->billtoAddress3)) {
    $variables['billing_info'][] = $invoice->billtoAddress3;
  }
  $variables['billing_info'][] =  $invoice->billtoCity . ', ' . $invoice->billtoState . ' ' . $invoice->billtoPostalCode;
  if (!empty($invoice->billtoCountry)) {
    $variables['billing_info'][] = $invoice->billtoCountry;
  }
  if (!empty($invoice->billtoPhone)) {
    $variables['billing_info'][] = $invoice->billtoPhone;
  }

  // Format Shipping Info.
  $variables['shipping_info'] = array();
  if (!empty($order->shiptoName)) {
    $variables['shipping_info'][] = $order->shiptoName;
  }
  if (!empty($order->shiptoAddress1)) {
    $variables['shipping_info'][] = $order->shiptoAddress1;
  }
  if (!empty($order->shiptoAddress2)) {
    $variables['shipping_info'][] = $order->shiptoAddress2;
  }
  if (!empty($order->shiptoAddress3)) {
    $variables['shipping_info'][] = $order->shiptoAddress3;
  }
  $variables['shipping_info'][] =  $order->shiptoCity . ', ' . $order->shiptoState . ' ' . $order->shiptoPostalCode;
  if (!empty($order->shiptoCountry)) {
    $variables['shipping_info'][] = $order->shiptoCountry;
  }
  if (!empty($order->shiptoContactPhone)) {
    $variables['shipping_info'][] = $order->shiptoContactPhone;
  }

  // Format Line Items.
  $variables['line_items'] = array();
  foreach ($invoice->lineItems as $line) {
    $variables['line_items'][$line['lineNumber']] = array(
      // TODO: Link to product page.
      'sku'        => _xdruple_commerce_product_format($line['item']),
      'descrip'    => $line['item']['description1'],
      'qty'        => number_format(round($line['quantity'], 2), 2),
      'uom'        => $line['priceUnit'],
      'price'      => _xdruple_commerce_currency_format($line['price'], $currency),
      'ext_price'  => _xdruple_commerce_currency_format($line['extendedPrice'], $currency),
    );
  }

  // Format Total.
  $variables['subtotal']   = _xdruple_commerce_currency_format($invoice->subtotal, $currency);
  $variables['freight']    = _xdruple_commerce_currency_format($invoice->freight, $currency);
  $variables['misc']       = _xdruple_commerce_currency_format($invoice->miscCharge, $currency);
  $variables['tax']        = _xdruple_commerce_currency_format($invoice->taxTotal, $currency);
  $total                   = $invoice->subtotal + $invoice->freight + $invoice->taxTotal + $invoice->miscCharge;
  $variables['total']      = _xdruple_commerce_currency_format($total, $currency);
  $credits                 = $invoice->allocatedCredit + $invoice->authorizedCredit + $invoice->outstandingCredit;
  $variables['credits']    = _xdruple_commerce_currency_format($credits * -1, $currency);
  $variables['total_due']  = _xdruple_commerce_currency_format($invoice->balance, $currency);
  $variables['terms_code'] = $invoice->terms['code'];

  // Format Tracking.
  $variables['tracking']      = array();
  foreach ($shipments as $shipment) {
    $variables['tracking'][] = _xdruple_commerce_tracking_format($shipment->trackingNumber);
  }

  $variables['notes']      = $invoice->notes;
}
