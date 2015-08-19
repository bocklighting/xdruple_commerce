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
 * @param                                   $limit
 *
 * @return string
 */
function xdruple_queries_products_by_category_page($group, $limit) {
  $output = [];
  $product_ids = [];
  $group_products = entity_load("xtuple_xdcatalogproduct", NULL, [
    "parentGroup" => $group->getId(),
  ]);
  foreach ($group_products as $item) {
    $product_ids[] = $item->product;
  }
  $output[] = [
    "#theme" => "xdruple_category_page",
    "#category" => \Xtuple\XdrupleQueries\Categories\Tree::buildCategory($group->getId()),
    "#products" => _xdruple_prepare_products_list($product_ids, $limit),
  ];
  if (empty($_GET["search"])) {
    $output[] = [
      "#theme" => "pager",
    ];
  }
  return $output;
}
