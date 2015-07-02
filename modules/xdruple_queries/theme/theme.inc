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
  $variables['unit'] = xdruple_get_unit_by_code($product->inventoryUnit);
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
  /** @var \stdClass $line_item */
  $line_item = commerce_product_line_item_new($variables["product"], $variables["quantity"], $variables["order_id"], [], NULL);
  xdruple_commerce_get_customer_line_item_price($line_item);
  $unit_price = $line_item->commerce_unit_price[LANGUAGE_NONE][0];
  if ($variables["format"]) {
    $price = commerce_currency_format($unit_price["amount"] / $uom_ratio, $unit_price["currency_code"]);
  }
  else {
    $price = $unit_price["amount"] / $uom_ratio;
  }
  $variables["price"] = $price;
  if ($variables["show_unit"]) {
    if ($variables["unit_price"]) {
      $unit = $variables["product"]->priceUnit;
    }
    else {
      $unit = $variables["product"]->inventoryUnit;
    }
    $variables["unit"] = xdruple_get_unit_by_code($unit);
  }
}

function template_process_xdruple_queries_price(&$variables) {
  if ($variables["label"]) {
    $variables["label"] = t($variables["label"]);
  }
}

function template_preprocess_xdruple_queries_add_to_cart_button(&$variables) {
  $product = $variables["product"];
  $product_ids = [
    $product->product_id,
  ];
  $form_id = commerce_cart_add_to_cart_form_id($product_ids);
  /** @var \stdClass $line_item */
  $line_item = commerce_product_line_item_new($product, $variables["quantity"], $variables["order_id"], []);
  $line_item->data["context"]["product_ids"] = $product_ids;
  $line_item->data["context"]["add_to_cart_combine"] = TRUE;
  $variables["line_item"] = $line_item;
  $variables["form"] = drupal_get_form($form_id, $line_item, $variables["show_quantity"], $variables["context"]);
}

function template_process_xdruple_queries_add_to_cart_button(&$variables) {
}

function theme_xdruple_queries_add_to_cart_button(&$variables) {
  return drupal_render($variables["form"]);
}

function template_preprocess_product_page(&$variables) {
  if (!empty($variables["product"])) {
    /** @var \Xtuple\Rescued\Controller\Entity $product */
    $product = $variables["product"];
    $variables["content"] = [];
    $variables["content"]["illustrations"] = [
      "#theme" => "xdruple_product_illustrations",
      "#product" => $product,
      "#thumbnail_style" => "ft_commerce_product_page_thumb",
      "#thumbnail_small_style" => "ft_commerce_product_page_thumb_small",
      "#full_image_style" => "large",
      "#weight" => -20,
    ];
    $variables["content"]["product_price"] = [
      "#theme" => "xdruple_queries_price",
      "#product" => $product,
      "#show_unit" => TRUE,
      "#weight" => -10,
    ];
    $variables["content"]["description"] = [
      "#theme" => "xdruple_product_description",
      "#product" => $product,
      "#weight" => 0,
    ];
    $variables["content"]["files"] = [
      "#theme" => "xdruple_product_files",
      "#product" => $product,
      "#weight" => 10,
    ];
    $variables["content"]["links"] = [
      "#theme" => "xdruple_product_links",
      "#product" => $product,
      "#weight" => 20,
    ];
    $variables["actions"] = [];
    $variables["actions"]["add_to_cart"] = [
      "#theme" => "xdruple_queries_add_to_cart_button",
      "#product" => $product,
      "#show_quantity" => TRUE,
      "#context" => [
        "commerce_product_page" => TRUE,
      ],
      "#weight" => -10,
    ];
    $variables["details"] = [];
    $variables["details"]["delivery"] = [
      "#theme" => "xdruple_product_delivery",
      "#product" => $product,
      "#weight" => -20,
    ];
    $variables["details"]["characteristics"] = [
      "#theme" => "xdruple_product_characteristics",
      "#product" => $product,
      "#weight" => -10,
    ];
    $variables["details"]["substitutes"] = [
      "#theme" => "xdruple_product_substitutes",
      "#product" => $product,
      "#weight" => 0,
    ];
  }
}

