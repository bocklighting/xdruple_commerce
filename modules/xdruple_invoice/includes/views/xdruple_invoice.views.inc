<?php

/**
 * Provide xDruple Commerce Invoice related Views integration.
 */

/**
 * Implements hook_views_data_alter().
 *
 * @param $data
 *   Information about Views' tables and fields.
 */
function xdruple_invoice_views_data_alter(&$data) {
  if (isset($data['efq_xtuple_invoicelistitem'])) {
    // Set custom handler to dynamically adds currency symbol to the rendered
    // amount based on the currency column.
    $data['efq_xtuple_invoicelistitem']['total']['field']['handler'] = 'xdruple_commerce_handler_currency_formatter';
  }
}
