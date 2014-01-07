<?php
/**
 * @file
 * session.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function session_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function session_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function session_flag_default_flags() {
  $flags = array();
  // Exported flag: "Session Vote".
  $flags['session_vote'] = array(
    'entity_type' => 'node',
    'title' => 'Session Vote',
    'global' => 0,
    'types' => array(
      0 => 'session',
    ),
    'flag_short' => 'I\'d like to attend this session',
    'flag_long' => 'Express interest in this session',
    'flag_message' => 'Your vote has been recorded!',
    'unflag_short' => 'Retract interest in session',
    'unflag_long' => 'Retract your vote for this session.',
    'unflag_message' => 'Your vote has been retracted.',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 0,
      'rss' => 0,
      'diff_standard' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'module' => 'session',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function session_node_info() {
  $items = array(
    'session' => array(
      'name' => t('Session'),
      'base' => 'node_content',
      'description' => t('Session'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
