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

  $category = \Xtuple\XdrupleQueries\Categories\Tree::buildCategory($group_id);
  drupal_set_title($category->getName());

  $params = [
    'fields' => [
      'add_to_cart' => [
        'show_quantity' => FALSE,
      ],
    ],
  ];

  drupal_alter([
    'product_page_item',
    'products_by_category_page_item'
  ], $params);

  $product_ids = [];
  $group_products = entity_load('xtuple_xdcatalogproduct', NULL, [
    'parentGroup' => $group_id,
  ]);
  foreach ($group_products as $item) {
    $product_ids[] = $item->product;
  }

  $vars = [
    "category" => $category,
    'products' => _xdruple_prepare_products_list($product_ids, $params),
  ];
  $output .= theme('products_page', $vars);

  if (empty($_GET["search"])) {
    $output .= theme('pager');
  }
  return $output;
}
