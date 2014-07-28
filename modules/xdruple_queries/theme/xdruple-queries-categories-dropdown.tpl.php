<?php
/**
 * @var \Xtuple\XdrupleQueries\Categories\Category[] $catalog
 */
?>
<?php if (!empty($catalog)): ?>
  <?php foreach ($catalog as $root_category): ?>
    <div class="b-categories-dropdown b-categories-dropdown--left">
      <div class="panel panel-primary">
        <div class="panel-heading">
          <h3 class="panel-title"><?php print $root_category->getName(); ?></h3>
        </div>

        <ul class="list-group">
          <?php foreach ($root_category->getChildren() as $category): ?>
            <li class="list-group-item">
              <div class="list-group-item-title"><?php print $category->getName() ?></div>
              <?php $category_children = $category->getChildren(); ?>
              <?php if (!empty($category_children)): ?>
                <div class="list-group-item-subcategories">
                  <?php $row_open = FALSE; ?>
                  <?php foreach ($category_children as $i => $sub_category): ?>
                    <?php if ($i % 3 === 0): ?>
                      <?php print '<div class="list-group-item-subcategories-row row">'; ?>
                      <?php $row_open = TRUE; ?>
                    <?php endif; ?>
                    <div class="col-lg-4">
                      <h4 class="subcategory-title"><?php print $sub_category->getName() ?></h4>
                      <?php $sub_category_children = $sub_category->getChildren(); ?>
                      <?php if (!empty($sub_category_children)): ?>
                        <ul>
                          <?php foreach ($sub_category_children as $sub_sub_category): ?>
                            <li><?php print $sub_sub_category->getName() ?></li>
                          <?php endforeach; ?>
                        </ul>
                      <?php endif; ?>
                    </div>
                    <?php if ($i % 3 === 2): ?>
                      <?php print '</div>'; ?>
                      <?php $row_open = FALSE; ?>
                    <?php endif; ?>
                  <?php endforeach; ?>
                  <?php if ($row_open): ?>
                    <?php print '</div>'; ?>
                  <?php endif; ?>
                </div>
              <?php endif; ?>
            </li>
          <?php endforeach; ?>
        </ul>
      </div>
    </div>
  <?php endforeach; ?>
<?php endif; ?>
