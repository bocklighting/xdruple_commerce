<?php

/**
 * Export xDruple Commerce Save Cart Orders to Views.
 */

/**
 * Implements hook_views_default_views().
 */
function xdruple_save_cart_views_default_views() {
  /**
   * User Saved Carts
   */
  $view = new view();
  $view->name = 'xd_user_saved_carts';
  $view->description = 'Display a list of Saved Cart orders for a user.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_order';
  $view->human_name = 'User Saved Carts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Saved Carts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own commerce_order entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 25;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = [
    'order_number' => 'order_number',
    'created' => 'created',
    'changed' => 'changed',
    'commerce_order_total' => 'commerce_order_total',
    'status' => 'status',
  ];
  $handler->display->display_options['style_options']['default'] = 'order_number';
  $handler->display->display_options['style_options']['info'] = [
    'order_number' => [
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ],
    'created' => [
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ],
    'changed' => [
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ],
    'commerce_order_total' => [
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ],
    'status' => [
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ],
    'xd_order_po_number' => [
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ],
    'xd_order_notes' => [
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ],
  ];
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'text';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'You have not placed any orders with us yet.';
  $handler->display->display_options['empty']['text']['format'] = 'plain_text';
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Cart number';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'customer';
  /* Field: Commerce Order: PO Number */
  $handler->display->display_options['fields']['xd_order_po_number']['id'] = 'xd_order_po_number';
  $handler->display->display_options['fields']['xd_order_po_number']['table'] = 'field_data_xd_order_po_number';
  $handler->display->display_options['fields']['xd_order_po_number']['field'] = 'xd_order_po_number';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  /* Field: Commerce Order: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = [
    'calculation' => FALSE,
  ];
  /* Field: Commerce Order: Operations */
  $handler->display->display_options['fields']['move_order']['id'] = 'move_order';
  $handler->display->display_options['fields']['move_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['move_order']['field'] = 'move_order';
  /* Contextual filter: Commerce Order: Uid */
  $handler->display->display_options['arguments']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['arguments']['uid_1']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['uid_1']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid_1']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid_1']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid_1']['validate']['type'] = 'current_user_or_role';
  $handler->display->display_options['arguments']['uid_1']['validate_options']['restrict_roles'] = TRUE;
  $handler->display->display_options['arguments']['uid_1']['validate_options']['roles'] = [
    3 => '3',
  ];
  /* Filter criterion: Commerce Order: Order state */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = [
    'saved_cart' => 'saved_cart',
  ];

  /* Display: User Orders */
  $handler = $view->new_display('page', 'User Orders', 'order_page');
  $handler->display->display_options['path'] = 'user/%/saved-carts';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Saved Carts';
  $handler->display->display_options['menu']['weight'] = '15';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Orders';
  $handler->display->display_options['tab_options']['description'] = 'User orders in the store.';
  $handler->display->display_options['tab_options']['weight'] = '';
  $handler->display->display_options['tab_options']['name'] = 'user-menu';

  $views[$view->name] = $view;

  $view = new view();
  $view->name = 'xd_user_saved_carts_block';
  $view->description = 'Display a list of Saved Cart orders for a user.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_order';
  $view->human_name = 'User Saved Carts (block)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Saved Carts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own commerce_order entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'text';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['content'] = 'You have not placed any orders with us yet.';
  $handler->display->display_options['empty']['text']['format'] = 'plain_text';
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Cart number';
  $handler->display->display_options['fields']['order_number']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'customer';
  /* Field: Commerce Order: PO Number */
  $handler->display->display_options['fields']['xd_order_po_number']['id'] = 'xd_order_po_number';
  $handler->display->display_options['fields']['xd_order_po_number']['table'] = 'field_data_xd_order_po_number';
  $handler->display->display_options['fields']['xd_order_po_number']['field'] = 'xd_order_po_number';
  $handler->display->display_options['fields']['xd_order_po_number']['label'] = 'PO';
  $handler->display->display_options['fields']['xd_order_po_number']['element_type'] = 'span';
  $handler->display->display_options['fields']['xd_order_po_number']['hide_empty'] = TRUE;
  /* Field: Commerce Order: Order Notes */
  $handler->display->display_options['fields']['xd_order_notes']['id'] = 'xd_order_notes';
  $handler->display->display_options['fields']['xd_order_notes']['table'] = 'field_data_xd_order_notes';
  $handler->display->display_options['fields']['xd_order_notes']['field'] = 'xd_order_notes';
  $handler->display->display_options['fields']['xd_order_notes']['label'] = 'Notes';
  $handler->display->display_options['fields']['xd_order_notes']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['xd_order_notes']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['xd_order_notes']['settings'] = [
    'trim_length' => '100',
  ];
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Commerce Order: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total';
  $handler->display->display_options['fields']['commerce_order_total']['element_type'] = 'span';
  $handler->display->display_options['fields']['commerce_order_total']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = [
    'calculation' => FALSE,
  ];
  /* Field: Commerce Order: Operations */
  $handler->display->display_options['fields']['move_order']['id'] = 'move_order';
  $handler->display->display_options['fields']['move_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['move_order']['field'] = 'move_order';
  $handler->display->display_options['fields']['move_order']['label'] = '';
  $handler->display->display_options['fields']['move_order']['element_label_colon'] = FALSE;
  /* Sort criterion: Commerce Order: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'commerce_order';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Sort criterion: Commerce Order: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'commerce_order';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Commerce Order: Uid */
  $handler->display->display_options['arguments']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['arguments']['uid_1']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['uid_1']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid_1']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid_1']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid_1']['validate']['type'] = 'current_user_or_role';
  $handler->display->display_options['arguments']['uid_1']['validate_options']['restrict_roles'] = TRUE;
  $handler->display->display_options['arguments']['uid_1']['validate_options']['roles'] = [
    3 => '3',
  ];
  /* Filter criterion: Commerce Order: Order state */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = [
    'saved_cart' => 'saved_cart',
  ];

  $views[$view->name] = $view;

  return $views;
}
