<?php

/**
 * @keeps theme callback
 */

/**
 * Preprocess variables for products-page.tpl.php
 */
function template_preprocess_products_page(&$variables) {
  $products = $variables['products'];

  $column_size = 3;
  $column = array();
  foreach ($products as $i => $product) {
    $column[] = $product;
    if (($i + 1) % $column_size === 0) {
      $variables['columns'][] = $column;
      $column = array();
    }
  }
  if (!empty($column)) {
    $variables['columns'][] = $column;
    unset($column);
  }

  if (!empty($variables['category'])) {
    $category = $variables['category'];
    if (!empty($category->groups)) {
      $catalog = entity_load('xtuple_xdcatalog');
      $subcategories = array();
      foreach ($category->groups as $group_id) {
        if (!empty($catalog[$group_id])) {
          $subcategories[$group_id] = array(
            'data' => l($catalog[$group_id]->name, 'products/categories/' . $group_id),
            'class' => array('col-lg-4'),
          );
        }
      }
      if (!empty($subcategories)) {
        $variables['subcategories'] = theme('item_list', array(
          'items' => $subcategories,
          'attributes' => array('class' => array('row')),
        ));
      }
    }
  }
}

/**
 * Preprocess variables for products-page-item.tpl.php
 */
function template_preprocess_products_page_item(&$variables) {
  $product = $variables['product'];
  $params = $variables['params'];

  $variables['id'] = $product->product_id;
  $variables['price'] = _xdruple_queries_price($product);

  $units = xdruple_fields_get_uom_list();
  $variables['unit'] = $units[$product->inventoryUnit];
  $variables['title'] = l($product->title, "products/{$product->product_id}");
  $variables['subtitle'] = $product->subTitle;
  $variables['img'] = _xdruple_queries_product_image($product, 'ft_commerce_product_thumb');

  if (!empty($params['fields']['add_to_cart'])) {
    $show_qty = FALSE;
    if (!empty($params['fields']['add_to_cart']['show_quantity'])) {
      $show_qty = $params['fields']['add_to_cart']['show_quantity'];
    }

    $qty = 1;
    if (isset($params['fields']['add_to_cart']['qty'])) {
      $qty = $params['fields']['add_to_cart']['qty'];
    }

    $order_id = 0;
    if (isset($params['fields']['add_to_cart']['order_id'])) {
      $order_id = $params['fields']['add_to_cart']['order_id'];
    }
    $variables['add_to_cart'] = _xdruple_queries_add_to_cart_button($product, $show_qty, array(), $qty, $order_id);
  }

  $variables['read_more'] = l('Read more', "products/$product->product_id", array(
    'attributes' => array(
      'class' => array('btn', 'btn-info'),
    ),
  ));
}
