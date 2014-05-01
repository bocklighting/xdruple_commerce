<?php

/**
 * @file keeps callbacks for /products/standard page
 */

/**
 * Page callback
 */
function xdruple_queries_products_standard_page() {
  $output = '';

  $params = array(
    'fields' => array(
      'add_to_cart' => array(
        'show_quantity' => FALSE,
      ),
    ),
  );
  drupal_alter(array('product_page_item', 'products_standard_page_item'), $params);

  $list   = array();
  $orders = _xdruple_queries_load_orders('xdcatalogshiptostdord');
  foreach ($orders as $order) {
    $list = _xdruple_prepare_products_list($order->products, $params, 'products_page_item__standard_order');
  }

  $output .= theme('products_page', array(
    'products' => $list,
  ));

  $output .= theme('pager');

  return $output;
}
