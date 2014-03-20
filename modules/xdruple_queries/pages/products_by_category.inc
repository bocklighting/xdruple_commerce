<?php

/**
 * @file keeps callbacks for products/categories/% page
 */

/**
 * Page callback
 *
 * @param $group_id
 *
 * @return string
 */
function xdruple_queries_products_by_category_page($group_id) {
  $output = '';

  $catalog = entity_load('xtuple_xdruplecatalog');
  foreach ($catalog as $cat) {
    if ($cat->id == $group_id) {
      drupal_set_title($cat->name);
      break;
    }
  }

  $list           = array();
  $group_products = entity_load('xtuple_xdrupleitemgroupitem', NULL, array(
    'parentGroup' => $group_id,
  ));
  foreach ($group_products as $item) {
    $product = entity_load_single('commerce_product', $item->Product);

    $list[] = theme('products_page_item', array(
      'id'          => $product->product_id,
      'price'       => commerce_currency_format($product->commerce_price['und'][0]['amount'], $product->commerce_price['und'][0]['currency_code']),
      'title'       => l($product->title, "products/{$product->product_id}"),
      'subtitle'    => $product->subTitle,
      'img'         => _xdruple_queries_product_image($product, 'ft_commerce_product_thumb'),
      'add_to_cart' => _xdruple_queries_add_to_cart_button($product),
      'read_more'   => l('Read more', "products/$product->product_id", array(
        'attributes' => array(
          'class' => array('btn', 'btn-info'),
        ),
      )),
    ));
  }

  $output .= theme('products_page', array(
    'products' => $list,
  ));

  return $output;
}

/**
 * Helper function to build "Add to cart" button
 */
function _xdruple_queries_add_to_cart_button($product) {
  $product_ids = array($product->product_id);
  $form_id     = commerce_cart_add_to_cart_form_id($product_ids);

  $line_item                                         = commerce_product_line_item_new($product, 1, 0, array(), NULL);
  $line_item->data['context']['product_ids']         = $product_ids;
  $line_item->data['context']['add_to_cart_combine'] = TRUE;

  return drupal_render(drupal_get_form($form_id, $line_item, FALSE, array()));
}

/**
 * Helper function to build Image field
 */
function _xdruple_queries_product_image($product, $style = '') {
  $img = !empty($product->field_product_image['und'][0]['uri']) ? l(theme('image_style', array(
    'style_name' => $style,
    'path'       => $product->field_product_image['und'][0]['uri'],
  )), "products/{$product->product_id}", array(
    'html' => TRUE,
  )) : '';

  return $img;
}
