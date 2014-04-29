<?php

/**
 * @file
 * Hooks provided by the xdruple_queries module.
 */

/**
 * Lets modules override access to checkout.
 * @See: xdruple_queries_access_product_lists()
 *
 * @param boolean $access
 *   Flag to grant user access to checkout.
 * @param object $user
 *   The user requesting access.
 * @param string $permission
 *   The name of the permission being checked.
 */
function hook_xdruple_queries_access_product_lists_alter(&$access, $user, $permission) {
  // TODO: Set $access to true or false based on your custom logic.
  if ($access && $user->uid > 0) {
    $access = true;
  }
}
