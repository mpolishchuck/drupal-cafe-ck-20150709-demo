<?php

$plugin = array(
  'title' => t("Custom user session"),
  'context' => 'demo_ctools_plugins_context_create_custom_user_session',
  'edit form' => 'demo_ctools_plugins_context_custom_user_session_settings_form',
  'defaults' => array(
    'uid' => 0,
  ),
  'keyword' => 'user_session',
  'context name' => 'custom_user_session',
  'convert list' => array(
    'uid' => t('User ID'),
    'sid' => t('Session ID'),
    'ssid' => t('Secure session ID'),
    'hostname' => t('Hostname'),
    'timestamp' => t('Timestamp'),
  ),
  'convert' => 'demo_ctools_plugins_context_custom_user_session_convert',
);

function demo_ctools_plugins_context_create_custom_user_session($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('custom_user_session');
  $context->plugin = 'custom_user_session';

  if ($empty) {
    return $context;
  }

  if (isset($data['uid'])) {
    $uid = $data['uid'];
    $data = db_select('sessions', 's')
      ->fields('s', array('uid', 'sid', 'ssid', 'hostname', 'timestamp'))
      ->condition('s.uid', $data['uid'])
      ->orderBy('timestamp', 'DESC')
      ->range(0, 1)
      ->execute()
      ->fetchAllAssoc('uid');
  }

  if (!empty($data)) {
    $context->data        = $data[$uid];

    return $context;
  }
}

function demo_ctools_plugins_context_custom_user_session_settings_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['uid'] = array(
    '#title'          => t('User ID'),
    '#type'           => 'textfield',
    '#required'       => TRUE,
    '#default_value'  => $conf['uid'],
  );

  return $form;
}

function demo_ctools_plugins_context_custom_user_session_settings_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

function demo_ctools_plugins_context_custom_user_session_convert($context, $type) {
  switch ($type) {
    case 'uid':
      return $context->data->uid;

    case 'sid':
      return $context->data->sid;

    case 'ssid':
      return $context->data->ssid;

    case 'hostname':
      return $context->data->hostname;

    case 'timestamp':
      return $context->data->timestamp;
  }
}
