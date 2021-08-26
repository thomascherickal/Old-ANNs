/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   T R A I N I N G   R A T E   A L G O R I T H M   T E S T   C L A S S                                        */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

// System includes

#include <iostream>

// OpenNN includes

#include "../../source/neural_network/neural_network.h"

// Unit testing includes

//#include "mock_training_algorithm.h"
#include "training_rate_algorithm_test.h"


using namespace OpenNN;


// GENERAL CONSTRUCTOR 

TrainingRateAlgorithmTest::TrainingRateAlgorithmTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

TrainingRateAlgorithmTest::~TrainingRateAlgorithmTest(void)
{
}


// METHODS


// void test_constructor(void) method

void TrainingRateAlgorithmTest::test_constructor(void)
{
   message += "test_constructor\n"; 

//   PerformanceFunctional mof;

//   MockTrainingAlgorithm mta1(&mof); 

//   assert_true(mta1.get_performance_functional_pointer() != NULL, LOG);   

//   MockTrainingAlgorithm mta2; 

//   assert_true(mta2.get_performance_functional_pointer() == NULL, LOG);   
}


// void test_destructor(void) method

void TrainingRateAlgorithmTest::test_destructor(void)
{
   message += "test_destructor\n"; 
}


// void test_get_performance_functional_pointer(void) method

void TrainingRateAlgorithmTest::test_get_performance_functional_pointer(void)
{
   message += "test_get_performance_functional_pointer\n"; 
   
//   MockTrainingAlgorithm mta;

//   PerformanceFunctional* ofp = mta.get_performance_functional_pointer();

//   assert_true(ofp == NULL, LOG);
}


// void test_get_training_rate_method(void) method

void TrainingRateAlgorithmTest::test_get_training_rate_method(void)
{
   message += "test_get_training_rate_method\n"; 
/*
   MockTrainingAlgorithm mta;

   mta.set_training_rate_method(TrainingAlgorithm::Fixed);
   assert_true(mta.get_training_rate_method() == TrainingAlgorithm::Fixed, LOG);

   mta.set_training_rate_method(TrainingAlgorithm::GoldenSection);
   assert_true(mta.get_training_rate_method() == TrainingAlgorithm::GoldenSection, LOG);

   mta.set_training_rate_method(TrainingAlgorithm::BrentMethod);
   assert_true(mta.get_training_rate_method() == TrainingAlgorithm::BrentMethod, LOG);
*/
}


// void test_get_training_rate_method_name(void) method

void TrainingRateAlgorithmTest::test_get_training_rate_method_name(void)
{
   message += "test_get_training_rate_method_name\n"; 
}


// void test_get_warning_parameters_norm(void) method

void TrainingRateAlgorithmTest::test_get_warning_parameters_norm(void)
{
   message += "test_get_warning_parameters_norm\n"; 

//   MockTrainingAlgorithm mta;

//   mta.set_warning_parameters_norm(0.0);

//   assert_true(mta.get_warning_parameters_norm() == 0.0, LOG);
}


// void test_get_warning_gradient_norm(void) method

void TrainingRateAlgorithmTest::test_get_warning_gradient_norm(void)
{
   message += "test_get_warning_gradient_norm\n"; 

//   MockTrainingAlgorithm mta;

//   mta.set_warning_gradient_norm(0.0);

//   assert_true(mta.get_warning_gradient_norm() == 0.0, LOG);
}


// void test_get_display(void) method

void TrainingRateAlgorithmTest::test_get_display(void)
{
   message += "test_get_warning_gradient_norm\n"; 

//   MockTrainingAlgorithm mta;

//   mta.set_display(false);

//   assert_true(mta.get_display() == false, LOG);
}


// void test_get_display_period(void) method

void TrainingRateAlgorithmTest::test_get_display_period(void)
{
   message += "test_get_warning_gradient_norm\n"; 

//   MockTrainingAlgorithm mta;

//   mta.set_display_period(1);

//   assert_true(mta.get_display_period() == 1, LOG);
}


// void test_get_first_training_rate(void) method

void TrainingRateAlgorithmTest::test_get_first_training_rate(void)
{
   message += "test_get_first_training_rate\n"; 

//   MockTrainingAlgorithm mta;

//   mta.set_first_training_rate(0.0);

//   assert_true(mta.get_first_training_rate() == 0.0, LOG);
}


// void test_get_bracketing_factor(void) method

void TrainingRateAlgorithmTest::test_get_bracketing_factor(void)   
{
   message += "test_get_bracketing_factor\n"; 

//   MockTrainingAlgorithm mta;

//   mta.set_bracketing_factor(0.0);

//   assert_true(mta.get_bracketing_factor() == 0.0, LOG);
}


// void test_get_training_rate_tolerance(void) method

void TrainingRateAlgorithmTest::test_get_training_rate_tolerance(void)
{
   message += "test_get_training_rate_tolerance\n"; 

//   MockTrainingAlgorithm mta;

}


