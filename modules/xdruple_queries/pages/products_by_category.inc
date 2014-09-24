<?php

/**
 * @file keeps callbacks for /products/categories/% page
 */

/**
 * Page callback
 *
 * @param $group_id
 *
 * @return string
 */
function xdruple_queries_products_by_category_page($group_id) {
  $output = '';

  $catalog = entity_load('xtuple_xdcatalog');
  foreach ($catalog as $cat) {
    if ($cat->id == $group_id) {
      drupal_set_title($cat->name);
      break;
    }
  }

  $params = array(
    'fields' => array(
      'add_to_cart' => array(
        'show_quantity' => FALSE,
      ),
    ),
  );

  drupal_alter(array(
    'product_page_item',
    'products_by_category_page_item'
  ), $params);

  $product_ids = array();
  $group_products = entity_load('xtuple_xdcatalogproduct', NULL, array(
    'parentGroup' => $group_id,
  ));
  foreach ($group_products as $item) {
    $product_ids[] = $item->product;
  }

  $vars = array(
    'products' => _xdruple_prepare_products_list($product_ids, $params),
  );
  if (!empty($cat)) {
    $vars['category'] = $cat;
  }
  $output .= theme('products_page', $vars);

  $output .= theme('pager');

  return $output;
}
