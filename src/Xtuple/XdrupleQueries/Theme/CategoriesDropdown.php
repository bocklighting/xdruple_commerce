<?php namespace Xtuple\XdrupleQueries\Theme;

use CDD\Extensions\Theme\AbstractThemeHook;
use Xtuple\XdrupleQueries\Categories\Tree;

class CategoriesDropdown extends AbstractThemeHook {
  /**
   * @return array
   */
  public function preprocess() {
    $variables = parent::preprocess();
    $variables['catalog'] = Tree::getCatalog();

    return $variables;
  }
}
