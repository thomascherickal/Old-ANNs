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

#include "../../source/neural_network/neural_network.h"

#include "../../source/performance_functional/outputs_integrals.h"

// Unit testing includes

#include "outputs_integrals_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

OutputsIntegralsTest::OutputsIntegralsTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

OutputsIntegralsTest::~OutputsIntegralsTest(void) 
{
}


// METHODS

// void test_constructor(void) method

void OutputsIntegralsTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default

   OutputsIntegrals oi1;

   assert_true(oi1.get_neural_network_pointer() == NULL, LOG);

   // Multilayer perceptron

   NeuralNetwork nn2;
   OutputsIntegrals sse2(&nn2);

//   assert_true(sse2.get_neural_network_pointer() != NULL, LOG);
}


// void test_destructor(void) method

void OutputsIntegralsTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_calculate_evaluation(void) method
// @todo

void OutputsIntegralsTest::test_calculate_evaluation(void)   
{
   message += "test_calculate_evaluation\n";

//   NeuralNetwork nn;
//   Vector<double> network_parameters; 

//   OutputsIntegrals nnoi(&nn);

//   double regularization;

   // Test

//   nn.set(1, 1, 1);
//   nn.initialize_parameters(0.0);

//   regularization = nnoi.calculate_evaluation();

//   assert_true(regularization == 0.0, LOG);
}


// void test_calculate_gradient(void) method
// @todo

void OutputsIntegralsTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

//   NumericalDifferentiation nd;
//   NeuralNetwork nn;
//   OutputsIntegrals nnoi(&nn);

//   Vector<unsigned int> architecture;

//   Vector<double> parameters;
//   Vector<double> gradient;
//   Vector<double> numerical_gradient;
//   Vector<double> error;

   // Test 

//   nn.set(1, 1);
//   nn.initialize_parameters(0.0);

//   gradient = nnoi.calculate_gradient();

//   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
//   assert_true(gradient == 0.0, LOG);

   // Test 

//   nn.set(1, 2);
//   nn.initialize_parameters(0.0);

//   nnoi.set_neural_network_pointer(&nn);

//   gradient = nnoi.calculate_gradient();

//   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
//   assert_true(gradient == 0.0, LOG);

   // Test

//   nn.set(1, 2);
//   nn.initialize_parameters(1.0);
//   parameters = nn.arrange_parameters();

//   gradient = nnoi.calculate_gradient();
//   numerical_gradient = nd.calculate_gradient(nnoi, &OutputsIntegrals::calculate_evaluation, parameters);
//   error = (gradient - numerical_gradient).calculate_absolute_value();
//   assert_true(error < 1.0e-3, LOG);
}


// void test_calculate_Hessian(void) method

// @todo

void OutputsIntegralsTest::test_calculate_Hessian(void)
{
   message += "test_calculate_Hessian\n";
}


// void test_to_XML(void) method

void OutputsIntegralsTest::test_to_XML(void)   
{
	message += "test_to_XML\n"; 
}


// void test_from_XML(void) method

void OutputsIntegralsTest::test_from_XML(void)
{
	message += "test_from_XML\n"; 
}


// void run_test_case(void) method

void OutputsIntegralsTest::run_test_case(void)
{
   message += "Running neural network outputs integral test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   // Set methods

   // Evaluation methods

   test_calculate_evaluation();   

   test_calculate_gradient();

   test_calculate_Hessian();

   // Serialization methods

   test_to_XML();   
   test_from_XML();

   message += "End of neural network outputs integral test case...\n";
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
