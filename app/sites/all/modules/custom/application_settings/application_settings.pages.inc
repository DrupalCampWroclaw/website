<?php
/**
 * @file
 * Pages callbacks.
 */

/**
 * Page callback.
 * @return string
 */
function application_settings_overview_page() {
  $output = '';

  $variables = application_settings_variables();
  if ($variables) {
    $links = array();
    foreach ($variables as $group_key => $group_value) {
      $links[] = array(
        'href' => 'admin/application/settings/' . $group_key,
        'title' => $group_key,
        'attributes' => array('class' => array('settings-link'))
      );
    }
    $output .= theme('links',  array(
        'links' => $links,
        'attributes' => array('class' => array('links'))));
  }

  return $output;
}

/**
 * Page callback.
 * @return string
 */
function application_settings_forms_page() {
  $output = '';
  $group = arg(3);
  $variables = application_settings_variables();
  if ($variables) {
    $group_variables = $variables[$group];
    $form = drupal_get_form('application_settings_forms', $group_variables);
    $output .= render($form);
  }
  else {
    $output .= t('No items');
  }
  return $output;
}

/**
 * Generate form.
 *
 * @param type $form_id
 * @param type $form_state
 * @param type $group_variables
 * @return type
 */
function application_settings_forms($form_id, $form_state, $group_variables) {

  $form = array();
  $form['groupname']['#markup'] = $group_variables;

  $languages = language_list('enabled');
  $languages = array_keys($languages[1]);

  $prefix = 'appset_';
  foreach ($group_variables as $item_key => $item_value) {
    $form[$item_key] =  array(
      '#type' => 'fieldset',
      '#title' => $item_value['#title'],
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    foreach ($languages as $lang_key) {
      if (!isset($item_value['#description'])) {
        $item_value['#description'] = '';
      }

      $form[$item_key][$prefix . $item_key . '_' . $lang_key] = $item_value;
      $form[$item_key][$prefix . $item_key . '_' . $lang_key]['#title'] = $lang_key;
      $form[$item_key][$prefix . $item_key . '_' . $lang_key]['#default_value'] = variable_get($prefix . $item_key . '_' . $lang_key, '');
      $form[$item_key][$prefix . $item_key . '_' . $lang_key]['#description'] = $item_value['#description']
              . ' | ' . t('Variable name short') . ': ' . $prefix . $item_key . ' ' . t('Variable name full') . ': ' . $prefix . $item_key . '_' . $lang_key;
    }
  }

  return system_settings_form($form);
}
