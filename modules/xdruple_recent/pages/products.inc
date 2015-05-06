<?php

/**
 * @file keeps callbacks for /products/recent page
 */

/**
 * Page callback
 */
function xdruple_recent_products_recent_page() {
  $output = '';

  $params = array(
    'fields' => array(
      'add_to_cart' => array(
        'show_quantity' => FALSE,
      ),
    ),
  );
  drupal_alter(array('product_page_item', 'products_recent_page_item'), $params);

  $products_ids = _xdruple_queries_load_products_by_order_type('xdcatalogrecentord');
  $list = _xdruple_prepare_products_list($products_ids, $params, 'products_page_item');

  $output .= theme('products_page', array(
    'products' => $list,
  ));

  if (empty($_GET["search"])) {
    $output .= theme('pager');
  }
  
  return $output;
}
