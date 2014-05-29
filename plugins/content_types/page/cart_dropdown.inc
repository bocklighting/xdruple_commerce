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
  return xdruple_commerce_cart_dropdown_block();
}
