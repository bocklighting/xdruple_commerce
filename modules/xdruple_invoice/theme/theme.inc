<?php

/**
 * @keeps theme callback
 */

use xTuple\xDruple\Theme\PrintAddressInfoHandler;
use xTuple\xDruple\Theme\PrintLineItems;
use xTuple\xDruple\Theme\PrintLogo;
use xTuple\xDruple\Theme\PrintMessage;
use xTuple\xDruple\Theme\PrintOrderInformation;
use xTuple\xDruple\Theme\PrintOrderTotal;
use xTuple\xDruple\Theme\PrintRemitToAddress;
use xTuple\xDruple\Theme\PrintTrackingInfo;

/**
 * Preprocess variables for invoice-page.tpl.php
 */
function template_preprocess_invoice_page(&$variables) {
  $invoice   = $variables['invoice'];
  $currency  = $variables['currency'];
  $order     = $variables['order'];
  $remit_to  = $variables['remitto'];
  $shipments = $variables['shipments'];

  $variables['logo'] = theme('xdruple_print_logo', array(
    'printLogo' => new PrintLogo()
  ));

  $variables['remit_to_address'] = theme('xdruple_print_remit_to_address', array(
    'printRemitToAddress' => new PrintRemitToAddress(str_replace("\n", "<br />", $remit_to->address), TRUE),
  ));

  $content = t('Thank you for ordering from @site. Please keep a copy of this invoice for your records.', array(
    '@site' => variable_get('site_name'),
  ));

  $variables['header_message'] = theme('xdruple_print_message', array(
    'printMessage' => new PrintMessage($invoice->customer['name'], $content, 'header'),
  ));

  $variables['header_table'] = theme('xdruple_print_order_information', array(
    'printOrderInformation' => new PrintOrderInformation($order, $invoice, $currency, 'Y-m-d', array(
        PrintOrderInformation::INVOICE_NUMBER        => t('Invoice #'),
        PrintOrderInformation::INVOICE_DATE          => t('Invoice date'),
        PrintOrderInformation::ACCOUNT_NUMBER        => t('Account #'),
        PrintOrderInformation::SALES_ORDER_NUMBER    => t('Sales order #'),
        PrintOrderInformation::ORDER_DATE            => t('Order date'),
        PrintOrderInformation::PURCHASE_ORDER_NUMBER => t('PO #'),
        PrintOrderInformation::INVOICE_DUE_DATE      => t('Scheduled date'),
        PrintOrderInformation::TOTAL_DUE             => t('Total due'),
      )),
  ));

  $variables['billing_info'] = theme('xdruple_print_address_info', array(
    'printAddressInfoHandler' => new PrintAddressInfoHandler($invoice, PrintAddressInfoHandler::BILL_TO),
    'title'                   => t('Billing information'),
  ));

  $variables['shipping_info'] = theme('xdruple_print_address_info', array(
    'printAddressInfoHandler' => new PrintAddressInfoHandler($order, PrintAddressInfoHandler::SHIP_TO),
    'title'                   => t('Shipping information'),
  ));

  $variables['line_items_table'] = theme('xdruple_print_line_items', array(
    'printLineItems' => new PrintLineItems($order, $currency),
  ));

  $variables['order_total'] = theme('xdruple_print_order_total', array(
    'printOrderTotal' => new PrintOrderTotal($order, $currency),
  ));

  $content = t('Thank you,<br />The @site Team', array(
    '@site' => variable_get('site_name'),
  ));

  $variables['footer_message'] = theme('xdruple_print_message', array(
    'printMessage' => new PrintMessage('', $content, 'footer'),
  ));

  $variables['notes'] = theme('xdruple_print_message', array(
    'printMessage' => new PrintMessage(t('Notes'), $order->orderNotes, 'notes'),
  ));

  $variables['tracking'] = theme('xdruple_print_tracking_info', array(
    'printTrackingInfo' => new PrintTrackingInfo(t('Tracking numbers'), $shipments),
  ));
}
