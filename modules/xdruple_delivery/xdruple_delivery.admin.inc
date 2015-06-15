<?php

/**
 * @file
 * xDruple Commerce Delivery - admin pages/forms
 */


/**
 * xDruple Commerce Delivery settings form.
 *
 * @param $form
 * @param $form_state
 *
 * @return array
 */
function xdruple_delivery_settings_form($form, &$form_state) {
  // Delivery shipping service display title.
  $form['xdruple_delivery_service_display_title'] = [
    '#type' => 'textfield',
    '#title' => t('Delivery service display title'),
    '#description' => t('Specify how you would like the delivery service to appear in checkout and in the order line item.'),
    '#default_value' => variable_get('xdruple_delivery_service_display_title', 'Delivery'),
    '#required' => TRUE,
  ];

  // Delivery shipping default rate amount.
  $form['xdruple_delivery_service_amount'] = [
    '#type' => 'textfield',
    '#title' => t('Delivery service rate amount'),
    '#description' => t('The shipping fee amount to add to the order when the delivery service is selected'),
    '#default_value' => variable_get('xdruple_delivery_service_amount', 0),
    '#required' => TRUE,
  ];

  return system_settings_form($form);
}
