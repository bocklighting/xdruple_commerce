<?php

/**
 * @file CTools content type plugin for Categories tree
 */
$plugin = extensions_content_type_plugin('xdruple_queries', 'categories', 'Categories tree', array(
  'description' => '',
  'css'         => array(),
), array(
  'override_title'      => 1,
  'override_title_text' => 'Categories',
), 'Page elements');

/**
 * Implementation of hook_PLUGIN_TYPE_content_type_render()
 */
function xdruple_queries_categories_content_type_plugin_render($subtype, $conf, $panel_args) {
  $output = '';

  $output .= xdruple_queries_categories_tree_block($output);

  return $output;
}
