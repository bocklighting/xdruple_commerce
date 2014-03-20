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

  $cats = _xdruple_queries_categories_tree();
  $output .= _core_categories_build_list_group_items($cats['tree'], $cats['catalog']);

  return $output;
}

function _core_categories_build_list_group_items($tree, $catalog) {
  $html = '';

  foreach ($tree as $id => $groups) {
    if ($catalog[$id]->catalog !== TRUE) {
      $html .= '<li>' . l($catalog[$id]->name, "products/categories/$id");
    }
    if (!empty($groups)) {
      $html .= '<ul>' . _core_categories_build_list_group_items($groups, $catalog) . '</ul>';
    }
    if ($catalog[$id]->catalog !== TRUE) {
      $html .= '</li>';
    }
  }

  return $html;
}
