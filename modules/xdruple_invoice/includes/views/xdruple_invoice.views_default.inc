<?php

/**
 * Views for xTuple Invoice resources.
 */

/**
 * Implements hook_views_default_views().
 */
function xdruple_invoice_views_default_views() {
  /**
   * Invoice List Item: Invoices.
   */
  $view = new view();
  $view->name = 'xd_invoices';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'efq_xtuple_invoicelistitem';
  $view->human_name = 'Invoices';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Invoices';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view personal rescued entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'number' => 'number',
    'orderNumber' => 'orderNumber',
    'invoiceDate' => 'invoiceDate',
    'billtoName' => 'billtoName',
    'billtoCity' => 'billtoCity',
    'billtoState' => 'billtoState',
    'total' => 'total',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'orderNumber' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'invoiceDate' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'billtoName' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'billtoCity' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'billtoState' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'total' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: InvoiceListItem: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'efq_xtuple_invoicelistitem';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['number']['alter']['path'] = 'invoice/[number]';
  $handler->display->display_options['fields']['number']['link_to_entity'] = 0;
  /* Field: InvoiceListItem: Order Number */
  $handler->display->display_options['fields']['orderNumber']['id'] = 'orderNumber';
  $handler->display->display_options['fields']['orderNumber']['table'] = 'efq_xtuple_invoicelistitem';
  $handler->display->display_options['fields']['orderNumber']['field'] = 'orderNumber';
  $handler->display->display_options['fields']['orderNumber']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['orderNumber']['alter']['path'] = 'order/[orderNumber]';
  $handler->display->display_options['fields']['orderNumber']['link_to_entity'] = 0;
  /* Field: InvoiceListItem: Invoice Date */
  $handler->display->display_options['fields']['invoiceDate']['id'] = 'invoiceDate';
  $handler->display->display_options['fields']['invoiceDate']['table'] = 'efq_xtuple_invoicelistitem';
  $handler->display->display_options['fields']['invoiceDate']['field'] = 'invoiceDate';
  $handler->display->display_options['fields']['invoiceDate']['date_format'] = 'custom';
  $handler->display->display_options['fields']['invoiceDate']['custom_date_format'] = 'Y-m-d';
  $handler->display->display_options['fields']['invoiceDate']['link_to_entity'] = 0;
  /* Field: InvoiceListItem: Billto Name */
  $handler->display->display_options['fields']['billtoName']['id'] = 'billtoName';
  $handler->display->display_options['fields']['billtoName']['table'] = 'efq_xtuple_invoicelistitem';
  $handler->display->display_options['fields']['billtoName']['field'] = 'billtoName';
  $handler->display->display_options['fields']['billtoName']['link_to_entity'] = 0;
  /* Field: InvoiceListItem: Billto City */
  $handler->display->display_options['fields']['billtoCity']['id'] = 'billtoCity';
  $handler->display->display_options['fields']['billtoCity']['table'] = 'efq_xtuple_invoicelistitem';
  $handler->display->display_options['fields']['billtoCity']['field'] = 'billtoCity';
  $handler->display->display_options['fields']['billtoCity']['link_to_entity'] = 0;
  /* Field: InvoiceListItem: Billto State */
  $handler->display->display_options['fields']['billtoState']['id'] = 'billtoState';
  $handler->display->display_options['fields']['billtoState']['table'] = 'efq_xtuple_invoicelistitem';
  $handler->display->display_options['fields']['billtoState']['field'] = 'billtoState';
  $handler->display->display_options['fields']['billtoState']['link_to_entity'] = 0;
  /* Field: InvoiceListItem: Total */
  $handler->display->display_options['fields']['total']['id'] = 'total';
  $handler->display->display_options['fields']['total']['table'] = 'efq_xtuple_invoicelistitem';
  $handler->display->display_options['fields']['total']['field'] = 'total';
  $handler->display->display_options['fields']['total']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total']['precision'] = '2';
  $handler->display->display_options['fields']['total']['link_to_entity'] = 0;
  /* Filter criterion: InvoiceListItem: Is Posted */
  $handler->display->display_options['filters']['isPosted']['id'] = 'isPosted';
  $handler->display->display_options['filters']['isPosted']['table'] = 'efq_xtuple_invoicelistitem';
  $handler->display->display_options['filters']['isPosted']['field'] = 'isPosted';
  $handler->display->display_options['filters']['isPosted']['value'] = '1';
  /* Filter criterion: InvoiceListItem: Is Void */
  $handler->display->display_options['filters']['isVoid']['id'] = 'isVoid';
  $handler->display->display_options['filters']['isVoid']['table'] = 'efq_xtuple_invoicelistitem';
  $handler->display->display_options['filters']['isVoid']['field'] = 'isVoid';
  $handler->display->display_options['filters']['isVoid']['value'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/invoices';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Invoices';
  $handler->display->display_options['menu']['weight'] = '22';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views[$view->name] = $view;

  return $views;
}
