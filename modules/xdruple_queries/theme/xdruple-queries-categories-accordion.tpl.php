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
          <h3 class="panel-title"><?php print $root_category->getName(); ?></h3>
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
                    <?php $sub_category_children = $sub_category->getChildren(); ?>
                    <?php if (!empty($sub_category_children)): ?>
                      <ul class="list-unstyled">
                        <?php foreach ($sub_category_children as $sub_sub_category): ?>
                          <li>
                            <?php print l($sub_sub_category->getName(), 'products/categories/' . $sub_sub_category->getId()) ?>
                          </li>
                        <?php endforeach; ?>
                      </ul>
                    <?php endif; ?>
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
