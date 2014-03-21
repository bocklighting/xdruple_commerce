<?php

/**
 * @file keeps callbacks for /products/recent page
 */

/**
 * Page callback
 */
function xdruple_queries_products_recent_page() {
  $output = '';

  $list   = array();
  $conditions = array();
  if (!empty($_SESSION['rescued']['ship_to'])) {
    $conditions = array(
      'shipTo' => $_SESSION['rescued']['ship_to'],
    );
  }
  $orders = entity_load('xtuple_xdcatalogrecentord', FALSE, $conditions);
  foreach ($orders as $order) {
    if (!empty($order->products)) {
      foreach ($order->products as $product_id) {
        $list[] = theme('products_page_item', array(
          'product' => entity_load_single('commerce_product', $product_id),
        ));
      }
    }
  }

  $output .= theme('products_page', array(
    'products' => $list,
  ));

  return $output;
}
