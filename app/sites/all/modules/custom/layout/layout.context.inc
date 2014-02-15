<?php
/**
 * @file
 * layout.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function layout_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontpage';
  $context->description = '';
  $context->tag = 'Layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-sponsors_frontpage_block-block' => array(
          'module' => 'views',
          'delta' => 'sponsors_frontpage_block-block',
          'region' => 'footer',
          'weight' => '-14',
        ),
        'views-8b25923f8a8f31d204c26febe72e3b65' => array(
          'module' => 'views',
          'delta' => '8b25923f8a8f31d204c26febe72e3b65',
          'region' => 'footer',
          'weight' => '-13',
        ),
        'views-c29026ea424da992d018da7a9cbfe178' => array(
          'module' => 'views',
          'delta' => 'c29026ea424da992d018da7a9cbfe178',
          'region' => 'footer',
          'weight' => '-12',
        ),
        'layout-social_facebook_gplus_twitter' => array(
          'module' => 'layout',
          'delta' => 'social_facebook_gplus_twitter',
          'region' => 'footer',
          'weight' => '5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout');
  $export['frontpage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = 'sitewide';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'superfish-1' => array(
          'module' => 'superfish',
          'delta' => '1',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'views-sponsors_diamond_block-block' => array(
          'module' => 'views',
          'delta' => 'sponsors_diamond_block-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('sitewide');
  $export['sitewide'] = $context;

  return $export;
}
