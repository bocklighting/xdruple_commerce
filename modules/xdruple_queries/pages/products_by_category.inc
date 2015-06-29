<?php

/**
 * @file keeps callbacks for /products/categories/% page
 */

/**
 * @param $group_id
 *
 * @return bool|mixed
 */
function xdruple_queries_category_load($group_id) {
  $category = FALSE;
  if (is_numeric($group_id)) {
    try {
      $category = entity_load_single("xtuple_xdcatalog", $group_id);
    } catch (\Exception $e) {
      watchdog_exception("xdruple_queries", $e);
    }
  }
  return $category;
}

/**
 * Title callback for /products/categories/% page
 *
 * @param $group
 *
 * @return mixed
 */
function xdruple_queries_products_by_category_page_title($group) {
  return $group->name;
}

/**
 * Page callback
 *
 * @param \Xtuple\Rescued\Controller\Entity $group
 *
 * @return string
 */
function xdruple_queries_products_by_category_page($group) {
  $output = "";

  $category = \Xtuple\XdrupleQueries\Categories\Tree::buildCategory($group->getId());
  $params = [
    "fields" => [
      "add_to_cart" => [
        "show_quantity" => FALSE,
      ],
    ],
  ];

  drupal_alter([
    "product_page_item",
    "products_by_category_page_item"
  ], $params);

  $product_ids = [];
  $group_products = entity_load("xtuple_xdcatalogproduct", NULL, [
    "parentGroup" => $group->getId(),
  ]);
  foreach ($group_products as $item) {
    $product_ids[] = $item->product;
  }

  $vars = [
    "category" => $category,
    "products" => _xdruple_prepare_products_list($product_ids, $params),
  ];
  $output .= theme("products_page", $vars);

  if (empty($_GET["search"])) {
    $output .= theme("pager");
  }
  return $output;
}
