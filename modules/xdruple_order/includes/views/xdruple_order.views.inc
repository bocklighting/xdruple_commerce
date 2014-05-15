<?php

/**
 * Provide xDruple Commerce Sales Order related Views integration.
 */

/**
 * Implements hook_views_data_alter().
 *
 * @param $data
 *   Information about Views' tables and fields.
 */
function xdruple_order_views_data_alter(&$data) {
  if (isset($data['efq_xtuple_salesorderlistitem'])) {
    // Set custom handler to dynamically adds currency symbol to the rendered
    // amount based on the currency column.
    $data['efq_xtuple_salesorderlistitem']['total']['field']['handler'] = 'xdruple_commerce_handler_currency_formatter';
    $data['efq_xtuple_salesorderlistitem']['number']['field']['handler'] = 'xdruple_order_handler_order_number_formatter';
  }
}