function template_process_product_page(&$variables) {
  if (!empty($variables["product"])) {
    /** @var \Xtuple\Rescued\Controller\Entity $product */
    $product = $variables["product"];
    if ($product->get("marketingSeoKeywords")) {
      drupal_add_html_head([
        "#type" => "html_tag",
        "#tag" => "meta",
        "#attributes" => [
          "name" => "keywords",
          "content" => $product->get("marketingSeoKeywords"),
        ],
      ], "xdruple_product_keywords");
    }
    if ($product->get("marketingTeaser")) {
      drupal_add_html_head([
        "#type" => "html_tag",
        "#tag" => "meta",
        "#attributes" => [
          "name" => "description",
          "content" => $product->get("marketingTeaser"),
        ],
      ], "xdruple_product_description");
    }
  }
}

function template_preprocess_xdruple_product_description(&$variables) {
  if (!empty($variables["product"])) {
    /** @var \Xtuple\Rescued\Controller\Entity $product */
    $product = $variables["product"];
  }
}

function template_process_xdruple_product_description(&$variables) {
}

function template_preprocess_xdruple_product_illustrations(&$variables) {
  if (!empty($variables["product"])) {
    /** @var \Xtuple\Rescued\Controller\Entity $product */
    $product = $variables["product"];
    $images = $product->get("xt_url_image_field");
    if (!empty($images["und"])) {
      $variables["images"] = [];
      $class = drupal_clean_css_identifier(strtr("fancybox--xdruple-product-illustrations--product-%id", [
        "%id" => $product->getId(),
      ]));
      foreach ($images["und"] as $i => $image) {
        $variables["images"][] = [
          "#theme" => "fancybox_formatter_default",
          "#settings" => [
            "preview" => $i == 0 ? $variables["thumbnail_style"] : $variables["thumbnail_small_style"],
            "full" => $variables["full_image_style"],
            "cyclic" => TRUE,
            "title_show" => TRUE,
            "title_position" => "over",
          ],
          "#item" => [
            "path" => $image["uri"],
            "width" => !empty($image["width"]) ? $image["width"] : NULL,
            "style" => !empty($image["height"]) ? $image["height"] : NULL,
            "alt" => !empty($image["alt"]) ? $image["alt"] : "",
            "title" => !empty($image["title"]) ? $image["title"] : "",
          ],
          "#rel" => $class,
          "#classes" => [
            "img-thumbnail" => "img-thumbnail",
          ],
        ];
      }
    }
  }
}

function template_process_xdruple_product_illustrations(&$variables) {
}

function template_preprocess_xdruple_product_files(&$variables) {
  if (!empty($variables["product"])) {
    /** @var \Xtuple\Rescued\Controller\Entity $product */
    $product = $variables["product"];
    $files = $product->get("xt_url_file_field");
    if (!empty($files["und"])) {
      $variables["files"] = [];
      foreach ($files["und"] as $file) {
        $variables["files"][] = [
          "#theme" => "file_link",
          "#file" => (object) $file,
        ];
      }
    }
  }
  $variables["classes_array"]["panel"] = "panel";
  $variables["classes_array"]["panel-default"] = "panel-default";
}

function template_process_xdruple_product_files(&$variables) {
}

function template_preprocess_xdruple_product_links(&$variables) {
  if (!empty($variables["product"])) {
    /** @var \Xtuple\Rescued\Controller\Entity $product */
    $product = $variables["product"];
    $links = $product->get("xt_url_link_field");
    if (!empty($links["und"])) {
      $variables["links"] = [];
      foreach ($links["und"] as $link) {
        $variables["links"][] = [
          "#theme" => "link",
          "#text" => $link["title"],
          "#path" => $link["url"],
          "#options" => [
            "html" => FALSE,
            "attributes" => [],
          ],
        ];
      }
    }
  }
  $variables["classes_array"]["panel"] = "panel";
  $variables["classes_array"]["panel-default"] = "panel-default";
}

