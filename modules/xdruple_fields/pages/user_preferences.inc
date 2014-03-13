<?php

/**
 * @file keeps callbacks for user/%user/preferences page
 */

/**
 * Page callback
 *
 * @param $account
 * @return string
 */
function xdruple_fields_user_preferences_page($account) {
  $output = '';

  $form = drupal_get_form('xtuple_order_defaults_form');
  $output .= drupal_render($form);

  return $output;
}

/**
 * Access callback
 *
 * @param $account
 * @return bool
 */
function xdruple_fields_user_preferences_access($account) {
//  $access = FALSE;
$access = TRUE;
  global $user;
  if (user_access('edit personal rescued entities') && $user->uid == $account->uid) {
    $access = TRUE;
  }

  return $access;
}
