<?php
/**
 * @file
 * ads_feeds.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ads_feeds_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
