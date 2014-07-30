<?php namespace Xtuple\XdrupleQueries\Categories;

/**
 * Class Category
 *
 * @package Xtuple\XdrupleQueries\Categories
 */
class Category {
  /**
   * @var
   */
  private $name;

  /**
   * @var
   */
  private $id;

  /**
   * @var Category[]
   */
  private $children = array();

  /**
   * @param integer    $id
   * @param string     $name
   * @param Category[] $children
   */
  public function __construct($id, $name, $children = array()) {
    $this->setId($id);
    $this->setName($name);
    $this->setChildren($children);
  }

  /**
   * @param Category $category
   */
  public function addChild(Category $category) {
    $this->children[] = $category;
  }

  /**
   * @return Category[]
   */
  public function getChildren() {
    return $this->children;
  }

  /**
   * @param Category[] $children
   */
  public function setChildren($children) {
    $this->children = $children;
  }

  /**
   * @return integer
   */
  public function getId() {
    return $this->id;
  }

  /**
   * @param integer $id
   */
  public function setId($id) {
    $this->id = $id;
  }

  /**
   * @return string
   */
  public function getName() {
    return $this->name;
  }

  /**
   * @param string $name
   */
  public function setName($name) {
    $this->name = $name;
  }
}
