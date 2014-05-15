<?php

/**
 * @file keeps callbacks for /user/%/invoices/% page
 */

/**
 * Page callback
 *
 * @param $invoice_number The Invoice number.
 *
 * @return string Themed output.
 */
function xdruple_invoice_page($invoice_number) {
  $output   = '';
  $invoices = array();

  if (!empty($invoice_number) && is_numeric($invoice_number)) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'xtuple_invoice')
      ->propertyCondition('number', $invoice_number, '=');

    if (user_access('administer rescued entities')) {
      $invoices = $query->execute();
    }
    else {
      if (isset($_SESSION['rescued']['customer'])) {
        $query->propertyCondition('customer', $_SESSION['rescued']['customer'], '=');
        $invoices = $query->execute();
      }
    }
    // TODO: Add Sales Rep, Empolyee and Owner query filters.

    $query_remitto = new EntityFieldQuery();
    $remitto       = $query_remitto->entityCondition('entity_type', 'xtuple_remitto')->execute();

    // TODO: The rescued_entity_field_query_builder(EntityFieldQuery $query)
    // function runs through entity_load to do the actual query. In theory,
    // an EntityFieldQuery() could go directly to the API and then you would
    // call entity_load() for the returned ids which will attach fields, etc.
    // We can skip this call for now. This is one reason why the entity cache
    // and EntityFieldQuery cache need to work together.
    //$invoice = entity_load('xtuple_invoicelistitem', array_keys($invoice['xtuple_invoicelistitem']));

    foreach ($invoices['xtuple_invoice'] as $invoice) {
      $currency = entity_load_single('xtuple_currency', $invoice->currency);

      $query_order = new EntityFieldQuery();
      $order       = $query_order->entityCondition('entity_type', 'xtuple_salesorder')
        ->propertyCondition('number', $invoice->orderNumber, '=')
        ->execute();

      $query_shipment = new EntityFieldQuery();
      $shipment       = $query_shipment->entityCondition('entity_type', 'xtuple_xdshipment')
        ->propertyCondition('order', $invoice->orderNumber, '=')
        ->execute();

      $params = array(
        'invoice'  => $invoice,
        'remitto'  => $remitto['xtuple_remitto'][key($remitto['xtuple_remitto'])],
        'currency' => $currency,
      );

      $params['order']     = count($order) > 0 ? $order['xtuple_salesorder'][$invoice->orderNumber] : array();
      $params['shipments'] = count($shipment) > 0 ? $shipment['xtuple_xdshipment'] : array();

      $output = theme('invoice_page', $params);
    }
  }

  return $output;
}

/**
 * Title callback
 */
function xdruple_invoice_page_title($invoice_number) {
  $title = t('Invoice');
  if (!empty($invoice_number) && is_numeric($invoice_number)) {
    $title = t('Invoice #!number', array(
      '!number' => $invoice_number,
    ));
  }

  return $title;
}
