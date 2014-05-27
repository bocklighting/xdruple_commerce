<?php

/**
 * @file keeps callbacks for /products/categories page
 */

/**
 * Get the formatted Product Catalog page.
 *
 * @return string The Product Catalog page's HTML unordered list.
 */
function xdruple_queries_categories_page() {
  $output = '';

  $cats = _xdruple_queries_categories_tree();
  $output .= _xdruple_queries_categories_build_html($cats['tree'], $cats['catalog']);

  return $output;
}

/**
 * Get the Product Catalog tree.
 *
 * @return array The Product Catalog tree array and an array of all Product
 *   Catalog branches.
 */
function _xdruple_queries_categories_tree() {
  $cid = 'xtuple_xdruplecatalog-tree';
  $cache = cache_get($cid, 'cache');

  if (empty($cache)) {
    $query = new EntityFieldQuery();
    $root_group = $query->entityCondition('entity_type', 'xtuple_xdruplecatalog')
                        ->propertyCondition('catalog', true, '=')
                        ->execute();

    if (empty($root_group['xtuple_xdruplecatalog'])) {
      drupal_set_message(t('Catalog structure not set. Contact the site administrator.'), 'error');
      return array('tree' => array(), 'catalog' => array());
    }

    $root_key = key($root_group['xtuple_xdruplecatalog']);

    $tree = array(
      $root_key => array(),
    );
    $catalog = array();

    if (!empty($tree)) {
      _xdruple_queries_categories_build_tree($tree, $catalog);
    }

    $cache_data = array(
      'tree'    => $tree,
      'catalog' => $catalog
    );

    cache_set($cid, $cache_data, 'cache', CACHE_TEMPORARY);
  } else {
    $cache_data = $cache->data;
  }

  return $cache_data;
}

/**
 * Build the Product Catalog tree up from it's root id.
 *
 * @param array $tree The catalog tree/branch to build.
 * @param arrat $catalog An array of all Product Catalog branches.
 */
function _xdruple_queries_categories_build_tree(&$tree, &$catalog) {
  foreach ($tree as $id => $temp) {
    $group = entity_load_single('xtuple_xdruplecatalog', $id);
    $catalog[$id] = $group;

    foreach ($group->groups as $group_id) {
      $tree[$id][$group_id] = array();
    }

    _xdruple_queries_categories_build_tree($tree[$id], $catalog);
  }
}

/**
 * Build the Product Catalog tree HTML unordered list.
 *
 * @param array $tree The catalog tree/branch to build.
 * @param arrat $catalog An array of all Product Catalog branches.
 *
 * @return string The HTML unordered list.
 */
function _xdruple_queries_categories_build_html($tree, $catalog) {
  $html = '';

  foreach ($tree as $id => $groups) {
    if ($catalog[$id]->catalog !== TRUE) {
      $html .= '<li>' . l($catalog[$id]->name, "products/categories/$id");
    }
    if (!empty($groups)) {
      $html .= '<ul>' . _xdruple_queries_categories_build_html($groups, $catalog) . '</ul>';
    }
    if ($catalog[$id]->catalog !== TRUE) {
      $html .= '</li>';
    }
  }

  return $html;
}
