<?php

/**
 * @file keeps callbacks for user/%user/preferences page
 */

/**
 * Access callback
 *
 * @param $account
 * @return bool
 */
function xdruple_fields_user_preferences_access($account) {
  $access = FALSE;

  global $user;
  if (user_access('edit personal rescued entities') && $user->uid == $account->uid) {
    $access = TRUE;
  }

  return $access;
}
