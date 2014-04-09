<?php
/**
 * @file
 * sponsor.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sponsor_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'sponsors_diamond_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'sponsors_diamond_block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Diamond sponsors';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['empty'] = TRUE;
  $handler->display->display_options['footer']['php']['php_output'] = '<?php print l(t(\'All sponsors\'), \'sponsors\'); ?>
';
  /* No results behavior: Global: PHP */
  $handler->display->display_options['empty']['php']['id'] = 'php';
  $handler->display->display_options['empty']['php']['table'] = 'views';
  $handler->display->display_options['empty']['php']['field'] = 'php';
  $handler->display->display_options['empty']['php']['empty'] = TRUE;
  $handler->display->display_options['empty']['php']['php_output'] = '<?php print t(\'No diamond sponsors yet.\')  . \' \' . l(t(\'Become a sponsor\'), \'sponsors\'); ?>';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Sponsor Logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'width175px',
    'image_link' => 'content',
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    'diamond' => 'diamond',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['sponsors_diamond_block'] = array(
    t('Master'),
    t('Diamond sponsors'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
  );
  $export['sponsors_diamond_block'] = $view;

  $view = new view();
  $view->name = 'sponsors_frontpage_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'sponsors_frontpage_block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Diamond sponsors';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Sponsor website */
  $handler->display->display_options['fields']['field_sponsor_website']['id'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_website']['type'] = 'link_plain';
  /* Field: Content: Sponsor Logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'width450px',
    'image_link' => 'content',
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    'all' => 'all',
    'diamond' => 'diamond',
    'platinium' => 'platinium',
    'gold' => 'gold',
    'silver' => 'silver',
    'bronze' => 'bronze',
    'party' => 'party',
  );

  /* Display: diamond */
  $handler = $view->new_display('block', 'diamond', 'block');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    'diamond' => 'diamond',
  );

  /* Display: platinium */
  $handler = $view->new_display('block', 'platinium', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Platinium sponsors';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Sponsor website */
  $handler->display->display_options['fields']['field_sponsor_website']['id'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_website']['type'] = 'link_plain';
  /* Field: Content: Sponsor Logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'width350px',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    'platinium' => 'platinium',
  );

  /* Display: gold */
  $handler = $view->new_display('block', 'gold', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Gold sponsors';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Sponsor website */
  $handler->display->display_options['fields']['field_sponsor_website']['id'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_website']['type'] = 'link_plain';
  /* Field: Content: Sponsor Logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['path'] = '[field_sponsor_website]';
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'width300px',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    'gold' => 'gold',
  );
  $translatables['sponsors_frontpage_block'] = array(
    t('Master'),
    t('Diamond sponsors'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('diamond'),
    t('platinium'),
    t('Platinium sponsors'),
    t('gold'),
    t('Gold sponsors'),
  );
  $export['sponsors_frontpage_block'] = $view;

  $view = new view();
  $view->name = 'sponsors_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'sponsors_page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sponsors';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_sponsor_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  /* Field: Content: Sponsor website */
  $handler->display->display_options['fields']['field_sponsor_website']['id'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_website']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Sponsor Type */
  $handler->display->display_options['fields']['field_sponsor_type']['id'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['field'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_type']['exclude'] = TRUE;
  /* Field: Content: Sponsor Logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'large',
    'image_link' => 'content',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    'gold' => 'gold',
  );

  /* Display: diamond */
  $handler = $view->new_display('page', 'diamond', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = TRUE;
  $handler->display->display_options['header']['php']['php_output'] = '<p>With our proposal we would like to encourage you to help with organization of the third conference in Poland devoted to CMS Drupal. We believe that the event will attract many experts, at the same time allowing you to promote your own business. <a href="http://www.drupalcampwroclaw.pl/downloadfiles/sponsorship_offer.pdf">Click here to download Sponsorship offer in PDF</a></p>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Sponsor website */
  $handler->display->display_options['fields']['field_sponsor_website']['id'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_website']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Sponsor Type */
  $handler->display->display_options['fields']['field_sponsor_type']['id'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['field'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_type']['exclude'] = TRUE;
  /* Field: Content: Sponsor Logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'width450px',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    'diamond' => 'diamond',
  );
  $handler->display->display_options['path'] = 'sponsors';

  /* Display: platinium */
  $handler = $view->new_display('attachment', 'platinium', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Sponsor website */
  $handler->display->display_options['fields']['field_sponsor_website']['id'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_website']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Sponsor Type */
  $handler->display->display_options['fields']['field_sponsor_type']['id'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['field'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_type']['exclude'] = TRUE;
  /* Field: Content: Sponsor Logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'width350px',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    'platinium' => 'platinium',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: gold */
  $handler = $view->new_display('attachment', 'gold', 'attachment_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Sponsor website */
  $handler->display->display_options['fields']['field_sponsor_website']['id'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_website']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Sponsor Type */
  $handler->display->display_options['fields']['field_sponsor_type']['id'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['field'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_type']['exclude'] = TRUE;
  /* Field: Content: Sponsor Logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['path'] = '[field_sponsor_website]';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'width300px',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    'gold' => 'gold',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: silver */
  $handler = $view->new_display('attachment', 'silver', 'attachment_3');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Sponsor website */
  $handler->display->display_options['fields']['field_sponsor_website']['id'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_website']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Sponsor Type */
  $handler->display->display_options['fields']['field_sponsor_type']['id'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['field'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_type']['exclude'] = TRUE;
  /* Field: Content: Sponsor Logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['path'] = '[field_sponsor_website]';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'width250px',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    'silver' => 'silver',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: bronze */
  $handler = $view->new_display('attachment', 'bronze', 'attachment_4');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Sponsor website */
  $handler->display->display_options['fields']['field_sponsor_website']['id'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_website']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Sponsor Type */
  $handler->display->display_options['fields']['field_sponsor_type']['id'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['field'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_type']['exclude'] = TRUE;
  /* Field: Content: Sponsor Logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['path'] = '[field_sponsor_website]';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'width200px',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    'bronze' => 'bronze',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: party */
  $handler = $view->new_display('attachment', 'party', 'attachment_5');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Sponsor website */
  $handler->display->display_options['fields']['field_sponsor_website']['id'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_website']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Sponsor Type */
  $handler->display->display_options['fields']['field_sponsor_type']['id'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['field'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_type']['exclude'] = TRUE;
  /* Field: Content: Sponsor Logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['path'] = '[field_sponsor_website]';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'width200px',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    'party' => 'party',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $translatables['sponsors_page'] = array(
    t('Master'),
    t('Sponsors'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('diamond'),
    t('platinium'),
    t('gold'),
    t('silver'),
    t('bronze'),
    t('party'),
  );
  $export['sponsors_page'] = $view;

  return $export;
}
