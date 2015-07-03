<?php

/**
 * @file keeps xdruple_favorites_remove_from_favorites_form callbacks
 */

/**
 * Form builder: xdruple_favorites_remove_from_favorites_form
 *
 * @param $form
 * @param $form_state
 * @param $product_id
 * @param $customer
 * @param $ship_to
 *
 * @return mixed
 */
function xdruple_favorites_remove_from_favorites_form($form, &$form_state, $product_id, $customer, $ship_to) {
  $form = _xdruple_favorites_prepare_add_remove_form(XDRUPLE_FAVORITES_REMOVE, $form, $form_state, $product_id, $customer, $ship_to);

  return $form;
}

/**
 * Form validation: xdruple_favorites_remove_from_favorites_form
 *
 * @param $form
 * @param $form_state
 */
function xdruple_favorites_remove_from_favorites_form_validate($form, &$form_state) {
}

/**
 * Form submission: xdruple_favorites_remove_from_favorites_form
 *
 * @param $form
 * @param $form_state
 */
function xdruple_favorites_remove_from_favorites_form_submit($form, &$form_state) {
  $entity_type = 'xtuple_xdstandardorderproduct';

  try {
    $values = $form_state['values'];
    $std_order_product = entity_load($entity_type, FALSE, [
      'product' => $values['product_id'],
      'customer' => $values['customer'],
      'shipTo' => $values['ship_to'],
    ]);
    if (count($std_order_product) === 1) {
      $uuid = key($std_order_product);
      entity_delete($entity_type, $uuid);

      // Invalidate cache.
      $cid = 'xtuple_xdcatalogshiptostandardorder-' . $values['ship_to'];
      cache_clear_all($cid, 'cache');
    }

    $product = entity_load_single('commerce_product', $values['product_id']);
    drupal_set_message(t("Product !title removed from the !favorites", [
      '!title' => l($product->title, "products/{$product->product_id}"),
      '!favorites' => t(variable_get('xdruple_favorites_favorites_title', 'Favorite products')),
    ]), 'warning');
  } catch (\Exception $e) {
    drupal_set_message($e->getMessage(), 'error');
    watchdog('xdruple_favorites', $e->getMessage(), [], WATCHDOG_ERROR);
  }
}
