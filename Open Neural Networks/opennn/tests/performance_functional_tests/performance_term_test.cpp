/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   P E R F O R M A N C E   T E R M   T E S T   C L A S S                                                      */
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
#include <string>
#include <sstream>
#include <cmath>   

// OpenNN includes

#include "../../source/utilities/numerical_differentiation.h"

#include "../../source/neural_network/neural_network.h"

#include "../../source/performance_functional/performance_term.h"

// Unit testing includes

#include "mock_performance_term.h"
#include "performance_term_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

PerformanceTermTest::PerformanceTermTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

PerformanceTermTest::~PerformanceTermTest(void)
{
}


// METHODS

// void test_constructor(void) method

void PerformanceTermTest::test_constructor(void)
{
   message += "test_constructor\n";
}


// void test_destructor(void)

void PerformanceTermTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_get_neural_network_pointer(void) method

void PerformanceTermTest::test_get_neural_network_pointer(void)
{
   message += "test_get_neural_network_pointer\n";

   MockPerformanceTerm of;
   NeuralNetwork nn;

   // Test

   assert_true(of.get_neural_network_pointer() == NULL,	LOG);

   // Test

   of.set_neural_network_pointer(&nn);
   assert_true(of.get_neural_network_pointer() != NULL,	LOG);

}


// void test_get_numerical_differentiation_pointer(void) method

void PerformanceTermTest::test_get_numerical_differentiation_pointer(void)
{
   message += "test_get_numerical_differentiation_pointer\n";

   MockPerformanceTerm mof;
  
   // Test

   assert_true(mof.get_numerical_differentiation_pointer() == NULL,	LOG);
}


// void test_get_objective_weight(void) method

void PerformanceTermTest::test_get_objective_weight(void)
{
   message += "test_get_objective_weight\n";

   MockPerformanceTerm mof;

   // Test

//   mof.set_objective_weight(0.0);
//   assert_true(mof.get_objective_weight() == 0.0, LOG);   

}


// void test_get_display(void) method

void PerformanceTermTest::test_get_display(void)
{
   message += "test_get_display\n";

   MockPerformanceTerm mof;

   // Test

   mof.set_display(true);
   assert_true(mof.get_display() == true, LOG);

   mof.set_display(false);
   assert_true(mof.get_display() == false, LOG);

}


// void test_set_multilayer_perceptron_pointer(void) method

void PerformanceTermTest::test_set_multilayer_perceptron_pointer(void)
{
   message += "test_set_multilayer_perceptron_pointer\n";

   MockPerformanceTerm mof;
   NeuralNetwork nn;

   // Test

   mof.set_neural_network_pointer(&nn);
   assert_true(mof.get_neural_network_pointer() != NULL, LOG);

}


// void test_set_numerical_differentiation_pointer(void) method

void PerformanceTermTest::test_set_numerical_differentiation_pointer(void)
{
   message += "test_set_numerical_differentiation_pointer\n";

   MockPerformanceTerm mof;

   NeuralNetwork nn;

}


// void test_set_default(void) method

void PerformanceTermTest::test_set_default(void)
{
   message += "test_set_default\n";

   MockPerformanceTerm mof;

   // Test

   mof.set_default();

}


// void test_set_objective_weight(void) method

void PerformanceTermTest::test_set_objective_weight(void)
{
   message += "test_set_objective_weight\n";

   MockPerformanceTerm mof;

   // Test
   
//   mof.set_objective_weight(1.0);
//   assert_true(mof.get_objective_weight() == 1.0, LOG);   

}


// void test_set_display(void) method

void PerformanceTermTest::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_calculate_layers_delta(void) method

