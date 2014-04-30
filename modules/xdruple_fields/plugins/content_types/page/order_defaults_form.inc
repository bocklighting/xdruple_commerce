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

  global $user;
  if (xdruple_fields_user_preferences_access($user)) {
    $form = drupal_get_form('xtuple_order_defaults_form');
    $output .= drupal_render($form);
  }

  return $output;
}
