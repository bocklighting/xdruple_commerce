<?php

/**
 * @file keeps callbacks for /products/% page
 */

/**
 * @param $product_id
 *
 * @return bool|mixed
 */
function xdruple_queries_product_load($product_id) {
  $product = FALSE;
  if (is_numeric($product_id)) {
    try {
      $product = entity_load_single("commerce_product", $product_id);
    } catch (\Exception $e) {
      watchdog_exception("xdruple_queries", $e);
    }
  }
  return $product;
}

/**
 * Page callback /products/% page
 *
 * @param $product
 *
 * @return array
 */
function xdruple_queries_product_page($product) {
  $output = [
    "#theme" => "xdruple_product_page",
    "#product" => $product,
  ];
  return $output;
}

/**
 * Title callback for /products/% page
 *
 * @param \Xtuple\Rescued\Controller\Entity $product
 *
 * @return string
 */
function xdruple_queries_product_page_title($product) {
  $title = $product->get("title");
  if ($product->get("marketingTitle")) {
    $title = $product->get("marketingTitle");
  }
  return $title;
}
