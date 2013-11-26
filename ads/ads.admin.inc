<?php
/**
 * @file
 * Admin functions for ads module.
 */

/**
 * Generates form to configure module.
 */
function ads_settings_form() {

  // General form container.
  $form['ads_cfg']['#prefix'] = '<div id="ads-admin">';
  $form['ads_cfg']['#suffix'] = '</div>';
  $form['#attached']['css'] = array(drupal_get_path('module', 'ads') . '/css/ads-admin.css');

  $form['ads_cfg'][] = array(
    '#markup' => '<div class="information"><div class="ads-logo">ADS</div>' .
    t('To configure <b>Ads</b> extensions,<br/>please use tabs on the top-right corner of this page.') .
    '</div>',
  );

  $form = system_settings_form($form);

  // We don't need submit button here.
  unset($form['actions']['submit']);

  return $form;
}

/**
 * Validate form submission.
 */
function ads_settings_form_validate($form, &$form_state) {
}

/**
 * Implements hook_form_submit().
 */
function ads_settings_form_submit($form, &$form_state) {
}
