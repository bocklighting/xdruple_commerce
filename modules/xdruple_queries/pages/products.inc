<?php

/**
 * @file keeps callbacks for /products page
 */

/**
 * Page callback
 */
function xdruple_queries_products_page() {
  $output = '';

  $params = [
    'fields' => [
      'add_to_cart' => [
        'show_quantity' => FALSE,
      ],
    ],
  ];
  drupal_alter(['product_page_item', 'products_by_category_page_item'], $params);

  $output .= theme('products_page', [
    'products' => _xdruple_prepare_products_list(NULL, $params),
  ]);

  if (empty($_GET["search"])) {
    $output .= theme('pager');
  }

  return $output;
}
