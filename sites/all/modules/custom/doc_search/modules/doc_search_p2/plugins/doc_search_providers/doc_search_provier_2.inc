<?php

$plugin = array(
  'title' => t('Provider 2'),
  'search function' => 'doc_search_p1_doc_search_provider_2_search',
);

function doc_search_p1_doc_search_provider_2_search($query) {
  $items[] = $query . 'sx23324434';
  $items[] = '235ssasedc34' . $query;
  $items[] = $query . '68rsvvfr';
  $items[] = $query . '1256dgvfg';
  $items[] = '123142' . $query . '1256dgvfg';

  return $items;
}
