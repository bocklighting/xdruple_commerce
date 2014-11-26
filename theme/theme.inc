<?php

/**
 * @file keeps theming functions
 */

function template_preprocess_xdruple_commerce_cart_dropdown(&$variables) {
  $variables['link'] = url('cart');
}

function template_preprocess_xdruple_commerce_similar_product_link_default(&$variables) {
  if (!empty($variables['product_id'])) {
    $product = entity_load_single('commerce_product', $variables['product_id']);
    $path = "products/{$variables['product_id']}";

    $variables['title'] = l($product->title, $path);
    if (!empty($product->xt_url_image_field['und'][0])) {
      $image = $product->xt_url_image_field['und'][0];
      $variables['image'] = l(theme('image_style', array(
        'style_name' => $variables['style'],
        'path' => $image['uri'],
        'width' => !empty($image['width']) ? $image['width'] : NULL,
        'height' => !empty($image['height']) ? $image['height'] : NULL,
        'alt' => !empty($image['alt']) ? $image['alt'] : '',
        'title' => !empty($image['title']) ? $image['title'] : '',
      )), $path, array(
        'html' => TRUE,
      ));
    }

    $units = xdruple_fields_get_uom_list();
    $unit = $units[$product->inventoryUnit];
    $variables['unit'] = $unit->description;

    $variables['attributes_array']['class'][] = 'b-product--teaser';
    $variables['title_attributes_array']['class'] = 'b-product-title';
    $variables['thumbnail_attributes_array'] = array(
      'class' => array('b-product-thumbnail'),
    );
  }
}
