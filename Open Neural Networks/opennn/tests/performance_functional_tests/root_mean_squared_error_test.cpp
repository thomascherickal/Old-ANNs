/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   R O O T   M E A N   S Q U A R E D   E R R O R   T E S T   C L A S S                                        */
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
#include "../../source/neural_network/neural_network.h"
#include "../../source/performance_functional/root_mean_squared_error.h"

// Unit testing includes

#include "root_mean_squared_error_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

RootMeanSquaredErrorTest::RootMeanSquaredErrorTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

/// Destructor.

RootMeanSquaredErrorTest::~RootMeanSquaredErrorTest(void)
{

}


// METHODS

// void test_constructor(void) method

void RootMeanSquaredErrorTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default

   RootMeanSquaredError rmse1;

   assert_true(rmse1.get_neural_network_pointer() == NULL, LOG);
   assert_true(rmse1.get_data_set_pointer() == NULL, LOG);

   // Neural network

   NeuralNetwork mlp2;
   RootMeanSquaredError rmse2(&mlp2);

   assert_true(rmse2.get_neural_network_pointer() != NULL, LOG);
   assert_true(rmse2.get_data_set_pointer() == NULL, LOG);

   // Neural network and data set

   NeuralNetwork mlp3;
   DataSet itds3;
   RootMeanSquaredError rmse3(&mlp3, &itds3);

   assert_true(rmse3.get_neural_network_pointer() != NULL, LOG);
   assert_true(rmse3.get_data_set_pointer() != NULL, LOG);

}


// void test_destructor(void) method

void RootMeanSquaredErrorTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_calculate_evaluation(void) method

void RootMeanSquaredErrorTest::test_calculate_evaluation(void)   
{
   message += "test_calculate_evaluation\n";

   NeuralNetwork mlp(1,1,1);
   mlp.initialize_parameters(0.0);

   DataSet ds(1,1,1);
   ds.initialize_data(0.0);

   RootMeanSquaredError rmse(&mlp, &ds);

   assert_true(rmse.calculate_evaluation() == 0.0, LOG);
}


// void test_calculate_gradient(void) method

void RootMeanSquaredErrorTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

   NumericalDifferentiation nd;

   NeuralNetwork mlp;

   Vector<double> network_parameters;

   DataSet ds;

   RootMeanSquaredError rmse(&mlp, &ds);

   Vector<double> objective_gradient;
   Vector<double> numerical_objective_gradient;

   // Test

   mlp.set(3,4,2);
   mlp.initialize_parameters(0.0);

   ds.set(5,3,2);
   ds.initialize_data(0.0);

   // Test

   mlp.set(3,4,2);
   mlp.initialize_parameters(1.0);

   network_parameters = mlp.arrange_parameters();

   ds.set(5,3,2);
   ds.initialize_data(1.0);

   objective_gradient = rmse.calculate_gradient();
   numerical_objective_gradient = nd.calculate_gradient(rmse, &RootMeanSquaredError::calculate_evaluation, network_parameters);
   assert_true((objective_gradient - numerical_objective_gradient).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   mlp.set(1,1,1);

   network_parameters = mlp.arrange_parameters();

   ds.set(1,1,1);
   ds.initialize_data(1.0);

   rmse.set_neural_network_pointer(&mlp);

   objective_gradient = rmse.calculate_gradient();
   numerical_objective_gradient = nd.calculate_gradient(rmse, &RootMeanSquaredError::calculate_evaluation, network_parameters);
   assert_true((objective_gradient - numerical_objective_gradient).calculate_absolute_value() < 1.0e-3, LOG);
}


// void test_calculate_generalization_evaluation(void) method

void RootMeanSquaredErrorTest::test_calculate_generalization_evaluation(void)   
{
   message += "test_calculate_generalization_evaluation\n";

   NeuralNetwork mlp(1,1,1);

   mlp.initialize_parameters(0.0);

   DataSet ds(1,1,1);

   ds.get_instances_information_pointer()->set_generalization();

   ds.initialize_data(0.0);

   RootMeanSquaredError rmse(&mlp, &ds);  
}


// void test_to_XML(void) method

void RootMeanSquaredErrorTest::test_to_XML(void)   
{
   message += "test_to_XML\n";
}


// void test_from_XML(void) method

void RootMeanSquaredErrorTest::test_from_XML(void)   
{
   message += "test_from_XML\n";
}


// void run_test_case(void) method

void RootMeanSquaredErrorTest::run_test_case(void)
{
   message += "Running root mean squared error test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   // Set methods

   // Objective methods

   test_calculate_evaluation();   
   test_calculate_generalization_evaluation();

   test_calculate_gradient();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   message += "End of root mean squared error test case...\n";
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
