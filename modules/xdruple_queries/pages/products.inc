<?php

/**
 * @file keeps callbacks for /products page
 */

/**
 * Page callback
 */
function xdruple_queries_products_page() {
  $output = '';

  $params = array(
    'fields' => array(
      'add_to_cart' => array(
        'show_quantity' => FALSE,
      ),
    ),
  );
  drupal_alter(array('product_page_item', 'products_by_category_page_item'), $params);

  $list     = array();
  $products = entity_load('commerce_product');
  foreach ($products as $product) {
    $list[] = theme('products_page_item', array(
      'product' => $product,
      'params'  => $params,
    ));
  }

  $output .= theme('products_page', array(
    'products' => $list,
  ));

  return $output;
}
