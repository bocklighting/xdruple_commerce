<?php

/**
 * Provide xDruple Commerce Save Cart Orders related Views integration.
 */

/**
 * Implements hook_views_data_alter().
 *
 * @param $data
 *   Information about Views' tables and fields.
 */
function xdruple_save_cart_views_data_alter(&$data) {
  if (isset($data['commerce_order'])) {
    // Adds a link to make this cart the active cart.
    $data['commerce_order']['move_order'] = [
      'field' => [
        'title' => t('Operations'),
        'help' => t('Adds a button to make this order the current active cart.'),
        'handler' => 'xdruple_save_cart_handler_field_move_order',
      ],
    ];
  }
}