// void test_get_warning_training_rate(void) method

void TrainingRateAlgorithmTest::test_get_warning_training_rate(void)
{
   message += "test_get_warning_training_rate\n"; 

//   MockTrainingAlgorithm mta;

//   mta.set_warning_training_rate(0.0);

//   assert_true(mta.get_warning_training_rate() == 0.0, LOG);
}


// void test_get_error_parameters_norm(void) method

void TrainingRateAlgorithmTest::test_get_error_parameters_norm(void)
{
   message += "test_get_error_parameters_norm\n"; 
}


// void test_get_error_gradient_norm(void) method

void TrainingRateAlgorithmTest::test_get_error_gradient_norm(void)
{
   message += "test_get_error_gradient_norm\n"; 
}


// void test_get_error_training_rate(void) method

void TrainingRateAlgorithmTest::test_get_error_training_rate(void)
{
   message += "test_get_error_training_rate\n"; 

//   MockTrainingAlgorithm mta;

//   mta.set_error_training_rate(0.0);

//   assert_true(mta.get_error_training_rate() == 0.0, LOG);
}


// void test_set(void) method

void TrainingRateAlgorithmTest::test_set(void)
{
   message += "test_set\n"; 
}


// void test_set_default(void) method

void TrainingRateAlgorithmTest::test_set_default(void)
{
   message += "test_set_default\n"; 
}


// void test_set_performance_functional_pointer(void) method

void TrainingRateAlgorithmTest::test_set_performance_functional_pointer(void)
{
   message += "test_set_performance_functional_pointer\n"; 
}


// void test_set_display(void) method

void TrainingRateAlgorithmTest::test_set_display(void)
{
   message += "test_set_display\n"; 
}


// void test_set_training_rate_method(void) method

void TrainingRateAlgorithmTest::test_set_training_rate_method(void)
{
   message += "test_set_training_rate_method\n"; 
}

/*
// void test_set_first_training_rate(void) method

void TrainingRateAlgorithmTest::test_set_first_training_rate(void)
{
   message += "test_set_first_training_rate\n"; 
}


// void test_set_bracketing_factor(void) method   

void TrainingRateAlgorithmTest::test_set_bracketing_factor(void)   
{
   message += "test_set_bracketing_factor\n"; 
}
*/

// void test_set_training_rate_tolerance(void) method

void TrainingRateAlgorithmTest::test_set_training_rate_tolerance(void)
{
   message += "test_set_training_rate_tolerance\n"; 
}


// void test_set_warning_training_rate(void) method

void TrainingRateAlgorithmTest::test_set_warning_training_rate(void)
{
   message += "test_set_warning_training_rate\n"; 
}


// void test_set_error_parameters_norm(void) method

//void TrainingRateAlgorithmTest::test_set_error_parameters_norm(void)
//{
//   message += "test_set_error_parameters_norm\n"; 
//}


// void test_set_error_gradient_norm(void) method

//void TrainingRateAlgorithmTest::test_set_error_gradient_norm(void)
//{
//   message += "test_set_error_gradient_norm\n"; 
//}


// void test_set_error_training_rate(void) method

void TrainingRateAlgorithmTest::test_set_error_training_rate(void)
{
   message += "test_set_error_training_rate\n"; 
}


// void test_calculate_training_rate_performance(void) method

void TrainingRateAlgorithmTest::test_calculate_training_rate_performance(void)
{
   message += "test_calculate_training_rate_performance\n"; 
}


// void test_calculate_fixed_training_rate_performance(void) method
//@todo
void TrainingRateAlgorithmTest::test_calculate_fixed_training_rate_performance(void)
{
   message += "test_calculate_fixed_training_rate_performance\n";
/*
   MultilayerPerceptron mlp;

   PerformanceFunctional mof(&mlp);

   double performance;
   Vector<double> gradient;

   MockTrainingAlgorithm mta(&mof);

   Vector<double> training_direction;
   double initial_training_rate;

   DirectionalPoint directional_point; 

   // Test

   mlp.set(1, 1);

   mlp.initialize_parameters(1.0);

   performance = mof.calculate_evaluation();

   gradient = mof.calculate_gradient();

   training_direction = gradient*(-1.0);
   initial_training_rate = 0.001;

   training_rate_performance = mta.calculate_fixed_directional_point(performance, training_direction, initial_training_rate);
*/
}



// void test_calculate_golden_section_training_rate_performance(void) method
//@todo
void TrainingRateAlgorithmTest::test_calculate_golden_section_training_rate_performance(void)
{
/*
   message += "test_calculate_golden_section_training_rate_performance\n";

   MultilayerPerceptron mlp(1, 1);
   PerformanceFunctional mof(&mlp);
   MockTrainingAlgorithm mta(&mof);

   mlp.initialize_parameters(1.0);

   double performance = mof.calculate_evaluation();
   Vector<double> gradient = mof.calculate_gradient();

   Vector<double> training_direction = gradient*(-1.0);
   double initial_training_rate = 0.001;

   double training_rate_tolerance = 1.0e-6;
   mta.set_training_rate_tolerance(training_rate_tolerance);
  
   Vector<double> training_rate_performance 
   = mta.calculate_golden_section_training_rate_performance(performance, training_direction, initial_training_rate);

   // Training rate assertion


   // Performance assertion
*/
}


