<?php

/**
 * @file keeps callbacks for /products page
 */

/**
 * Page callback
 */
function xdruple_queries_products_page() {
  $output = '';

  $params = array(
    'fields' => array(
      'add_to_cart' => array(
        'show_quantity' => FALSE,
      ),
    ),
  );
  drupal_alter(array('product_page_item', 'products_by_category_page_item'), $params);

  $list       = array();
  $query      = new EntityFieldQuery();
  $products   = $query->entityCondition('entity_type', 'commerce_product')
                  ->pager(20)
                  ->execute();
  // TODO: The rescued_entity_field_query_builder(EntityFieldQuery $query)
  // function runs through entity_load to do the actual query. In theory,
  // an EntityFieldQuery() could go directly to the API and then you would
  // call entity_load() for the returned ids which will attach fields, etc.
  // We can skip this call for now. This is one reason why the entity cache
  // and EntityFieldQuery cache need to work together.
  //$products = entity_load('commerce_product', array_keys($products['commerce_product']));

  foreach ($products['commerce_product'] as $product) {
    $list[] = theme('products_page_item', array(
      'product' => $product,
      'params'  => $params,
    ));
  }

  $output .= theme('products_page', array(
    'products' => $list,
  ));

  $output .= theme('pager');

  return $output;
}
