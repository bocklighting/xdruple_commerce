<?php

/**
 * @file
 * Field handler to present a button to move a saved cart to the active cart.
 */

/**
 * Field handler to present a button to move a saved cart to the active cart.
 */
class xdruple_save_cart_handler_field_move_order extends commerce_order_handler_field_order_link {

  function construct() {
    parent::construct();

    $this->additional_fields['uid'] = 'uid';
  }

  function render($values) {
    // Ensure the user has access to this order.
    $order = commerce_order_new();
    $order->order_id = $this->get_value($values, 'order_id');
    $order->uid = $this->get_value($values, 'uid');

    if (!commerce_order_access('update', $order)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('Make active cart');

    $destination = array('destination' => 'cart');

    // TODO: Do we really want this action to be mixed in with the other order ui operations?
    return l($text, 'admin/commerce/orders/' . $order->order_id . '/move', array('query' => $destination));
  }
}
