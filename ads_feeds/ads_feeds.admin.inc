<?php
/**
 * @file
 * Admin functions for ads_feeds module.
 */

/**
 * Generates form to configure interface.
 */
function ads_feeds_settings_form() {

  // General form container.
  $form['ads_feeds']['#prefix'] = '<div id="ads-admin">';
  $form['ads_feeds']['#suffix'] = '</div>';

  // "Feeds sources"
  $form['ads_feeds']['ads_feeds_cfg_feeds_sources_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Feeds sources'),
  );

  // "Import feeds on site installation"
  $form['ads_feeds']['ads_feeds_cfg_feeds_sources_fieldset']['ads_feeds_cfg_feeds_event_site_install_import'] = array(
    '#type' => 'checkbox',
    '#title' => t('Import feeds on site installation'),
    '#default_value' => variable_get('ads_feeds_cfg_feeds_event_site_install_import', FALSE),
  );

  // "Please provide feed URLs in separate lines"
  $form['ads_feeds']['ads_feeds_cfg_feeds_sources_fieldset']['ads_feeds_cfg_feeds_sources'] = array(
    '#type' => 'textarea',
    '#title' => '',
    '#description' => t('Please provide feed URLs in separate lines.'),
    '#default_value' => variable_get('ads_feeds_cfg_feeds_sources', ''),
  );

  // "Remember to save feeds sources before"
  $form['ads_feeds']['ads_feeds_cfg_feeds_sources_fieldset']['ads_feeds_cfg_feeds_installation_import_action'] = array(
    '#type' => 'submit',
    '#value' => t('Import feeds now'),
    '#suffix' => t('Remember to save feeds sources before.'),
    '#executes_submit_callback' => TRUE,
    '#submit' => array('ads_feeds_settings_action_import_feeds'),
  );

  return system_settings_form($form);
}

/**
 * Validate form submission.
 */
function ads_feeds_settings_form_validate($form, &$form_state) {
  // @TODO: Validate feeds sources.
}

/**
 * Invokes feeds import action.
 */
function ads_feeds_settings_action_import_feeds($form, &$form_state) {
  ads_feeds_import();
  drupal_set_message(t('Feeds has been imported.'), 'status');
}
