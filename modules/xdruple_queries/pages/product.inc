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

    return MENU_NOT_FOUND;
  }

  $output = '';

  if (user_access('administer rescued entities')) {
    $output .= theme('bootstrap_pills', array(
      'items' => array(
        array(
          'title' => t('Edit'),
          'link' => "admin/commerce/products/$product_id/edit",
        ),
      ),
    ));
  }

  $product = entity_load_single('commerce_product', $product_id);

  if (!empty($product)) {
    drupal_set_title($product->title);
    /** @var array $product_render */
    $product_render = entity_view('commerce_product', array($product), 'full', NULL, TRUE);
    if (!empty($product_render)) {
      $product_render['commerce_product'][$product_id]['product_price'] = array(
        '#markup' => _xdruple_queries_price($product),
        '#weight' => 20,
      );
      $product_render['commerce_product'][$product_id]['add_to_cart'] = array(
        '#markup' => _xdruple_queries_add_to_cart_button($product, TRUE, array(
          'commerce_product_page' => TRUE,
        )),
        '#weight' => 20,
      );
    }
    $output .= drupal_render($product_render);
  }
  else {
    drupal_not_found();
  }

  return $output;
}

function xdruple_queries_product_page_title($product_id) {
  $title = '';

  if (is_numeric($product_id)) {
    $product = entity_load_single('commerce_product', $product_id);
    if (!empty($product)) {
      $title = $product->title;
    }
  }

  return $title;
}

function xdruple_queries_node_view_alter(&$build) {

}
