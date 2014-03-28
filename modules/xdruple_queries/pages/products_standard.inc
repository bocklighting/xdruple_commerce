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

  foreach ($orders as $order) {
    if (!empty($order->products)) {
      $query = new EntityFieldQuery();
      $products = $query->entityCondition('entity_type', 'commerce_product')
        // TODO: nginx seems to max out around 180 products. Then it returns a
        // 414 Request-URI Too Large. Using 50 as a default for now until this
        // is fixed by dev ops.
        ->propertyCondition('product_id', array_slice($order->products, 0, 50), 'ANY')
        ->pager(20)
        ->execute();

      // TODO: The rescued_entity_field_query_builder(EntityFieldQuery $query)
      // function runs through entity_load to do the actual query. In theory,
      // an EntityFieldQuery() could go directly to the API and then you would
      // call entity_load() for the returned ids which will attach fields, etc.
      // We can skip this call for now. This is one reason why the entity cache
      // and EntityFieldQuery cache need to work together.
      //$products = entity_load('commerce_product', array_keys($products['commerce_product']));

      foreach ($products['commerce_product'] as $product) {
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

  $output .= theme('pager');

  return $output;
}
