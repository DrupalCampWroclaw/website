<?php
/**
 * @file
 * Pages callbacks.
 */

/**
 * Placeholder for application settings page.
 * URL: /admin/application
 */
function application_api_admin_page() {
  $output = t('Application settings');
  $result_parent = db_select('menu_links', 'm')
    ->fields('m')
    ->condition('menu_name', 'management', '=')
    ->condition('link_path', 'admin/application', '=')
    ->execute()
    ->fetchAssoc();

  $mlid = $result_parent['mlid'];
  $result_childrens = db_select('menu_links', 'm')
    ->fields('m')
    ->condition('plid', $mlid, '=')
    ->execute();
  foreach ($result_childrens as $child_item) {
    $output .= '<p>' . l($child_item->link_title, $child_item->link_path) . '</p>';
  }

  return $output;
}
