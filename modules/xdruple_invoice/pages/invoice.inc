<?php

/**
 * @file keeps callbacks for /invoice/% page
 */

/**
 * Page callback
 *
 * @param $product_id
 *
 * @return string
 */
function xdruple_invoice_page($invc_id) {
  $output = '';

  $list           = array();

  if (!empty($invc_id)) {
    $query = new EntityFieldQuery();
    $invoices = $query->entityCondition('entity_type', 'xtuple_invoicelistitem')
      // TODO: nginx seems to max out around 180 products. Then it returns a
      // 414 Request-URI Too Large. Using 50 as a default for now until this
      // is fixed by dev ops.
      ->propertyCondition('number', $invc_id, '=')
      ->execute();

    // TODO: The rescued_entity_field_query_builder(EntityFieldQuery $query)
    // function runs through entity_load to do the actual query. In theory,
    // an EntityFieldQuery() could go directly to the API and then you would
    // call entity_load() for the returned ids which will attach fields, etc.
    // We can skip this call for now. This is one reason why the entity cache
    // and EntityFieldQuery cache need to work together.
    //$invoice = entity_load('xtuple_invoicelistitem', array_keys($invoice['xtuple_invoicelistitem']));

    foreach ($invoices['xtuple_invoicelistitem'] as $invoice) {
      $output = theme('invoice_page', array(
        'invoice' => $invoice,
      ));
    }
  }

  return $output;
}
