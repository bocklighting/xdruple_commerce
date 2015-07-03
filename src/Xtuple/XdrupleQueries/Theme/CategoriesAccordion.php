<?php namespace Xtuple\XdrupleQueries\Theme;

use CDD\Bootstrap\Common\Context;
use CDD\Extensions\Theme\AbstractThemeHook;
use Xtuple\XdrupleQueries\Categories\Tree;

class CategoriesAccordion extends AbstractThemeHook {
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
    $variables['content_attributes_array'] = [
      'class' => [
        'panel',
        'panel-' . $this->getContext(),
      ],
    ];
    $variables['attributes_array'] = [
      'class' => [
        'b-categories-accordion',
      ],
    ];

    return $variables;
  }

  /**
   * @param int   $weight
   * @param array $variables
   *
   * @return array
   */
  public function render($weight = 0, array $variables = []) {
    $return = parent::render();
    $path = drupal_get_path("module", "xdruple_queries");
    $return["#attached"] = [
      "library" => [
        ["system", "ui.accordion"],
      ],
      "js" => [
        "$path/js/xdruple_queries.js",
      ],
    ];

    return $return;
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
