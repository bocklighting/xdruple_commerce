<?php

/**
 * @file keeps callbacks for /products page
 */

/**
 * Page callback
 *
 * @param int $limit
 *
 * @return array
 */
function xdruple_queries_products_page($limit) {
  $page = [];
  $page["products"] = [
    "#theme" => "xdruple_products_page",
    "#products" => _xdruple_prepare_products_list(NULL, $limit),
  ];
  if (empty($_GET["search"])) {
    $page["pager"] = [
      "#theme" => "pager",
    ];
  }
  return $page;
}
