<?php

/**
 * @file keeps callbacks for /products/recent page
 */

/**
 * Page callback
 */
function xdruple_recent_products_recent_page() {
  $output = [];
  $params = [
    'fields' => [
      'add_to_cart' => [
        'show_quantity' => FALSE,
      ],
    ],
  ];
  drupal_alter(['product_page_item', 'products_recent_page_item'], $params);
  $products_ids = _xdruple_queries_load_products_by_order_type('xdcatalogrecentorderproduct');
  $list = _xdruple_prepare_products_list($products_ids, $params, FALSE);
  $output[] = [
    "#theme" => 'xdruple_products_page',
    '#products' => $list,
  ];
  if (empty($_GET["search"])) {
    $output[] = [
      "#theme" => 'pager',
    ];
  }
  return $output;
}
