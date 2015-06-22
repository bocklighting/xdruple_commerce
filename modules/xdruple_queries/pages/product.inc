<?php

/**
 * @file keeps callbacks for /products/% page
 */

/**
 * Page callback /products/% page
 *
 * @param $product_id
 *
 * @return array
 */
function xdruple_queries_product_page($product_id) {
  if (!is_numeric($product_id)) {
    drupal_not_found();
    return MENU_NOT_FOUND;
  }
  try {
    $product = entity_load_single("commerce_product", $product_id);
    $output = [
      "#theme" => "product_page",
      "#product" => $product,
    ];
  } catch (\Exception $e) {
    watchdog_exception("xdruple_queries", $e);
    drupal_not_found();
    return MENU_NOT_FOUND;
  }
  return $output;
}

/**
 * Title callback for /products/% page
 *
 * @param $product_id
 *
 * @return string
 */
function xdruple_queries_product_page_title($product_id) {
  $title = "";
  if (is_numeric($product_id)) {
    $product = entity_load_single("commerce_product", $product_id);
    if (!empty($product)) {
      $title = $product->title;
    }
  }
  return $title;
}
