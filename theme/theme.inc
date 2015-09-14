<?php

/**
 * @file keeps theming functions
 *
 * @param $variables
 */

function template_preprocess_xdruple_commerce_cart_dropdown(&$variables) {
  $variables['link'] = url('cart');
}
