/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   S U M   S Q U A R E D   E R R O R   T E S T   C L A S S                                                    */
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

#include "../../source/utilities/numerical_differentiation.h"
#include "../../source/data_set/data_set.h"
#include "../../source/neural_network/neural_network.h"
#include "../../source/performance_functional/performance_functional.h"
#include "../../source/performance_functional/sum_squared_error.h"

// Unit testing includes

#include "sum_squared_error_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

SumSquaredErrorTest::SumSquaredErrorTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

SumSquaredErrorTest::~SumSquaredErrorTest(void) 
{
}


// METHODS

// void test_constructor(void) method

void SumSquaredErrorTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default

   SumSquaredError sse1;

   assert_true(sse1.get_neural_network_pointer() == NULL, LOG);
   assert_true(sse1.get_data_set_pointer() == NULL, LOG);

   // Multilayer perceptron

   NeuralNetwork nn2;
   SumSquaredError sse2(&nn2);

   assert_true(sse2.get_neural_network_pointer() != NULL, LOG);
   assert_true(sse2.get_data_set_pointer() == NULL, LOG);

   // Multilayer perceptron and data set

   NeuralNetwork nn3;
   DataSet ds3;
   SumSquaredError sse3(&nn3, &ds3);

   assert_true(sse3.get_neural_network_pointer() != NULL, LOG);
   assert_true(sse3.get_data_set_pointer() != NULL, LOG);

}


// void test_destructor(void) method

void SumSquaredErrorTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_calculate_evaluation(void) method

void SumSquaredErrorTest::test_calculate_evaluation(void)   
{
   message += "test_calculate_evaluation\n";

   NeuralNetwork nn;
   Vector<double> network_parameters; 

   DataSet ds;
   Matrix<double> data;

   SumSquaredError sse(&nn, &ds);

   double objective;

   // Test

   nn.set(1, 1, 1);
   nn.initialize_parameters(0.0);

   ds.set(1,1,1);
   ds.initialize_data(0.0);

   objective = sse.calculate_evaluation();

   assert_true(objective == 0.0, LOG);

   // Test

   nn.set(1, 1, 1);
   nn.initialize_parameters(0.0);

   ds.set(1, 1, 1);
   ds.initialize_data(1.0);

   objective = sse.calculate_evaluation();

   assert_true(objective == 1.0, LOG);
}


// void test_calculate_gradient(void) method

void SumSquaredErrorTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

   NumericalDifferentiation nd;
   DataSet ds;
   NeuralNetwork nn;
   SumSquaredError sse(&nn, &ds);

   Vector<unsigned int> architecture;

   Vector<double> parameters;
   Vector<double> gradient;
   Vector<double> numerical_gradient;
   Vector<double> error;

   // Test 

   nn.set(1, 1, 1);
   nn.initialize_parameters(0.0);

   ds.set(1,1,1);
   ds.initialize_data(0.0);

   gradient = sse.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test 

   nn.set(3, 4, 2);
   nn.initialize_parameters(0.0);

   ds.set(5, 3, 2);
   sse.set(&nn, &ds);
   ds.initialize_data(0.0);

   gradient = sse.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test

   architecture.set(3);
   architecture[0] = 5;
   architecture[1] = 1;
   architecture[2] = 2;

   nn.set(architecture);
   nn.initialize_parameters(0.0);

   ds.set(1, 5, 2);
   sse.set(&nn, &ds);
   ds.initialize_data(0.0);

   gradient = sse.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test

   nn.set(1, 1, 1);

   nn.initialize_parameters(0.0);

   ds.set(1, 1, 1);

   ds.initialize_data(0.0);

   gradient = sse.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test 

   nn.set(3, 4, 2);
   nn.initialize_parameters(0.0);

   ds.set(5, 3, 2);
   sse.set(&nn, &ds);
   ds.initialize_data(0.0);

   gradient = sse.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test

   nn.set(2, 3, 4);
   nn.initialize_parameters(0.0);

   ds.set(5, 2, 4);
   sse.set(&nn, &ds);
   ds.initialize_data(0.0);

   gradient = sse.calculate_gradient();

   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(gradient == 0.0, LOG);

   // Test

   ds.initialize_data(1.0);

   nn.initialize_parameters(1.0);
   parameters = nn.arrange_parameters();

   gradient = sse.calculate_gradient();
   numerical_gradient = nd.calculate_gradient(sse, &SumSquaredError::calculate_evaluation, parameters);
   error = (gradient - numerical_gradient).calculate_absolute_value();
   assert_true(error < 1.0e-3, LOG);

   // Test

   nn.set(1, 1, 1);
   nn.initialize_parameters(1.0);
   parameters = nn.arrange_parameters();

   ds.set(1, 1, 1);

   ds.initialize_data(1.0);

   gradient = sse.calculate_gradient();
   numerical_gradient = nd.calculate_gradient(sse, &SumSquaredError::calculate_evaluation, parameters);
   assert_true((gradient - numerical_gradient).calculate_absolute_value() < 1.0e-3, LOG);

}


