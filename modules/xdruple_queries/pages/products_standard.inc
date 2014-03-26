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
  $cache      = false;

  if (!empty($_SESSION['rescued']['ship_to'])) {
    $conditions = array(
      'shipTo' => $_SESSION['rescued']['ship_to'],
    );
    $cid = 'xdruple_xdcatalogshiptostdord-' . $_SESSION['rescued']['ship_to'];
    $cache = cache_get($cid, 'cache');
  }

  if (empty($cache)) {
    $orders = entity_load('xtuple_xdcatalogshiptostdord', FALSE, $conditions);
    if (!empty($_SESSION['rescued']['ship_to'])) {
      cache_set($cid, $orders, 'cache', CACHE_TEMPORARY);
    }
  } else {
    $orders = $cache->data;
  }

  // TODO: Add pager support.
  foreach ($orders as $order) {
    if (!empty($order->products)) {
      $prod_conditions = array(
        'query' => array(
          'product_id' => array(
            // TODO: Implement pager request. Node.js seems to max out around
            //  180 products. Using 50 as a default for now.
            'ANY' => array_slice($order->products, 0, 50),
          ),
        ),
      );
      $products = entity_load('xtuple_xdruplecommerceproduct', FALSE, $prod_conditions);
      foreach ($products as $product) {
        $list[] = theme('products_page_item__standard_order', array(
          'product' => $product,
          'params' => $params,
        ));
      }
    }
  }

  $output .= theme('products_page', array(
    'products' => $list,
  ));

  return $output;
}