void PerformanceTermTest::test_calculate_layers_delta(void)
{
   message += "test_calculate_layers_delta\n";

   NeuralNetwork nn;

   Vector<double> inputs;

   Vector< Vector<double> > layers_activation_derivative; 
   Vector<double> output_objective_gradient;

   MockPerformanceTerm mof(&nn);

   Vector< Vector<double> > layers_delta;

   // Test 

   nn.construct_multilayer_perceptron();

   layers_delta = mof.calculate_layers_delta(layers_activation_derivative, output_objective_gradient);

   assert_true(layers_delta.size() == 0, LOG);

   // Test

   nn.set(1, 1);

   inputs.set(1, 0.0);

   layers_activation_derivative = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation_derivative(inputs); 

   output_objective_gradient.set(1, 0.0);

   layers_delta = mof.calculate_layers_delta(layers_activation_derivative, output_objective_gradient);

   assert_true(layers_delta.size() == 1, LOG);
   assert_true(layers_delta[0].size() == 1, LOG);
   assert_true(layers_delta[0] == 0.0, LOG);

   // Test

   nn.set(1, 1, 1);

   inputs.set(1, 0.0);

   layers_activation_derivative = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation_derivative(inputs); 

   output_objective_gradient.set(1, 0.0);

   layers_delta = mof.calculate_layers_delta(layers_activation_derivative, output_objective_gradient);

   assert_true(layers_delta.size() == 2, LOG);
   assert_true(layers_delta[0].size() == 1, LOG);
   assert_true(layers_delta[0] == 0.0, LOG);
   assert_true(layers_delta[1].size() == 1, LOG);
   assert_true(layers_delta[1] == 0.0, LOG);

   // Test

   nn.set(4, 3, 5);

   inputs.set(4, 0.0);

   layers_activation_derivative = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation_derivative(inputs); 

   output_objective_gradient.set(5, 0.0);

   layers_delta = mof.calculate_layers_delta(layers_activation_derivative, output_objective_gradient);

   assert_true(layers_delta.size() == 2, LOG);
   assert_true(layers_delta[0].size() == 3, LOG);
   assert_true(layers_delta[0] == 0.0, LOG);
   assert_true(layers_delta[1].size() == 5, LOG);
   assert_true(layers_delta[1] == 0.0, LOG);

}


// void test_calculate_interlayers_Delta(void) method
// @todo

void PerformanceTermTest::test_calculate_interlayers_Delta(void)
{
   message += "test_calculate_interlayers_Delta\n";

   NeuralNetwork nn;
   Vector<unsigned int> layers_size;

   Vector<double> inputs;
   Vector<double> outputs;

   Vector< Vector<double> > layers_activation_derivative; 
   Vector< Vector<double> > layers_activation_second_derivative; 

   Matrix< Matrix<double> > interlayers_combination_combination_Jacobian;

   Vector<double> output_objective_gradient;
   Matrix<double> output_objective_Hessian;

   Vector< Vector<double> > layers_delta;

   MockPerformanceTerm mof(&nn);

   Matrix< Matrix<double> > interlayers_Delta;

   // Test 

   nn.construct_multilayer_perceptron();

   interlayers_combination_combination_Jacobian = nn.get_multilayer_perceptron_pointer()->calculate_interlayers_combination_combination_Jacobian(inputs);

   layers_delta = mof.calculate_layers_delta(layers_activation_derivative, output_objective_gradient);
   interlayers_Delta = mof.calculate_interlayers_Delta(layers_activation_derivative, layers_activation_second_derivative, interlayers_combination_combination_Jacobian, output_objective_gradient, output_objective_Hessian, layers_delta);

   assert_true(interlayers_Delta.get_rows_number() == 0, LOG);
   assert_true(interlayers_Delta.get_columns_number() == 0, LOG);

   // Test

   nn.set(1, 1);

   inputs.set(1, 0.0);

   layers_activation_derivative = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation_derivative(inputs); 
   layers_activation_second_derivative = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation_second_derivative(inputs); 

   interlayers_combination_combination_Jacobian = nn.get_multilayer_perceptron_pointer()->calculate_interlayers_combination_combination_Jacobian(inputs);

   output_objective_gradient.set(1, 0.0);
   output_objective_Hessian.set(1, 1, 0.0);

   layers_delta = mof.calculate_layers_delta(layers_activation_derivative, output_objective_gradient);
   interlayers_Delta = mof.calculate_interlayers_Delta(layers_activation_derivative, layers_activation_second_derivative, interlayers_combination_combination_Jacobian, output_objective_gradient, output_objective_Hessian, layers_delta);

   assert_true(interlayers_Delta.get_rows_number() == 1, LOG);
   assert_true(interlayers_Delta.get_columns_number() == 1, LOG);
   assert_true(interlayers_Delta[0][0].get_rows_number() == 1, LOG);
   assert_true(interlayers_Delta[0][0].get_columns_number() == 1, LOG);
   assert_true(interlayers_Delta[0][0] == 0.0, LOG);

   // Test

   nn.set(1, 1);

   nn.initialize_parameters(0.0);

   inputs.set(1, 0.0);

   outputs = nn.calculate_outputs(inputs);

   layers_activation_derivative = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation_derivative(inputs); 
   layers_activation_second_derivative = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation_second_derivative(inputs); 

   interlayers_combination_combination_Jacobian = nn.get_multilayer_perceptron_pointer()->calculate_interlayers_combination_combination_Jacobian(inputs);

   output_objective_gradient.set(1, 2.0*outputs[0]);
   
   output_objective_Hessian.set(1, 1, 2.0);

   layers_delta = mof.calculate_layers_delta(layers_activation_derivative, output_objective_gradient);
   interlayers_Delta = mof.calculate_interlayers_Delta(layers_activation_derivative, layers_activation_second_derivative, interlayers_combination_combination_Jacobian, output_objective_gradient, output_objective_Hessian, layers_delta);

   assert_true(interlayers_Delta.get_rows_number() == 1, LOG);
   assert_true(interlayers_Delta.get_columns_number() == 1, LOG);
   assert_true(interlayers_Delta[0][0].get_rows_number() == 1, LOG);
   assert_true(interlayers_Delta[0][0].get_columns_number() == 1, LOG);
//   assert_true(interlayers_Delta[0][0] == 0.0, LOG);

   // Test

   layers_size.set(4, 1);

   nn.set(layers_size);

   inputs.set(1, 1.0);

   outputs = nn.calculate_outputs(inputs);
   layers_activation_derivative = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation_derivative(inputs); 
   layers_activation_second_derivative = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation_second_derivative(inputs); 

   interlayers_combination_combination_Jacobian = nn.get_multilayer_perceptron_pointer()->calculate_interlayers_combination_combination_Jacobian(inputs);

   output_objective_gradient.set(1, 2.0*outputs[0]);
   
   output_objective_Hessian.set(1, 1, 2.0);

   layers_delta = mof.calculate_layers_delta(layers_activation_derivative, output_objective_gradient);
   interlayers_Delta = mof.calculate_interlayers_Delta(layers_activation_derivative, layers_activation_second_derivative, interlayers_combination_combination_Jacobian, output_objective_gradient, output_objective_Hessian, layers_delta);

   assert_true(interlayers_Delta.get_rows_number() == 3, LOG);
   assert_true(interlayers_Delta.get_columns_number() == 3, LOG);
   assert_true(interlayers_Delta[0][0].get_rows_number() == 1, LOG);
   assert_true(interlayers_Delta[0][0].get_columns_number() == 1, LOG);
//   assert_true(interlayers_Delta[0][0] == 0.0, LOG);
}


