<?php

/**
 * @file
 * This is the Form API Tutorial from the handbook.
 *
 * It goes through nine form examples in increasing complexity to demonstrate
 * Drupal 7 Form API.
 *
 * Links are provided inline for the related handbook pages.
 *
 * @see http://drupal.org/node/262422
 */

/**
 * Main Form tutorial page.
 *
 * @see form_example_tutorial_1()
 * @see form_example_tutorial_2()
 * @see form_example_tutorial_3()
 * @see form_example_tutorial_4()
 * @see form_example_tutorial_5()
 * @see form_example_tutorial_6()
 * @see form_example_tutorial_7()
 * @see form_example_tutorial_8()
 * @see form_example_tutorial_9()
 * @see form_example_tutorial_10()
 *
 * @ingroup form_example
 */
function form_example_tutorial() {
  return t('This is a set of nine form tutorials tied to the <a href="http://drupal.org/node/262422">Drupal handbook</a>.');
}

//////////////// Tutorial Example 1 //////////////////////

/**
 * This first form function is from the @link http://drupal.org/node/717722 Form Tutorial handbook page @endlink
 *
 * It just creates a very basic form with a textfield.
 *
 * This function is called the "form constructor function". It builds the form.
 * It takes a two arguments, $form and $form_state, but if drupal_get_form()
 * sends additional arguments, they will be provided after $form_state.
 *
 * @ingroup form_example
 */
function form_example_tutorial_1($form, &$form_state) {

  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('A form with nothing but a textfield'),
  );
  // This is the first form element. It's a textfield with a label, "Name"
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
  );
  return $form;
}
