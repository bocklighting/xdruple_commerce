<?php

/**
 * @file CTools content type plugin to show Cart Dropdown
 */
$plugin = extensions_content_type_plugin('xdruple_fields', 'order_defaults_form', 'Order Defaults form', array(
  'description' => '',
  'css'         => array(),
), array(
  'override_title'      => 1,
  'override_title_text' => '',
), 'Page elements');

/**
 * Implementation of hook_PLUGIN_TYPE_content_type_render()
 */
function xdruple_fields_order_defaults_form_content_type_plugin_render($subtype, $conf, $panel_args) {
  $output = '';

  $output .= xdruple_fields_order_defaults_form_block();

  return $output;
}
