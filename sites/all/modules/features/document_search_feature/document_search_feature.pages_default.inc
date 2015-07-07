<?php
/**
 * @file
 * document_search_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function document_search_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'document_search';
  $page->task = 'page';
  $page->admin_title = 'Document Search';
  $page->admin_description = '';
  $page->path = 'doc-search/!search_db/!query';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'search_db' => array(
      'id' => 1,
      'identifier' => 'Search Database',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'query' => array(
      'id' => 2,
      'identifier' => 'Query',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_document_search__panel_context_7bf9a5c8-6f56-4e76-8f28-960f032459d8';
  $handler->task = 'page';
  $handler->subtask = 'document_search';
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
    'contexts' => array(),
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
  $display->uuid = '25a57a57-ad99-49c9-a2a7-136b16a6621f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-daf087d7-e43a-4ac7-b588-eee8c456fbbf';
    $pane->panel = 'middle';
    $pane->type = 'doc_search_form';
    $pane->subtype = 'doc_search_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'query' => '%query:raw',
      'search_db' => '%search_db:raw',
      'redirect_path' => 'doc-search',
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
    $pane->uuid = 'daf087d7-e43a-4ac7-b588-eee8c456fbbf';
    $display->content['new-daf087d7-e43a-4ac7-b588-eee8c456fbbf'] = $pane;
    $display->panels['middle'][0] = 'new-daf087d7-e43a-4ac7-b588-eee8c456fbbf';
    $pane = new stdClass();
    $pane->pid = 'new-fe2e87c0-0a79-4fdd-b730-3e49881bcb4c';
    $pane->panel = 'middle';
    $pane->type = 'doc_search_results';
    $pane->subtype = 'doc_search_results';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'query' => '%query:raw',
      'search_db' => '%search_db:raw',
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
    $pane->uuid = 'fe2e87c0-0a79-4fdd-b730-3e49881bcb4c';
    $display->content['new-fe2e87c0-0a79-4fdd-b730-3e49881bcb4c'] = $pane;
    $display->panels['middle'][1] = 'new-fe2e87c0-0a79-4fdd-b730-3e49881bcb4c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-daf087d7-e43a-4ac7-b588-eee8c456fbbf';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['document_search'] = $page;

  return $pages;

}
