<?php

/**
 * @file keeps xdruple_queries_remove_from_standard_order_form callbacks
 */

/**
 * Form builder: xdruple_queries_remove_from_standard_order_form
 */
function xdruple_queries_remove_from_standard_order_form($form, &$form_state, $product_id, $customer, $ship_to) {
  $form['submit']     = array(
    '#type'  => 'submit',
    '#value' => t('Remove from the Standard Order'),
  );
  $form['product_id'] = array(
    '#type'  => 'value',
    '#value' => $product_id,
  );
  $form['customer']   = array(
    '#type'  => 'value',
    '#value' => $customer,
  );
  $form['ship_to']    = array(
    '#type'  => 'value',
    '#value' => $ship_to,
  );

  $form['#attributes']['class'][] = drupal_clean_css_identifier('xdruple_queries_remove_from_standard_order_form');

  return $form;
}

/**
 * Form validation: xdruple_queries_remove_from_standard_order_form
 */
function xdruple_queries_remove_from_standard_order_form_validate($form, &$form_state) {
}

/**
 * Form submission: xdruple_queries_remove_from_standard_order_form
 */
function xdruple_queries_remove_from_standard_order_form_submit($form, &$form_state) {
  $entity_type = 'xtuple_xdstdorditem';

  try {
    $values         = $form_state['values'];
    $std_order_item = entity_load($entity_type, FALSE, array(
      'product'  => $values['product_id'],
      'customer' => $values['customer'],
      'shipTo'   => $values['ship_to'],
    ));
    if (count($std_order_item) === 1) {
      $uuid = key($std_order_item);
      entity_delete($entity_type, $uuid);

      // Invalidate cache.
      $cid = 'xtuple_xdcatalogshiptostdord-' . $values['ship_to'];
      cache_clear_all($cid, 'cache');
    }
    drupal_set_message(t("Product removed from the Standard order"));
  } catch (\Exception $e) {
    drupal_set_message($e->getMessage(), 'error');
    watchdog('xdruple_queries', $e->getMessage(), array(), WATCHDOG_ERROR);
  }
}
