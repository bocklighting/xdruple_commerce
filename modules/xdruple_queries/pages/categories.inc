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

  $cats = \Xtuple\XdrupleQueries\Categories\Tree::getCatalog();
  $output .= _xdruple_queries_categories_build_html($cats);

  return $output;
}

/**
 * @return string
 */
function xdruple_queries_categories_tree_block() {
  $output = '';

  if (xdruple_access('products', 'view', 'xtuple: access product lists')) {
    $cats = \Xtuple\XdrupleQueries\Categories\Tree::getCatalog();
    $output .= _xdruple_queries_categories_build_list_group_items($cats['tree'], $cats['catalog']);
  }

  return $output;
}

function _xdruple_queries_categories_build_list_group_items($tree, $catalog) {
  $html = '';

  foreach ($tree as $id => $groups) {
    if ($catalog[$id]->catalog !== TRUE) {
      $html .= '<li>' . l($catalog[$id]->name, "products/categories/$id");
    }
    if (!empty($groups)) {
      $html .= '<ul>' . _xdruple_queries_categories_build_list_group_items($groups, $catalog) . '</ul>';
    }
    if ($catalog[$id]->catalog !== TRUE) {
      $html .= '</li>';
    }
  }

  return $html;
}

/**
 * Build the Product Catalog tree HTML unordered list.
 *
 * @param array $tree The catalog tree/branch to build.
 *
 * @return string The HTML unordered list.
 */
function _xdruple_queries_categories_build_html($tree) {
  $html = '';

  foreach ($tree as $id => $category) {
    /** @var Xtuple\XdrupleQueries\Categories\Category $category */
    $html .= '<li>' . l($category->getName(), 'products/categories/' . $category->getId());
    $children = $category->getChildren(TRUE);
    if (!empty($children)) {
      $html .= '<ul>' . _xdruple_queries_categories_build_html($children) . '</ul>';
    }
    $html .= '</li>';
  }

  return $html;
}
