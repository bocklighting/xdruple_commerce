<?php namespace Xtuple\XdrupleQueries\Theme;

use CDD\Bootstrap\Common\Context;
use CDD\Extensions\Theme\AbstractThemeHook;
use Xtuple\XdrupleQueries\Categories\Tree;

class CategoriesDropdown extends AbstractThemeHook {
  private $context = Context::NONE;

  public function __construct($context = Context::NONE) {
    $this->setContext($context);
  }

  /**
   * @return array
   */
  public function preprocess() {
    $variables = parent::preprocess();
    $variables['catalog'] = Tree::getCatalog();
    $variables['content_attributes_array'] = array(
      'class' => array(
        'panel',
        'panel-' . $this->getContext(),
      ),
    );
    $variables['attributes_array'] = array(
      'class' => array(
        'b-categories-dropdown',
        'b-categories-dropdown--left',
      ),
    );

    return $variables;
  }

  /**
   * @return string
   */
  public function getContext() {
    return $this->context;
  }

  /**
   * @param string $context
   */
  public function setContext($context) {
    $this->context = $context;
  }
}
