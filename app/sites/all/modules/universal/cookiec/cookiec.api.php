<?php

/**
 * Implements hook_cookie_langcode_alter()
 */
function hook_cookiec_langcode_alter(&$langcode) {
  // I wan to switch to chinese.
  $langcode = 'cn';
}
