/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   G R A D I E N T   D E S C E N T   T E S T   C L A S S                                                      */
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
#include <fstream>
#include <algorithm>
#include <functional>
#include <limits>
#include <cmath>
#include <ctime>

// OpenNN includes

#include "../../source/neural_network/neural_network.h"
#include "../../source/training_strategy/gradient_descent.h"

// Unit testing includes

#include "gradient_descent_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR 

GradientDescentTest::GradientDescentTest(void) : UnitTesting()
{
}



// DESTRUCTOR

GradientDescentTest::~GradientDescentTest(void)
{
}


// METHODS

// void test_constructor(void) method

void GradientDescentTest::test_constructor(void)
{
   message += "test_constructor\n"; 

   PerformanceFunctional pf;

   // Default constructor

   GradientDescent gd1; 
   assert_true(gd1.get_performance_functional_pointer() == NULL, LOG);   

   // Performance functional constructor

   GradientDescent gd2(&pf); 
   assert_true(gd2.get_performance_functional_pointer() != NULL, LOG);   
}


// void test_destructor(void) method

void GradientDescentTest::test_destructor(void)
{
   message += "test_destructor\n"; 
}


// void test_set_reserve_all_training_history(void) method

void GradientDescentTest::test_set_reserve_all_training_history(void)
{
   message += "test_set_reserve_all_training_history\n";

   GradientDescent gd;

   gd.set_reserve_all_training_history(true);

   assert_true(gd.get_reserve_elapsed_time_history() == true, LOG);
   assert_true(gd.get_reserve_parameters_history() == true, LOG);
   assert_true(gd.get_reserve_parameters_norm_history() == true, LOG);
   assert_true(gd.get_reserve_evaluation_history() == true, LOG);
   assert_true(gd.get_reserve_gradient_history() == true, LOG);
   assert_true(gd.get_reserve_gradient_norm_history() == true, LOG);
   assert_true(gd.get_reserve_training_direction_history() == true, LOG);
   assert_true(gd.get_reserve_training_rate_history() == true, LOG);
   assert_true(gd.get_reserve_generalization_evaluation_history() == true, LOG);
}


// void test_perform_training(void) method
// @todo

void GradientDescentTest::test_perform_training(void)
{
   message += "test_perform_training\n";

//   DataSet ds(2, 1, 1);
//   ds.initialize_data_normal();

//   NeuralNetwork nn(1, 1);

//   PerformanceFunctional pf(&nn, &ds);

//   GradientDescent gd(&pf);

//   nn.initialize_parameters(3.1415927);

//   double old_performance = pf.calculate_evaluation();

//   gd.set_display(false);
//   gd.set_maximum_epochs_number(1);
//   gd.perform_training();

//   double performance = pf.calculate_evaluation();

//   assert_true(performance < old_performance, LOG);

   // Minimum parameters increment norm

//   nn.initialize_parameters(-1.0);

//   double minimum_parameters_increment_norm = 0.1;

//   gd.set_minimum_parameters_increment_norm(minimum_parameters_increment_norm);
//   gd.set_performance_goal(0.0);
//   gd.set_minimum_performance_increase(0.0);
//   gd.set_gradient_norm_goal(0.0);
//   gd.set_maximum_epochs_number(1000);
//   gd.set_maximum_time(1000.0);

//   gd.perform_training();

   // Performance goal

//   nn.initialize_parameters(-1.0);

//   double performance_goal = 0.1;

//   gd.set_minimum_parameters_increment_norm(0.0);
//   gd.set_performance_goal(performance_goal);
//   gd.set_minimum_performance_increase(0.0);
//   gd.set_gradient_norm_goal(0.0);
//   gd.set_maximum_epochs_number(1000);
//   gd.set_maximum_time(1000.0);

//   gd.perform_training();

//   performance = pf.calculate_evaluation();

   // Minimum evaluation improvement

//   nn.initialize_parameters(-1.0);

//   double minimum_performance_increase = 0.1;

//   gd.set_minimum_parameters_increment_norm(0.0);
//   gd.set_performance_goal(0.0);
//   gd.set_minimum_performance_increase(minimum_performance_increase);
//   gd.set_gradient_norm_goal(0.0);
//   gd.set_maximum_epochs_number(1000);
//   gd.set_maximum_time(1000.0);

//   gd.perform_training();

   // Gradient norm goal 

//   nn.initialize_parameters(-1.0);

//   double gradient_norm_goal = 0.1;

//   gd.set_minimum_parameters_increment_norm(0.0);
//   gd.set_performance_goal(0.0);
//   gd.set_minimum_performance_increase(0.0);
//   gd.set_gradient_norm_goal(gradient_norm_goal);
//   gd.set_maximum_epochs_number(1000);
//   gd.set_maximum_time(1000.0);

//   gd.perform_training();

//   double gradient_norm = pf.calculate_gradient().calculate_norm();
//   assert_true(gradient_norm < gradient_norm_goal, LOG);

}


// void test_resize_training_history(void) method

void GradientDescentTest::test_resize_training_history(void)
{
   message += "test_resize_training_history\n";

   GradientDescent gd;

   gd.set_reserve_all_training_history(true);

   GradientDescent::GradientDescentResults gdtr;

   gdtr.resize_training_history(1);

   assert_true(gdtr.parameters_history.size() == 1, LOG);
   assert_true(gdtr.parameters_norm_history.size() == 1, LOG);

   assert_true(gdtr.evaluation_history.size() == 1, LOG);
   assert_true(gdtr.gradient_history.size() == 1, LOG);
   assert_true(gdtr.gradient_norm_history.size() == 1, LOG);
   assert_true(gdtr.generalization_evaluation_history.size() == 1, LOG);  

   assert_true(gdtr.training_direction_history.size() == 1, LOG);
   assert_true(gdtr.training_rate_history.size() == 1, LOG);
   assert_true(gdtr.elapsed_time_history.size() == 1, LOG);

}


// void test_to_XML(void) method
// @todo

void GradientDescentTest::test_to_XML(void)
{
   message += "test_to_XML\n";

   GradientDescent gd;

//   TiXmlElement* gde = gd.to_XML();
//   assert_true(gde != NULL, LOG);
}


// void test_from_XML(void) method

void GradientDescentTest::test_from_XML(void)
{
   message += "test_from_XML\n";

   GradientDescent gd;

//   TiXmlElement* gde = gd.to_XML();

//   gd.from_XML(gde);
}


// void run_test_case(void) method

void GradientDescentTest::run_test_case(void)
{
   message += "Running gradient descent test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Set methods

   test_set_reserve_all_training_history();

   // Training methods

   test_perform_training();

   // Training history methods

   test_resize_training_history();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   message += "End of gradient descent test case...\n";
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

