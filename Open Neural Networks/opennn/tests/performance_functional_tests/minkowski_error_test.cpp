/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   M I N K O W S K I   E R R O R   T E S T   C L A S S                                                        */
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
#include <cmath>

// OpenNN includes

#include "../../source/data_set/data_set.h"
#include "../../source/utilities/numerical_differentiation.h"

#include "../../source/neural_network/neural_network.h"
#include "../../source/performance_functional/minkowski_error.h"

// Unit testing includes

#include "minkowski_error_test.h"

using namespace OpenNN;

// GENERAL CONSTRUCTOR

MinkowskiErrorTest::MinkowskiErrorTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

MinkowskiErrorTest::~MinkowskiErrorTest(void) 
{
}


// METHODS


// void test_constructor(void) method

void MinkowskiErrorTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default

   MinkowskiError me1;

   assert_true(me1.get_neural_network_pointer() == NULL, LOG);
   assert_true(me1.get_data_set_pointer() == NULL, LOG);

   // Multilayer perceptron

   NeuralNetwork mlp2;
   MinkowskiError me2(&mlp2);

   assert_true(me2.get_neural_network_pointer() != NULL, LOG);
   assert_true(me2.get_data_set_pointer() == NULL, LOG);

   // Multilayer perceptron and data set

   NeuralNetwork mlp3;
   DataSet itds3;
   MinkowskiError me3(&mlp3, &itds3);

   assert_true(me3.get_neural_network_pointer() != NULL, LOG);
   assert_true(me3.get_data_set_pointer() != NULL, LOG);

}


// void test_destructor(void) method

void MinkowskiErrorTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_get_Minkowski_parameter(void) method

void MinkowskiErrorTest::test_get_Minkowski_parameter(void)
{
   message += "test_get_Minkowski_parameter\n";

   MinkowskiError me;

   me.set_Minkowski_parameter(1.0);
   
   assert_true(me.get_Minkowski_parameter() == 1.0, LOG);
}


// void test_set_Minkowski_parameter(void) method

void MinkowskiErrorTest::test_set_Minkowski_parameter(void)
{
   message += "test_set_Minkowski_parameter\n";
}


// void test_calculate_evaluation(void) method

void MinkowskiErrorTest::test_calculate_evaluation(void)
{
   message += "test_calculate_evaluation\n";

   NeuralNetwork nn(1,1,1);
   nn.initialize_parameters(0.0);

   DataSet ds(1,1,1);
   ds.initialize_data(0.0);

   MinkowskiError me(&nn, &ds);

   assert_true(me.calculate_evaluation() == 0.0, LOG);
}


// void test_calculate_generalization_evaluation(void) method

void MinkowskiErrorTest::test_calculate_generalization_evaluation(void)
{
   message += "test_calculate_generalization_evaluation\n";  
}


// void test_calculate_gradient(void) method
// @todo

void MinkowskiErrorTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

   NumericalDifferentiation nd;

   NeuralNetwork nn;
   Vector<unsigned int> architecture;

   Vector<double> parameters;

   DataSet ds;

   MinkowskiError me(&nn, &ds);

   Vector<double> objective_gradient;
   Vector<double> numerical_objective_gradient;

   // Test

   nn.set(1,1,1);

   nn.initialize_parameters(0.0);

   ds.set(1,1,1);

   ds.initialize_data(0.0);

   objective_gradient = me.calculate_gradient();

   assert_true(objective_gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test 

   nn.set(3,4,2);
   nn.initialize_parameters(0.0);

   ds.set(5,3,2);
   me.set(&nn, &ds);
   ds.initialize_data(0.0);

   objective_gradient = me.calculate_gradient();

   assert_true(objective_gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test

//   architecture.set(3);
//   architecture[0] = 2;
//   architecture[1] = 1;
//   architecture[2] = 2;

//   nn.set(architecture);
//   nn.initialize_parameters(0.0);

//   ds.set(5,2,3);
//   me.set(&nn, &ds);
//   ds.initialize_data(0.0);

//   objective_gradient = me.calculate_gradient();

//   assert_true(objective_gradient.size() == nn.count_parameters_number(), LOG);
//   assert_true(objective_gradient == 0.0, LOG);

   // Test

   nn.set(1,1,1);

   nn.initialize_parameters(0.0);

   ds.set(1,1,1);

   ds.initialize_data(0.0);

   objective_gradient = me.calculate_gradient();

   assert_true(objective_gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test 

   nn.set(3,4,2);
   nn.initialize_parameters(0.0);

   ds.set(5,3,2);
   me.set(&nn, &ds);
   ds.initialize_data(0.0);

//   objective_gradient = me.calculate_gradient();

//   assert_true(objective_gradient.size() == nn.count_parameters_number(), LOG);
//   assert_true(objective_gradient == 0.0, LOG);

   // Test

   architecture.set(3);
   architecture[0] = 2;
   architecture[1] = 1;
   architecture[2] = 2;

   nn.set(architecture);
   nn.initialize_parameters(0.0);

   ds.set(5,2,3);
   me.set(&nn, &ds);
   ds.initialize_data(0.0);

//   objective_gradient = me.calculate_gradient();

//   assert_true(objective_gradient.size() == nn.count_parameters_number(), LOG);
//   assert_true(objective_gradient == 0.0, LOG);

   // Test

   architecture.set(4, 1);

   nn.set(architecture);
   nn.initialize_parameters_normal();

   parameters = nn.arrange_parameters();

   ds.set(1,1,1);
   ds.initialize_data_normal();

//   objective_gradient = me.calculate_gradient();
//   numerical_objective_gradient = nd.calculate_gradient(me, &MinkowskiError::calculate_evaluation, parameters);   

//   assert_true((objective_gradient - numerical_objective_gradient).calculate_absolute_value() < 1.0e-3, LOG);

   // Test 

   nn.set(5,4,3);
   nn.initialize_parameters_normal();

   parameters = nn.arrange_parameters();

   ds.set(2,5,3);
   ds.initialize_data_normal();

   me.set_Minkowski_parameter(1.75);

//   objective_gradient = me.calculate_gradient();
//   numerical_objective_gradient = nd.calculate_gradient(me, &MinkowskiError::calculate_evaluation, parameters);   
//   assert_true((objective_gradient - numerical_objective_gradient).calculate_absolute_value() < 1.0e-3, LOG);

}


// void test_to_XML(void) method

void MinkowskiErrorTest::test_to_XML(void)   
{
   message += "test_to_XML\n";  
}


// void test_from_XML(void) method

void MinkowskiErrorTest::test_from_XML(void)   
{
   message += "test_from_XML\n";  
}


// void run_test_case(void) method

void MinkowskiErrorTest::run_test_case(void)
{
   message += "Running Minkowski error test case...\n";  

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_Minkowski_parameter();

   // Set methods

   test_set_Minkowski_parameter();

   // Objective methods

   test_calculate_evaluation();   
   test_calculate_generalization_evaluation();
   test_calculate_gradient();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   message += "End of Minkowski error test case...\n";  
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
