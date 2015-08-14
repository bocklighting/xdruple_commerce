<?php

/**
 * @file keeps callbacks for /products page
 */

/**
 * Page callback
 */
function xdruple_queries_products_page() {
  $page = [];
  $page["products"] = [
    "#theme" => "xdruple_products_page",
    "#products" => _xdruple_prepare_products_list(NULL),
  ];
  if (empty($_GET["search"])) {
    $page["pager"] = [
      "#theme" => "pager",
    ];
  }
  return $page;
}
