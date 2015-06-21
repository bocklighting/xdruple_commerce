<?php

/**
 * @keeps theme callback
 */

/**
 * Preprocess variables for products-page.tpl.php
 *
 * @param $variables
 *
 * @throws \Exception
 */
function template_preprocess_products_page(&$variables) {
  $products = $variables['products'];

  $column_size = 3;
  $column = [];
  foreach ($products as $i => $product) {
    $column[] = $product;
    if (($i + 1) % $column_size === 0) {
      $variables['columns'][] = $column;
      $column = [];
    }
  }
  if (!empty($column)) {
    $variables['columns'][] = $column;
    unset($column);
  }

  if (!empty($variables['category'])) {
    /** @var \Xtuple\XdrupleQueries\Categories\Category $category */
    $category = $variables['category'];
    if (!empty($category->getChildren())) {
      $cid = 'xtuple_xdcatalog-flat';
      $cache = cache_get($cid, 'cache');
      $entity_info = entity_get_info('xtuple_xdcatalog');

      if ((empty($cache) || xdruple_cache_expired($cache)) && !empty($entity_info)) {
        $query = new EntityFieldQuery();
        $count = $query->entityCondition('entity_type', 'xtuple_xdcatalog')
                       ->count()
                       ->execute();

        if ($count <= 100) {
          $xd_catalogs = entity_load('xtuple_xdcatalog');
        }
        else {
          // Paginate through all catalogs.
          $pages = ceil($count / 100);
          $xd_catalogs = [];

          $i = 0;
          while ($i < $pages) {
            $page_query = new EntityFieldQuery();
            $catalogs = $page_query->entityCondition('entity_type', 'xtuple_xdcatalog')
                                   ->range($i * 100, 100)
                                   ->propertyOrderBy('id', 'ASC')
                                   ->execute();

            $xd_catalogs = $xd_catalogs + $catalogs['xtuple_xdcatalog'];
            $i++;
          }
        }
        cache_set($cid, $xd_catalogs, 'cache', REQUEST_TIME + 60 * 60 * 1);
      }
      else {
        if (!$cache || empty($cache->data)) {
          $xd_catalogs = [];
        }
        else {
          $xd_catalogs = $cache->data;
        }
      }

      $subcategories = [];
      foreach ($category->getChildren() as $child) {
        if (!empty($xd_catalogs[$child->getId()])) {
          $subcategories[$child->getId()] = [
            'data' => l($xd_catalogs[$child->getId()]->name, 'products/categories/' . $child->getId()),
            "title" => $xd_catalogs[$child->getId()]->name,
            "url" => 'products/categories/' . $child->getId(),
            'class' => ['col-lg-4'],
          ];
        }
      }
      if (!empty($subcategories)) {
        $variables["subcategories"] = [
          "#theme" => "item_list",
          "#items" => $subcategories,
          "#attributes" => [
            "class" => [
              "row" => "row"
            ],
          ],
        ];
      }
    }
  }
}

function template_process_products_page(&$variables) {
  if (!empty($variables["subcategories"])) {
    $variables["subcategories"] = drupal_render($variables["subcategories"]);
  }
}

/**
 * Preprocess variables for products-page-item.tpl.php
 *
 * @param $variables
 */
function template_preprocess_products_page_item(&$variables) {
  $product = $variables['product'];
  $params = $variables['params'];

  $variables['id'] = $product->product_id;
  $units = xdruple_fields_get_uom_list();
  $variables['unit'] = $units[$product->inventoryUnit];
  $variables['price'] = [
    "#theme" => "xdruple_queries_price",
    "#product" => $product,
    "#label" => "",
  ];
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
    $variables['add_to_cart'] = [
      "#theme" => "xdruple_queries_add_to_cart_button",
      "#product" => $product,
      "#show_quantity" => $show_qty,
      "#context" => [],
      "#quantity" => $qty,
      "#order_id" => $order_id,
    ];
  }

  $variables['read_more'] = l('Read more', "products/$product->product_id", [
    'attributes' => [
      'class' => ['btn', 'btn-info'],
    ],
  ]);
}

function template_process_products_page_item(&$variables) {
  if (!empty($variables["unit_price"])) {
    $variables["unit_price"] = drupal_render($variables["unit_price"]);
  }
  if (!empty($variables["price"])) {
    $variables["price"] = drupal_render($variables["price"]);
  }
  if (!empty($variables["add_to_cart"])) {
    $variables["add_to_cart"] = drupal_render($variables["add_to_cart"]);
  }
}

function template_preprocess_xdruple_queries_price(&$variables) {
  $uom_ratio = 1;
  if ($variables["unit_price"]) {
    $uom_ratio = $variables["product"]->uomRatio;
  }
  $variables["price"] = _xdruple_queries_price($variables["product"], $variables["quantity"], $variables["order_id"], $variables["format"], $uom_ratio);
  if ($variables["show_unit"]) {
    if ($variables["unit_price"]) {
      $unit = $variables["product"]->priceUnit;
    }
    else {
      $unit = $variables["product"]->inventoryUnit;
    }
    $units = xdruple_fields_get_uom_list();
    $variables["unit"] = $units[$unit];
  }
}

function template_process_xdruple_queries_price(&$variables) {
  if ($variables["label"]) {
    $variables["label"] = t($variables["label"]);
  }
}

function template_preprocess_xdruple_queries_add_to_cart_button(&$variables) {
}

function template_process_xdruple_queries_add_to_cart_button(&$variables) {
}

function theme_xdruple_queries_add_to_cart_button(&$variables) {
  return _xdruple_queries_add_to_cart_button(
    $variables["product"],
    $variables["show_quantity"],
    $variables["context"],
    $variables["quantity"],
    $variables["order_id"]
  );
}
