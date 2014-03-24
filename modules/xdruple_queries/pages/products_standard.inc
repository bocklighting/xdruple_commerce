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
  drupal_alter(array('product_page_item', 'products_by_category_page_item'), $params);

  $list       = array();
  $conditions = array();
  if (!empty($_SESSION['rescued']['ship_to'])) {
    $conditions = array(
      'shipTo' => $_SESSION['rescued']['ship_to'],
    );
  }
  $orders = entity_load('xtuple_xdcatalogshiptostdord', FALSE, $conditions);
  foreach ($orders as $order) {
    if (!empty($order->products)) {
      foreach ($order->products as $product_id) {
        $list[] = theme('products_page_item__standard_order', array(
          'product' => entity_load_single('commerce_product', $product_id),
          'params'  => $params,
        ));
      }
    }
  }

  $output .= theme('products_page', array(
    'products' => $list,
  ));

  return $output;
}
