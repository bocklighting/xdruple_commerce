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

  $summary = _xdruple_commerce_get_cart_summary();
  if (!empty($summary['count']) && $summary['count'] > 0) {
    $output .= theme('xdruple_commerce_cart_dropdown', array(
      'title'  => t('My cart'),
      'count'  => format_plural($summary['count'], '1 item', '@count items'),
      'amount' => commerce_currency_format($summary['total'], $summary['currency']),
    ));
  }
  else {
    $output .= theme('xdruple_commerce_cart_dropdown', array(
      'title' => t('My cart is empty'),
    ));
  }

  return $output;
}
