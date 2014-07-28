<?php namespace Xtuple\XdrupleQueries\Categories;

use EntityFieldQuery;

class Tree {
  /**
   * @return array
   */
  static public function getAll() {
    $cid = 'xtuple_xdcatalog-tree';
    $cache = cache_get($cid, 'cache');
    $entity_info = entity_get_info('xtuple_xdcatalog');

    if (empty($cache) && !empty($entity_info)) {
      $query = new EntityFieldQuery();
      $root_group = $query->entityCondition('entity_type', 'xtuple_xdcatalog')
        ->propertyCondition('catalog', TRUE, '=')
        ->execute();

      if (empty($root_group['xtuple_xdcatalog'])) {
        drupal_set_message(t('Catalog structure not set. Contact the site administrator.'), 'warning');

        return array('tree' => array(), 'catalog' => array());
      }

      $root_key = key($root_group['xtuple_xdcatalog']);

      $tree = array(
        $root_key => array(),
      );
      $catalog = array();

      if (!empty($tree)) {
        self::build($tree, $catalog);
      }

      $cache_data = array(
        'tree' => $tree,
        'catalog' => $catalog
      );

      cache_set($cid, $cache_data, 'cache', CACHE_TEMPORARY);
    }
    else {
      if (!$cache || empty($cache->data)) {
        $cache_data = array(
          'tree' => array(),
          'catalog' => array()
        );
      }
      else {
        $cache_data = $cache->data;
      }
    }

    return $cache_data;
  }

  /**
   * @param $tree
   * @param $catalog
   */
  static public function build(&$tree, &$catalog) {
    foreach ($tree as $id => $temp) {
      $group = entity_load_single('xtuple_xdcatalog', $id);
      $catalog[$id] = $group;

      foreach ($group->groups as $group_id) {
        $tree[$id][$group_id] = array();
      }

      self::build($tree[$id], $catalog);
    }
  }
}
