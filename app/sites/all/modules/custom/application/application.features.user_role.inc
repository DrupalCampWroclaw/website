<?php
/**
 * @file
 * application.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function application_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: conference organizer.
  $roles['conference organizer'] = array(
    'name' => 'conference organizer',
    'weight' => 3,
  );

  return $roles;
}
