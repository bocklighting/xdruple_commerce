<?php

/**
 * @file keeps callbacks for /products/recent page
 */

/**
 * Page callback
 */
function xdruple_recent_products_recent_page() {
  $output = [];
  $output[] = [
    "#theme" => 'xdruple_products_page',
    '#products' => _xdruple_prepare_products_list(
      _xdruple_queries_load_products_by_order_type('xdcatalogrecentorderproduct')
    ),
  ];
  if (empty($_GET["search"])) {
    $output[] = [
      "#theme" => 'pager',
    ];
  }
  return $output;
}
