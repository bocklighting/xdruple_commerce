<?php

/**
 * @file
 * xDruple Commerce Specialty Shipping - admin pages/forms
 */


/**
 * xDruple Commerce Specialty Shipping settings form.
 *
 * @param $form
 * @param $form_state
 *
 * @return array
 */
function xdruple_specialty_shipping_settings_form($form, &$form_state) {
  // Delivery shipping service display title.
  $form['xdruple_specialty_shipping_service_display_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Specialty Shipping service display title'),
    '#description' => t('Specify how you would like the specialty shipping service to appear in checkout and in the order line item.'),
    '#default_value' => variable_get('xdruple_specialty_shipping_service_display_title', 'Specialty Shipping'),
    '#required' => TRUE,
  );

  // Delivery shipping default rate amount.
  $form['xdruple_specialty_shipping_service_amount'] = array(
    '#type' => 'textfield',
    '#title' => t('Specialty Shipping service rate amount'),
    '#description' => t('The shipping fee amount to add to the order when the Specialty Shipping service is selected'),
    '#default_value' => variable_get('xdruple_specialty_shipping_service_amount', 0),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
