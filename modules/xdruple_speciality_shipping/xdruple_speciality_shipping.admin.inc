<?php

/**
 * @file
 * xDruple Commerce Speciality Shipping - admin pages/forms
 */


/**
 * xDruple Commerce Speciality Shipping settings form.
 */
function xdruple_speciality_shipping_settings_form($form, &$form_state) {
  // Delivery shipping service display title.
  $form['xdruple_speciality_shipping_service_display_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Speciality Shipping service display title'),
    '#description' => t('Specify how you would like the speciality shipping service to appear in checkout and in the order line item.'),
    '#default_value' => variable_get('xdruple_speciality_shipping_service_display_title', 'Speciality Shipping'),
    '#required' => TRUE,
  );

  // Delivery shipping default rate amount.
  $form['xdruple_speciality_shipping_service_amount'] = array(
    '#type' => 'textfield',
    '#title' => t('Speciality Shipping service rate amount'),
    '#description' => t('The shipping fee amount to add to the order when the Speciality Shipping service is selected'),
    '#default_value' => variable_get('xdruple_speciality_shipping_service_amount', 0),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
