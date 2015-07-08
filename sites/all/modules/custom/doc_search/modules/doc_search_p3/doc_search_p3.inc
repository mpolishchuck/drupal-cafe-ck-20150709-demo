<?php

function doc_search_p3_search($query) {
  $items = array();

  db_set_active('data_source');

  $results = db_select('data', 'd')
    ->fields('d', array('id_pk', 'Year', 'CertNum', 'PIN', 'LastName', 'FirstName', 'MiddleName'))
    ->condition('CertNum', '%' . $query . '%', 'LIKE')
    ->condition('id_pk', 10000, '>')
    ->condition('id_pk', 15000, '<=')
    ->range(0, 30)
    ->execute()
    ->fetchAllAssoc('id_pk');

  foreach ($results as $result) {
    $items[] = $result->Year . ' ' . $result->CertNum . ' ' . $result->PIN . ' ' .
      transliteration_get($result->LastName) . ' ' .
      transliteration_get($result->FirstName) . ' ' .
      transliteration_get($result->MiddleName);
  }

  db_set_active();

  return $items;
}
