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

  $output .= theme('products_page', array(
    'products' => _xdruple_prepare_products_list(NULL, $params),
  ));

  if (empty($_GET["search"])) {
    $output .= theme('pager');
  }

  return $output;
}
