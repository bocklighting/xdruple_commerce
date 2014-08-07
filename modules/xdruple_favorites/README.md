# xDruple Favorites

Provides functionality for "Favorite" items ("Standard order")

## Usage

* module provides `products/favorites` page that shows the list of favorite products;
* module provides `xdruple_favorites_favorites_title` variable (defaults to `Favorite products`) that allows modules
to override name of this section (e. g. to `Standard orders`);
* module provides `xdruple_favorites_ajax_enabled` variable (default to `TRUE`) that enables processing "Add to" and
"Remove from" Favorites forms submissions via AJAX;
* module provides `xdruple_favorites_add_to_favorites_form` and `xdruple_favorites_remove_from_favorites_form` forms to
add or remove products; to get these form it's __highly recommended__ to use `xdruple_favorites_get_favorites_form()`
function, as it encapsulates check if product is in the "Favorites" or not and so returns either "Add to" or "Remove
from" Favorites form array;

## Hooks

### `hook_xdruple_favorites_favorites_form_submit_ajax_commands_alter`

Hook should be used to alter AJAX commands list for "Add to" and "Remove from" form submissions. For example:

```php
function core_xdruple_favorites_favorites_form_submit_ajax_commands_alter(&$commands, $form, $form_state, $new_form) {
  if ($form['#page_url'] == 'products/favorites') {
    if (!empty($commands['replace'])) {
      $commands['remove'] = ajax_command_remove("tr:has(#{$new_form['#id']})");
    }
  }
}
```