// void test_calculate_point_gradient(void) method

void PerformanceTermTest::test_calculate_point_gradient(void)
{
   message += "test_calculate_point_gradient\n";

   NeuralNetwork nn;

   unsigned int network_parameters_number;

   Vector<double> inputs;

   Vector< Vector<double> > layers_activation; 
   Vector< Vector<double> > layers_activation_derivative; 
   Vector<double> output_objective_gradient;

   MockPerformanceTerm mof(&nn);

   Vector< Vector<double> > layers_delta;

   Vector<double> point_gradient;

   // Test 
   
   nn.set();
   nn.construct_multilayer_perceptron();

   inputs.set();

   layers_activation_derivative = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation_derivative(inputs); 

   layers_delta = mof.calculate_layers_delta(layers_activation_derivative, output_objective_gradient);

   point_gradient = mof.calculate_point_gradient(inputs, layers_activation, layers_delta);

   assert_true(point_gradient.size() == 0, LOG);

   // Test

   nn.set(1, 1);
   
   network_parameters_number = nn.count_parameters_number();

   inputs.set(1, 0.0);

   layers_activation = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation(inputs); 
   layers_activation_derivative = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation_derivative(inputs); 

   output_objective_gradient.set(1, 0.0);

   layers_delta = mof.calculate_layers_delta(layers_activation_derivative, output_objective_gradient);

   point_gradient = mof.calculate_point_gradient(inputs, layers_activation, layers_delta);

   assert_true(point_gradient.size() == network_parameters_number, LOG);
   assert_true(point_gradient[0] == 0.0, LOG);

   // Test

   nn.set(1, 1, 1);

   network_parameters_number = nn.count_parameters_number();

   inputs.set(1, 0.0);

   layers_activation = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation(inputs); 
   layers_activation_derivative = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation_derivative(inputs); 

   output_objective_gradient.set(1, 0.0);

   layers_delta = mof.calculate_layers_delta(layers_activation_derivative, output_objective_gradient);

   point_gradient = mof.calculate_point_gradient(inputs, layers_activation, layers_delta);

   assert_true(point_gradient.size() == network_parameters_number, LOG);
   assert_true(point_gradient[0] == 0.0, LOG);
}


