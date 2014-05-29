<?php

function template_preprocess_block_categories_tree(&$variables) {
  if (!empty($variables['name'])) {
    $base_class     = 'b-block';
    $instance_class = drupal_clean_css_identifier($base_class . '-' . $variables['name']);

    $variables['attributes_array'] += array(
      'class' => array(
        $base_class,
        $instance_class
      ),
    );

    $variables['title_attributes_array'] += array(
      'class' => array(
        "$base_class--title",
        "$instance_class--title",
      ),
    );

    $variables['content_attributes_array'] += array(
      'class' => array(
        "$base_class--content",
        "$instance_class--content",
      ),
    );

    $variables['content'] = xdruple_queries_categories_tree_block();
  }
}
