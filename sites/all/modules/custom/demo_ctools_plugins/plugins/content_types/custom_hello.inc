<?php

$plugin = array(
  'title'             => t('Custom Hello'),
  'content_types'     => array('custom_hello'),
  'category'          => t('Drupal Cafe'),
  'single'            => TRUE,
  'render callback'   => 'demo_ctools_plugins_custom_hello_content_type_render',
  'edit form'         => 'demo_ctools_plugins_custom_hello_edit_form',
  'all contexts'      => TRUE,
  'defaults'          => array(
    'name' => 'Someone',
  ),
);

function demo_ctools_plugins_custom_hello_content_type_render($subtype, $conf, $panel_args, $context) {
  $pane = new stdClass();

  if (!empty($context)) {
    $conf['name'] = ctools_context_keyword_substitute($conf['name'], array(), $context);
  }

  $pane->content = t('Hello, @name!', array('@name' => $conf['name']));

  return $pane;
}

function demo_ctools_plugins_custom_hello_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['name'] = array(
    '#title'          => t('Name'),
    '#type'           => 'textfield',
    '#required'       => TRUE,
    '#default_value'  => $conf['name'],
  );

  return $form;
}

function demo_ctools_plugins_custom_hello_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
