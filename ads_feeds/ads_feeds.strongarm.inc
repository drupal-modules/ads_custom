<?php
/**
 * @file
 * ads_feeds.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ads_feeds_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ads_feeds_cfg_feeds_event_site_install_import';
  $strongarm->value = 1;
  $export['ads_feeds_cfg_feeds_event_site_install_import'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ads_feeds_cfg_feeds_sources';
  $strongarm->value = 'http://www.gumtree.com/rssfeed/jobs/london';
  $export['ads_feeds_cfg_feeds_sources'] = $strongarm;

  return $export;
}