// void test_calculate_Hessian(void) method
// @todo

void SumSquaredErrorTest::test_calculate_Hessian(void)
{
   message += "test_calculate_Hessian\n";

   NumericalDifferentiation nd;
   DataSet ds;
   NeuralNetwork nn;
   SumSquaredError sse(&nn, &ds);

   Vector<double> parameters;
   Matrix<double> Hessian;
   Matrix<double> numerical_Hessian;

   // Test 

   nn.set();
   nn.construct_multilayer_perceptron();

   ds.set();

   Hessian = sse.calculate_Hessian();
   
   assert_true(Hessian.get_rows_number() == 0, LOG);
   assert_true(Hessian.get_columns_number() == 0, LOG);

   // Test

   ds.set(1, 1, 1);
   ds.initialize_data_normal();

   nn.set(1,1),

   nn.initialize_parameters_normal();
   parameters = nn.arrange_parameters();

   Hessian = sse.calculate_Hessian();
   numerical_Hessian = nd.calculate_Hessian(sse, &SumSquaredError::calculate_evaluation, parameters);
//   assert_true((Hessian - numerical_Hessian).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   ds.set(1,2,1);
   ds.initialize_data_normal();

   nn.set(2,1),
   nn.initialize_parameters_normal();
   parameters = nn.arrange_parameters();

   Hessian = sse.calculate_Hessian();
   numerical_Hessian = nd.calculate_Hessian(sse, &SumSquaredError::calculate_evaluation, parameters);
//   assert_true((Hessian - numerical_Hessian).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   ds.set(1, 1, 2);
   ds.initialize_data_normal();

   nn.set(1,2),
   nn.initialize_parameters_normal();
   parameters = nn.arrange_parameters();

   Hessian = sse.calculate_Hessian();
   numerical_Hessian = nd.calculate_Hessian(sse, &SumSquaredError::calculate_evaluation, parameters);
//   assert_true((objective_Hessian - numerical_objective_Hessian).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   ds.set(1, 2, 2);
   ds.initialize_data_normal();

   nn.set(2,2);
   nn.initialize_parameters_normal();
   parameters = nn.arrange_parameters();

   Hessian = sse.calculate_Hessian();
   numerical_Hessian = nd.calculate_Hessian(sse, &SumSquaredError::calculate_evaluation, parameters);
//   assert_true((objective_Hessian - numerical_objective_Hessian).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   ds.set(1, 1, 1);
   ds.initialize_data_normal();

   nn.set(1, 1, 1);
   nn.initialize_parameters_normal();
   parameters = nn.arrange_parameters();

   Hessian = sse.calculate_Hessian();
   numerical_Hessian = nd.calculate_Hessian(sse, &SumSquaredError::calculate_evaluation, parameters);
//   assert_true((objective_Hessian - numerical_objective_Hessian).calculate_absolute_value() < 1.0e-3, LOG);
}


// void test_calculate_evaluation_terms(void) method

void SumSquaredErrorTest::test_calculate_evaluation_terms(void)
{
   message += "test_calculate_evaluation_terms\n";
}


// void test_calculate_Jacobian_terms(void) method

