/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   N O R M A L I Z E D   S Q U A R E D   E R R O R   T E S T   C L A S S                                      */
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
#include <limits>
#include <cmath>

// OpenNN includes

#include "../../source/data_set/data_set.h"
#include "../../source/utilities/numerical_differentiation.h"
#include "../../source/neural_network/neural_network.h"
#include "../../source/performance_functional/performance_functional.h"
#include "../../source/performance_functional/normalized_squared_error.h"

// Unit testing includes

#include "normalized_squared_error_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR


NormalizedSquaredErrorTest::NormalizedSquaredErrorTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

NormalizedSquaredErrorTest::~NormalizedSquaredErrorTest(void)
{
}


// METHODS

// void test_constructor(void) method

void NormalizedSquaredErrorTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default

   NormalizedSquaredError nse1;

   assert_true(nse1.get_neural_network_pointer() == NULL, LOG);
   assert_true(nse1.get_data_set_pointer() == NULL, LOG);

   // Neural network

   NeuralNetwork mlp2;
   NormalizedSquaredError nse2(&mlp2);

   assert_true(nse2.get_neural_network_pointer() != NULL, LOG);
   assert_true(nse2.get_data_set_pointer() == NULL, LOG);

   // Neural network and data set

   NeuralNetwork mlp3;
   DataSet itds3;
   NormalizedSquaredError nse3(&mlp3, &itds3);

   assert_true(nse3.get_neural_network_pointer() != NULL, LOG);
   assert_true(nse3.get_data_set_pointer() != NULL, LOG);
}


// void test_destructor(void)

void NormalizedSquaredErrorTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_calculate_evaluation(void) method

void NormalizedSquaredErrorTest::test_calculate_evaluation(void)   
{
   message += "test_calculate_evaluation\n";

   NeuralNetwork nn(1,1);

   MultilayerPerceptron* mlpp = nn.get_multilayer_perceptron_pointer();

   mlpp->get_layer_pointer(0)->set_activation_function(Perceptron::Linear);

   mlpp->initialize_biases(0.0);
   mlpp->initialize_synaptic_weights(1.0);

   DataSet ds(2,1,1);

   Matrix<double> new_data(2, 2);
   new_data[0][0] = -1.0;
   new_data[0][1] = -1.0;
   new_data[1][0] = 1.0;
   new_data[1][1] = 1.0;

   ds.set_data(new_data);

   NormalizedSquaredError nse(&nn, &ds);

   assert_true(nse.calculate_evaluation() == 0.0, LOG);

}


// void test_calculate_generalization_evaluation(void) method

void NormalizedSquaredErrorTest::test_calculate_generalization_evaluation(void)   
{
   message += "test_calculate_generalization_evaluation\n";

   NeuralNetwork nn;

   DataSet ds;

   NormalizedSquaredError nse(&nn, &ds);  

   double generalization_evaluation;

   // Test

   nn.set(2,2,2);

   ds.set(2,2,2);

   ds.get_instances_information_pointer()->set_generalization();

   ds.initialize_data_normal();

   generalization_evaluation = nse.calculate_generalization_evaluation();

   assert_true(generalization_evaluation != 0.0, LOG);

}


// void test_calculate_gradient(void) method

void NormalizedSquaredErrorTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

   NumericalDifferentiation nd;

   NeuralNetwork nn;

   Vector<double> network_parameters;

   DataSet ds;
   Matrix<double> data;

   NormalizedSquaredError nse(&nn, &ds);

   Vector<double> objective_gradient;
   Vector<double> numerical_objective_gradient;

   // Test 

   nn.set(1,1,1);

   nn.initialize_parameters(0.0);

   ds.set(2,1,1);

   data.set(2, 2);
   data[0][0] = -1.0;
   data[0][1] = -1.0;
   data[1][0] = 1.0;
   data[1][1] = 1.0;

   ds.set_data(data);

   objective_gradient = nse.calculate_gradient();

   assert_true(objective_gradient.size() == nn.count_parameters_number(), LOG);
   assert_true(objective_gradient == 0.0, LOG);

   // Test 

   nn.set(3, 4, 5);
   nn.initialize_parameters_normal();

   network_parameters = nn.arrange_parameters();

   ds.set(2, 3, 5);
   ds.initialize_data_normal();

   objective_gradient = nse.calculate_gradient();
   numerical_objective_gradient = nd.calculate_gradient(nse, &NormalizedSquaredError::calculate_evaluation, network_parameters);

   assert_true((objective_gradient - numerical_objective_gradient).calculate_absolute_value() < 1.0e-3, LOG);
}


