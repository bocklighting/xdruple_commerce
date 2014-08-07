<?php

/**
 * @file keeps xdruple_favorites_add_to_favorites_form callbacks
 */

/**
 * Form builder: xdruple_favorites_add_to_favorites_form
 */
function xdruple_favorites_add_to_favorites_form($form, &$form_state, $product_id, $customer, $ship_to) {
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add to the Favorites'),
  );
  $form['product_id'] = array(
    '#type' => 'value',
    '#value' => $product_id,
  );
  $form['customer'] = array(
    '#type' => 'value',
    '#value' => $customer,
  );
  $form['ship_to'] = array(
    '#type' => 'value',
    '#value' => $ship_to,
  );

  $form['#attributes']['class'][] = drupal_clean_css_identifier('xdruple_favorites_add_to_favorites_form');

  return $form;
}

/**
 * Form validation: xdruple_favorites_add_to_favorites_form
 */
function xdruple_favorites_add_to_favorites_form_validate($form, &$form_state) {
}

/**
 * Form submission: xdruple_favorites_add_to_favorites_form
 */
function xdruple_favorites_add_to_favorites_form_submit($form, &$form_state) {
  $entity_type = 'xtuple_xdstdordproduct';

  try {
    $values = $form_state['values'];
    $std_order_product = entity_create($entity_type, array(
      'product' => $values['product_id'],
      'customer' => $values['customer'],
      'shipto' => $values['ship_to'],
    ));
    entity_save($entity_type, $std_order_product);

    // Invalidate cache.
    $cid = 'xtuple_xdcatalogshiptostdord-' . $values['ship_to'];
    cache_clear_all($cid, 'cache');

    $product = entity_load_single('commerce_product', $values['product_id']);
    drupal_set_message(t("Product !title added to the Favorites", array(
      '!title' => l($product->title, "products/{$product->product_id}"),
    )));
  } catch (Google_ServiceException $e) {
    $errors = $e->getErrors();
    if ($errors[0]['message'] == 'Error: duplicate key value violates unique constraint "xd_stdorditem_unique"') {
      drupal_set_message(t('You already have this product in the Favorites'));
    }
    else {
      drupal_set_message($e->getMessage(), 'error');
    }
    watchdog('xdruple_favorites', $e->getMessage(), array(), WATCHDOG_ERROR);
  } catch (\Exception $e) {
    drupal_set_message($e->getMessage(), 'error');
    watchdog('xdruple_favorites', $e->getMessage(), array(), WATCHDOG_ERROR);
  }
}
