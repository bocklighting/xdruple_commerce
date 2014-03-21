<?php

/**
 * @file keeps callbacks for /products page
 */

/**
 * Page callback
 */
function xdruple_queries_products_page() {
  $output = '';

  $list   = array();
  $products = entity_load('commerce_product');
  foreach ($products as $product) {
    $list[] = theme('products_page_item', array(
      'product' => $product,
    ));
  }

  $output .= theme('products_page', array(
    'products' => $list,
  ));

  return $output;
}