// void test_calculate_Hessian(void)

void NormalizedSquaredErrorTest::test_calculate_Hessian(void)
{
   message += "test_calculate_Hessian\n";
}


// void test_calculate_evaluation_terms(void)

void NormalizedSquaredErrorTest::test_calculate_evaluation_terms(void)
{
   message += "test_calculate_evaluation_terms\n";

   NeuralNetwork nn;
   Vector<unsigned int> multilayer_perceptron_architecture;
   Vector<double> network_parameters;

   DataSet ds;

   NormalizedSquaredError nse(&nn, &ds);

   double objective;

   Vector<double> evaluation_terms;

   // Test

   nn.set(2, 2);
   nn.initialize_parameters_normal();

   ds.set(3, 2, 2);
   ds.initialize_data_normal();

   objective = nse.calculate_evaluation();

   evaluation_terms = nse.calculate_evaluation_terms();

   assert_true(fabs((evaluation_terms*evaluation_terms).calculate_sum() - objective) < 1.0e-3, LOG);

}


// void test_calculate_Jacobian_terms(void)

void NormalizedSquaredErrorTest::test_calculate_Jacobian_terms(void)
{
   message += "test_calculate_Jacobian_terms\n";

   NumericalDifferentiation nd;

   NeuralNetwork nn;
   Vector<int> hidden_layers_size;
   Vector<double> network_parameters;

   DataSet ds;

   NormalizedSquaredError nse(&nn, &ds);

   Vector<double> objective_gradient;

   Vector<double> evaluation_terms;
   Matrix<double> Jacobian_terms;
   Matrix<double> numerical_Jacobian_terms;

   // Test

   nn.set(1, 1);
   nn.initialize_parameters_normal();
   network_parameters = nn.arrange_parameters();

   ds.set(2, 1, 1);
   ds.initialize_data_normal();

   Jacobian_terms = nse.calculate_Jacobian_terms();
   numerical_Jacobian_terms = nd.calculate_Jacobian(nse, &NormalizedSquaredError::calculate_evaluation_terms, network_parameters);

   assert_true((Jacobian_terms-numerical_Jacobian_terms).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   nn.set(2, 2, 2);
   nn.initialize_parameters_normal();
   network_parameters = nn.arrange_parameters();

   ds.set(2, 2, 2);
   ds.initialize_data_normal();

   Jacobian_terms = nse.calculate_Jacobian_terms();
   numerical_Jacobian_terms = nd.calculate_Jacobian(nse, &NormalizedSquaredError::calculate_evaluation_terms, network_parameters);

   assert_true((Jacobian_terms-numerical_Jacobian_terms).calculate_absolute_value() < 1.0e-3, LOG);

   // Test

   nn.set(2,2,2);
   nn.initialize_parameters_normal();

   ds.set(2,2,2);
   ds.initialize_data_normal();
   
   objective_gradient = nse.calculate_gradient();

   evaluation_terms = nse.calculate_evaluation_terms();
   Jacobian_terms = nse.calculate_Jacobian_terms();

   assert_true(((Jacobian_terms.calculate_transpose()).dot(evaluation_terms)*2.0 - objective_gradient).calculate_absolute_value() < 1.0e-3, LOG);

}


// void test_to_XML(void) method

void NormalizedSquaredErrorTest::test_to_XML(void)
{
   message += "test_to_XML\n";
}


// void test_from_XML(void) method

void NormalizedSquaredErrorTest::test_from_XML(void)
{
   message += "test_from_XML\n";
}


// void run_test_case(void) method

void NormalizedSquaredErrorTest::run_test_case(void)
{
   message += "Running normalized squared error test case...\n";

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
   test_calculate_evaluation_terms();

   test_calculate_Jacobian_terms();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   message += "End of normalized squared error test case...\n";
}


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2012 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lenser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lenser General Public License for more details.

// You should have received a copy of the GNU Lenser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
