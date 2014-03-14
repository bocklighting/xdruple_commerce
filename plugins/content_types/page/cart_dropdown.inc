<?php

/**
 * @file CTools content type plugin to show Cart Dropdown
 */
$plugin = extensions_content_type_plugin('xdruple_commerce', 'cart_dropdown', 'Cart Dropdown', array(
  'description' => '',
  'css'         => array(),
), array(
  'override_title'      => 1,
  'override_title_text' => '',
), 'Page elements');

/**
 * Implementation of hook_PLUGIN_TYPE_content_type_render()
 */
function xdruple_commerce_cart_dropdown_content_type_plugin_render($subtype, $conf, $panel_args) {
  $output = '';

  global $user;
  $order = commerce_cart_order_load($user->uid);
  $count = 0;
  if ($order) {
    $wrapper = entity_metadata_wrapper('commerce_order', $order);
    $count   = commerce_line_items_quantity($wrapper->commerce_line_items, commerce_product_line_item_types());
    if ($count > 0) {
      $total    = $order->commerce_order_total['und'][0]['amount'];
      $currency = $order->commerce_order_total['und'][0]['currency_code'];

      $output = theme('xdruple_commerce_cart_dropdown', array(
        'title'  => t('My cart'),
        'count'  => format_plural($count, '1 item', '@count items'),
        'amount' => commerce_currency_format($total, $currency),
      ));
    }
  }

  if ($count == 0) {
    $output = theme('xdruple_commerce_cart_dropdown', array(
      'title' => t('My cart is empty'),
    ));
  }

  return $output;
}
