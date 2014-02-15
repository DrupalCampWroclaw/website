<?php
/**
 * @file
 * bannerslider.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bannerslider_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'bannerslider';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'BannerSlider';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'więcej';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Zastosuj';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Przywróć';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortuj po';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Rosnąco';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Opis';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['style_options']['optionset'] = 'frontpage';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_bannerslider_link']['id'] = 'field_bannerslider_link';
  $handler->display->display_options['fields']['field_bannerslider_link']['table'] = 'field_data_field_bannerslider_link';
  $handler->display->display_options['fields']['field_bannerslider_link']['field'] = 'field_bannerslider_link';
  $handler->display->display_options['fields']['field_bannerslider_link']['label'] = '';
  $handler->display->display_options['fields']['field_bannerslider_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bannerslider_link']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_bannerslider_image']['id'] = 'field_bannerslider_image';
  $handler->display->display_options['fields']['field_bannerslider_image']['table'] = 'field_data_field_bannerslider_image';
  $handler->display->display_options['fields']['field_bannerslider_image']['field'] = 'field_bannerslider_image';
  $handler->display->display_options['fields']['field_bannerslider_image']['label'] = '';
  $handler->display->display_options['fields']['field_bannerslider_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_bannerslider_image']['alter']['path'] = '[field_bannerslider_link]';
  $handler->display->display_options['fields']['field_bannerslider_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bannerslider_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bannerslider_image']['settings'] = array(
    'image_style' => '1200x522',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Text */
  $handler->display->display_options['fields']['field_bannerslider_text']['id'] = 'field_bannerslider_text';
  $handler->display->display_options['fields']['field_bannerslider_text']['table'] = 'field_data_field_bannerslider_text';
  $handler->display->display_options['fields']['field_bannerslider_text']['field'] = 'field_bannerslider_text';
  $handler->display->display_options['fields']['field_bannerslider_text']['label'] = '';
  $handler->display->display_options['fields']['field_bannerslider_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bannerslider_text']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['field_bannerslider_text']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_bannerslider_text']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Weight (field_bannerslider_weight) */
  $handler->display->display_options['sorts']['field_bannerslider_weight_value']['id'] = 'field_bannerslider_weight_value';
  $handler->display->display_options['sorts']['field_bannerslider_weight_value']['table'] = 'field_data_field_bannerslider_weight';
  $handler->display->display_options['sorts']['field_bannerslider_weight_value']['field'] = 'field_bannerslider_weight_value';
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
    'bannerslider' => 'bannerslider',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['bannerslider'] = array(
    t('Master'),
    t('więcej'),
    t('Zastosuj'),
    t('Przywróć'),
    t('Sortuj po'),
    t('Rosnąco'),
    t('Opis'),
    t('Block'),
    t('more'),
  );
  $export['bannerslider'] = $view;

  $view = new view();
  $view->name = 'bannerslider_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'BannerSlider Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content Advance';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'więcej';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer application';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Zastosuj';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Przywróć';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortuj po';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Rosnąco';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Opis';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementów na stronę';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Wszystko -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Przesunięcie';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« pierwsza';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ poprzednia';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'następna ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'ostatnia »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_bannerslider_bg_left']['id'] = 'field_bannerslider_bg_left';
  $handler->display->display_options['fields']['field_bannerslider_bg_left']['table'] = 'field_data_field_bannerslider_bg_left';
  $handler->display->display_options['fields']['field_bannerslider_bg_left']['field'] = 'field_bannerslider_bg_left';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_bannerslider_bg_right']['id'] = 'field_bannerslider_bg_right';
  $handler->display->display_options['fields']['field_bannerslider_bg_right']['table'] = 'field_data_field_bannerslider_bg_right';
  $handler->display->display_options['fields']['field_bannerslider_bg_right']['field'] = 'field_bannerslider_bg_right';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_bannerslider_image']['id'] = 'field_bannerslider_image';
  $handler->display->display_options['fields']['field_bannerslider_image']['table'] = 'field_data_field_bannerslider_image';
  $handler->display->display_options['fields']['field_bannerslider_image']['field'] = 'field_bannerslider_image';
  $handler->display->display_options['fields']['field_bannerslider_image']['label'] = 'Obraz';
  $handler->display->display_options['fields']['field_bannerslider_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bannerslider_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_bannerslider_link']['id'] = 'field_bannerslider_link';
  $handler->display->display_options['fields']['field_bannerslider_link']['table'] = 'field_data_field_bannerslider_link';
  $handler->display->display_options['fields']['field_bannerslider_link']['field'] = 'field_bannerslider_link';
  $handler->display->display_options['fields']['field_bannerslider_link']['label'] = 'Odnośnik';
  /* Field: Content: Text */
  $handler->display->display_options['fields']['field_bannerslider_text']['id'] = 'field_bannerslider_text';
  $handler->display->display_options['fields']['field_bannerslider_text']['table'] = 'field_data_field_bannerslider_text';
  $handler->display->display_options['fields']['field_bannerslider_text']['field'] = 'field_bannerslider_text';
  $handler->display->display_options['fields']['field_bannerslider_text']['label'] = 'Tekst';
  /* Field: Content: Weight */
  $handler->display->display_options['fields']['field_bannerslider_weight']['id'] = 'field_bannerslider_weight';
  $handler->display->display_options['fields']['field_bannerslider_weight']['table'] = 'field_data_field_bannerslider_weight';
  $handler->display->display_options['fields']['field_bannerslider_weight']['field'] = 'field_bannerslider_weight';
  $handler->display->display_options['fields']['field_bannerslider_weight']['label'] = 'Waga';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Opublikowane';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bannerslider' => 'bannerslider',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Typ';
  $handler->display->display_options['filters']['type']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/application/bannerslider';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Banner Slider';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['bannerslider_admin'] = array(
    t('Master'),
    t('Content Advance'),
    t('więcej'),
    t('Zastosuj'),
    t('Przywróć'),
    t('Sortuj po'),
    t('Rosnąco'),
    t('Opis'),
    t('Elementów na stronę'),
    t('- Wszystko -'),
    t('Przesunięcie'),
    t('« pierwsza'),
    t('‹ poprzednia'),
    t('następna ›'),
    t('ostatnia »'),
    t('Title'),
    t('Published'),
    t('Post date'),
    t('Updated date'),
    t('Broken handler node.views_bulk_operations'),
    t('Author uid'),
    t('Broken handler field_data_field_bannerslider_bg_left.field_bannerslider_bg_left'),
    t('Broken handler field_data_field_bannerslider_bg_right.field_bannerslider_bg_right'),
    t('Obraz'),
    t('Odnośnik'),
    t('Tekst'),
    t('Waga'),
    t('Edit link'),
    t('Language'),
    t('Opublikowane'),
    t('Typ'),
    t('Page'),
    t('more'),
  );
  $export['bannerslider_admin'] = $view;

  return $export;
}
