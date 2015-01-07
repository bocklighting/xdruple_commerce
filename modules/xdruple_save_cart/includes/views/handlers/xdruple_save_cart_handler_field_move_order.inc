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

  /**
   * @return bool
   */
  protected function hasAccess() {
    return user_access('view own commerce_order entities');
  }

  /**
   * @param $values
   * @return mixed
   */
  protected function createOrder($values) {
    $order = commerce_order_new();
    $order->order_id = $this->get_value($values, 'order_id');
    $order->uid = $this->get_value($values, 'uid');

    return $order;
  }

  /**
   * @return string
   */
  protected function getLinkText() {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('Make active cart');

    return $text;
  }

  /**
   * @param $values
   * @return string
   */
  protected function getLinkPath($values) {
    $order = $this->createOrder($values);
    $link = 'admin/commerce/orders/' . $order->order_id . '/move';

    return $link;
  }

  /**
   * @return array
   */
  protected function getLinkOptions() {
    $destination = array('destination' => 'cart');
    $options = array(
      'query' => $destination,
    );

    return $options;
  }

  /**
   * @param $values
   * @return string
   */
  function render($values) {
    if (!$this->hasAccess()) {
      return;
    }

    return l($this->getLinkText(), $this->getLinkPath($values), $this->getLinkOptions());
  }
}