// void test_calculate_point_Hessian(void) method
// @todo

void PerformanceTermTest::test_calculate_point_Hessian(void)
{
   message += "test_calculate_point_Hessian\n";

   NeuralNetwork nn;

//   unsigned int parameters_number;

   Vector<double> inputs;

   Vector< Vector<double> > layers_activation; 
   Vector< Vector<double> > layers_activation_derivative; 
   Vector< Vector<double> > layers_activation_second_derivative; 

   Matrix< Matrix<double> > interlayers_combination_combination_Jacobian;

   Vector< Vector< Vector<double> > > perceptrons_combination_parameters_gradient;

   Vector<double> output_objective_gradient;
   Matrix<double> output_objective_Hessian;

   MockPerformanceTerm mof(&nn);

   Vector< Vector<double> > layers_delta;
   Matrix< Matrix<double> > interlayers_Delta;

   Matrix<double> point_Hessian;
   
   // Test 

   nn.set();
   nn.construct_multilayer_perceptron();

   layers_delta = mof.calculate_layers_delta(layers_activation_derivative, output_objective_gradient);
   interlayers_Delta = mof.calculate_interlayers_Delta(layers_activation_derivative, layers_activation_second_derivative, interlayers_combination_combination_Jacobian, output_objective_gradient, output_objective_Hessian, layers_delta);

   point_Hessian = mof.calculate_point_Hessian(layers_activation_derivative, perceptrons_combination_parameters_gradient, interlayers_combination_combination_Jacobian, layers_delta, interlayers_Delta);

   assert_true(point_Hessian.get_rows_number() == 0, LOG);
   assert_true(point_Hessian.get_columns_number() == 0, LOG);

   // Test

   nn.set(1, 1);
 
//   parameters_number = nn.count_parameters_number();

   inputs.set(1, 0.0);

   layers_activation = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation(inputs); 
   layers_activation_derivative = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation_derivative(inputs); 
   layers_activation_second_derivative = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation_second_derivative(inputs); 

   output_objective_gradient.set(1, 0.0);
   output_objective_Hessian.set(1, 1, 0.0);

   layers_delta = mof.calculate_layers_delta(layers_activation_derivative, output_objective_gradient);
   interlayers_Delta = mof.calculate_interlayers_Delta(layers_activation_derivative, layers_activation_second_derivative, interlayers_combination_combination_Jacobian, output_objective_gradient, output_objective_Hessian, layers_delta);

//   point_Hessian = mof.calculate_point_Hessian(layers_activation_derivative, perceptrons_combination_parameters_gradient, interlayers_combination_combination_Jacobian, layers_delta, interlayers_Delta);

//   assert_true(point_Hessian.get_rows_number() == network_parameters_number, LOG);
//   assert_true(point_Hessian.get_columns_number() == network_parameters_number, LOG);
//   assert_true(point_Hessian[0][0] == 0.0, LOG);

   // Test

   nn.set(1, 1, 1);
 
//   parameters_number = nn.count_parameters_number();

   inputs.set(1, 0.0);

   layers_activation = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation(inputs); 
   layers_activation_derivative = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation_derivative(inputs); 
   layers_activation_second_derivative = nn.get_multilayer_perceptron_pointer()->calculate_layers_activation_second_derivative(inputs); 

   output_objective_gradient.set(1, 0.0);
   output_objective_Hessian.set(1, 1, 0.0);

   layers_delta = mof.calculate_layers_delta(layers_activation_derivative, output_objective_gradient);
//   interlayers_Delta = mof.calculate_interlayers_Delta(layers_activation_derivative, layers_activation_second_derivative, interlayers_combination_combination_Jacobian, output_objective_gradient, output_objective_Hessian, layers_delta);

//   point_Hessian = mof.calculate_point_Hessian(inputs, layers_activation, layers_delta, layers_Delta);

//   assert_true(point_Hessian.get_rows_number() == network_parameters_number, LOG);
//   assert_true(point_Hessian.get_columns_number() == network_parameters_number, LOG);
//   assert_true(point_Hessian[0][0] == 0.0, LOG);

}


// void test_calculate_evaluation(void) method

void PerformanceTermTest::test_calculate_evaluation(void)
{
   message += "test_calculate_evaluation\n";

   NeuralNetwork nn;
   MockPerformanceTerm mof(&nn);

   // Test

   nn.set(1,1,1);

   nn.initialize_parameters(0.0);

   assert_true(mof.calculate_evaluation() == 0.0, LOG);

}


