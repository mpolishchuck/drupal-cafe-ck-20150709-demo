<?php

$plugin = array(
  'title'             => t('Custom Node Add Form'),
  'content_types'     => array('custom_node_add_form'),
  'category'          => t('Drupal Cafe'),
  'single'            => TRUE,
  'required context'  => new ctools_context_required(t('Node author'), 'user'),
  'render callback'   => 'demo_ctools_plugins_custom_node_add_form_content_type_render',
  'edit form'         => 'demo_ctools_plugins_custom_node_add_form_edit_form',
  'admin info'        => 'demo_ctools_plugins_custom_node_add_form_admin_info',
  'defaults'          => array(
    'node_type' => '',
  ),
);

function demo_ctools_plugins_custom_node_add_form_content_type_render($subtype, $conf, $panel_args, $context) {
  $author = $context->data;

  $pane = new stdClass();

  $node = (object) array(
    'uid'       => $author->uid,
    'name'      => (isset($author->name) ? $author->name : ''),
    'type'      => $conf['node_type'],
    'language'  => LANGUAGE_NONE,
  );

  $form_state = array(
    'want form'   => TRUE,
    'build_info'  => array('args' => array($node)),
  );

  $file = drupal_get_path('module', 'node') . '/node.pages.inc';
  require_once DRUPAL_ROOT . '/' . $file;
  $form_state['build_info']['files'] = array($file);

  $form = drupal_build_form($conf['node_type'] . '_node_form', $form_state);

  $pane->content = render($form);

  return $pane;
}

function demo_ctools_plugins_custom_node_add_form_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $types = node_type_get_types();
  $types = array_map(function ($type) {
    return sprintf('%s (%s)', $type->name, $type->type);
  }, $types);

  $form['node_type'] = array(
    '#title'          => t('Node type'),
    '#type'           => 'select',
    '#required'       => TRUE,
    '#default_value'  => $conf['node_type'],
    '#options'        => $types,
  );

  return $form;
}

function demo_ctools_plugins_custom_node_add_form_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

function demo_ctools_plugins_custom_node_add_form_admin_info($subtype, $conf, $context = NULL) {
  $pane = new stdClass();

  $pane->content = t('Node type: @type', array('@type' => $conf['node_type']));

  return $pane;
}
