<?php

/**
 * @file
 * Field handler to present a button to move a saved cart to the active cart.
 * Contains class xdruple_invoice_handler_currency_formatter.
 *
 * Heavily borrowed from the Currency module. We could use that module, but it
 * doesn't work on PostgresQL databases.
 * @See: https://drupal.org/node/2007388
 */

/**
 * Field handler to present a button to move a saved cart to the active cart.
 */
//class xdruple_commerce_handler_currency_formatter extends views_handler_field {
class xdruple_commerce_handler_currency_formatter extends entity_views_handler_field_numeric {

  /**
   * Implements the undocumented views_object::definition property.
   *
   * @var array
   */
  public $definition = array(
    // A default currency code to use for the amounts.
    'currency_code' => 'USD',
    // The name of the database field the currency code is in.
    'currency_code_field' => NULL,
    // The name of the database table currency_field is in. Defaults to the
    // same table this handler is used on.
    'currency_code_table' => NULL,
    'type' => 'decimal',
    'float' => TRUE,
    'click sortable' => TRUE,
  );

  /**
   * Overrides parent::set_definition().
   *
   * @param $definition
   */
  function set_definition($definition) {
    $this->definition = array_merge($this->definition, $definition);
    if (isset($definition['field'])) {
      $this->real_field = $definition['field'];
    }
  }

  /**
   * Overrides parent::query().
   */
  function query() {
    $this->ensure_my_table();
    if ($this->definition['currency_code_field']) {
      $this->additional_fields['currency_code_field'] = array(
        'field' => $this->definition['currency_code_field'],
        'table' => $this->definition['currency_code_table'] ? $this->definition['currency_code_table'] : $this->table_alias,
      );
    }
    parent::query();
  }

  /**
   * Overrides parent::render().
   * Dynamically adds currency symbol to the rendered amount based on the currency column.
   *
   * @param $values
   *
   * @return string
   */
  function render($values) {
    $amount = parent::render($values);
    $currency = $this->getCurrency($values);

    // Add the currency symbol to the rendered amount.
    $format = $currency->symbol . $amount;

    return $format;
  }

  /**
   * Loads the Currency for this field.
   *
   * @throws RuntimeException
   *
   * @param $values
   *   A values object as received by $this->render().
   *
   * @return Currency
   */
  function getCurrency($values) {
    $currency = NULL;

    if ($this->definition['currency_code_field']) {
      $currency_code = $this->get_value($values, 'currency_code_field');
      if ($currency_code) {
        $currency = $this->currency_load($currency_code);
      }
    }
    if (!$currency) {
      $currency = $this->currency_load($this->definition['currency_code']);
    }
    if (!$currency) {
      $currency = $this->currency_load('XXX');
    }
    if (!$currency) {
      throw new RuntimeException(t('Could not load currency with ISO 4217 code XXX.'));
    }

    return $currency;
  }

  /**
   * Gets this field's.
   *
   * If the amount cannot be fetched from your implementation's database field
   * as a numeric string, you should override this method so it returns a
   * numeric/decimal representation of the amount.
   *
   * @param $values
   *   A values object as received by $this->render().
   *
   * @return string
   *   A numeric string.
   */
  function getAmount($values) {
    return $this->get_value($values);
  }

  /**
   * Loads the Currency for this field from the REST API.
   *
   * @param $currency_code
   *   The currency code.
   *
   * @return \Xtuple\Rescued\Controller\Entity - xTuple's Currency resource for the matching code.
   */
  function currency_load($currency_code) {
    $currency = NULL;

    $currency = entity_load_single('xtuple_currency', $currency_code);

    return $currency;
  }
}
