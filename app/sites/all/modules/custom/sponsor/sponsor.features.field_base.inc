<?php
/**
 * @file
 * sponsor.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function sponsor_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_sponsor_type'
  $field_bases['field_sponsor_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sponsor_type',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'diamond' => 'Diamond',
        'platinium' => 'Platinum',
        'gold' => 'Gold',
        'silver' => 'Silver',
        'bronze' => 'Bronze',
        'party' => 'Drupal night',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