// void test_calculate_Brent_method_training_rate_performance(void) method

void TrainingRateAlgorithmTest::test_calculate_Brent_method_training_rate_performance(void)
{
   message += "test_calculate_Brent_method_training_rate_performance\n";
}


// void test_to_XML(void) method

void TrainingRateAlgorithmTest::test_to_XML(void)
{
   message += "test_to_XML\n";
}
   


// void run_test_case(void) method

void TrainingRateAlgorithmTest::run_test_case(void)
{
   message += "Running training algorithm test case...\n";
/*
   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_performance_functional_pointer();

   // Training operators

   test_get_training_rate_method();
   test_get_training_rate_method_name();

   // Training parameters

   test_get_first_training_rate();
   test_get_bracketing_factor();   
   test_get_training_rate_tolerance();

   test_get_warning_parameters_norm();
   test_get_warning_gradient_norm();
   test_get_warning_training_rate();

   test_get_error_parameters_norm();
   test_get_error_gradient_norm();
   test_get_error_training_rate();

   // Stopping criteria

   test_get_minimum_parameter_increment_norm();

   test_get_performance_goal();
   test_get_minimum_performance_increase();
   test_get_gradient_norm_goal();

   test_get_maximum_epochs_number();
   test_get_maximum_time();

   // Reserve training history

   test_get_reserve_parameters_history();
   test_get_reserve_parameters_norm_history();

   test_get_reserve_evaluation_history();
   test_get_reserve_gradient_history();
   test_get_reserve_gradient_norm_history();
   test_get_reserve_generalization_evaluation_history();

   test_get_reserve_training_direction_history();
   test_get_reserve_training_rate_history();
   test_get_reserve_elapsed_time_history();

   // Training history

   test_arrange_parameters_history();
   test_arrange_parameters_norm_history();

   test_get_evaluation_history();
   test_get_gradient_history();
   test_get_gradient_norm_history();
   test_get_inverse_Hessian_history();
   test_get_generalization_evaluation_history();

   test_get_training_direction_history();
   test_get_training_rate_history();
   test_get_elapsed_time_history();

   // Utilities
   
   test_get_display();
   test_get_display_period();

   // Set methods

   test_set();
   test_set_default();   

   test_set_performance_functional_pointer();

   // Training operators

   test_set_training_rate_method();

   // Training parameters

   test_set_first_training_rate();
   test_set_bracketing_factor();   
   test_set_training_rate_tolerance();

   test_set_warning_parameters_norm();
   test_set_warning_gradient_norm();
   test_set_warning_training_rate();

   test_set_error_parameters_norm();
   test_set_error_gradient_norm();
   test_set_error_training_rate();

   // Stopping criteria

   test_set_minimum_parameter_increment_norm();

   test_set_minimum_performance_increase();
   test_set_performance_goal();
   test_set_gradient_norm_goal();

   test_set_maximum_epochs_number();
   test_set_maximum_time();

   // Reserve training history

   test_set_reserve_parameters_history();
   test_set_reserve_parameters_norm_history();

   test_set_reserve_evaluation_history();
   test_set_reserve_gradient_history();
   test_set_reserve_gradient_norm_history();
   test_set_reserve_inverse_Hessian_history();
   test_set_reserve_generalization_evaluation_history();

   test_set_reserve_training_direction_history();
   test_set_reserve_training_rate_history();
   test_set_reserve_elapsed_time_history();

   test_set_reserve_all_training_history();

   // Training history

   test_set_parameters_history();
   test_set_parameters_norm_history();

   test_set_evaluation_history();
   test_set_gradient_history();
   test_set_gradient_norm_history();
   test_set_inverse_Hessian_history();
   test_set_generalization_evaluation_history();

   test_set_training_direction_history();
   test_set_training_rate_history();
   test_set_elapsed_time_history();

   // Utilities

   test_set_display();
   test_set_display_period();

   // Training methods

   test_calculate_fixed_training_rate_performance();
   test_calculate_golden_section_training_rate_performance();
   test_calculate_Brent_method_training_rate_performance();
   test_calculate_training_rate_performance();

   test_perform_training();


   // Training history methods   

   test_resize_training_history();

   test_get_training_history_XML();   
   test_print_training_history();
   test_save_training_history();

   // Serialization methods

   test_to_XML();
   test_print();
   test_save();
   test_load();
*/
   message += "End of training algorithm test case...\n";
}

// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2012 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