void SumSquaredErrorTest::test_calculate_Jacobian_terms(void)
{   
   message += "test_calculate_Jacobian_terms\n";

   NumericalDifferentiation nd;

   NeuralNetwork nn;
   Vector<unsigned int> architecture;
   Vector<double> parameters;

   DataSet ds;

   SumSquaredError sse(&nn, &ds);

   Vector<double> gradient;

   Vector<double> terms;
   Matrix<double> Jacobian_terms;
   Matrix<double> numerical_Jacobian_terms;

   // Test

   nn.set(1, 1);

   nn.initialize_parameters(0.0);

   ds.set(1, 1, 1);

   ds.initialize_data(0.0);

   Jacobian_terms = sse.calculate_Jacobian_terms();

   assert_true(Jacobian_terms.get_rows_number() == ds.get_instances_number(), LOG);
   assert_true(Jacobian_terms.get_columns_number() == nn.count_parameters_number(), LOG);
   assert_true(Jacobian_terms == 0.0, LOG);

   // Test 

   nn.set(3, 4, 2);
   nn.initialize_parameters(0.0);

   ds.set(5, 3, 2);
   sse.set(&nn, &ds);
   ds.initialize_data(0.0);

   Jacobian_terms = sse.calculate_Jacobian_terms();

   assert_true(Jacobian_terms.get_rows_number() == ds.get_instances_number(), LOG);
   assert_true(Jacobian_terms.get_columns_number() == nn.count_parameters_number(), LOG);
   assert_true(Jacobian_terms == 0.0, LOG);

   // Test

   architecture.set(3);
   architecture[0] = 5;
   architecture[1] = 1;
   architecture[2] = 2;

   nn.set(architecture);
   nn.initialize_parameters(0.0);

   ds.set(3, 5, 2);
   sse.set(&nn, &ds);
   ds.initialize_data(0.0);

   Jacobian_terms = sse.calculate_Jacobian_terms();

   assert_true(Jacobian_terms.get_rows_number() == ds.get_instances_number(), LOG);
   assert_true(Jacobian_terms.get_columns_number() == nn.count_parameters_number(), LOG);
   assert_true(Jacobian_terms == 0.0, LOG);

   // Test

   nn.set(1, 1, 1);
   nn.initialize_parameters_normal();
   parameters = nn.arrange_parameters();

   ds.set(1, 1, 1);
   ds.initialize_data_normal();

   Jacobian_terms = sse.calculate_Jacobian_terms();
   numerical_Jacobian_terms = nd.calculate_Jacobian(sse, &SumSquaredError::calculate_evaluation_terms, parameters);

   assert_true((Jacobian_terms-numerical_Jacobian_terms).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   nn.set(2, 2, 2);
   nn.initialize_parameters_normal();
   parameters = nn.arrange_parameters();

   ds.set(2, 2, 2);
   ds.initialize_data_normal();

   Jacobian_terms = sse.calculate_Jacobian_terms();
   numerical_Jacobian_terms = nd.calculate_Jacobian(sse, &SumSquaredError::calculate_evaluation_terms, parameters);

   assert_true((Jacobian_terms-numerical_Jacobian_terms).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   nn.set(2, 2, 2);
   nn.initialize_parameters_normal();

   ds.set(2, 2, 2);
   ds.initialize_data_normal();
   
   gradient = sse.calculate_gradient();

   terms = sse.calculate_evaluation_terms();
   Jacobian_terms = sse.calculate_Jacobian_terms();

   assert_true(((Jacobian_terms.calculate_transpose()).dot(terms)*2.0 - gradient).calculate_absolute_value() < 1.0e-3, LOG);
}


// void test_calculate_generalization_evaluation(void) method

void SumSquaredErrorTest::test_calculate_generalization_evaluation(void)   
{
   message += "test_calculate_generalization_evaluation\n";

   NeuralNetwork nn;
   DataSet ds;
   SumSquaredError sse(&nn, &ds);

   double generalization_objective;

   // Test

   nn.set();

   nn.construct_multilayer_perceptron();

   ds.set();

   generalization_objective = sse.calculate_generalization_evaluation();
   
   assert_true(generalization_objective == 0.0, LOG);

}


// void test_calculate_squared_errors(void) method

void SumSquaredErrorTest::test_calculate_squared_errors(void)
{
   message += "test_calculate_squared_errors\n";

   NeuralNetwork nn;

   DataSet ds;

   SumSquaredError sse(&nn, &ds);

   Vector<double> squared_errors;

   double objective;

   // Test 

   nn.set(1,1,1);

   nn.initialize_parameters(0.0);

   ds.set(1,1,1);

   ds.initialize_data(0.0);

   squared_errors = sse.calculate_squared_errors();

   assert_true(squared_errors.size() == 1, LOG);
   assert_true(squared_errors == 0.0, LOG);   

   // Test

   nn.set(2,2,2);

   nn.initialize_parameters_normal();

   ds.set(2,2,2);

   ds.initialize_data_normal();

   squared_errors = sse.calculate_squared_errors();

   objective = sse.calculate_evaluation();

   assert_true(fabs(squared_errors.calculate_sum() - objective) < 1.0e-12, LOG);

}


// void test_to_XML(void) method

void SumSquaredErrorTest::test_to_XML(void)   
{
	message += "test_to_XML\n"; 
}


// void test_from_XML(void) method
// @todo

void SumSquaredErrorTest::test_from_XML(void)
{
   SumSquaredError sse;

   sse.set_display(false);

//   sse.save("../data/opennn_tests/sum_squared_error.xml");

//   sse.load("../data/opennn_tests/sum_squared_error.xml");

   assert_true(sse.get_display() == false, LOG);
}


// void run_test_case(void) method

void SumSquaredErrorTest::run_test_case(void)
{
   message += "Running sum squared error test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   // Set methods

   // Objective methods

   test_calculate_evaluation();   
   test_calculate_generalization_evaluation();

   test_calculate_gradient();

   test_calculate_Hessian();

   // Objective terms methods

   test_calculate_evaluation_terms();

   test_calculate_Jacobian_terms();

   // Serialization methods

   test_to_XML();   
   test_from_XML();

   message += "End of sum squared error test case...\n";
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
