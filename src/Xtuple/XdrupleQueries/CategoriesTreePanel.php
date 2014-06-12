<?php namespace Xtuple\XdrupleQueries;

use CDD\Bootstrap\Drupal\Panel;

class CategoriesTreePanel extends Panel {
  public function __construct($title = 'Categories') {
    parent::__construct('categories-tree', '', t($title));
  }

  protected function getBody() {
    return xdruple_queries_categories_tree_block();
  }
}
