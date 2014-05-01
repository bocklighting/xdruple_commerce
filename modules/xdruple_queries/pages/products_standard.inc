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

  $products_ids = _xdruple_queries_load_products_by_order_type('xdcatalogshiptostdord');
  $list = _xdruple_prepare_products_list($products_ids, $params, 'products_page_item__standard_order');

  $output .= theme('products_page', array(
    'products' => $list,
  ));

  $output .= theme('pager');

  return $output;
}
