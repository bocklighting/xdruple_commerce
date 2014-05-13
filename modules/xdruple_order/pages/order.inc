<?php

/**
 * @file keeps callbacks for /order/% page
 */

/**
 * Page callback
 *
 * @param $order_num
 *
 * @return string
 */
function xdruple_order_page($order_num) {
  $output = '';
  $orders = array();

  if (!empty($order_num)) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'xtuple_salesorder')
      ->propertyCondition('number', $order_num, '=');

    if (user_access('administer rescued entities')) {
      $orders = $query->execute();
    }
    else {
      if (isset($_SESSION['rescued']['customer'])) {
        $query->propertyCondition('customer', $_SESSION['rescued']['customer'], '=');
        $orders = $query->execute();
      }
    }
    // TODO: Add Sales Rep, Emplyee and Owner query filters.

    $query_remitto = new EntityFieldQuery();
    $remitto       = $query_remitto->entityCondition('entity_type', 'xtuple_remitto')
      ->execute();

    // TODO: The rescued_entity_field_query_builder(EntityFieldQuery $query)
    // function runs through entity_load to do the actual query. In theory,
    // an EntityFieldQuery() could go directly to the API and then you would
    // call entity_load() for the returned ids which will attach fields, etc.
    // We can skip this call for now. This is one reason why the entity cache
    // and EntityFieldQuery cache need to work together.
    //$order = entity_load('xtuple_salesorder', array_keys($order['xtuple_salesorder']));

    foreach ($orders['xtuple_salesorder'] as $order) {
      $currency = entity_load_single('xtuple_currency', $order->currency['abbreviation']);

      $params = array(
        'order'    => $order,
        'remitto'  => $remitto['xtuple_remitto'][key($remitto['xtuple_remitto'])],
        'currency' => $currency,
      );

      $output = theme('order_page', $params);
    }
  }

  return $output;
}
