<?php
/**
 * @var \Xtuple\XdrupleQueries\Categories\Category[] $catalog
 * @var string                                       $content_attributes
 * @var string                                       $attributes
 */
?>
<?php if (!empty($catalog)): ?>
  <?php foreach ($catalog as $root_category): ?>
    <div<?php print $attributes ?>>
      <div<?php print $content_attributes; ?>>
        <div class="panel-heading">
          <h3 class="panel-title"><?php print $title; ?></h3>
        </div>
        <div class="panel-body">
          <?php foreach ($root_category->getChildren() as $category): ?>
            <?php $category_children = $category->getChildren(); ?>
            <?php if (!empty($category_children)): ?>
              <div class="accordion-item-title item-title">
                <?php print l($category->getName(), 'products/categories/' . $category->getId()) ?>
              </div>
              <div class="accordion-item-subcategories">
                <?php foreach ($category_children as $i => $sub_category): ?>
                  <div class="subcategories-item">
                    <div class="subcategory-title">
                      <?php print l($sub_category->getName(), 'products/categories/' . $sub_category->getId()) ?>
                    </div>
                  </div>
                <?php endforeach; ?>
              </div>
            <?php else: ?>
              <div class="item-title ui-corner-all">
                <?php print l($category->getName(), 'products/categories/' . $category->getId()) ?>
              </div>
            <?php endif; ?>
          <?php endforeach; ?>
        </div>
      </div>
    </div>
  <?php endforeach; ?>
<?php endif; ?>
