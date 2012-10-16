<?php

/**
 * @file
 * This is an example demonstrating how a module can define custom form and
 * render elements.
 *
 * Form elements are already familiar to anyone who uses Form API. They share
 * history with render elements, which are explained in the
 * @link render_example.module Render Example @endlink. Examples
 * of core form elements are 'textfield', 'checkbox' and 'fieldset'. Drupal
 * utilizes hook_elements() to define these FAPI types, and this occurs in
 * the core function system_elements().
 *
 * Each form element has a #type value that determines how it is treated by
 * the Form API and how it is ultimately rendered into HTML.
 * hook_element_info() allows modules to define new element types, and tells
 * the Form API what default values they should automatically be populated with.
 *
 * By implementing hook_element_info() in your own module, you can create custom
 * form (or render) elements with their own properties, validation and theming.
 *
 * In this example, we define a series of elements that range from trivial
 * (a renamed textfield) to more advanced (a telephone number field with each
 * portion separately validated).
 *
 * Since each element can use arbitrary properties (like #process or #dropthis)
 * it can be quite complicated to figure out what all the properties actually
 * mean. This example won't undertake the exhaustive task of explaining them
 * all, as that would probably be impossible.
 */

/**
 * @todo: Some additional magic things to explain:
 * - #process and process callback (and naming) (in forms)
 * - #value and value callback (and naming of the above)
 * - #theme and #theme_wrappers
 * - What is #return_value?
 * - system module provides the standard default elements.
 * - What are all the things that can be defined in hook_element_info() and
 *   where do the defaults come from?
 * - Form elements that have a type that has a matching type in the element
 *   array created by hook_element_info() get those items merged with them.
 * - #value_callback is called first by form_builder(). Its job is to figure
 *   out what the actual value of the element, using #default_value or whatever.
 * - #process is then called to allow changes to the whole element (like adding
 *   child form elements.)
 * - #return_value: chx: you need three different values for form API. You need
 *   the default value (#default_value), the value for the element if it gets
 *   checked )#return_value) and then #value which is either 0 or the
 *   #return_value
 */





/**
 * Simple form to demonstrate how to use the various new FAPI elements
 * we've defined.
 */
// This is the form-defining callback called in the hook_menu implementation for this module (example)
function form_example_element_demo_form($form, &$form_state) {
  $form['a_form_example_textfield'] = array(
    '#type'          => 'form_example_textfield',
    '#title'         => t('Form Example textfield'),
    '#default_value' => variable_get('form_example_textfield', ''),
    '#description'   => t('form_example_textfield is a new type, but it is actually uses the system-provided functions of textfield'),
  );

  $form['a_form_example_checkbox'] = array(
    '#type'          => 'form_example_checkbox',
    '#title'         => t('Form Example checkbox'),
    '#default_value' => variable_get('form_example_checkbox', FALSE),
    '#description'   => t('Nothing more than a regular checkbox but with a theme provided by this module.')
  );

  $form['a_form_example_element_discrete'] = array(
    '#type'          => 'form_example_phonenumber_discrete',
    '#title'         => t('Discrete phone number'),
    '#default_value' => variable_get('form_example_element_discrete', array('areacode' => '999', 'prefix' => '999', 'extension' => '9999')),
    '#description'   => t('A phone number : areacode (XXX), prefix (XXX) and extension (XXXX). This one uses a "discrete" element type, one which stores the three parts of the telephone number separately.'),
  );

  $form['a_form_example_element_combined'] = array(
    '#type'          => 'form_example_phonenumber_combined',
    '#title'         => t('Combined phone number'),
    '#default_value' => variable_get('form_example_element_combined', '0000000000'),
    '#description'   => t('form_example_element_combined one uses a "combined" element type, one with a single 10-digit value which is broken apart when needed.'),
  );

  $form['submit'] = array(
    '#type'  => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Submit handler for form_example_element_demo_form().
 */
function form_example_element_demo_form_submit($form, &$form_state) {
  // Exclude unnecessary elements.
  unset($form_state['values']['submit'], $form_state['values']['form_id'], $form_state['values']['op'], $form_state['values']['form_token'], $form_state['values']['form_build_id']);

  foreach ($form_state['values'] as $key => $value) {
    variable_set($key, $value);
    drupal_set_message(t('%name has value %value', array('%name' => $key, '%value' => print_r($value, TRUE))));
  }
}
