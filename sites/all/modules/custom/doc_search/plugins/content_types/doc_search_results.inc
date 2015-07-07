<?php

$plugin = array(
  'title'             => t('Results Pane'),
  'content_types'     => array('doc_search_results'),
  'category'          => t('Drupal Cafe Document Search'),
  'single'            => TRUE,
  'render callback'   => 'doc_search_doc_search_results_content_type_render',
  'edit form'         => 'doc_search_doc_search_results_edit_form',
  'all contexts'      => TRUE,
  'defaults'          => array(
    'query'         => '',
    'search_db'     => '',
  ),
);

function doc_search_doc_search_results_content_type_render($subtype, $conf, $panel_args, $context) {
  $pane = new stdClass();

  if (!empty($context)) {
    $conf['query'] = ctools_context_keyword_substitute($conf['query'], array(), $context);
    $conf['search_db'] = ctools_context_keyword_substitute($conf['search_db'], array(), $context);
  }

  $plugin = ctools_get_plugins('doc_search', 'doc_search_provider', $conf['search_db']);

  if (!$plugin) {
    return $pane;
  }

  $function = !empty($plugin['search function']) ? $plugin['search function'] : '';

  if (!function_exists($function)) {
    return $pane;
  }

  $items = $function($conf['query']);

  $pane->content = theme('item_list', array(
    'type' => 'ul',
    'title' => '',
    'items' => $items,
  ));

  return $pane;
}

function doc_search_doc_search_results_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['query'] = array(
    '#title'          => t('Query string'),
    '#type'           => 'textfield',
    '#required'       => TRUE,
    '#default_value'  => $conf['query'],
  );

  $form['search_db'] = array(
    '#title'          => t('Search Database'),
    '#type'           => 'textfield',
    '#required'       => TRUE,
    '#default_value'  => $conf['search_db'],
  );

  return $form;
}

function doc_search_doc_search_results_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
