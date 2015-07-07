<?php

$plugin = array(
  'title'             => t('Search Form'),
  'content_types'     => array('doc_search_form'),
  'category'          => t('Drupal Cafe Document Search'),
  'single'            => TRUE,
  'render callback'   => 'doc_search_doc_search_form_content_type_render',
  'edit form'         => 'doc_search_doc_search_form_edit_form',
  'all contexts'      => TRUE,
  'defaults'          => array(
    'query'         => '',
    'search_db'     => '',
    'redirect_path' => '',
  ),
);

function doc_search_doc_search_form_content_type_render($subtype, $conf, $panel_args, $context) {
  $pane = new stdClass();

  if (!empty($context)) {
    $conf['query'] = ctools_context_keyword_substitute($conf['query'], array(), $context);
    $conf['search_db'] = ctools_context_keyword_substitute($conf['search_db'], array(), $context);
    $conf['redirect_path'] = ctools_context_keyword_substitute($conf['redirect_path'], array(), $context);
  }

  $form_state = array(
    'want form'   => TRUE,
    'build_info'  => array(
      'args' => array(
        'redirect_path' => $conf['redirect_path'],
      ),
    ),
    'values'      => array(
      'query'     => $conf['query'],
      'search_db' => $conf['search_db'],
    ),
  );

  $form = drupal_build_form('_doc_search_form', $form_state);
  $pane->content = render($form);

  return $pane;
}

function doc_search_doc_search_form_edit_form($form, &$form_state) {
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

  $form['redirect_path'] = array(
    '#title'          => t('Redirect path'),
    '#type'           => 'textfield',
    '#required'       => TRUE,
    '#default_value'  => $conf['redirect_path'],
  );

  return $form;
}

function doc_search_doc_search_form_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

function _doc_search_form($form, $form_state) {
  $form['query'] = array(
    '#title'          => t('Query string'),
    '#type'           => 'textfield',
    '#required'       => TRUE,
    '#default_value'  => $form_state['values']['query'],
  );

  $search_db_providers = ctools_get_plugins('doc_search', 'doc_search_provider');
  $search_db_options   = array();

  foreach ($search_db_providers as $id => $plugin) {
    $search_db_options[$id] = $plugin['title'];
  }

  $form['search_db'] = array(
    '#title'          => t('Provider'),
    '#type'           => 'select',
    '#required'       => TRUE,
    '#default_value'  => $form_state['values']['search_db'],
    '#options'        => $search_db_options,
  );

  $form['submit'] = array(
    '#value'          => t('Search'),
    '#type'           => 'submit',
  );

  return $form;
}

function _doc_search_form_submit($form, &$form_state) {
  $form_state['redirect'] = $form_state['build_info']['args']['redirect_path'] . '/' .
    $form_state['values']['search_db'] . '/' . $form_state['values']['query'];
}
