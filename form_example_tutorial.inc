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
    '#type'  => 'item',
    '#title' => t('A form with nothing but a textfield'),
  );
  // This is the first form element. It's a textfield with a label, "Name"
  $form['name'] = array(
    '#type'  => 'textfield',
    '#title' => t('Name'),
  );
  return $form;
}



//////////////// Tutorial Example 2 //////////////////////

/**
 * This is Example 2, a basic form with a submit button.
 *
 * @see http://drupal.org/node/717726
 * @ingroup form_example
 */
function form_example_tutorial_2($form, &$form_state) {
  $form['description'] = array(
    '#type'  => 'item',
    '#title' => t('A simple form with a submit button'),
  );

  $form['name'] = array(
    '#type'  => 'textfield',
    '#title' => t('Name'),
  );

  // Adds a simple submit button that refreshes the form and clears its
  // contents. This is the default behavior for forms.
  $form['submit'] = array(
    '#type'  => 'submit',
    '#value' => 'Submit',
  );
  return $form;
}


//////////////// Tutorial Example 3 //////////////////////

/**
 * Example 3: A basic form with fieldsets.
 *
 * We establish a fieldset element and then place two text fields within
 * it, one for a first name and one for a last name. This helps us group
 * related content.
 *
 * Study the code below and you'll notice that we renamed the array of the first
 * and last name fields by placing them under the $form['name']
 * array. This tells Form API these fields belong to the $form['name'] fieldset.
 *
 * @ingroup form_example
 */
function form_example_tutorial_3($form, &$form_state) {
  $form['description'] = array(
    '#type'  => 'item',
    '#title' => t('A form with a fieldset'),  // This is the title of the form.
  );

  $form['name'] = array(
    '#type'  => 'fieldset',    // A fieldset 'title' gets class="fieldset-legend"
    '#title' => t('Name'),     // The fieldset 'title' has larger font size than the form element label
  );
  $form['name']['first'] = array(
    '#type'  => 'textfield',
    '#title' => t('First name'),   // This is more of a 'label' than a 'title'
  );
  $form['name']['last'] = array(
    '#type'  => 'textfield',
    '#title' => t('Last name'),
  );


  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  return $form;
}



//////////////// Tutorial Example 4 //////////////////////

/**
 * Example 4: Basic form with required fields.
 *
 * @ingroup form_example
 */
function form_example_tutorial_4($form, &$form_state) {
  $form['description'] = array(
    '#type'  => 'item',
    '#title' => t('A form with validation'),
  );

  $form['name'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Name'),
    // Make the fieldset collapsible.
    // To collapse, click on the fieldset label 'Name'.
    '#collapsible' => TRUE, // Added
    '#collapsed'   => FALSE,  // Added
  );

  // Make these fields required.
  $form['name']['first'] = array(
    '#type'     => 'textfield',
    '#title'    => t('First name'),
    '#required' => TRUE,           // Added from tutorial_3
  );
  $form['name']['last'] = array(
    '#type'     => 'textfield',
    '#title'    => t('Last name'),
    '#required' => TRUE,          // Added from tutorial_3
  );

  $form['submit'] = array(
    '#type'  => 'submit',
    '#value' => 'Submit',
  );
  return $form;
}



//////////////// Tutorial Example 5 //////////////////////

/**
 * Example 5: Basic form with additional element attributes.
 *
 * This demonstrates additional attributes of text form fields.
 *
 * For a more extensive example on element types
 * @see http://drupal.org/node/751826
 *
 * See the @link http://api.drupal.org/api/file/developer/topics/forms_api.html complete form reference @endlink
 *
 * @ingroup form_example
 */
function form_example_tutorial_5($form, &$form_state) {
  $form['description'] = array(
    '#type'        => 'item',
    '#title'       => t('A form with additional attributes'),
    '#description' => t('This one adds #default_value and #description'),   // Added
  );
  $form['name'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Name'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
  );

  $form['name']['first'] = array(
    '#type'          => 'textfield',
    '#title'         => t('First name'),
    '#required'      => TRUE,
    '#default_value' => "First name",                    // added default value.
    '#description'   => "Please enter your first name.", // added description
    '#size'          => 20,                              // added
    '#maxlength'     => 20,                              // added
  );
  $form['name']['last'] = array(
    '#type'     => 'textfield',
    '#title'    => t('Last name'),
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type'  => 'submit',
    '#value' => 'Submit',
  );
  return $form;
}


//////////////// Tutorial Example 6 //////////////////////

/**
 * Example 6: A basic form with a validate handler.
 *
 * From http://drupal.org/node/717736
 * @see form_example_tutorial_6_validate()
 */
function form_example_tutorial_6($form, &$form_state) {
  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('A form with a validation handler'),
  );

  $form['name'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Name'),
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
  );
  $form['name']['first'] = array(
    '#type'          => 'textfield',
    '#title'         => t('First name'),
    '#required'      => TRUE,
    '#default_value' => "First name",
    '#description'   => "Please enter your first name.",
    '#size'          => 20,
    '#maxlength'     => 20,
  );
  $form['name']['last'] = array(
    '#type'     => 'textfield',
    '#title'    => t('Last name'),
    '#required' => TRUE,
  );

  // New form field added to permit entry of year of birth.
  // The data entered into this field will be validated with
  // the default validation function which is named form_example_tutorial_6_VALIDATE
  $form['year_of_birth'] = array(
    '#type'        => 'textfield',
    '#title'       => "Year of birth",
    '#description' => 'Format is "YYYY"',
  );

  $form['submit'] = array(
    '#type'  => 'submit',
    '#value' => 'Submit',
  );
  return $form;
}


/**
 * Now we add a handler/function to validate the data entered into the
 * "year of birth" field to make sure it's between the values of 1900
 * and 2000. If not, it displays an error. The value report is
 * $form_state['values'] (see http://drupal.org/node/144132#form-state).
 *
 * Notice the name of the function. It is simply the name of the form
 * followed by '_validate'. This is always the name of the default validation
 * function. An alternate LIST of validation functionS could have been provided
 * in $form['#validate'].
 *
 * @see form_example_tutorial_6()
 */
function form_example_tutorial_6_validate($form, &$form_state) {
  $year_of_birth = $form_state['values']['year_of_birth'];
  if ($year_of_birth && ($year_of_birth < 1900 || $year_of_birth > 2000)) {
    form_set_error('year_of_birth', t('Enter a year between 1900 and 2000.'));
  }
}