// void test_calculate_generalization_evaluation(void) method   

void PerformanceTermTest::test_calculate_generalization_evaluation(void)   
{
   message += "test_calculate_generalization_evaluation\n";

   MockPerformanceTerm mof;

   double generalization_objective;

   // Test

   generalization_objective = mof.calculate_generalization_evaluation();

   assert_true(generalization_objective == 0.0, LOG);
}


// void test_calculate_gradient(void) method
// @todo

void PerformanceTermTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

   NumericalDifferentiation nd;

   NeuralNetwork nn;

//   unsigned int parameters_number;
 
   Vector<double> parameters;

   MockPerformanceTerm mof(&nn);

   Vector<double> gradient;
   Vector<double> numerical_gradient;

   // Test 

   nn.set(1, 1);

   nn.initialize_parameters(0.0);

   gradient = mof.calculate_gradient();

//   parameters_number = nn.count_parameters_number();

//   assert_true(gradient.size() == parameters_number, LOG);
//   assert_true(gradient == 0.0, LOG);

   // Test

   nn.set(1, 1);

   nn.initialize_parameters_normal();

   parameters = nn.arrange_parameters();

   gradient = mof.calculate_gradient();

//   numerical_gradient = nd.calculate_gradient(mof, &MockPerformanceTerm::calculate_evaluation, parameters);

//   assert_true((gradient-numerical_gradient).calculate_absolute_value() < 1.0e-3, LOG);

}


// void test_calculate_Hessian(void) method
// @todo

void PerformanceTermTest::test_calculate_Hessian(void)
{
   message += "test_calculate_Hessian\n";

   NeuralNetwork nn;
   unsigned int parameters_number;
   Vector<double> parameters;
   
   MockPerformanceTerm mof(&nn);
   Matrix<double> Hessian;

   // Test

   nn.set(1, 1, 1);

   nn.initialize_parameters(0.0);

   parameters_number = nn.count_parameters_number();
   parameters = nn.arrange_parameters();

   Hessian = mof.calculate_Hessian();

//   assert_true(Hessian.get_rows_number() == parameters_number, LOG);
//   assert_true(Hessian.get_columns_number() == parameters_number, LOG);

   // Test

   nn.set();

   nn.initialize_parameters(0.0);

   parameters_number = nn.count_parameters_number();
   parameters = nn.arrange_parameters();

   Hessian = mof.calculate_Hessian();

   assert_true(Hessian.get_rows_number() == parameters_number, LOG);
   assert_true(Hessian.get_columns_number() == parameters_number, LOG);

   // Test

   nn.set(1, 1, 1);

   nn.initialize_parameters(0.0);

   parameters_number = nn.count_parameters_number();
   parameters = nn.arrange_parameters();

   Hessian = mof.calculate_Hessian();

//   assert_true(Hessian.get_rows_number() == parameters_number, LOG);
//   assert_true(Hessian.get_columns_number() == parameters_number, LOG);

}



// void test_to_XML(void) method

void PerformanceTermTest::test_to_XML(void)
{
   message += "test_to_XML\n";

   MockPerformanceTerm mof;

   TiXmlElement* mofe = mof.to_XML();

   assert_true(mofe != NULL, LOG);
}


// void test_print_information(void) method

void PerformanceTermTest::test_print_information(void)
{
   message += "test_print_information\n";

//   MockPerformanceTerm mof;

//   mof.print_information();
}


// void run_test_case(void) method

void PerformanceTermTest::run_test_case(void)
{
   message += "Running performance term test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_neural_network_pointer();

   test_get_numerical_differentiation_pointer();

   // Objective term methods 

   test_get_objective_weight();

   // Serialization methods

   test_get_display();

   // Set methods

   test_set_multilayer_perceptron_pointer();

   test_set_numerical_differentiation_pointer();

   test_set_default();

   // Objective term methods 

   test_set_objective_weight();

   // Serialization methods

   test_set_display();

   // delta methods

   test_calculate_layers_delta();
   test_calculate_interlayers_Delta();

   // Point objective function methods

   test_calculate_point_gradient();
   test_calculate_point_Hessian();

   // Objective methods

   test_calculate_evaluation();

   test_calculate_generalization_evaluation();   

   test_calculate_gradient(); 
   test_calculate_Hessian(); 

   // Serialization methods

   test_to_XML();

   test_print_information();

   message += "End of performance term test case...\n";
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
