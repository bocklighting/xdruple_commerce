<?php namespace Xtuple\XdrupleQueries\Categories;

use EntityFieldQuery;

class Tree {
  /**
   * @return array
   */
  static public function getCatalog() {
    $cid = 'xtuple_xdcatalog-tree';
    $cache = cache_get($cid, 'cache');
    $entity_info = entity_get_info('xtuple_xdcatalog');

    if ((empty($cache) || xdruple_cache_expired($cache)) && !empty($entity_info)) {
      $query = new EntityFieldQuery();
      $count = $query->entityCondition('entity_type', 'xtuple_xdcatalog')
                     ->count()
                     ->execute();

      if ($count <= 100) {
        $xd_catalogs = entity_load('xtuple_xdcatalog');
      }
      else {
        // Paginate through all catalogs.
        $pages = ceil($count / 100);
        $xd_catalogs = [];

        $i = 0;
        while ($i < $pages) {
          $page_query = new EntityFieldQuery();
          $catalogs = $page_query->entityCondition('entity_type', 'xtuple_xdcatalog')
                                 ->range($i * 100, 100)
                                 ->propertyOrderBy('id', 'ASC')
                                 ->execute();

          $xd_catalogs = $xd_catalogs + $catalogs['xtuple_xdcatalog'];
          $i++;
        }
      }

      $root_key = NULL;

      // Find root group.
      foreach ($xd_catalogs as $key => $catalog) {
        if ($catalog->catalog) {
          $root_key = $key;
          $root_group = $catalog;
        }
      }

      if (empty($root_group) || empty($root_key)) {
        drupal_set_message(t('Catalog structure not set. Contact the site administrator.'), 'warning');

        return [];
      }

      $tree = [
        $root_key => [],
      ];

      $catalog = [];
      if (!empty($tree)) {
        foreach (array_keys($tree) as $entityId) {
          $catalog[] = self::buildCategory($entityId);
        }
      }
      self::buildPath($catalog[0]);

      cache_set($cid, $catalog, 'cache', REQUEST_TIME + 60 * 60 * 1); // Expires 1 hour from now.
    }
    else {
      if (!$cache || empty($cache->data)) {
        $catalog = [];
      }
      else {
        $catalog = $cache->data;
      }
    }

    return $catalog;
  }

  /**
   * @param $entityId
   *
   * @return Category
   */
  static public function buildCategory($entityId) {
    // This relies on the entity static cache to be fast. The calling function
    // getCatalog() called entity_load('xtuple_xdcatalog'), so entity_load_single()
    // will hit it's static cache instead of the REST API.
    $group = entity_load_single('xtuple_xdcatalog', $entityId);
    $category = new Category($entityId, $group->name, [], $group->documents);
    if (!empty($group->groups)) {
      foreach ($group->groups as $groupId) {
        $category->addChild(self::buildCategory($groupId));
      }
    }

    return $category;
  }

  /**
   * Search a catalog tree and find a child category by category name.
   *
   * @param Category $category      The Category that is the root of the catalog tree.
   * @param string   $category_name The name of the child category to find.
   *
   * @return Category
   */
  static public function findChildByName($category, $category_name) {
    foreach ($category->getChildren() as $branch) {
      if ($branch->getName() === $category_name) {
        return $branch;
      }
      else {
        // Recurse into children.
        $found = self::findChildByName($branch, $category_name);
        if (!empty($found)) {
          return $found;
        }
      }
    }
    return NULL;
  }

  /**
   * Builds the tree path used for breadcrumbs from the root of the catalog tree
   * by setting the $category->path array on each Category branch of the tree.
   *
   * @param Category $category The Category that is the root of the catalog tree.
   */
  static public function buildPath($category) {
    foreach ($category->getChildren() as $child) {
      // We allow a many-to-many tree, so there is no one true path for breadcrumbs.
      // Instead, we alpha sort the parent names and grab the first parent to use
      // for setting the breadcrumb path.
      $parent_names = [];
      $parents = $child->getParents();
      foreach ($parents as $parent) {
        $parent_names[$parent->getName()] = $parent;
      }

      if (!empty($parent_names)) {
        // Alpha sort on parent name key and get first parent.
        ksort($parent_names);
        $first_parent = array_shift($parent_names);
        $parent_paths = $first_parent->getPath();

        // Add parent tree paths to the child path.
        foreach ($parent_paths as $parent_path) {
          $child->addPath($parent_path);
        }

        // Then add the new immediate parent to the child path.
        $path = [
          'id' => $first_parent->getId(),
          'name' => $first_parent->getName(),
        ];
        $child->addPath($path);
      }

      // Recurse into children.
      self::buildPath($child);
    }
  }
}
