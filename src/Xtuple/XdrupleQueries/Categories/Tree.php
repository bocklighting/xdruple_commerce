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
        $xdcatalogs = entity_load('xtuple_xdcatalog');
      }
      else {
        // Paginate through all catalogs.
        $pages = ceil($count / 100);
        $xdcatalogs = array();

        $i = 0;
        while ($i < $pages) {
          $page_query = new EntityFieldQuery();
          $catalogs = $page_query->entityCondition('entity_type', 'xtuple_xdcatalog')
            ->range($i * 100, 100)
            ->propertyOrderBy('id', 'ASC')
            ->execute();

          $xdcatalogs = $xdcatalogs + $catalogs['xtuple_xdcatalog'];
          $i++;
        }
      }

      $root_key = NULL;

      // Find root group.
      foreach ($xdcatalogs as $key => $catalog) {
        if ($catalog->catalog) {
          $root_key = $key;
          $root_group = $catalog;
        }
      }

      if (empty($root_group) || empty($root_key)) {
        drupal_set_message(t('Catalog structure not set. Contact the site administrator.'), 'warning');

        return array();
      }

      $tree = array(
        $root_key => array(),
      );

      $catalog = array();
      if (!empty($tree)) {
        foreach (array_keys($tree) as $entityId) {
          $catalog[] = self::buildCategory($entityId);
        }
      }

      cache_set($cid, $catalog, 'cache', REQUEST_TIME + 60 * 60 * 1); // Expires 1 hour from now.
    }
    else {
      if (!$cache || empty($cache->data)) {
        $catalog = array();
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
    $category = new Category($entityId, $group->name);
    if (!empty($group->groups)) {
      foreach ($group->groups as $groupId) {
        $category->addChild(self::buildCategory($groupId));
      }
    }

    return $category;
  }
}
