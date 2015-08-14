<?php

/**
 * @file keeps callbacks for /products/favorites page
 */

/**
 * Page callback
 *
 * @see xdruple_favorites_menu()
 */
function xdruple_favorites_favorite_products_page() {
  $output = [];
  $output[] = [
    "#theme" => 'xdruple_products_page',
    'products' => _xdruple_prepare_products_list(
      _xdruple_queries_load_products_by_order_type('xdcatalogshiptostandardorder')
    ),
  ];
  if (empty($_GET["search"])) {
    $output[] = [
      "#theme" => 'pager',
    ];
  }
  return $output;
}
