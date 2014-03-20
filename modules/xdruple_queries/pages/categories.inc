<?php

/**
 * @file keeps callbacks for /products/categories page
 */

function xdruple_queries_categories_page() {
  $output = '';

  $cats = _xdruple_queries_categories_tree();
  $output .= _xdruple_queries_categories_build_html($cats['tree'], $cats['catalog']);

  return $output;
}

function _xdruple_queries_categories_tree() {
  $catalog = entity_load('xtuple_xdruplecatalog');

  // Lookup for root group
  $tree = array();
  foreach ($catalog as $group) {
    if ($group->catalog === TRUE) {
      $tree = array(
        $group->id => array(),
      );
      break;
    }
  }

  if (!empty($tree)) {
    _xdruple_queries_categories_build_tree($tree, $catalog);
  }

  return array(
    'tree'    => $tree,
    'catalog' => $catalog,
  );
}

function _xdruple_queries_categories_build_tree(&$group, $catalog) {
  foreach ($group as $id => $temp) {
    if (!empty($catalog[$id]->groups)) {
      foreach ($catalog[$id]->groups as $group_id) {
        $group[$id][$group_id] = array();
      }
      _xdruple_queries_categories_build_tree($group[$id], $catalog);
    }
  }
}

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

