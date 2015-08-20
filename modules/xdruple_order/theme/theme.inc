<?php

/**
 * @keeps theme callback
 */

use Xtuple\Xdruple\Theme\PrintAddressInfoHandler;
use Xtuple\Xdruple\Theme\PrintLineItems;
use Xtuple\Xdruple\Theme\PrintLogo;
use Xtuple\Xdruple\Theme\PrintMessage;
use Xtuple\Xdruple\Theme\PrintOrderInformation;
use Xtuple\Xdruple\Theme\PrintOrderTotal;
use Xtuple\Xdruple\Theme\PrintRemitToAddress;

/**
 * Preprocess variables for order-page.tpl.php
 *
 * @param $variables
 *
 * @throws \Exception
 */
function template_preprocess_order_page(&$variables) {
  $order = $variables['order'];
  $currency = $variables['currency'];
  $remit_to = $variables['remitto'];

  $variables['logo'] = theme('xdruple_print_logo', [
    'printLogo' => new PrintLogo(),
  ]);

  $variables['remit_to_address'] = theme('xdruple_print_remit_to_address', [
    'printRemitToAddress' => new PrintRemitToAddress(str_replace("\n", "<br />", $remit_to->address), TRUE),
  ]);

  $content = t('Thank you for ordering from @site.', [
    '@site' => variable_get('site_name'),
  ]);

  $variables['header_message'] = theme('xdruple_print_message', [
    'printMessage' => new PrintMessage($order->customer['name'], $content, 'header'),
  ]);

  $variables['header_table'] = theme('xdruple_print_order_information', [
    'printOrderInformation' => new PrintOrderInformation($order, NULL, $currency, 'Y-m-d', [
      PrintOrderInformation::SALES_ORDER_NUMBER => t('Sales Order #'),
      PrintOrderInformation::ORDER_DATE => t('Order date'),
      PrintOrderInformation::ACCOUNT_NUMBER => t('Account #'),
      PrintOrderInformation::PURCHASE_ORDER_NUMBER => t('PO #'),
      PrintOrderInformation::ORDER_SCHEDULE_DATE => t('Scheduled date'),
    ]),
  ]);

  $variables['billing_info'] = theme('xdruple_print_address_info', [
    'printAddressInfoHandler' => new PrintAddressInfoHandler($order, PrintAddressInfoHandler::BILL_TO),
    'title' => t('Billing information'),
  ]);

  $variables['shipping_info'] = theme('xdruple_print_address_info', [
    'printAddressInfoHandler' => new PrintAddressInfoHandler($order, PrintAddressInfoHandler::SHIP_TO),
    'title' => t('Shipping information'),
  ]);

  $variables['line_items_table'] = theme('xdruple_print_line_items', [
    'printLineItems' => new PrintLineItems($order, $currency),
  ]);

  $variables['order_total'] = theme('xdruple_print_order_total', [
    'printOrderTotal' => new PrintOrderTotal($order, $currency),
  ]);

  $content = t('Thank you,<br />The @site Team', [
    '@site' => variable_get('site_name'),
  ]);

  $variables['footer_message'] = theme('xdruple_print_message', [
    'printMessage' => new PrintMessage('', $content, 'footer'),
  ]);

  $variables['notes'] = theme('xdruple_print_message', [
    'printMessage' => new PrintMessage(t('Notes'), $order->orderNotes, 'notes'),
  ]);
}
