<?php

/**
 * @file keeps theming functions
 */

function template_preprocess_xdruple_commerce_cart_dropdown(&$variables) {
  $variables['link'] = url('cart');
}
