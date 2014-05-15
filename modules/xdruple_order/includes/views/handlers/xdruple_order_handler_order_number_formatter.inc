<?php

class xdruple_order_handler_order_number_formatter extends entity_views_handler_field_text {
  public function render($values) {
    global $user;

    $output = '';
    if (!empty($user->uid) && !empty($values->number)) {
      $output = l($values->number, "user/{$user->uid}/pending-orders/{$values->number}");
    }

    return $output;
  }
}
