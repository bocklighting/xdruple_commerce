<?php

/**
 * @file keeps callbacks for /products page
 */

/**
 * Page callback
 */
function xdruple_queries_products_page() {
  $page = [];
  $params = [
    'fields' => [
      'add_to_cart' => [
        'show_quantity' => FALSE,
      ],
    ],
  ];
  drupal_alter(['product_page_item', 'products_by_category_page_item'], $params);
  $products = _xdruple_prepare_products_list(NULL, $params, FALSE);
  $page["products"] = [
    "#theme" => "xdruple_products_page",
    "#products" => $products,
  ];
  if (empty($_GET["search"])) {
    $page["pager"] = [
      "#theme" => "pager",
    ];
  }
  return $page;
}
