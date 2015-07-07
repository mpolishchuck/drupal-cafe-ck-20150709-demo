<?php
/**
 * @file
 * demo_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function demo_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'test_page';
  $page->task = 'page';
  $page->admin_title = 'Test Page';
  $page->admin_description = '';
  $page->path = 'test-page';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_test_page__panel_context_3336d381-151d-42c7-ad67-da73f08e066b';
  $handler->task = 'page';
  $handler->subtask = 'test_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'beb4fd65-0029-445e-bbc5-d9c4ba7cb788';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ea3efda8-fa9a-4363-8ed3-d6c472d47393';
    $pane->panel = 'middle';
    $pane->type = 'custom_node_add_form';
    $pane->subtype = 'custom_node_add_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'node_type' => 'article',
      'context' => 'context_user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ea3efda8-fa9a-4363-8ed3-d6c472d47393';
    $display->content['new-ea3efda8-fa9a-4363-8ed3-d6c472d47393'] = $pane;
    $display->panels['middle'][0] = 'new-ea3efda8-fa9a-4363-8ed3-d6c472d47393';
    $pane = new stdClass();
    $pane->pid = 'new-7c8b6133-e301-4ffc-aeb5-438d7ffdb408';
    $pane->panel = 'middle';
    $pane->type = 'custom_node_add_form';
    $pane->subtype = 'custom_node_add_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'node_type' => 'page',
      'context' => 'context_user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7c8b6133-e301-4ffc-aeb5-438d7ffdb408';
    $display->content['new-7c8b6133-e301-4ffc-aeb5-438d7ffdb408'] = $pane;
    $display->panels['middle'][1] = 'new-7c8b6133-e301-4ffc-aeb5-438d7ffdb408';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['test_page'] = $page;

  return $pages;

}
