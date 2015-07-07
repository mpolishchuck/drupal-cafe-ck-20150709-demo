<?php

$plugin = array(
  'title' => t('Custom user session'),
  'keyword' => 'user_session',
  'required context' => new ctools_context_required(t('User'), 'user'),
  'context' => 'demo_ctools_plugins_custom_user_session_context',
);

function demo_ctools_plugins_custom_user_session_context($context, $conf) {
  if (empty($context->data)) {
    return ctools_context_create_empty('custom_user_session');
  }

  $user = $context->data;

  return ctools_context_create('custom_user_session', array('uid' => $user->uid));
}
