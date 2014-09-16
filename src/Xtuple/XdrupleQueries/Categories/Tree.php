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
      $root_group = $query->entityCondition('entity_type', 'xtuple_xdcatalog')
        ->propertyCondition('catalog', TRUE, '=')
        ->execute();

      if (empty($root_group['xtuple_xdcatalog'])) {
        drupal_set_message(t('Catalog structure not set. Contact the site administrator.'), 'warning');

        return array();
      }

      $root_key = key($root_group['xtuple_xdcatalog']);

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
