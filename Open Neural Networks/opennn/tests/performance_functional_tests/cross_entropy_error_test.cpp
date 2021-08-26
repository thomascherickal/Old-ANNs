/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   C R O S S   E N T R O P Y   E R R O R   T E S T   C L A S S                                                */
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

#include "../../source/data_set/data_set.h"
#include "../../source/neural_network/neural_network.h"
#include "../../source/performance_functional/cross_entropy_error.h"

// OpenNN includes


#include "cross_entropy_error_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

CrossEntropyErrorTest::CrossEntropyErrorTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

CrossEntropyErrorTest::~CrossEntropyErrorTest(void)
{
}


// METHODS


// void test_calculate_evaluation(void) method
// @todo

void CrossEntropyErrorTest::test_calculate_evaluation(void)
{
   message += "test_calculate_evaluation\n";

   NeuralNetwork nn;

   MultilayerPerceptron* mlpp;

   DataSet ds;
   
   CrossEntropyError cee(&nn, &ds);
//   double evaluation;

   // Test

   nn.set(1, 1);

   mlpp = nn.get_multilayer_perceptron_pointer();

   mlpp->get_layer_pointer(0)->set_activation_function(Perceptron::Logistic);
   nn.initialize_parameters(0.0);
   
   ds.set(1,1,1);
   ds.initialize_data(0.0);

//   objective = cee.calculate_evaluation();

//   assert_true(objective == 0.0, LOG);
}


// void test_calculate_generalization_evaluation(void) method
// @todo

void CrossEntropyErrorTest::test_calculate_generalization_evaluation(void)   
{
   message += "test_calculate_generalization_evaluation\n";

   NeuralNetwork nn;
   DataSet ds;
   
   CrossEntropyError cee(&nn, &ds);

//   double generalization_objective;

   // Test

   nn.set(1, 1);
   nn.get_multilayer_perceptron_pointer()->get_layer_pointer(0)->set_activation_function(Perceptron::Logistic);
   nn.initialize_parameters(0.0);
   
   ds.set(1,1,1);
   ds.get_instances_information_pointer()->set_generalization();
   ds.initialize_data(0.0);
   
//   generalization_objective = cee.calculate_generalization_evaluation();

//   assert_true(generalization_objective == 0.0, LOG);

}


// void test_calculate_gradient(void) method
// @todo

void CrossEntropyErrorTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

   NumericalDifferentiation nd;

   NeuralNetwork nn;
   Vector<unsigned int> architecture;

   Vector<double> parameters;

   DataSet ds;

   CrossEntropyError cee(&nn, &ds);

   Vector<double> gradient;
   Vector<double> numerical_gradient;
   Vector<double> numerical_differentiation_error;

   // Test

   nn.set(1, 1);

   nn.set_probabilistic_layer_flag(true);

   nn.initialize_parameters(0.0);

   ds.set(1,1,1);

   ds.initialize_data(0.0);

//   gradient = cee.calculate_gradient();

//   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
//   assert_true(gradient == 0.0, LOG);

   // Test 

   nn.set(3, 4, 2);

   nn.set_probabilistic_layer_flag(true);

   nn.initialize_parameters(0.0);

   ds.set(5,3,2);
   cee.set(&nn, &ds);
   ds.initialize_data(0.0);

//   gradient = cee.calculate_gradient();

//   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
//   assert_true(gradient == 0.0, LOG);

   // Test

   architecture.set(3);
   architecture[0] = 2;
   architecture[1] = 1;
   architecture[2] = 3;

   nn.set(architecture);

   nn.set_probabilistic_layer_flag(true);

   nn.initialize_parameters(0.0);

   ds.set(5,2,3);
   cee.set(&nn, &ds);
   ds.initialize_data(0.0);

//   gradient = cee.calculate_gradient();

//   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
//   assert_true(gradient == 0.0, LOG);

   // Test

   nn.set(1, 1, 1);

   nn.set_probabilistic_layer_flag(true);

   nn.initialize_parameters(0.0);

   ds.set(1,1,1);

   ds.initialize_data(0.0);

//   gradient = cee.calculate_gradient();

//   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
//   assert_true(gradient == 0.0, LOG);

   // Test 

   nn.set(3,4,2);

   nn.set_probabilistic_layer_flag(true);

   nn.initialize_parameters(0.0);

   ds.set(5,3,2);
   cee.set(&nn, &ds);
   ds.initialize_data(0.0);

//   gradient = cee.calculate_gradient();

//   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
//   assert_true(gradient == 0.0, LOG);

   // Test

   architecture.set(3);
   architecture[0] = 2;
   architecture[1] = 1;
   architecture[2] = 3;

   nn.set(architecture);
   nn.initialize_parameters(0.0);

   nn.set_probabilistic_layer_flag(true);

   ds.set(5,2,3);
   cee.set(&nn, &ds);
   ds.initialize_data(0.0);

//   gradient = cee.calculate_gradient();

//   assert_true(gradient.size() == nn.count_parameters_number(), LOG);
//   assert_true(gradient == 0.0, LOG);

   // Test

   nn.set(1, 1);

   nn.set_probabilistic_layer_flag(true);

   nn.initialize_parameters(1.0);
   parameters = nn.arrange_parameters();

   ds.set(2,1,1);
   ds.initialize_data(0.5);

//   gradient = cee.calculate_gradient();
//   numerical_gradient = nd.calculate_gradient(cee, &CrossEntropyError::calculate_evaluation, parameters);   
//   assert_true((gradient - numerical_gradient).calculate_absolute_value() < 1.0e-3, LOG);

}


// void test_calculate_Hessian(void) method

void CrossEntropyErrorTest::test_calculate_Hessian(void)
{
   message += "test_calculate_Hessian\n";
}


// void test_to_XML(void) method

void CrossEntropyErrorTest::test_to_XML(void)   
{
	message += "test_to_XML\n"; 
}


// void test_from_XML(void) method

void CrossEntropyErrorTest::test_from_XML(void)
{
	message += "test_from_XML\n"; 
}



// void run_test_case(void) method

void CrossEntropyErrorTest::run_test_case(void)
{
   // Get methods

   // Set methods

   // Objective methods

   test_calculate_evaluation();   
   test_calculate_generalization_evaluation();

   test_calculate_gradient();
   test_calculate_Hessian();

   // Serialization methods

   test_to_XML();
   test_from_XML();

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
