<?php
/**
 * @file
 * userprofile.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function userprofile_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_default_country';
  $strongarm->value = '';
  $export['site_default_country'] = $strongarm;

  return $export;
}
