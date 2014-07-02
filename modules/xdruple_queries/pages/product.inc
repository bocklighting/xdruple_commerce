<?php

/**
 * @file keeps callbacks for /products/% page
 */

/**
 * Page callback
 *
 * @param $product_id
 *
 * @return string
 */
function xdruple_queries_product_page($product_id) {
  if (!is_numeric($product_id)) {
    drupal_not_found();
  }

  $output = '';

  if (user_access('administer rescued entities')) {
    $output .= theme('bootstrap_pills', array(
      'items' => array(
        array(
          'title' => t('Edit'),
          'link'  => "admin/commerce/products/$product_id/edit",
        ),
      ),
    ));
  }

  $product = entity_load_single('commerce_product', $product_id);

  if (!empty($product)) {
    $product_render = entity_view('commerce_product', array($product));
    $output .= drupal_render($product_render);
  }
  else {
    drupal_not_found();
  }

  return $output;
}

function xdruple_queries_product_page_title($product_id) {
  $title = '';

  $product = entity_load_single('commerce_product', $product_id);
  if (!empty($product)) {
    $title = $product->title;
  }

  return $title;
}

function xdruple_queries_node_view_alter(&$build) {

}
