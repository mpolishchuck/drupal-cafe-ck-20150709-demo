<?php

function doc_search_p3_search($query) {
  $count = rand(5,8);
  $items = array();

  for ($i = 0; $i < $count; $i++) {
    $items[] = _doc_search_p3_random_string(rand(2,4)) .
      $query . _doc_search_p3_random_string(rand(3,5));
  }

  return $items;
}

function _doc_search_p3_random_string($length = 10)
{
  $characters = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
    $random_string = '';
    for ($i = 0; $i < $length; $i++) {
      $random_string = $characters[rand(0, strlen($characters) - 1)];
    }

    return $random_string;
}
