<?php

$plugin = array(
  'title' => t('Provider 1'),
  'search function' => 'doc_search_p1_doc_search_provider_1_search',
);

function doc_search_p1_doc_search_provider_1_search($query) {
  $items[] = 'sdcasd' . $query . 'sx';
  $items[] = '235' . $query . '68r';
  $items[] = $query . '68rsvvfr';

  return $items;
}
