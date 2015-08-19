<?php

/**
 * @file keeps callbacks for /products/recent page
 */

/**
 * Page callback
 *
 * @param $limit
 *
 * @return array
 */
function xdruple_recent_products_recent_page($limit) {
  $output = [];
  $output[] = [
    "#theme" => 'xdruple_products_page',
    '#products' => _xdruple_prepare_products_list(
      _xdruple_queries_load_products_by_order_type('xdcatalogrecentorderproduct'),
      $limit
    ),
  ];
  if (empty($_GET["search"])) {
    $output[] = [
      "#theme" => 'pager',
    ];
  }
  return $output;
}
