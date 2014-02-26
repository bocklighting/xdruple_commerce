<?php

/**
 * Implements the callback of the checkout pane form setting.
 */
function xdruple_commerce_cp_panes_contents_settings_form($checkout_pane) {
  $form = array();
  return $form;
}

/**
 * Implements the callback of the checkout pane form
 */
function xdruple_commerce_cp_panes_contents_checkout_form(&$form, &$form_state, $checkout_pane, $order) {
  $pane_form = array('#parents' => array($checkout_pane['pane_id']));

  // Extract the type of profile2 represented by this pane from its ID.
  $type = substr($checkout_pane['pane_id'], strlen('xd_commerce_cp_'));

  // Find the referenced profile using the related reference field...
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
  $pane = NULL;

  // If the associated order field has been set...
  if ($field_name = variable_get($checkout_pane['pane_id'] . '_field', '')) {
    $pane_wrapper = $order_wrapper->{$field_name};
    $pane = $pane_wrapper->value();
  }
  else {
    // Or try the association stored in the order's data array if no field is set.
    if (!empty($order->data[$type][$checkout_pane['pane_id']])) {
      $pane = entity_load($type, $order->data[$type][$checkout_pane['pane_id']]);
      $panewrapper = entity_metadata_wrapper($type, $pane);
    }
  }

  // Create a new pane of the specified type if it hasn't already been made.
  if (empty($pane)) {
    $pane = entity_get_controller($type)->create(array());
    //$foo = entity_load($type, array(1));
    //$pane = $foo[1];
    $pane_wrapper = entity_metadata_wrapper($type, $pane);
  }

  // Add the entity context of the current cart order.
  $pane->entity_context = array(
   'entity_type' => 'commerce_order',
   'entity_id' => $order->order_id,
  );

  // TODO: We don't need to save a blank contact here.
  //$pane_wrapper->save();

  // If the associated order field has been set...
  if ($field_name = variable_get($checkout_pane['pane_id'] . '_field', '')) {
    $order_wrapper->{$field_name} = $pane;
    //$order_wrapper->{$field_name} = null;
  }
  else {
    // Or try the association stored in the order's data array if no field is set.
    if (!empty($order->data[$type][$checkout_pane['pane_id']])) {
      $order->data[$type][$checkout_pane['pane_id']] = $pane->id;
    }
  }
  $order_wrapper->save();

  $pane_form[$type] = array(
    '#type' => 'value',
    '#value' => $pane,
  );

  // Add the field widgets for the profile.
  field_attach_form($type, $pane, $pane_form, $form_state);
  $handler = entity_operations_get_entity_operation_handler($type, 'edit');
  $foo_form = $handler->form($pane_form, $form_state, $type, $pane, 'edit');

  $options = array('deleted' => false);
  // If no language is provided use the default site language.
  $options['language'] = 'und'; // field_valid_language(NULL);
  $instances = _field_invoke_get_instances('commerce_order', 'commerce_order', $options);
  $instance = $instances[$checkout_pane['pane_id']];
  $field = field_info_field_by_id($instances[$checkout_pane['pane_id']]['field_id']);
  $available_languages = field_available_languages('commerce_order', $field);
  $languages = _field_language_suggestion($available_languages, $options['language'], $field_name);
  $items = isset($order->{$field_name}[$options['language']]) ? $order->{$field_name}[$options['language']] : array();
  $pane_form += field_default_form($type, $pane, $field, $instance, $options['language'], $items, $pane_form, $form_state);

  return $pane_form;
}

/**
 * Implements the callback for the checkout pane form validate
 */
function xdruple_commerce_cp_panes_contents_checkout_form_validate($form, &$form_state, $checkout_pane, $order) {
  // Extract the type of xTuple entity represented by this pane from its ID.
  $type = substr($checkout_pane['pane_id'], strlen('xd_commerce_cp_'));

  $pane = $form_state['values'][$checkout_pane['pane_id']];

  // Notify field widgets to validate their data.
  field_attach_form_validate($type, $pane, $form[$checkout_pane['pane_id']], $form_state);

  //rescued_form_submit_build_entity($type, $pane, $form[$checkout_pane['pane_id']], $form_state);

  return TRUE;
}

/**
 * Implements the callback for the checkout pane form submit
 */
function xdruple_commerce_cp_panes_contents_checkout_form_submit($form, &$form_state, $checkout_pane, $order) {
  // Extract the type of xTuple entity represented by this pane from its ID.
  $type = substr($checkout_pane['pane_id'], strlen('xd_commerce_cp_'));

  $pane = $form_state['values'][$checkout_pane['pane_id']][$type];

  // TODO: Set the contact's uid if it's being created at this time.
  //if (empty($pane->identifier())) {
    //$pane->uid = $order->uid;
  //}

  // Notify field widgets.
  field_attach_submit($type, $pane, $form[$checkout_pane['pane_id']], $form_state);

  // Save the profile.
  //$pane->save();

  // Store the profile ID for the related field as specified on the settings form.
  //$order_wrapper = entity_metadata_wrapper('commerce_order', $order);

  if ($field_name = variable_get($checkout_pane['pane_id'] . '_field', '')) {
    //$order_wrapper->{$field_name} = $pane;
  }
  else {
    // Or make the association in the order's data array if no field was found.
    //$order->data['profiles'][$checkout_pane['pane_id']] = $pane->identifier();
  }
}

/**
 * Checkout pane callback: returns the cart contents review data for the
 *   Review checkout pane.
 */
function xdruple_commerce_cp_panes_contents_review($form, $form_state, $checkout_pane, $order) {
  // Extract the type of xTuple entity represented by this pane from its ID.
  $type = substr($checkout_pane['pane_id'], strlen('xd_commerce_cp_'));

  // Load the profile based on the related customer profile reference field...
  if ($field_name = variable_get($checkout_pane['pane_id'] . '_field', '')) {
    $pane = entity_metadata_wrapper('commerce_order', $order)->{$field_name}->value();
  }
  else {
    // Or use the association stored in the order's data array if no field is set.
    $pane = entity_load($type, $order->data[$type][$checkout_pane['pane_id']]);
  }

  if ($pane) {
    // @TODO use a specific display type instead of "account"
    $content = entity_view($type, array($pane->identifier() => $pane), 'account');
    return drupal_render($content);
  }
  else {
    return t('No information');
  }
}
