<?php
/**
 * @file
 * Drush commands for ads_feeds module.
 */

/**
 * Implements hook_drush_command().
 */
function ads_feeds_drush_command() {
  $items = array();
  $items['ads-feeds-import'] = array(
    'callback'  => 'ads_feeds_drush_import',
    'arguments' => array(
      'url' => array(
        'description' => dt('Optional. Feed source URL.'),
        'required'    => FALSE,
      ),
      'importer_name' => array(
        'description' => dt('Optional. Custom feed importer name.'),
        'required'    => FALSE,
      ),
    ),
    'description' => dt('Imports Ads feed(s) content.'),
    'examples' => array(
      'drush ads-feeds-import'                   => dt('Imports content from all the configured Ads feeds sources.'),
      'drush ads-feeds-import url'               => dt('Imports content from the specified URL using default Ads feed importer.'),
      'drush ads-feeds-import url importer_name' => dt('Imports content from the specified URL using custom Ads feed importer.'),
    ),
    'aliases' => array('adsfi'),
  );

  $items['ads-feeds-event-site-install'] = array(
    'callback'  => 'ads_feeds_drush_event_site_install',
    'description' => dt('Runs site installation tasks defined on the /admin/config/ads/settings/feeds page.'),
  );
  return $items;
}

/**
 * Implements hook_drush_help().
 */
function ads_feeds_drush_help($section) {
  switch ($section) {
    case 'ads-feeds-import':
      return dt("Imports content from the specified URL using default or custom Ads feed importer.");
  }
}

/**
 * Drush command (ads-feeds-import).
 *
 * Imports content from the specified URL using default or custom Ads feed
 * importer.
 *
 * @param string $url
 *   Feed source URL.
 * @param string $importer_name
 *   Optional. Custom feed importer name.
 */
function ads_feeds_drush_import($url = NULL, $importer_name = NULL) {
  if ($url === NULL) {
    // No URL specified, importing all the configured Ads feeds sources.
    ads_feeds_import();
  }
  else {
    // Importing a single Ads feeds source.
    ads_feeds_import_ex($url, $importer_name);
  }
}

/**
 * Drush command (ads-feeds-event-site-install).
 *
 * Runs site installation tasks defined on the /admin/config/ads/settings/feeds
 * page.
 */
function ads_feeds_drush_event_site_install() {
  if (variable_get('ads_feeds_cfg_feeds_event_site_install_import', FALSE)) {
    // Initiating feeds import.
    ads_feeds_import();
  }
}
