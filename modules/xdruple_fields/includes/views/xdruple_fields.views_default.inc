<?php

/**
 * Views for the default xTuple resource lists.
 */

/**
 * Implements hook_views_default_views().
 */
function xdruple_fields_views_default_views() {
  /**
   * Address List
   */
  $view = new view();
  $view->name = 'xd_address_list';
  $view->description = 'A list of xTuple Addresses';
  $view->tag = 'default';
  $view->base_table = 'efq_xtuple_xdruplecommerceaddress';
  $view->human_name = 'xd Address List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    user_role_load_by_name('authenticated user')->rid => strval(user_role_load_by_name('authenticated user')->rid),
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: XdrupleCommerceAddress: Line1 */
  $handler->display->display_options['fields']['line1']['id'] = 'line1';
  $handler->display->display_options['fields']['line1']['table'] = 'efq_xtuple_xdruplecommerceaddress';
  $handler->display->display_options['fields']['line1']['field'] = 'line1';
  $handler->display->display_options['fields']['line1']['label'] = '';
  $handler->display->display_options['fields']['line1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['line1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['line1']['link_to_entity'] = 0;
  /* Field: XdrupleCommerceAddress: Line2 */
  $handler->display->display_options['fields']['line2']['id'] = 'line2';
  $handler->display->display_options['fields']['line2']['table'] = 'efq_xtuple_xdruplecommerceaddress';
  $handler->display->display_options['fields']['line2']['field'] = 'line2';
  $handler->display->display_options['fields']['line2']['label'] = '';
  $handler->display->display_options['fields']['line2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['line2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['line2']['alter']['text'] = '<br />[line2]';
  $handler->display->display_options['fields']['line2']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['line2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['line2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['line2']['link_to_entity'] = 0;
  /* Field: XdrupleCommerceAddress: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'efq_xtuple_xdruplecommerceaddress';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['label'] = '';
  $handler->display->display_options['fields']['city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['city']['link_to_entity'] = 0;
  /* Field: XdrupleCommerceAddress: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'efq_xtuple_xdruplecommerceaddress';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = '';
  $handler->display->display_options['fields']['state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['state']['link_to_entity'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[line1] [line2]
  [city], [state]
  <hr />';
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

  /* Display: Entity Reference EFQ Views */
  $handler = $view->new_display('entityreference_efq_views', 'Entity Reference EFQ Views', 'entityreference_efq_views_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_efq_views_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'line1' => 'line1',
    'line2' => 'line2',
    'city' => 'city',
    'state' => 'state',
    'nothing' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'nothing' => 'nothing',
  );
  $handler->display->display_options['row_options']['separator'] = '';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  $views[$view->name] = $view;

  /**
   * Contact List
   */
  $view = new view();
  $view->name = 'xd_contact_list';
  $view->description = 'A list of xTuple Contacts';
  $view->tag = 'default';
  $view->base_table = 'efq_xtuple_xdruplecommercecontact';
  $view->human_name = 'xd Contact List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    user_role_load_by_name('authenticated user')->rid => strval(user_role_load_by_name('authenticated user')->rid),
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: XdrupleCommerceContact: First Name */
  $handler->display->display_options['fields']['firstName']['id'] = 'firstName';
  $handler->display->display_options['fields']['firstName']['table'] = 'efq_xtuple_xdruplecommercecontact';
  $handler->display->display_options['fields']['firstName']['field'] = 'firstName';
  $handler->display->display_options['fields']['firstName']['label'] = '';
  $handler->display->display_options['fields']['firstName']['exclude'] = TRUE;
  $handler->display->display_options['fields']['firstName']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['firstName']['link_to_entity'] = 0;
  /* Field: XdrupleCommerceContact: Last Name */
  $handler->display->display_options['fields']['lastName']['id'] = 'lastName';
  $handler->display->display_options['fields']['lastName']['table'] = 'efq_xtuple_xdruplecommercecontact';
  $handler->display->display_options['fields']['lastName']['field'] = 'lastName';
  $handler->display->display_options['fields']['lastName']['label'] = '';
  $handler->display->display_options['fields']['lastName']['exclude'] = TRUE;
  $handler->display->display_options['fields']['lastName']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['lastName']['link_to_entity'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[firstName] [lastName]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

  /* Display: Entity Reference EFQ Views */
  $handler = $view->new_display('entityreference_efq_views', 'Entity Reference EFQ Views', 'entityreference_efq_views_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_efq_views_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'firstName' => 'firstName',
    'lastName' => 'lastName',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'nothing' => 'nothing',
  );
  $handler->display->display_options['row_options']['separator'] = '';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  $views[$view->name] = $view;

  /**
   * Customer List
   */
  $view = new view();
  $view->name = 'xd_customer_list';
  $view->description = 'A list of xTuple Customers';
  $view->tag = 'default';
  $view->base_table = 'efq_xtuple_xdruplecommercecustomer';
  $view->human_name = 'xd Customer List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    user_role_load_by_name('authenticated user')->rid => strval(user_role_load_by_name('authenticated user')->rid),
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: XdrupleCommerceCustomer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'efq_xtuple_xdruplecommercecustomer';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_entity'] = 0;
  /* Field: XdrupleCommerceCustomer: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'efq_xtuple_xdruplecommercecustomer';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['label'] = '';
  $handler->display->display_options['fields']['number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['number']['link_to_entity'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[number] - [name]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

  /* Display: Entity Reference EFQ Views */
  $handler = $view->new_display('entityreference_efq_views', 'Entity Reference EFQ Views', 'entityreference_efq_views_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_efq_views_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
    'number' => 'number',
    'nothing' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'nothing' => 'nothing',
  );
  $handler->display->display_options['row_options']['separator'] = '';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  $views[$view->name] = $view;

  /**
   * Ship To List
   */
  $view = new view();
  $view->name = 'xd_ship_to_list';
  $view->description = 'A list of xTuple Ship Tos';
  $view->tag = 'default';
  $view->base_table = 'efq_xtuple_xdruplecommerceshipto';
  $view->human_name = 'xd Ship To List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    user_role_load_by_name('authenticated user')->rid => strval(user_role_load_by_name('authenticated user')->rid),
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: XdrupleCommerceCustomer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'efq_xtuple_xdruplecommerceshipto';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_entity'] = 0;
  /* Field: XdrupleCommerceCustomer: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'efq_xtuple_xdruplecommerceshipto';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['label'] = '';
  $handler->display->display_options['fields']['number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['number']['link_to_entity'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[number] - [name]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

  /* Display: Entity Reference EFQ Views */
  $handler = $view->new_display('entityreference_efq_views', 'Entity Reference EFQ Views', 'entityreference_efq_views_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_efq_views_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
    'number' => 'number',
    'nothing' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'nothing' => 'nothing',
  );
  $handler->display->display_options['row_options']['separator'] = '';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  $views[$view->name] = $view;

  /**
   * Product List
   */
  $view = new view();
  $view->name = 'xd_products';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'efq_commerce_product';
  $view->human_name = 'Products';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Products';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Commerce Product: SKU */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'efq_commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['link_to_entity'] = 0;
  /* Field: Commerce Product: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'efq_commerce_product';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Commerce Product: Class Code */
  $handler->display->display_options['fields']['classCode']['id'] = 'classCode';
  $handler->display->display_options['fields']['classCode']['table'] = 'efq_commerce_product';
  $handler->display->display_options['fields']['classCode']['field'] = 'classCode';
  $handler->display->display_options['fields']['classCode']['link_to_entity'] = 0;
  /* Field: Commerce Product: Ext Descrip */
  $handler->display->display_options['fields']['extDescrip']['id'] = 'extDescrip';
  $handler->display->display_options['fields']['extDescrip']['table'] = 'efq_commerce_product';
  $handler->display->display_options['fields']['extDescrip']['field'] = 'extDescrip';
  $handler->display->display_options['fields']['extDescrip']['link_to_entity'] = 0;
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'efq_commerce_product';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['type'] = 'commerce_price_savings_formatter_formatter';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => 'calculated_sell_price',
    'prices' => array(
      'list' => 'list',
      'price' => 'price',
      'savings' => 'savings',
    ),
    'savings' => 'both',
    'show_labels' => 1,
  );
  /* Field: Commerce Product: Add to Cart form */
  $handler->display->display_options['fields']['add_to_cart_form']['id'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['table'] = 'views_entity_commerce_product';
  $handler->display->display_options['fields']['add_to_cart_form']['field'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['label'] = '';
  $handler->display->display_options['fields']['add_to_cart_form']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['add_to_cart_form']['show_quantity'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['default_quantity'] = '1';
  $handler->display->display_options['fields']['add_to_cart_form']['combine'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['display_path'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['line_item_type'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'products';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Products';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  $views[$view->name] = $view;

  /**
   * User Account Address List
   */
  $view = new view();
  $view->name = 'xd_user_addresses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'efq_xtuple_xdruplecommerceaddress';
  $view->human_name = 'User Addresses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Addresses';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view personal rescued entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'line1' => 'line1',
    'line2' => 'line2',
    'line3' => 'line3',
    'city' => 'city',
    'state' => 'state',
    'postalCode' => 'postalCode',
    'country' => 'country',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'line1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'line2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'line3' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'city' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'postalCode' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'country' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Add New Link */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'Add New Link';
  $handler->display->display_options['header']['area']['content'] = '<a href=\'/xtuple/xdruplecommerceaddress/add\'>+ Add New Address</a>';
  if (module_exists('htmlpurifier')) {
    $handler->display->display_options['header']['area']['format'] = 'html_purifier_full';
  } else {
    $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  }
  /* Field: XdrupleCommerceAddress: Line1 */
  $handler->display->display_options['fields']['line1']['id'] = 'line1';
  $handler->display->display_options['fields']['line1']['table'] = 'efq_xtuple_xdruplecommerceaddress';
  $handler->display->display_options['fields']['line1']['field'] = 'line1';
  $handler->display->display_options['fields']['line1']['label'] = 'Address 1';
  $handler->display->display_options['fields']['line1']['link_to_entity'] = 1;
  /* Field: XdrupleCommerceAddress: Line2 */
  $handler->display->display_options['fields']['line2']['id'] = 'line2';
  $handler->display->display_options['fields']['line2']['table'] = 'efq_xtuple_xdruplecommerceaddress';
  $handler->display->display_options['fields']['line2']['field'] = 'line2';
  $handler->display->display_options['fields']['line2']['label'] = 'Address 2';
  $handler->display->display_options['fields']['line2']['link_to_entity'] = 0;
  /* Field: XdrupleCommerceAddress: Line3 */
  $handler->display->display_options['fields']['line3']['id'] = 'line3';
  $handler->display->display_options['fields']['line3']['table'] = 'efq_xtuple_xdruplecommerceaddress';
  $handler->display->display_options['fields']['line3']['field'] = 'line3';
  $handler->display->display_options['fields']['line3']['label'] = 'Address 3';
  $handler->display->display_options['fields']['line3']['link_to_entity'] = 0;
  /* Field: XdrupleCommerceAddress: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'efq_xtuple_xdruplecommerceaddress';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['link_to_entity'] = 0;
  /* Field: XdrupleCommerceAddress: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'efq_xtuple_xdruplecommerceaddress';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['link_to_entity'] = 0;
  /* Field: XdrupleCommerceAddress: Postal Code */
  $handler->display->display_options['fields']['postalCode']['id'] = 'postalCode';
  $handler->display->display_options['fields']['postalCode']['table'] = 'efq_xtuple_xdruplecommerceaddress';
  $handler->display->display_options['fields']['postalCode']['field'] = 'postalCode';
  $handler->display->display_options['fields']['postalCode']['label'] = 'Zip';
  $handler->display->display_options['fields']['postalCode']['link_to_entity'] = 0;
  /* Field: XdrupleCommerceAddress: Country */
  $handler->display->display_options['fields']['country']['id'] = 'country';
  $handler->display->display_options['fields']['country']['table'] = 'efq_xtuple_xdruplecommerceaddress';
  $handler->display->display_options['fields']['country']['field'] = 'country';
  $handler->display->display_options['fields']['country']['link_to_entity'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/addresses';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Addresses';
  $handler->display->display_options['menu']['weight'] = '20';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views[$view->name] = $view;

  /**
   * User Account Contact List
   */
  $view = new view();
  $view->name = 'xd_user_contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'efq_xtuple_xdruplecommercecontact';
  $view->human_name = 'User Contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Contacts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view personal rescued entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'firstName' => 'firstName',
    'lastName' => 'lastName',
    'primaryEmail' => 'primaryEmail',
    'phone' => 'phone',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'firstName' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'lastName' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'primaryEmail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'phone' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Add New Link */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'Add New Link';
  $handler->display->display_options['header']['area']['content'] = '<a href=\'/xtuple/xdruplecommercecontact/add\'>+ Add New Contact</a>';
  if (module_exists('htmlpurifier')) {
    $handler->display->display_options['header']['area']['format'] = 'html_purifier_full';
  } else {
    $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  }
  /* Field: XdrupleCommerceContact: First Name */
  $handler->display->display_options['fields']['firstName']['id'] = 'firstName';
  $handler->display->display_options['fields']['firstName']['table'] = 'efq_xtuple_xdruplecommercecontact';
  $handler->display->display_options['fields']['firstName']['field'] = 'firstName';
  $handler->display->display_options['fields']['firstName']['label'] = 'First Name';
  $handler->display->display_options['fields']['firstName']['link_to_entity'] = 1;
  /* Field: XdrupleCommerceContact: Last Name */
  $handler->display->display_options['fields']['lastName']['id'] = 'lastName';
  $handler->display->display_options['fields']['lastName']['table'] = 'efq_xtuple_xdruplecommercecontact';
  $handler->display->display_options['fields']['lastName']['field'] = 'lastName';
  $handler->display->display_options['fields']['lastName']['label'] = 'Last Name';
  $handler->display->display_options['fields']['lastName']['link_to_entity'] = 0;
  /* Field: XdrupleCommerceContact: Primary Email */
  $handler->display->display_options['fields']['primaryEmail']['id'] = 'primaryEmail';
  $handler->display->display_options['fields']['primaryEmail']['table'] = 'efq_xtuple_xdruplecommercecontact';
  $handler->display->display_options['fields']['primaryEmail']['field'] = 'primaryEmail';
  $handler->display->display_options['fields']['primaryEmail']['label'] = 'Primary Email';
  $handler->display->display_options['fields']['primaryEmail']['link_to_entity'] = 0;
  /* Field: XdrupleCommerceContact: Phone */
  $handler->display->display_options['fields']['phone']['id'] = 'phone';
  $handler->display->display_options['fields']['phone']['table'] = 'efq_xtuple_xdruplecommercecontact';
  $handler->display->display_options['fields']['phone']['field'] = 'phone';
  $handler->display->display_options['fields']['phone']['label'] = 'Phone';
  $handler->display->display_options['fields']['phone']['link_to_entity'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/contacts';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Contacts';
  $handler->display->display_options['menu']['weight'] = '20';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views[$view->name] = $view;

  /**
   * User Account Ship To List
   */
  $view = new view();
  $view->name = 'xd_user_shiptos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'efq_xtuple_xdruplecommerceshipto';
  $view->human_name = 'User Ship Tos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ship Tos';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view personal rescued entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'number' => 'number',
    'name' => 'name',
    'customer' => 'customer',
    'isDefault' => 'isDefault',
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
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'customer' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'isDefault' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Add New Link */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'Add New Link';
  $handler->display->display_options['header']['area']['content'] = '<a href=\'/xtuple/xdruplecommerceshipto/add\'>+ Add New Ship To</a>';
  if (module_exists('htmlpurifier')) {
    $handler->display->display_options['header']['area']['format'] = 'html_purifier_full';
  } else {
    $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  }
  /* Field: XdrupleCommerceContact: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'efq_xtuple_xdruplecommerceshipto';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['label'] = 'Number';
  $handler->display->display_options['fields']['number']['link_to_entity'] = 1;
  /* Field: XdrupleCommerceContact: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'efq_xtuple_xdruplecommerceshipto';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Name';
  $handler->display->display_options['fields']['name']['link_to_entity'] = 0;
  /* Field: XdrupleCommerceContact: Customer */
  $handler->display->display_options['fields']['customer']['id'] = 'customer';
  $handler->display->display_options['fields']['customer']['table'] = 'efq_xtuple_xdruplecommerceshipto';
  $handler->display->display_options['fields']['customer']['field'] = 'customer';
  $handler->display->display_options['fields']['customer']['label'] = 'Customer';
  $handler->display->display_options['fields']['customer']['link_to_entity'] = 0;
  /* Field: XdrupleCommerceContact: Is Default */
  $handler->display->display_options['fields']['isDefault']['id'] = 'isDefault';
  $handler->display->display_options['fields']['isDefault']['table'] = 'efq_xtuple_xdruplecommerceshipto';
  $handler->display->display_options['fields']['isDefault']['field'] = 'isDefault';
  $handler->display->display_options['fields']['isDefault']['label'] = 'Is Default';
  $handler->display->display_options['fields']['isDefault']['link_to_entity'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/shiptos';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Ship Tos';
  $handler->display->display_options['menu']['weight'] = '20';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views[$view->name] = $view;


  return $views;
}
