<?php
/**
 * @file
 * timeslot.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function timeslot_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-timeslot-field_timeslot_date'
  $field_instances['node-timeslot-field_timeslot_date'] = array(
    'bundle' => 'timeslot',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'short',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_timeslot_date',
    'label' => 'Date',
    'required' => 1,
    'settings' => array(
      'default_value' => 'strtotime',
      'default_value2' => 'strtotime',
      'default_value_code' => '2014-05-17',
      'default_value_code2' => '2014-05-17',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 5,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_select',
      'weight' => -4,
    ),
  );

  // Exported field_instance: 'node-timeslot-field_timeslot_room'
  $field_instances['node-timeslot-field_timeslot_room'] = array(
    'bundle' => 'timeslot',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_timeslot_room',
    'label' => 'Room',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Date');
  t('Room');

  return $field_instances;
}
