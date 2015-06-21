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
  if ($product = entity_load_single("commerce_product", $product_id)) {
    /** @var array $output */
    if ($output = entity_view("commerce_product", [$product], "full", NULL, TRUE)) {
      $output["commerce_product"][$product_id]["product_price"] = [
        "#markup" => _xdruple_queries_price($product),
        "#weight" => 20,
      ];
      $output["commerce_product"][$product_id]["add_to_cart"] = [
        "#markup" => _xdruple_queries_add_to_cart_button($product, TRUE, [
          "commerce_product_page" => TRUE,
        ]),
        "#weight" => 20,
      ];
    }
    else {
      $output = [];
    }
  }
  else {
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