function template_process_xdruple_product_links(&$variables) {
}

function template_preprocess_xdruple_product_delivery(&$variables) {
  if (!empty($variables["product"])) {
    /** @var \Xtuple\Rescued\Controller\Entity $product */
    $product = $variables["product"];
    $variables["data"] = [
      "product_dimensions" => [
        "#theme" => "xdruple_dimensions",
        "#title" => "Product dimensions",
        "#length" => $product->get("productLength"),
        "#width" => $product->get("productWidth"),
        "#height" => $product->get("productHeight"),
        "#unit" => $product->get("dimensionUnit"),
      ],
      "product_weight" => [
        "#theme" => "xdruple_weight",
        "#title" => "Product weight",
        "#weight" => $product->get("productWeight"),
        "#unit" => $product->get("weightUnit"),
      ],
      "package_dimensions" => [
        "#theme" => "xdruple_dimensions",
        "#title" => "Package dimensions",
        "#length" => $product->get("packageLength"),
        "#width" => $product->get("packageWidth"),
        "#height" => $product->get("packageHeight"),
        "#unit" => $product->get("dimensionUnit"),
      ],
      "package_weight" => [
        "#theme" => "xdruple_weight",
        "#title" => "Package weight",
        "#weight" => $product->get("packageWeight"),
        "#unit" => $product->get("weightUnit"),
      ],
    ];
  }
  $variables["classes_array"]["panel"] = "panel";
  $variables["classes_array"]["panel-default"] = "panel-default";
}

function template_process_xdruple_product_delivery(&$variables) {
  if (!empty($variables["data"])) {
    $variables["info"] = [
      "#theme" => "table",
      "#rows" => [],
    ];
    foreach ($variables["data"] as $key => $value) {
      $title = $value["#title"];
      $value["#title"] = "";
      $variables["info"]["#rows"][] = [
        $title,
        ["data" => $value],
      ];
    }
  }
}

function template_preprocess_xdruple_product_characteristics(&$variables) {
  if (!empty($variables["product"])) {
    /** @var \Xtuple\Rescued\Controller\Entity $product */
    $product = $variables["product"];
    $chars = $product->get("xt_char");
    if (!empty($chars["und"])) {
      $variables["characteristics"] = [];
      foreach ($chars["und"] as $char) {
        $variables["characteristics"][] = [
          "title" => $char["characteristic"],
          "value" => $char["value"],
          "class" => drupal_clean_css_identifier(
            strtolower($char["characteristic"])
          ),
        ];
      }
    }
  }
  $variables["classes_array"]["panel"] = "panel";
  $variables["classes_array"]["panel-default"] = "panel-default";
  $variables["characteristics_table"] = [
    "#theme" => "table",
    "#rows" => [],
    "#attributes" => [
      "class" => [
        "table-condensed" => "table-condensed",
      ],
    ]
  ];
}

function template_process_xdruple_product_characteristics(&$variables) {
  if (!empty($variables["characteristics"])) {
    $columns = $variables["columns"];
    foreach ($variables["characteristics"] as $i => $characteristic) {
      if ($i % $columns == 0) {
        if (!empty($row)) {
          $variables["characteristics_table"]["#rows"][] = $row;
        }
        $row = [];
      }
      $row[] = $characteristic["title"];
      $row[] = $characteristic["value"];
    }
    if (!empty($row)) {
      if ($missing_columns = ($columns * 2 - sizeof($row))) {
        for ($i = 0; $i < $missing_columns; $i++) {
          $row[] = "";
        }
      }
      $variables["characteristics_table"]["#rows"][] = $row;
    }
  }
}
