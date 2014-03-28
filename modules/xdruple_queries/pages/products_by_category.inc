<?php

/**
 * @file keeps callbacks for /products/categories/% page
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

  $params = array(
    'fields' => array(
      'add_to_cart' => array(
        'show_quantity' => FALSE,
      ),
    ),
  );
  drupal_alter(array('product_page_item', 'products_by_category_page_item'), $params);

  $list           = array();
  $product_ids    = array();
  $group_products = entity_load('xtuple_xdrupleitemgroupitem', NULL, array(
    'parentGroup' => $group_id,
  ));
  foreach ($group_products as $item) {
    $product_ids[] = $item->Product;
  }

  if (!empty($product_ids)) {
    $query = new EntityFieldQuery();
    $products = $query->entityCondition('entity_type', 'commerce_product')
      // TODO: nginx seems to max out around 180 products. Then it returns a
      // 414 Request-URI Too Large. Using 50 as a default for now until this
      // is fixed by dev ops.
      ->propertyCondition('product_id', $product_ids, 'ANY')
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
        'params' => $params,
      ));
    }
  }

  $output .= theme('products_page', array(
    'products' => $list,
  ));

  $output .= theme('pager');

  return $output;
}
