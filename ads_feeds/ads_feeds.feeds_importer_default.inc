<?php
/**
 * @file
 * ads_feeds.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ads_feeds_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ads_feeds_default_importer';
  $feeds_importer->config = array(
    'name' => 'Ads Feeds Default Importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 1,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'advert',
        'expire' => '3600',
        'author' => 0,
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'author_name',
            'target' => 'user_name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
          ),
          3 => array(
            'source' => 'url',
            'target' => 'field_ad_link:url',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'title',
            'target' => 'field_ad_link:title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => 1,
          ),
          6 => array(
            'source' => 'tags',
            'target' => 'field_ad_category',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => 'advert',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 0,
    'process_in_background' => 0,
  );
  $export['ads_feeds_default_importer'] = $feeds_importer;

  return $export;
}
