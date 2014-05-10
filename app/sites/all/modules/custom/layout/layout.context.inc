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
        'layout-frontpage_top' => array(
          'module' => 'layout',
          'delta' => 'frontpage_top',
          'region' => 'content_top',
          'weight' => '-10',
        ),
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
        'layout-flickr_gallery' => array(
          'module' => 'layout',
          'delta' => 'flickr_gallery',
          'region' => 'footer',
          'weight' => '6',
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
  $context->name = 'node_add_session';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/add/session' => 'node/add/session',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['node_add_session'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sessions_proposed';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'sessions/proposed' => 'sessions/proposed',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['sessions_proposed'] = $context;

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
          'weight' => '15',
        ),
        'layout-sessions' => array(
          'module' => 'layout',
          'delta' => 'sessions',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('sitewide');
  $export['sitewide'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_profile';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-sessions_user-block' => array(
          'module' => 'views',
          'delta' => 'sessions_user-block',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['user_profile'] = $context;

  return $export;
}
