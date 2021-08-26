/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   N E U R A L   P A R A M E T E R S   N O R M   T E R M   C L A S S                                          */
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

#include "../../source/neural_network/neural_network.h"

#include "../../source/performance_functional/neural_parameters_norm.h"

// Unit testing includes

#include "neural_parameters_norm_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

NeuralParametersNormTest::NeuralParametersNormTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

NeuralParametersNormTest::~NeuralParametersNormTest(void) 
{
}


// METHODS

// void test_constructor(void) method

void NeuralParametersNormTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default

   NeuralParametersNorm mlppn1;

   assert_true(mlppn1.get_neural_network_pointer() == NULL, LOG);

   // Neural network 

   NeuralNetwork nn2;
   NeuralParametersNorm mlppn2(&nn2);

   assert_true(mlppn2.get_neural_network_pointer() != NULL, LOG);
}


// void test_destructor(void) method

void NeuralParametersNormTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_calculate_evaluation(void) method

void NeuralParametersNormTest::test_calculate_evaluation(void)   
{
   message += "test_calculate_evaluation\n";

   NeuralNetwork nn;
   Vector<double> network_parameters; 

   NeuralParametersNorm mlppn(&nn);

   double objective;

   // Test

   nn.set(1, 1, 1);
   nn.initialize_parameters(0.0);

   objective = mlppn.calculate_evaluation();

   assert_true(objective == 0.0, LOG);
}


// void test_calculate_generalization_regularization(void) method
// @todo

void NeuralParametersNormTest::test_calculate_generalization_regularization(void)   
{
   message += "test_calculate_generalization_regularization\n";

//   NeuralNetwork nn;

//   NeuralParametersNorm mlppn(&nn);

//   double generalization_regularization;

   // Test

//   generalization_regularization = mlppn.calculate_generalization_evaluation();
   
//   assert_true(generalization_regularization == 0.0, LOG);
}


// void test_calculate_gradient(void) method
// @todo

void NeuralParametersNormTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

   NumericalDifferentiation nd;
   NeuralNetwork nn;
   NeuralParametersNorm mlppn(&nn);

   Vector<unsigned int> architecture;

   Vector<double> parameters;
   Vector<double> gradient;
   Vector<double> numerical_gradient;
   Vector<double> error;

   // Test 

   nn.set(1, 1, 1);
   nn.initialize_parameters(0.0);

   gradient = mlppn.calculate_gradient();

//   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
//   assert_true(gradient == 0.0, LOG);

   // Test 

   nn.set(3, 4, 2);
   nn.initialize_parameters(0.0);

   gradient = mlppn.calculate_gradient();

//   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
//   assert_true(gradient == 0.0, LOG);

   // Test

   architecture.set(3);
   architecture[0] = 5;
   architecture[1] = 1;
   architecture[2] = 2;

   nn.set(architecture);
   nn.initialize_parameters(0.0);

   mlppn.set_neural_network_pointer(&nn);

   gradient = mlppn.calculate_gradient();

//   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
//   assert_true(gradient == 0.0, LOG);

   // Test 

   nn.set(3, 4, 2);
   nn.initialize_parameters(0.0);

   mlppn.set_neural_network_pointer(&nn);

   gradient = mlppn.calculate_gradient();

//   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
//   assert_true(gradient == 0.0, LOG);


   // Test

   nn.initialize_parameters(1.0);
   parameters = nn.arrange_parameters();

//   gradient = mlppn.calculate_gradient();
//   numerical_gradient = nd.calculate_gradient(mlppn, &NeuralParametersNorm::calculate_evaluation, parameters);
//   error = (gradient - numerical_gradient).calculate_absolute_value();

//   assert_true(error < 1.0e-3, LOG);

   // Conditions 

//   nn.set(1, 1, 1);
//   mnn.initialize_parameters(1.0);
//   network_parameters = mnn.arrange_parameters();

//   ds.set(1, 1, 1);

//   ds.initialize_data(1.0);

//   gradient = mlppn.calculate_gradient();
//   numerical_objective_gradient = nd.calculate_gradient(mlppn, &NeuralParametersNorm::calculate_evaluation, parameters);

//   assert_true((gradient - numerical_gradient).calculate_absolute_value() < 1.0e-3, LOG);

}


// void test_calculate_Hessian(void) method
// @todo

void NeuralParametersNormTest::test_calculate_Hessian(void)
{
   message += "test_calculate_Hessian\n";
}


// void test_to_XML(void) method

void NeuralParametersNormTest::test_to_XML(void)   
{
	message += "test_to_XML\n"; 
}


// void test_from_XML(void) method

void NeuralParametersNormTest::test_from_XML(void)
{
	message += "test_from_XML\n"; 
}


// void run_test_case(void) method

void NeuralParametersNormTest::run_test_case(void)
{
   message += "Running multilayer perceptron parameters norm test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   // Set methods

   // Objective methods

   test_calculate_evaluation();   
   test_calculate_generalization_regularization();

   test_calculate_gradient();

   test_calculate_Hessian();

   // Serialization methods

   test_to_XML();   
   test_from_XML();

   message += "End of multilayer perceptron parameters norm test case...\n";
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
