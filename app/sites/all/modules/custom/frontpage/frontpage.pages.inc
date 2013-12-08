<?php
/**
 * @file
 * Pages callbacks.
 */

/**
 * Front page callback.
 *
 * @return
 *   HTML output.
 */
function frontpage_main_page() {
  $output = '';

  if (user_is_logged_in()) {
    $output .= frontpage_main_page_logged_in();
  }
  else {
    $output .= frontpage_main_page_anonymous();
  }
  return $output;
}

/**
 * Front page content for anonymous users.
 * Components:
 *  - Login block.
 *
 * @return
 *   HTML output
 */
function frontpage_main_page_anonymous() {
  $output = '';
  $block = module_invoke('user', 'block_view', 'login');
  $output .= '<h2>' . t('Log in') . '</h2>';
  $output .= render($block['content']);
  return $output;
}

/**
 * Front page content for logged in users.
 *
 * @return
 *   HTML output.
 */
function frontpage_main_page_logged_in() {
  $output = '';
  $output .= '<h2>' . t('Welcome!') . '</h2>';
  return $output;
}
