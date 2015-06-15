<?php

/**
 * Views for xTuple Sales Order resources.
 */

/**
 * Implements hook_views_default_views().
 */
function xdruple_order_views_default_views() {
  /**
   * Sales Order List Item: Pending Orders.
   */
  $view = new view();
  $view->name = 'xd_pending_orders';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'efq_xtuple_salesorderlistitem';
  $view->human_name = 'Pending Orders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Pending orders';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view list rescued entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = [
    'number' => 'number',
    'orderDate' => 'orderDate',
    'billtoName' => 'billtoName',
    'billtoCity' => 'billtoCity',
    'billtoState' => 'billtoState',
    'shiptoName' => 'shiptoName',
    'shiptoCity' => 'shiptoCity',
    'shiptoState' => 'shiptoState',
    'total' => 'total',
  ];
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = [
    'number' => [
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ],
    'orderDate' => [
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ],
    'billtoName' => [
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ],
    'billtoCity' => [
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ],
    'billtoState' => [
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ],
    'shiptoName' => [
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ],
    'shiptoCity' => [
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ],
    'shiptoState' => [
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ],
    'total' => [
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ],
  ];
  /* Field: SalesOrderListItem: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'efq_xtuple_salesorderlistitem';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['number']['alter']['path'] = 'order/[number]';
  $handler->display->display_options['fields']['number']['link_to_entity'] = 0;
  /* Field: SalesOrderListItem: Order Date */
  $handler->display->display_options['fields']['orderDate']['id'] = 'orderDate';
  $handler->display->display_options['fields']['orderDate']['table'] = 'efq_xtuple_salesorderlistitem';
  $handler->display->display_options['fields']['orderDate']['field'] = 'orderDate';
  $handler->display->display_options['fields']['orderDate']['date_format'] = 'custom';
  $handler->display->display_options['fields']['orderDate']['custom_date_format'] = 'Y-m-d';
  $handler->display->display_options['fields']['orderDate']['link_to_entity'] = 0;
  /* Field: SalesOrderListItem: Billto Name */
  $handler->display->display_options['fields']['billtoName']['id'] = 'billtoName';
  $handler->display->display_options['fields']['billtoName']['table'] = 'efq_xtuple_salesorderlistitem';
  $handler->display->display_options['fields']['billtoName']['field'] = 'billtoName';
  $handler->display->display_options['fields']['billtoName']['link_to_entity'] = 0;
  /* Field: SalesOrderListItem: Billto City */
  $handler->display->display_options['fields']['billtoCity']['id'] = 'billtoCity';
  $handler->display->display_options['fields']['billtoCity']['table'] = 'efq_xtuple_salesorderlistitem';
  $handler->display->display_options['fields']['billtoCity']['field'] = 'billtoCity';
  $handler->display->display_options['fields']['billtoCity']['link_to_entity'] = 0;
  /* Field: SalesOrderListItem: Billto State */
  $handler->display->display_options['fields']['billtoState']['id'] = 'billtoState';
  $handler->display->display_options['fields']['billtoState']['table'] = 'efq_xtuple_salesorderlistitem';
  $handler->display->display_options['fields']['billtoState']['field'] = 'billtoState';
  $handler->display->display_options['fields']['billtoState']['link_to_entity'] = 0;
  /* Field: SalesOrderListItem: Shipto Name */
  $handler->display->display_options['fields']['shiptoName']['id'] = 'shiptoName';
  $handler->display->display_options['fields']['shiptoName']['table'] = 'efq_xtuple_salesorderlistitem';
  $handler->display->display_options['fields']['shiptoName']['field'] = 'shiptoName';
  $handler->display->display_options['fields']['shiptoName']['link_to_entity'] = 0;
  /* Field: SalesOrderListItem: Shipto City */
  $handler->display->display_options['fields']['shiptoCity']['id'] = 'shiptoCity';
  $handler->display->display_options['fields']['shiptoCity']['table'] = 'efq_xtuple_salesorderlistitem';
  $handler->display->display_options['fields']['shiptoCity']['field'] = 'shiptoCity';
  $handler->display->display_options['fields']['shiptoCity']['link_to_entity'] = 0;
  /* Field: SalesOrderListItem: Shipto State */
  $handler->display->display_options['fields']['shiptoState']['id'] = 'shiptoState';
  $handler->display->display_options['fields']['shiptoState']['table'] = 'efq_xtuple_salesorderlistitem';
  $handler->display->display_options['fields']['shiptoState']['field'] = 'shiptoState';
  $handler->display->display_options['fields']['shiptoState']['link_to_entity'] = 0;
  /* Field: SalesOrderListItem: Total */
  $handler->display->display_options['fields']['total']['id'] = 'total';
  $handler->display->display_options['fields']['total']['table'] = 'efq_xtuple_salesorderlistitem';
  $handler->display->display_options['fields']['total']['field'] = 'total';
  $handler->display->display_options['fields']['total']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total']['precision'] = '2';
  $handler->display->display_options['fields']['total']['link_to_entity'] = 0;
  /* Filter criterion: SalesOrderListItem: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'efq_xtuple_salesorderlistitem';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'O';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/pending-orders';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Pending Orders';
  $handler->display->display_options['menu']['weight'] = '21';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views[$view->name] = $view;

  return $views;
}
