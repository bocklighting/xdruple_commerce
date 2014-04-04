<?php

/**
 * @keeps theme callback
 */

/**
 * Preprocess variables for invoice-page.tpl.php
 */
function template_preprocess_invoice_page(&$variables) {
  $invoice = $variables['invoice'];

  $variables['number']       = $invoice->number;
}
