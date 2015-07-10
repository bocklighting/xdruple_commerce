<?php namespace Xtuple\XdrupleQueries\Categories;

use Xtuple\REST\Resource\DocumentAssociation\DocumentAssociationList;

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
  /** @var \Xtuple\REST\Resource\DocumentAssociation\DocumentAssociationList */
  private $documents;
  /** @var \stdClass[] */
  private $files = [];
  /** @var string */
  private $description = "";

  /**
   * @param integer    $id
   * @param string     $name
   * @param Category[] $children
   * @param array      $documents
   * @param string     $description
   */
  public function __construct($id, $name, $children = [], $documents = [], $description = "") {
    $this->setId($id);
    $this->setName($name);
    $this->setChildren($children);
    $this->setDocuments($documents);
    $this->description = $description;
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
   * @param bool $sorted
   *
   * @return \Xtuple\XdrupleQueries\Categories\Category[]
   */
  public function getChildren($sorted = FALSE) {
    if (!$sorted) {
      return $this->children;
    }
    else {
      $children = [];
      foreach ($this->children as $child) {
        $children[$child->getName()] = $child;
      }
      ksort($children, SORT_NATURAL);
      return $children;
    }
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

  /**
   * @param array $documents
   */
  public function setDocuments(array $documents) {
    $this->documents = DocumentAssociationList::constructFromResponseData($documents);
    $this->files = $this->importFiles();
  }

  /**
   * @return \Xtuple\REST\Resource\DocumentAssociation\DocumentAssociationList
   */
  public function getDocuments() {
    return $this->documents;
  }

  /**
   * @return \stdClass[]
   */
  public function files() {
    $files = [];
    foreach ($this->files as $key => $file) {
      if ($file->type !== "image") {
        $files[$key] = $file;
      }
    }
    return $files;
  }

  /**
   * @return \stdClass[]
   */
  public function images() {
    $files = [];
    foreach ($this->files as $key => $file) {
      if ($file->type == "image") {
        $files[$key] = $file;
      }
    }
    return $files;
  }

  /**
   * @return string
   */
  public function description() {
    return $this->description;
  }

  protected function importFiles() {
    $files = [];
    if (!empty($this->documents)) {
      $dir = "public://content/external/xd-catalog/" . $this->getId();
      file_prepare_directory($dir, FILE_MODIFY_PERMISSIONS | FILE_CREATE_DIRECTORY);
      foreach ($this->documents as $document) {
        if ($document->targetType() == "URL") {
          if ($file = entity_uuid_load("file", [$document->uuid()])) {
            $files[$document->uuid()] = array_pop($file);
          }
          else {
            try {
              if ($url = xdruple_fields_get_doc_url($document->target())) {
                $file = system_retrieve_file($url["path"], $dir, $managed = TRUE);
                $file->uuid = $document->uuid();
                $file = file_save($file);
                $files[$document->uuid()] = $file;
              }
            } catch (\Exception $e) {
              watchdog_exception("xdruple_queries", $e);
            }
          }
        }
      }
    }
    return $files;
  }
}
