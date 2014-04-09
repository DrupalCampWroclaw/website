<?php
/**
 * @file
 * job.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function job_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'jobs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Jobs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Jobs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_sponsor_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'title_1' => 'title_1',
    'field_sponsor_type' => 'field_sponsor_type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sponsor_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_job_sponsor_ref_target_id']['id'] = 'field_job_sponsor_ref_target_id';
  $handler->display->display_options['relationships']['field_job_sponsor_ref_target_id']['table'] = 'field_data_field_job_sponsor_ref';
  $handler->display->display_options['relationships']['field_job_sponsor_ref_target_id']['field'] = 'field_job_sponsor_ref_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Job Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_job_sponsor_ref_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Sponsor';
  /* Field: Content: Sponsor Type */
  $handler->display->display_options['fields']['field_sponsor_type']['id'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['field'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['relationship'] = 'field_job_sponsor_ref_target_id';
  $handler->display->display_options['fields']['field_sponsor_type']['exclude'] = TRUE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['sorts']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['sorts']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['sorts']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['sorts']['field_sponsor_type_value']['relationship'] = 'field_job_sponsor_ref_target_id';
  $handler->display->display_options['sorts']['field_sponsor_type_value']['order'] = 'DESC';
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
    'job' => 'job',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['relationship'] = 'field_job_sponsor_ref_target_id';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    'platinium' => 'platinium',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
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
    'job' => 'job',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['relationship'] = 'field_job_sponsor_ref_target_id';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    'diamond' => 'diamond',
  );
  $handler->display->display_options['path'] = 'jobs';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Attachment 2 */
  $handler = $view->new_display('attachment', 'Attachment 2', 'attachment_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Sponsor website */
  $handler->display->display_options['fields']['field_sponsor_website']['id'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['relationship'] = 'field_job_sponsor_ref_target_id';
  $handler->display->display_options['fields']['field_sponsor_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_website']['click_sort_column'] = 'url';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Job Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_job_sponsor_ref_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Sponsor';
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = '[field_sponsor_website]';
  $handler->display->display_options['fields']['title_1']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Sponsor Type */
  $handler->display->display_options['fields']['field_sponsor_type']['id'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['field'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['relationship'] = 'field_job_sponsor_ref_target_id';
  $handler->display->display_options['fields']['field_sponsor_type']['exclude'] = TRUE;
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
    'job' => 'job',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['relationship'] = 'field_job_sponsor_ref_target_id';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    'gold' => 'gold',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Attachment 3 */
  $handler = $view->new_display('attachment', 'Attachment 3', 'attachment_3');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Sponsor website */
  $handler->display->display_options['fields']['field_sponsor_website']['id'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['relationship'] = 'field_job_sponsor_ref_target_id';
  $handler->display->display_options['fields']['field_sponsor_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_website']['click_sort_column'] = 'url';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Job Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_job_sponsor_ref_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Sponsor';
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = '[field_sponsor_website]';
  $handler->display->display_options['fields']['title_1']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Sponsor Type */
  $handler->display->display_options['fields']['field_sponsor_type']['id'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['field'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['relationship'] = 'field_job_sponsor_ref_target_id';
  $handler->display->display_options['fields']['field_sponsor_type']['exclude'] = TRUE;
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
    'job' => 'job',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['relationship'] = 'field_job_sponsor_ref_target_id';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    'silver' => 'silver',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $translatables['jobs'] = array(
    t('Master'),
    t('Jobs'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content entity referenced from field_job_sponsor_ref'),
    t('Job Title'),
    t('Sponsor'),
    t('Sponsor Type'),
    t('Page'),
    t('Attachment'),
    t('Attachment 2'),
    t('Sponsor website'),
    t('Attachment 3'),
  );
  $export['jobs'] = $view;

  return $export;
}
