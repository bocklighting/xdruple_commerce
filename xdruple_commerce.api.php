<?php

/**
 * @file
 * Hooks provided by the xdruple_commerce module.
 */

/**
 * Lets modules override access to checkout.
 * @See: xdruple_commerce_access_checkout()
 *
 * @param boolean $access
 *   Flag to grant user access to checkout.
 * @param object $user
 *   The user requesting access.
 * @param string $permission
 *   The name of the permission being checked.
 */
function hook_xdruple_commerce_access_checkout_alter(&$access, $user, $permission) {
  // TODO: Set $access to true or false based on your custom logic.
  if ($access && $user->uid > 0) {
    $access = true;
  }
}

/**
 * Lets modules override access to the cart.
 * @See: xdruple_commerce_access_cart()
 *
 * @param boolean $access
 *   Flag to grant user access to checkout.
 * @param object $user
 *   The user requesting access.
 * @param string $permission
 *   The name of the permission being checked.
 */
function hook_xdruple_commerce_access_cart_alter(&$access, $user, $permission) {
  // TODO: Set $access to true or false based on your custom logic.
  if ($access && $user->uid > 0) {
    $access = true;
  }
}
