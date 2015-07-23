<?php

/**
 * @param $variables
 */
function template_preprocess_xdruple_saved_carts_block(&$variables) {
  /** @var stdClass $user */
  global $user;
  $variables["uid"] = $user->uid;
  $variables["empty"] = [
    "#theme" => "xdruple_empty",
    "#content" => t("You have no saved carts."),
  ];
  $variables["classes_array"]["panel"] = "panel";
  $variables["classes_array"]["panel-default"] = "panel-default";
  $variables["title_attributes_array"]["class"]["panel-heading"] = "panel-heading";
  $variables["content_attributes_array"]["class"]["panel-body"] = "panel-body";
}

/**
 * @param $variables
 */
function template_process_xdruple_saved_carts_block(&$variables) {
  $result = views_get_view_result($variables["view"], "default", $variables["uid"]);
  if (empty($result)) {
    $variables["content"] = drupal_render($variables["empty"]);
  }
  else {
    unset($variables["content_attributes_array"]["class"]["panel-body"]);
    $variables["content_attributes"] = drupal_attributes($variables["content_attributes_array"]);
    $variables["content"] = views_embed_view($variables["view"], "default", $variables["uid"]);
  }
}
