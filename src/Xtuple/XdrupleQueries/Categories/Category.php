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
  private $children = [];
  private $parents = [];
  private $path = [];

  /**
   * @param integer    $id
   * @param string     $name
   * @param Category[] $children
   */
  public function __construct($id, $name, $children = []) {
    $this->setId($id);
    $this->setName($name);
    $this->setChildren($children);
  }

  /**
   * @param Category $category
   */
  public function addChild(Category $category) {
    $this->children[] = $category;
    $category->addParent($this);
  }

  /**
   * @param Category $category
   */
  public function addParent(Category $category) {
    $this->parents[] = $category;
  }

  /**
   * @param array $path
   */
  public function addPath($path) {
    $this->path[] = $path;
  }

  /**
   * @return Category[]
   */
  public function getChildren() {
    return $this->children;
  }

  /**
   * @return Category[]
   */
  public function getParents() {
    return $this->parents;
  }

  /**
   * @return Category[]
   */
  public function getPath() {
    return $this->path;
  }

  /**
   * @param Category[] $children
   */
  public function setChildren($children) {
    $this->children = $children;
  }

  /**
   * @param Category[] $parents
   */
  public function setParents($parents) {
    $this->parents = $parents;
  }

  /**
   * @param array $path
   */
  public function setPath($path) {
    $this->path = $path;
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
