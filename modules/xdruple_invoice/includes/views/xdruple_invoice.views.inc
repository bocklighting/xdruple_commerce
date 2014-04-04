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
    // Add a custom field to the view that takes the total and formats it as currency.
    $data['efq_xtuple_invoicelistitem']['total_amount'] = array(
      'title' => t('Total'),
      'help' => t('The Total amount formatted to include the currency symbol.'),
      'real field' => 'total',
      'field' => array(
        'handler' => 'xdruple_commerce_handler_currency_formatter',
        // @See: https://drupal.org/node/2007388
        //'handler' => 'CurrencyAmountViewsHandlerField',
        'currency_code_field' => 'currency',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
    );
  }
}
