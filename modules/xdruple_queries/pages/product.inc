<?php

/**
 * @file keeps callbacks for /products/% page
 */

/**
 * Page callback
 *
 * @param $product_id
 *
 * @return string
 */
function xdruple_queries_product_page($product_id) {
  if (!is_numeric($product_id)) {
    drupal_not_found();
  }

  $output = '';

  if (user_access('administer rescued entities')) {
    $output .= theme('bootstrap_pills', array(
      'items' => array(
        array(
          'title' => t('Edit'),
          'link'  => "admin/commerce/products/$product_id/edit",
        ),
      ),
    ));
  }

  $view = views_get_view(variable_get('xdruple_queries_product_page_view_name', 'ft_commerce_product'));
  $view->execute_display('default', array($product_id));
  if (!empty($view->result)) {
    if (!empty($view->result[0]->title)) {
      drupal_set_title($view->result[0]->title);
    }

    $output .= $view->render();
  }
  else {
    drupal_not_found();
  }

  return $output;
}
