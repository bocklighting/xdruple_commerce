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

  // Format Messages.
  $variables['remitto_logo']    = $logo;
  $variables['remitto_name']    = $remitto->name;
  $variables['remitto_addr']    = explode("\n", $remitto->address);
  $variables['customer']        = $order->customer['name'];
  $variables['header_mgs']      = t('Thank you for ordering from @cust.', array(
                                    '@cust' => $order->customer['name']
                                  ));

  // Format Header.
  $variables['order_num']       = $order->number;
  $order_date                   = new DateTime($order->orderDate);
  $variables['order_date']      = $order_date->format('Y-m-d');
  $variables['account_num']     = $order->customer['number'];
  $variables['po_num']          = $order->customerPurchaseOrderNumber;
  $sched_date                   = new DateTime($order->scheduleDate);
  $variables['sched_date']      = $sched_date->format('Y-m-d');

  // Format Billing Info.
  $variables['billing_info'] = array();
  if (!empty($order->billtoName)) {
    $variables['billing_info'][] = $order->billtoName;
  }
  if (!empty($order->billtoAddress1)) {
    $variables['billing_info'][] = $order->billtoAddress1;
  }
  if (!empty($order->billtoAddress2)) {
    $variables['billing_info'][] = $order->billtoAddress2;
  }
  if (!empty($order->billtoAddress3)) {
    $variables['billing_info'][] = $order->billtoAddress3;
  }
  $variables['billing_info'][] =  $order->billtoCity . ', ' . $order->billtoState . ' ' . $order->billtoPostalCode;
  if (!empty($order->billtoCountry)) {
    $variables['billing_info'][] = $order->billtoCountry;
  }
  if (!empty($order->billtoPhone)) {
    $variables['billing_info'][] = $order->billtoPhone;
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
  foreach ($order->lineItems as $line) {
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
  $variables['subtotal']   = _xdruple_commerce_currency_format($order->subtotal, $currency);
  $variables['freight']    = _xdruple_commerce_currency_format($order->freight, $currency);
  $variables['misc']       = _xdruple_commerce_currency_format($order->miscCharge, $currency);
  $variables['tax']        = _xdruple_commerce_currency_format($order->taxTotal, $currency);
  $total                   = $order->subtotal + $order->freight + $order->taxTotal + $order->miscCharge;
  $variables['total']      = _xdruple_commerce_currency_format($total, $currency);
  $credits                 = $order->allocatedCredit + $order->authorizedCredit + $order->outstandingCredit;
  $variables['credits']    = _xdruple_commerce_currency_format($credits * -1, $currency);
  $variables['total_due']  = _xdruple_commerce_currency_format($order->balance, $currency);
  $variables['terms_code'] = $order->terms['code'];

  $variables['notes']      = $order->orderNotes;
}
