/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   P E R C E P T R O N   L A Y E R   T E S T   C L A S S                                                      */
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
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>   

// OpenNN incldues

#include "../../source/neural_network/perceptron_layer.h"

#include "../../source/utilities/numerical_differentiation.h"

// Unit testing includes

#include "perceptron_layer_test.h"


using namespace OpenNN;


// GENERAL CONSTRUCTOR

PerceptronLayerTest::PerceptronLayerTest(void) : UnitTesting()
{
}


// DESTRUCTOR

PerceptronLayerTest::~PerceptronLayerTest(void)
{
}


// METHODS

// void test_constructor(void) method

void PerceptronLayerTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default constructor

   PerceptronLayer l1;

   assert_true(l1.count_inputs_number() == 0, LOG);
   assert_true(l1.count_perceptrons_number() == 0, LOG);

   // Copy constructor

   l1.set(1, 2);

   PerceptronLayer l2(l1);

   assert_true(l2.count_inputs_number() == 1, LOG);
   assert_true(l2.count_perceptrons_number() == 2, LOG);
}


// void test_destructor(void)

void PerceptronLayerTest::test_destructor(void)
{
   message += "test_destructor\n";

}


// void test_assignment_operator(void)

void PerceptronLayerTest::test_assignment_operator(void)
{
   message += "test_assignment_operator\n";

   PerceptronLayer l_1;
   PerceptronLayer l_2 = l_1;

   assert_true(l_2.count_inputs_number() == 0, LOG);
   assert_true(l_2.count_perceptrons_number() == 0, LOG);
   
}


// void test_count_inputs_number(void) method

void PerceptronLayerTest::test_count_inputs_number(void)
{
   message += "test_count_inputs_number\n";

   PerceptronLayer l;

   // Test

   l.set();
   assert_true(l.count_inputs_number() == 0, LOG);

   // Test

   l.set(1, 1);
   assert_true(l.count_inputs_number() == 1, LOG);
}


// void test_count_perceptrons_number(void) method

void PerceptronLayerTest::test_count_perceptrons_number(void)
{
   message += "test_get_size\n";

   PerceptronLayer l(1, 1);
   
   assert_true(l.count_perceptrons_number() == 1, LOG);
}


// void test_get_activation_function(void) method

void PerceptronLayerTest::test_get_activation_function(void)
{
   message += "test_get_activation_function\n";

   PerceptronLayer l(1, 1);
   
   l.set_activation_function(Perceptron::Logistic);
   assert_true(l.get_activation_function() == Perceptron::Logistic, LOG);

   l.set_activation_function(Perceptron::HyperbolicTangent);
   assert_true(l.get_activation_function() == Perceptron::HyperbolicTangent, LOG);

   l.set_activation_function(Perceptron::Threshold);
   assert_true(l.get_activation_function() == Perceptron::Threshold, LOG);
   l.set_activation_function(Perceptron::SymmetricThreshold);
   assert_true(l.get_activation_function() == Perceptron::SymmetricThreshold, LOG);

   l.set_activation_function(Perceptron::Linear);
   assert_true(l.get_activation_function() == Perceptron::Linear, LOG);

}


// void test_get_activation_function_name(void) method

void PerceptronLayerTest::test_get_activation_function_name(void)
{
   message += "test_get_activation_function_name\n";
}


// void test_count_parameters_number(void) method

void PerceptronLayerTest::test_count_parameters_number(void)
{      
   message += "test_count_parameters_number\n";

   PerceptronLayer l;

   // Test

   l.set(1, 1);

   assert_true(l.count_parameters_number() == 2, LOG);

   // Test

   l.set(3, 1);

   assert_true(l.count_parameters_number() == 4, LOG);

   // Test

   l.set(2, 4);

   assert_true(l.count_parameters_number() == 12, LOG);

   // Test

   l.set(4, 2);

   assert_true(l.count_parameters_number() == 10, LOG);

}


// void test_count_cumulative_parameters_number(void) method

void PerceptronLayerTest::test_count_cumulative_parameters_number(void)
{      
   message += "test_count_cumulative_parameters_number\n";

   PerceptronLayer l;
}


// void test_set(void) method

void PerceptronLayerTest::test_set(void)
{
   message += "test_set\n";
}


// void test_set_default(void) method

void PerceptronLayerTest::test_set_default(void)
{
   message += "test_set_default\n";
}


// void test_arrange_biases(void) method

void PerceptronLayerTest::test_arrange_biases(void)
{
   message += "test_arrange_biases\n";

   PerceptronLayer l;
   Vector<double> biases;

   // Test

   l.set(1, 1);
   l.initialize_parameters(0.0);

   biases = l.arrange_biases();

   assert_true(biases.size() == 1, LOG);
   assert_true(biases[0] == 0.0, LOG);
}


// void test_arrange_synaptic_weights(void) method

void PerceptronLayerTest::test_arrange_synaptic_weights(void)
{
   message += "test_arrange_synaptic_weights\n";

   PerceptronLayer l;

   Matrix<double> synaptic_weights;

   // Test

   l.set(1, 1);

   l.initialize_parameters(0.0);

   synaptic_weights = l.arrange_synaptic_weights();

   assert_true(synaptic_weights.get_rows_number() == 1, LOG);
   assert_true(synaptic_weights.get_columns_number() == 1, LOG);
   assert_true(synaptic_weights == 0.0, LOG);
}


// void test_arrange_parameters(void) method

void PerceptronLayerTest::test_arrange_parameters(void)
{
   message += "test_arrange_parameters\n";

   PerceptronLayer l;
   Vector<double> biases;
   Matrix<double> synaptic_weights;
   Vector<double> parameters;

   // Test

   l.set(1, 1);
   l.initialize_parameters(1.0);

   parameters = l.arrange_parameters();

   assert_true(parameters.size() == 2, LOG);
   assert_true(parameters == 1.0, LOG);

   // Test

   l.set(2, 4);

   biases.set(4);
   biases[0] =  0.85;
   biases[1] = -0.25;
   biases[2] =  0.29;
   biases[3] = -0.77;

   l.set_biases(biases);

   synaptic_weights.set(4, 2);

   synaptic_weights[0][0] = -0.04;
   synaptic_weights[0][1] =  0.87;

   synaptic_weights[1][0] =  0.25;
   synaptic_weights[1][1] = -0.27;

   synaptic_weights[2][0] = -0.57;
   synaptic_weights[2][1] =  0.15;

   synaptic_weights[3][0] =  0.96;
   synaptic_weights[3][1] = -0.48;

   l.set_synaptic_weights(synaptic_weights);

   parameters = l.arrange_parameters();

   assert_true(parameters.size() == 12, LOG);
   assert_true(parameters[0] == 0.85, LOG);
   assert_true(parameters[11] == -0.48, LOG);
}


// void test_set_biases(void) method

void PerceptronLayerTest::test_set_biases(void)
{
   message += "test_set_biases\n";

   PerceptronLayer l;

   Vector<double> biases;

   // Test

   l.set(1, 1);

   biases.set(1, 0.0);

   l.set_biases(biases);

   assert_true(l.arrange_biases() == biases, LOG);
}


// void test_set_synaptic_weights(void) method

void PerceptronLayerTest::test_set_synaptic_weights(void)
{
   message += "test_set_synaptic_weights\n";

   PerceptronLayer l(1, 1);

   Matrix<double> synaptic_weights(1, 1, 0.0);

   l.set_synaptic_weights(synaptic_weights);

   assert_true(l.arrange_synaptic_weights() == synaptic_weights, LOG);
}


// void test_set_parameters(void) method

void PerceptronLayerTest::test_set_parameters(void)
{
   message += "test_set_parameters\n";

   PerceptronLayer l(1, 1);

   Vector<double> parameters(2, 0.0);

   l.set_parameters(parameters);

   assert_true(l.arrange_parameters() == parameters, LOG);
}


// void test_get_display(void) method

void PerceptronLayerTest::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set_size(void) method

void PerceptronLayerTest::test_set_size(void)
{
   message += "test_set_size\n";
}


// void test_set_activation_function(void) method

void PerceptronLayerTest::test_set_activation_function(void)
{
   message += "test_set_activation_function\n";
}


// void test_set_display(void) method

void PerceptronLayerTest::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_initialize_random(void) method

void PerceptronLayerTest::test_initialize_random(void)
{
   message += "test_initialize_random\n";

   PerceptronLayer l;

   unsigned int inputs_number;
   unsigned int perceptrons_number;

   // Test

   l.initialize_random();

   inputs_number = l.count_inputs_number();

   assert_true(inputs_number >= 1 && inputs_number <= 10, LOG); 

   perceptrons_number = l.count_perceptrons_number();

   assert_true(perceptrons_number >= 1 && perceptrons_number <= 10, LOG); 
}


// void test_initialize_parameters(void) method

void PerceptronLayerTest::test_initialize_parameters(void)
{
   message += "test_initialize_parameters\n";

   PerceptronLayer l;

   Vector<double> parameters;

   // Test

   l.set(1, 1);
   l.initialize_parameters(0.0);

   parameters = l.arrange_parameters();

   assert_true(parameters == 0.0, LOG);
}


// void test_initialize_biases(void) method

void PerceptronLayerTest::test_initialize_biases(void)
{
   message += "test_initialize_biases\n";
}


// void test_initialize_synaptic_weights(void) method

void PerceptronLayerTest::test_initialize_synaptic_weights(void)
{
   message += "test_initialize_synaptic_weights\n";
}



// void test_initialize_parameters_uniform(void) method

void PerceptronLayerTest::test_initialize_parameters_uniform(void)
{
   message += "test_initialize_parameters_uniform\n";

   PerceptronLayer l;
   Vector<double> parameters;

   // Test

   l.set(1, 1);

   l.initialize_parameters_uniform();
   parameters = l.arrange_parameters();
   
   assert_true(parameters >= -1.0, LOG);
   assert_true(parameters <=  1.0, LOG);   

}


// void test_initialize_parameters_normal(void) method

void PerceptronLayerTest::test_initialize_parameters_normal(void)
{
   message += "test_initialize_parameters_normal\n";

   PerceptronLayer l;
   Vector<double> parameters;

   // Test

   l.set(1, 1);

   l.initialize_parameters_normal(1.0, 0.0);
   parameters = l.arrange_parameters();

   assert_true(parameters == 1.0, LOG);
}


// void test_calculate_parameters_norm(void)

void PerceptronLayerTest::test_calculate_parameters_norm(void)
{
   message += "test_calculate_parameters_norm\n";

   PerceptronLayer l;
   Vector<double> biases;
   Matrix<double> synaptic_weights;
   Vector<double> parameters;

   double parameters_norm;

   // Test

   l.set(1, 1);
   l.initialize_parameters(0.0);

   parameters_norm = l.calculate_parameters_norm();

   assert_true(parameters_norm == 0.0, LOG);

   // Test

   l.set(2, 4);

   biases.set(4);
   biases[0] =  0.85;
   biases[1] = -0.25;
   biases[2] =  0.29;
   biases[3] = -0.77;

   l.set_biases(biases);

   synaptic_weights.set(4, 2);

   synaptic_weights[0][0] = -0.04;
   synaptic_weights[0][1] =  0.87;

   synaptic_weights[1][0] =  0.25;
   synaptic_weights[1][1] = -0.27;

   synaptic_weights[2][0] = -0.57;
   synaptic_weights[2][1] =  0.15;

   synaptic_weights[3][0] =  0.96;
   synaptic_weights[3][1] = -0.48;

   l.set_synaptic_weights(synaptic_weights);

   parameters = l.arrange_parameters();

   parameters_norm = l.calculate_parameters_norm();

   assert_true(parameters_norm == parameters.calculate_norm(), LOG);

   // Test

   l.set(4, 2);

   parameters.set(10);
   parameters[0] =  0.41;
   parameters[1] = -0.68; 
   parameters[2] =  0.14; 
   parameters[3] = -0.50; 
   parameters[4] =  0.52; 
   parameters[5] = -0.70; 
   parameters[6] =  0.85; 
   parameters[7] = -0.18; 
   parameters[8] = -0.65; 
   parameters[9] =  0.05; 

   l.set_parameters(parameters);

   parameters_norm = l.calculate_parameters_norm();

   assert_true(parameters_norm == parameters.calculate_norm(), LOG);
}


// void test_calculate_combination(void) method

void PerceptronLayerTest::test_calculate_combination(void)
{
   message += "test_calculate_combination\n";

   PerceptronLayer l;

   Vector<double> biases;
   Matrix<double> synaptic_weights;
   Vector<double> parameters;

   Vector<double> inputs;   

   Vector<double> combination;

   // Test
 
   l.set(1, 2);
   l.initialize_parameters(0.0);
   inputs.set(1, 0.0);   

   combination = l.calculate_combination(inputs);

   assert_true(combination.size() == 2, LOG);      
   assert_true(combination == 0.0, LOG);

   // Test

   l.set(2, 4);

   biases.set(4);
   biases[0] =  0.85;
   biases[1] = -0.25;
   biases[2] =  0.29;
   biases[3] = -0.77;

   l.set_biases(biases);

   synaptic_weights.set(4, 2);

   synaptic_weights[0][0] = -0.04;
   synaptic_weights[0][1] =  0.87;

   synaptic_weights[1][0] =  0.25;
   synaptic_weights[1][1] = -0.27;

   synaptic_weights[2][0] = -0.57;
   synaptic_weights[2][1] =  0.15;

   synaptic_weights[3][0] =  0.96;
   synaptic_weights[3][1] = -0.48;

   l.set_synaptic_weights(synaptic_weights);

   inputs.set(2);
   inputs[0] = -0.88;
   inputs[1] =  0.78;

   combination = l.calculate_combination(inputs);

   assert_true(combination == biases + synaptic_weights.dot(inputs), LOG);

   // Test

   l.set(4, 2);

   parameters.set(10);
   parameters[0] =  0.41;
   parameters[1] = -0.68; 
   parameters[2] =  0.14; 
   parameters[3] = -0.50; 
   parameters[4] =  0.52; 
   parameters[5] = -0.70; 
   parameters[6] =  0.85; 
   parameters[7] = -0.18; 
   parameters[8] = -0.65; 
   parameters[9] =  0.05; 

   l.set_parameters(parameters);

   inputs.set(4);
   inputs[0] =  0.85;
   inputs[1] = -0.25;
   inputs[2] =  0.29;
   inputs[3] = -0.77;

   combination = l.calculate_combination(inputs);

   biases = l.arrange_biases();
   synaptic_weights = l.arrange_synaptic_weights();

   assert_true(combination == biases + synaptic_weights.dot(inputs), LOG);
}


// void test_calculate_combination_Jacobian(void) method

void PerceptronLayerTest::test_calculate_combination_Jacobian(void)
{
   message += "test_calculate_combination_Jacobian\n";

   NumericalDifferentiation nd;

   PerceptronLayer l;

   Matrix<double> synaptic_weights;
   Vector<double> parameters;
   Vector<double> inputs;

   Matrix<double> combination_Jacobian;
   Matrix<double> numerical_combination_Jacobian;

   // Test

   l.set(3, 2);

   inputs.set(3);
   inputs.initialize_normal();

   combination_Jacobian = l.calculate_combination_Jacobian(inputs);

   if(numerical_differentiation_tests)
   {
      numerical_combination_Jacobian = nd.calculate_Jacobian(l, &PerceptronLayer::calculate_combination, inputs);

      assert_true((combination_Jacobian-numerical_combination_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
   }

   // Test

   l.set(4, 2);

   parameters.set(10);
   parameters[0] =  0.41;
   parameters[1] = -0.68; 
   parameters[2] =  0.14; 
   parameters[3] = -0.50; 
   parameters[4] =  0.52; 
   parameters[5] = -0.70; 
   parameters[6] =  0.85; 
   parameters[7] = -0.18; 
   parameters[8] = -0.65; 
   parameters[9] =  0.05; 

   l.set_parameters(parameters);

   inputs.set(4);
   inputs[0] =  0.85;
   inputs[1] = -0.25;
   inputs[2] =  0.29;
   inputs[3] = -0.77;

   combination_Jacobian = l.calculate_combination_Jacobian(inputs);

   synaptic_weights = l.arrange_synaptic_weights();

   assert_true(combination_Jacobian == synaptic_weights, LOG);

   if(numerical_differentiation_tests)
   {
      numerical_combination_Jacobian = nd.calculate_Jacobian(l, &PerceptronLayer::calculate_combination, inputs);
      assert_true((combination_Jacobian-numerical_combination_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
   }

}


// void test_calculate_combination_Hessian_form(void) method

void PerceptronLayerTest::test_calculate_combination_Hessian_form(void)
{
   message += "test_calculate_combination_Hessian_form\n";

   NumericalDifferentiation nd;

   PerceptronLayer l;

   Vector<double> parameters;
   Vector<double> inputs;

   Vector< Matrix<double> > combination_Hessian_form;
   Vector< Matrix<double> > numerical_combination_Hessian_form;

   // Test

   l.set(2, 4);

   inputs.set(2);
   inputs.initialize_normal();

   combination_Hessian_form = l.calculate_combination_Hessian_form(inputs);

   assert_true(combination_Hessian_form.size() == 4, LOG);

   if(numerical_differentiation_tests)
   {
      numerical_combination_Hessian_form = nd.calculate_Hessian_form(l, &PerceptronLayer::calculate_combination, inputs);

      assert_true((combination_Hessian_form[0]-numerical_combination_Hessian_form[0]).calculate_absolute_value() < 1.0e-3, LOG);
      assert_true((combination_Hessian_form[1]-numerical_combination_Hessian_form[1]).calculate_absolute_value() < 1.0e-3, LOG);
      assert_true((combination_Hessian_form[2]-numerical_combination_Hessian_form[2]).calculate_absolute_value() < 1.0e-3, LOG);
      assert_true((combination_Hessian_form[3]-numerical_combination_Hessian_form[3]).calculate_absolute_value() < 1.0e-3, LOG);
   }

   // Test

   l.set(4, 2);

   parameters.set(10);
   parameters[0] =  0.41;
   parameters[1] = -0.68; 
   parameters[2] =  0.14; 
   parameters[3] = -0.50; 
   parameters[4] =  0.52; 
   parameters[5] = -0.70; 
   parameters[6] =  0.85; 
   parameters[7] = -0.18; 
   parameters[8] = -0.65; 
   parameters[9] =  0.05; 

   l.set_parameters(parameters);

   inputs.set(4);
   inputs[0] =  0.85;
   inputs[1] = -0.25;
   inputs[2] =  0.29;
   inputs[3] = -0.77;

   combination_Hessian_form = l.calculate_combination_Hessian_form(inputs);

   assert_true(combination_Hessian_form.size() == 2, LOG);

   assert_true(combination_Hessian_form[0].get_rows_number() == 4, LOG);
   assert_true(combination_Hessian_form[0].get_columns_number() == 4, LOG);
   assert_true(combination_Hessian_form[0] == 0.0, LOG);
   assert_true(combination_Hessian_form[0].is_symmetric(), LOG);

   assert_true(combination_Hessian_form[1].get_rows_number() == 4, LOG);
   assert_true(combination_Hessian_form[1].get_columns_number() == 4, LOG);
   assert_true(combination_Hessian_form[1] == 0.0, LOG);
   assert_true(combination_Hessian_form[1].is_symmetric(), LOG);

   if(numerical_differentiation_tests)
   {
      numerical_combination_Hessian_form = nd.calculate_Hessian_form(l, &PerceptronLayer::calculate_combination, inputs);

      assert_true((combination_Hessian_form[0]-numerical_combination_Hessian_form[0]).calculate_absolute_value() < 1.0e-3, LOG);
      assert_true((combination_Hessian_form[1]-numerical_combination_Hessian_form[1]).calculate_absolute_value() < 1.0e-3, LOG);
   }
}


// void test_calculate_combination_parameters_Jacobian(void) method

void PerceptronLayerTest::test_calculate_combination_parameters_Jacobian(void)
{
   message += "test_calculate_combination_parameters_Jacobian\n";

   NumericalDifferentiation nd;

   PerceptronLayer l;

   Vector<double> parameters;

   Vector<double> inputs;

   Matrix<double> combination_parameters_Jacobian;
   Matrix<double> numerical_combination_parameters_Jacobian;

   // Test

   l.set(2, 4);

   parameters = l.arrange_parameters();

   inputs.set(2);
   inputs[0] = -0.88;
   inputs[1] =  0.78;

   combination_parameters_Jacobian = l.calculate_combination_parameters_Jacobian(inputs, parameters);

   if(numerical_differentiation_tests)
   {
      numerical_combination_parameters_Jacobian = nd.calculate_Jacobian(l, &PerceptronLayer::calculate_combination_parameters, inputs, parameters);

      assert_true((combination_parameters_Jacobian-numerical_combination_parameters_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
   }

   // Test

   l.set(4, 2);

   parameters.set(10);
   parameters[0] =  0.41;
   parameters[1] = -0.68; 
   parameters[2] =  0.14; 
   parameters[3] = -0.50; 
   parameters[4] =  0.52; 
   parameters[5] = -0.70; 
   parameters[6] =  0.85; 
   parameters[7] = -0.18; 
   parameters[8] = -0.65; 
   parameters[9] =  0.05; 

   l.set_parameters(parameters);

   inputs.set(4);
   inputs[0] =  0.85;
   inputs[1] = -0.25;
   inputs[2] =  0.29;
   inputs[3] = -0.77;

   combination_parameters_Jacobian = l.calculate_combination_parameters_Jacobian(inputs, parameters);

   if(numerical_differentiation_tests)
   {
      numerical_combination_parameters_Jacobian = nd.calculate_Jacobian(l, &PerceptronLayer::calculate_combination_parameters, inputs, parameters);

      assert_true((combination_parameters_Jacobian-numerical_combination_parameters_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
   }
}


// void test_calculate_combination_parameters_Hessian_form(void) method

void PerceptronLayerTest::test_calculate_combination_parameters_Hessian_form(void)
{
   message += "test_calculate_combination_parameters_Hessian_form\n";

   NumericalDifferentiation nd;

   PerceptronLayer l;

   unsigned int parameters_number;
   Vector<double> parameters;

   Vector<double> inputs;

   Vector< Matrix<double> > combination_parameters_Hessian_form;
   Vector< Matrix<double> > numerical_combination_parameters_Hessian_form;

   // Test

   l.set(2, 4);

   parameters_number = l.count_parameters_number();
   parameters = l.arrange_parameters();

   inputs.set(2);
   inputs[0] = -0.88;
   inputs[1] =  0.78;

   combination_parameters_Hessian_form = l.calculate_combination_parameters_Hessian_form(inputs, parameters);

   assert_true(combination_parameters_Hessian_form.size() == 4, LOG);
   assert_true(combination_parameters_Hessian_form[0].get_rows_number() == parameters_number, LOG);
   assert_true(combination_parameters_Hessian_form[0].get_columns_number() == parameters_number, LOG);
   assert_true(combination_parameters_Hessian_form[0].calculate_absolute_value() < 1.0e-6 , LOG);

   assert_true(combination_parameters_Hessian_form[1].get_rows_number() == parameters_number, LOG);
   assert_true(combination_parameters_Hessian_form[1].get_columns_number() == parameters_number, LOG);
   assert_true(combination_parameters_Hessian_form[1].calculate_absolute_value() < 1.0e-6 , LOG);

   assert_true(combination_parameters_Hessian_form[2].get_rows_number() == parameters_number, LOG);
   assert_true(combination_parameters_Hessian_form[2].get_columns_number() == parameters_number, LOG);
   assert_true(combination_parameters_Hessian_form[2].calculate_absolute_value() < 1.0e-6 , LOG);

   assert_true(combination_parameters_Hessian_form[3].get_rows_number() == parameters_number, LOG);
   assert_true(combination_parameters_Hessian_form[3].get_columns_number() == parameters_number, LOG);
   assert_true(combination_parameters_Hessian_form[3].calculate_absolute_value() < 1.0e-6 , LOG);

   if(numerical_differentiation_tests)
   {
      numerical_combination_parameters_Hessian_form = nd.calculate_Hessian_form(l, &PerceptronLayer::calculate_combination_parameters, inputs, parameters);

      assert_true((combination_parameters_Hessian_form[0]-numerical_combination_parameters_Hessian_form[0]).calculate_absolute_value() < 1.0e-3, LOG);
      assert_true((combination_parameters_Hessian_form[1]-numerical_combination_parameters_Hessian_form[1]).calculate_absolute_value() < 1.0e-3, LOG);
      assert_true((combination_parameters_Hessian_form[2]-numerical_combination_parameters_Hessian_form[2]).calculate_absolute_value() < 1.0e-3, LOG);
      assert_true((combination_parameters_Hessian_form[3]-numerical_combination_parameters_Hessian_form[3]).calculate_absolute_value() < 1.0e-3, LOG);
   }

   // Test

   l.set(4, 2);

   parameters.set(10);
   parameters[0] =  0.41;
   parameters[1] = -0.68; 
   parameters[2] =  0.14; 
   parameters[3] = -0.50; 
   parameters[4] =  0.52; 
   parameters[5] = -0.70; 
   parameters[6] =  0.85; 
   parameters[7] = -0.18; 
   parameters[8] = -0.65; 
   parameters[9] =  0.05; 

   l.set_parameters(parameters);

   inputs.set(4);
   inputs[0] =  0.85;
   inputs[1] = -0.25;
   inputs[2] =  0.29;
   inputs[3] = -0.77;

   parameters_number = l.count_parameters_number();

   combination_parameters_Hessian_form = l.calculate_combination_parameters_Hessian_form(inputs, parameters);

   assert_true(combination_parameters_Hessian_form.size() == 2, LOG);
   assert_true(combination_parameters_Hessian_form[0].get_rows_number() == parameters_number, LOG);
   assert_true(combination_parameters_Hessian_form[0].get_columns_number() == parameters_number, LOG);
   assert_true(combination_parameters_Hessian_form[0].calculate_absolute_value() < 1.0e-6 , LOG);

   assert_true(combination_parameters_Hessian_form[1].get_rows_number() == parameters_number, LOG);
   assert_true(combination_parameters_Hessian_form[1].get_columns_number() == parameters_number, LOG);
   assert_true(combination_parameters_Hessian_form[1].calculate_absolute_value() < 1.0e-6 , LOG);

   if(numerical_differentiation_tests)
   {
      numerical_combination_parameters_Hessian_form = nd.calculate_Hessian_form(l, &PerceptronLayer::calculate_combination_parameters, inputs, parameters);

      assert_true((combination_parameters_Hessian_form[0]-numerical_combination_parameters_Hessian_form[0]).calculate_absolute_value() < 1.0e-3, LOG);
      assert_true((combination_parameters_Hessian_form[1]-numerical_combination_parameters_Hessian_form[1]).calculate_absolute_value() < 1.0e-3, LOG);
   }
}


// void test_calculate_activation(void) method

void PerceptronLayerTest::test_calculate_activation(void)
{
   message += "test_calculate_activation\n";

   PerceptronLayer l;

   Vector<double> parameters;
 
   Vector<double> inputs;   
   Vector<double> combination;   
   Vector<double> activation;

   // Test

   l.set(1, 2);
   l.initialize_parameters(0.0);

   combination.set(2, 0.0);

   l.set_activation_function(Perceptron::Logistic);
   activation = l.calculate_activation(combination);
   assert_true(activation.size() == 2, LOG);
   assert_true(activation == 0.5, LOG);

   // Test

   l.set(1, 2);
   l.initialize_parameters(0.0);

   combination.set(2, 0.0);

   l.set_activation_function(Perceptron::HyperbolicTangent);
   activation = l.calculate_activation(combination);
   assert_true(activation.size() == 2, LOG);
   assert_true(activation == 0.0, LOG);

   // Test

   l.set(1, 2);
   l.initialize_parameters(0.0);

   combination.set(2, 0.0);

   l.set_activation_function(Perceptron::Threshold);
   activation = l.calculate_activation(combination);
   assert_true(activation.size() == 2, LOG);
   assert_true(activation == 1.0, LOG);

   // Test

   l.set(1, 2);
   l.initialize_parameters(0.0);

   combination.set(2, 0.0);

   l.set_activation_function(Perceptron::SymmetricThreshold);
   activation = l.calculate_activation(combination);
   assert_true(activation.size() == 2, LOG);
   assert_true(activation == 1.0, LOG);

   // Test

   l.set(1, 2);
   l.initialize_parameters(0.0);

   combination.set(2, 0.0);

   l.set_activation_function(Perceptron::Linear);
   activation = l.calculate_activation(combination);
   assert_true(activation.size() == 2, LOG);
   assert_true(activation == 0.0, LOG);

   // Test

   l.set(4, 2);

   parameters.set(10);
   parameters[0] =  0.41;
   parameters[1] = -0.68; 
   parameters[2] =  0.14; 
   parameters[3] = -0.50; 
   parameters[4] =  0.52; 
   parameters[5] = -0.70; 
   parameters[6] =  0.85; 
   parameters[7] = -0.18; 
   parameters[8] = -0.65; 
   parameters[9] =  0.05; 

   l.set_parameters(parameters);

   inputs.set(4);
   inputs[0] =  0.85;
   inputs[1] = -0.25;
   inputs[2] =  0.29;
   inputs[3] = -0.77;

   combination = l.calculate_combination(inputs);

   l.set_activation_function(Perceptron::Threshold);
   activation = l.calculate_activation(combination);
   assert_true(activation.size() == 2, LOG);

   l.set_activation_function(Perceptron::SymmetricThreshold);
   activation = l.calculate_activation(combination);
   assert_true(activation.size() == 2, LOG);

   l.set_activation_function(Perceptron::Logistic);
   activation = l.calculate_activation(combination);
   assert_true(activation.size() == 2, LOG);

   l.set_activation_function(Perceptron::HyperbolicTangent);
   activation = l.calculate_activation(combination);       
   assert_true(activation.size() == 2, LOG);

   l.set_activation_function(Perceptron::Linear);
   activation = l.calculate_activation(combination);      
   assert_true(activation.size() == 2, LOG);
}


// void test_calculate_activation_derivative(void) method

void PerceptronLayerTest::test_calculate_activation_derivative(void)
{
   message += "test_calculate_activation_derivative\n";

   NumericalDifferentiation nd;

   PerceptronLayer l;
   Vector<double> parameters;         
   Vector<double> inputs;         
   Vector<double> combination;         
   Vector<double> activation_derivative; 
   Vector<double> numerical_activation_derivative; 

   // Test

   l.set(1, 2);
   combination.set(2, 0.0);         

   l.set_activation_function(Perceptron::Logistic);
   activation_derivative = l.calculate_activation_derivative(combination);
   assert_true(activation_derivative.size() == 2, LOG);
   assert_true(activation_derivative == 0.25, LOG);

   l.set_activation_function(Perceptron::HyperbolicTangent);
   activation_derivative = l.calculate_activation_derivative(combination);       
   assert_true(activation_derivative.size() == 2, LOG);
   assert_true(activation_derivative == 1.0, LOG);

   l.set_activation_function(Perceptron::Linear);
   activation_derivative = l.calculate_activation_derivative(combination);      
   assert_true(activation_derivative.size() == 2, LOG);
   assert_true(activation_derivative == 1.0, LOG);   

   // Test

   if(numerical_differentiation_tests)
   {
      l.set(2, 4);

      combination.set(4);         
      combination[0] =  1.56;
      combination[1] = -0.68;
      combination[2] =  0.91;
      combination[3] = -1.99;

      l.set_activation_function(Perceptron::Threshold);
      activation_derivative = l.calculate_activation_derivative(combination);
      numerical_activation_derivative = nd.calculate_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_derivative - numerical_activation_derivative).calculate_absolute_value() < 1.0e-3, LOG);

      l.set_activation_function(Perceptron::SymmetricThreshold);
      activation_derivative = l.calculate_activation_derivative(combination);
      numerical_activation_derivative = nd.calculate_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_derivative - numerical_activation_derivative).calculate_absolute_value() < 1.0e-3, LOG);

      l.set_activation_function(Perceptron::Logistic);
      activation_derivative = l.calculate_activation_derivative(combination);

      numerical_activation_derivative = nd.calculate_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_derivative - numerical_activation_derivative).calculate_absolute_value() < 1.0e-3, LOG);

      l.set_activation_function(Perceptron::HyperbolicTangent);
      activation_derivative = l.calculate_activation_derivative(combination);       
      numerical_activation_derivative = nd.calculate_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_derivative - numerical_activation_derivative).calculate_absolute_value() < 1.0e-3, LOG);

      l.set_activation_function(Perceptron::Linear);
      activation_derivative = l.calculate_activation_derivative(combination);      
      numerical_activation_derivative = nd.calculate_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_derivative - numerical_activation_derivative).calculate_absolute_value() < 1.0e-3, LOG);
   }

   // Test

   if(numerical_differentiation_tests)
   {
      l.set(4, 2);

      parameters.set(10);
      parameters[0] =  0.41;
      parameters[1] = -0.68; 
      parameters[2] =  0.14; 
      parameters[3] = -0.50; 
      parameters[4] =  0.52; 
      parameters[5] = -0.70; 
      parameters[6] =  0.85; 
      parameters[7] = -0.18; 
      parameters[8] = -0.65; 
      parameters[9] =  0.05; 

      l.set_parameters(parameters);

      inputs.set(4);
      inputs[0] =  0.85;
      inputs[1] = -0.25;
      inputs[2] =  0.29;
      inputs[3] = -0.77;

      combination = l.calculate_combination(inputs);

      l.set_activation_function(Perceptron::Threshold);
      activation_derivative = l.calculate_activation_derivative(combination);
      numerical_activation_derivative = nd.calculate_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_derivative - numerical_activation_derivative).calculate_absolute_value() < 1.0e-3, LOG);

      l.set_activation_function(Perceptron::SymmetricThreshold);
      activation_derivative = l.calculate_activation_derivative(combination);
      numerical_activation_derivative = nd.calculate_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_derivative - numerical_activation_derivative).calculate_absolute_value() < 1.0e-3, LOG);

      l.set_activation_function(Perceptron::Logistic);
      activation_derivative = l.calculate_activation_derivative(combination);
      numerical_activation_derivative = nd.calculate_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_derivative - numerical_activation_derivative).calculate_absolute_value() < 1.0e-3, LOG);

      l.set_activation_function(Perceptron::HyperbolicTangent);
      activation_derivative = l.calculate_activation_derivative(combination);       
      numerical_activation_derivative = nd.calculate_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_derivative - numerical_activation_derivative).calculate_absolute_value() < 1.0e-3, LOG);

      l.set_activation_function(Perceptron::Linear);
      activation_derivative = l.calculate_activation_derivative(combination);      
      numerical_activation_derivative = nd.calculate_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_derivative - numerical_activation_derivative).calculate_absolute_value() < 1.0e-3, LOG);
   }
}


// void test_calculate_activation_second_derivative(void) method

void PerceptronLayerTest::test_calculate_activation_second_derivative(void)
{
   message += "test_calculate_activation_second_derivative\n";

   NumericalDifferentiation nd;

   PerceptronLayer l;

   Vector<double> parameters;         

   Vector<double> inputs;         
   Vector<double> combination;         
   Vector<double> activation_second_derivative; 
   Vector<double> numerical_activation_second_derivative; 

   // Test

   l.set(1, 2);
   l.initialize_parameters(0.0);
   
   combination.set(2, 0.0);   

   l.set_activation_function(Perceptron::Logistic);
   activation_second_derivative  = l.calculate_activation_second_derivative(combination);
   assert_true(activation_second_derivative.size() == 2, LOG);
   assert_true(activation_second_derivative == 0.0, LOG);

   l.set_activation_function(Perceptron::HyperbolicTangent);
   activation_second_derivative = l.calculate_activation_second_derivative(combination);
   assert_true(activation_second_derivative.size() == 2, LOG);
   assert_true(activation_second_derivative == 0.0, LOG);

   l.set_activation_function(Perceptron::Linear);
   activation_second_derivative = l.calculate_activation_second_derivative(combination);
   assert_true(activation_second_derivative.size() == 2, LOG);
   assert_true(activation_second_derivative == 0.0, LOG);

   // Test
   
   if(numerical_differentiation_tests)
   {
      l.set(2, 4);

      combination.set(4);         
      combination[0] =  1.56;
      combination[1] = -0.68;
      combination[2] =  0.91;
      combination[3] = -1.99;

      l.set_activation_function(Perceptron::Threshold);
      activation_second_derivative = l.calculate_activation_second_derivative(combination);
      numerical_activation_second_derivative = nd.calculate_second_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_second_derivative - numerical_activation_second_derivative).calculate_absolute_value() < 1.0e-3, LOG);

      l.set_activation_function(Perceptron::SymmetricThreshold);
      activation_second_derivative = l.calculate_activation_second_derivative(combination);
      numerical_activation_second_derivative = nd.calculate_second_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_second_derivative - numerical_activation_second_derivative).calculate_absolute_value() < 1.0e-3, LOG);

      l.set_activation_function(Perceptron::Logistic);
      activation_second_derivative = l.calculate_activation_second_derivative(combination);
      numerical_activation_second_derivative = nd.calculate_second_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_second_derivative - numerical_activation_second_derivative).calculate_absolute_value() < 1.0e-3, LOG);

      l.set_activation_function(Perceptron::HyperbolicTangent);
      activation_second_derivative = l.calculate_activation_second_derivative(combination);       
      numerical_activation_second_derivative = nd.calculate_second_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_second_derivative - numerical_activation_second_derivative).calculate_absolute_value() < 1.0e-3, LOG);

      l.set_activation_function(Perceptron::Linear);
      activation_second_derivative = l.calculate_activation_second_derivative(combination);      
      numerical_activation_second_derivative = nd.calculate_second_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_second_derivative - numerical_activation_second_derivative).calculate_absolute_value() < 1.0e-3, LOG);
   }

   // Test

   if(numerical_differentiation_tests)
   {
      l.set(4, 2);

      parameters.set(10);
      parameters[0] =  0.41;
      parameters[1] = -0.68; 
      parameters[2] =  0.14; 
      parameters[3] = -0.50; 
      parameters[4] =  0.52; 
      parameters[5] = -0.70; 
      parameters[6] =  0.85; 
      parameters[7] = -0.18; 
      parameters[8] = -0.65; 
      parameters[9] =  0.05; 

      l.set_parameters(parameters);

      inputs.set(4);
      inputs[0] =  0.85;
      inputs[1] = -0.25;
      inputs[2] =  0.29;
      inputs[3] = -0.77;

      combination = l.calculate_combination(inputs);

      l.set_activation_function(Perceptron::Threshold);
      activation_second_derivative = l.calculate_activation_second_derivative(combination);
      numerical_activation_second_derivative = nd.calculate_second_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_second_derivative - numerical_activation_second_derivative).calculate_absolute_value() < 1.0e-3, LOG);

      l.set_activation_function(Perceptron::SymmetricThreshold);
      activation_second_derivative = l.calculate_activation_second_derivative(combination);
      numerical_activation_second_derivative = nd.calculate_second_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_second_derivative - numerical_activation_second_derivative).calculate_absolute_value() < 1.0e-3, LOG);

      l.set_activation_function(Perceptron::Logistic);
      activation_second_derivative = l.calculate_activation_second_derivative(combination);
      numerical_activation_second_derivative = nd.calculate_second_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_second_derivative - numerical_activation_second_derivative).calculate_absolute_value() < 1.0e-3, LOG);

      l.set_activation_function(Perceptron::HyperbolicTangent);
      activation_second_derivative = l.calculate_activation_second_derivative(combination);       
      numerical_activation_second_derivative = nd.calculate_second_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_second_derivative - numerical_activation_second_derivative).calculate_absolute_value() < 1.0e-3, LOG);

      l.set_activation_function(Perceptron::Linear);
      activation_second_derivative = l.calculate_activation_second_derivative(combination);      
      numerical_activation_second_derivative = nd.calculate_second_derivative(l, &PerceptronLayer::calculate_activation, combination);
      assert_true((activation_second_derivative - numerical_activation_second_derivative).calculate_absolute_value() < 1.0e-3, LOG);
   }
}


// void test_calculate_outputs(void) method

void PerceptronLayerTest::test_calculate_outputs(void)
{
   message += "test_calculate_outputs\n";

   PerceptronLayer l;

   Vector<double> parameters;

   Vector<double> inputs;
   Vector<double> outputs;

   // Test 

   l.set(3, 2);
   l.initialize_parameters(0.0);   

   inputs.set(3, 0.0);

   outputs = l.calculate_outputs(inputs);

   assert_true(outputs.size() == 2, LOG);
   assert_true(outputs == 0.0, LOG);

   // Test

   l.set(4, 2);

   parameters.set(10);
   parameters[0] =  0.41;
   parameters[1] = -0.68; 
   parameters[2] =  0.14; 
   parameters[3] = -0.50; 
   parameters[4] =  0.52; 
   parameters[5] = -0.70; 
   parameters[6] =  0.85; 
   parameters[7] = -0.18; 
   parameters[8] = -0.65; 
   parameters[9] =  0.05; 

   l.set_parameters(parameters);

   inputs.set(4);
   inputs[0] =  0.85;
   inputs[1] = -0.25;
   inputs[2] =  0.29;
   inputs[3] = -0.77;

   outputs = l.calculate_outputs(inputs);

   assert_true(outputs.size() ==  2, LOG);
}


// void test_calculate_Jacobian(void) method

void PerceptronLayerTest::test_calculate_Jacobian(void)
{
   message += "test_calculate_Jacobian\n";

   NumericalDifferentiation nd;

   PerceptronLayer l;

   Vector<double> parameters;

   Vector<double> inputs;

   Matrix<double> Jacobian;
   Matrix<double> numerical_Jacobian;

   // Test

   if(numerical_differentiation_tests)
   {
      l.set(3, 2);

      inputs.set(3);
      inputs.initialize_normal();

      Jacobian = l.calculate_Jacobian(inputs);

      numerical_Jacobian = nd.calculate_Jacobian(l, &PerceptronLayer::calculate_outputs, inputs);

      assert_true((Jacobian-numerical_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
   }

   // Test

   if(numerical_differentiation_tests)
   {
      l.set(4, 2);

      parameters.set(10);
      parameters[0] =  0.41;
      parameters[1] = -0.68; 
      parameters[2] =  0.14; 
      parameters[3] = -0.50; 
      parameters[4] =  0.52; 
      parameters[5] = -0.70; 
      parameters[6] =  0.85; 
      parameters[7] = -0.18; 
      parameters[8] = -0.65; 
      parameters[9] =  0.05; 

      l.set_parameters(parameters);

      inputs.set(4);
      inputs[0] =  0.85;
      inputs[1] = -0.25;
      inputs[2] =  0.29;
      inputs[3] = -0.77;

      Jacobian = l.calculate_Jacobian(inputs);

      numerical_Jacobian = nd.calculate_Jacobian(l, &PerceptronLayer::calculate_outputs, inputs);

      assert_true((Jacobian-numerical_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
   }
}


// void test_calculate_Hessian_form(void) method

void PerceptronLayerTest::test_calculate_Hessian_form(void)
{
   message += "test_calculate_Hessian_form\n";

   NumericalDifferentiation nd;

   PerceptronLayer l;

   Vector<double> parameters;

   Vector<double> inputs;

   Vector< Matrix<double> > Hessian_form;
   Vector< Matrix<double> > numerical_Hessian_form;

   Matrix<double> Hessian;

   // Test

   l.set(1, 1);
   l.initialize_parameters(0.0);

   inputs.set(1);
   inputs.initialize(0.0);

   Hessian_form = l.calculate_Hessian_form(inputs);

   assert_true(Hessian_form.size() == 1, LOG);
   assert_true(Hessian_form[0].get_rows_number() == 1, LOG);
   assert_true(Hessian_form[0].get_columns_number() == 1, LOG);
   assert_true(Hessian_form[0] == 0.0, LOG);

   // Test

   if(numerical_differentiation_tests)
   {
      l.set(2, 1);

      inputs.set(2);
      inputs.initialize_normal();

      Hessian_form = l.calculate_Hessian_form(inputs);

      numerical_Hessian_form = nd.calculate_Hessian_form(l, &PerceptronLayer::calculate_outputs, inputs);

      assert_true((Hessian_form[0]-numerical_Hessian_form[0]).calculate_absolute_value() < 1.0e-3, LOG);
   }

   // Test

   l.set(2, 2);

   inputs.set(2);
   inputs.initialize_normal();

   Hessian_form = l.calculate_Hessian_form(inputs);

   assert_true(Hessian_form.size() == 2, LOG);
   assert_true(Hessian_form[0].get_rows_number() == 2, LOG);
   assert_true(Hessian_form[0].get_columns_number() == 2, LOG);
   assert_true(Hessian_form[1].get_rows_number() == 2, LOG);
   assert_true(Hessian_form[1].get_columns_number() == 2, LOG);

   if(numerical_differentiation_tests)
   {
      numerical_Hessian_form = nd.calculate_Hessian_form(l, &PerceptronLayer::calculate_outputs, inputs);

      assert_true((Hessian_form[0]-numerical_Hessian_form[0]).calculate_absolute_value() < 1.0e-3, LOG);
      assert_true((Hessian_form[1]-numerical_Hessian_form[1]).calculate_absolute_value() < 1.0e-3, LOG);
   }

   // Test

   l.set(4, 2);

   parameters.set(10);
   parameters[0] =  0.41;
   parameters[1] = -0.68; 
   parameters[2] =  0.14; 
   parameters[3] = -0.50; 
   parameters[4] =  0.52; 
   parameters[5] = -0.70; 
   parameters[6] =  0.85; 
   parameters[7] = -0.18; 
   parameters[8] = -0.65; 
   parameters[9] =  0.05; 

   l.set_parameters(parameters);

   inputs.set(4);
   inputs[0] =  0.85;
   inputs[1] = -0.25;
   inputs[2] =  0.29;
   inputs[3] = -0.77;

   Hessian_form = l.calculate_Hessian_form(inputs);

   assert_true((l.get_perceptron(0).calculate_Hessian(inputs) - Hessian_form[0]).calculate_absolute_value() < 1.0e-3, LOG);
   assert_true((l.get_perceptron(1).calculate_Hessian(inputs) - Hessian_form[1]).calculate_absolute_value() < 1.0e-3, LOG);

   if(numerical_differentiation_tests)
   {
      numerical_Hessian_form = nd.calculate_Hessian_form(l, &PerceptronLayer::calculate_outputs, inputs);

      assert_true((Hessian_form[0]-numerical_Hessian_form[0]).calculate_absolute_value() < 1.0e-3, LOG);
      assert_true((Hessian_form[1]-numerical_Hessian_form[1]).calculate_absolute_value() < 1.0e-3, LOG);
   }

}


// void test_calculate_parameters_Jacobian(void) method

void PerceptronLayerTest::test_calculate_parameters_Jacobian(void)
{
   message += "test_calculate_parameters_Jacobian\n";

   NumericalDifferentiation nd;

   PerceptronLayer l;

   Vector<double> parameters;

   Vector<double> inputs;

   Matrix<double> parameters_Jacobian;
   Matrix<double> numerical_parameters_Jacobian;

   // Test

   l.set(4, 2);

   parameters.set(10);
   parameters[0] =  0.41;
   parameters[1] = -0.68; 
   parameters[2] =  0.14; 
   parameters[3] = -0.50; 
   parameters[4] =  0.52; 
   parameters[5] = -0.70; 
   parameters[6] =  0.85; 
   parameters[7] = -0.18; 
   parameters[8] = -0.65; 
   parameters[9] =  0.05; 

   l.set_parameters(parameters);

   inputs.set(4);
   inputs[0] =  0.85;
   inputs[1] = -0.25;
   inputs[2] =  0.29;
   inputs[3] = -0.77;

   parameters_Jacobian = l.calculate_parameters_Jacobian(inputs, parameters);

   assert_true(parameters_Jacobian.get_rows_number() == 2, LOG);
   assert_true(parameters_Jacobian.get_columns_number() == 10, LOG);
   
   if(numerical_differentiation_tests)
   {
      numerical_parameters_Jacobian = nd.calculate_Jacobian(l, &PerceptronLayer::calculate_parameters_output, inputs, parameters);
      assert_true((parameters_Jacobian-numerical_parameters_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
   }

}


// void test_calculate_parameters_Hessian_form(void) method

void PerceptronLayerTest::test_calculate_parameters_Hessian_form(void)
{
   message += "test_calculate_parameters_Hessian_form\n";

   NumericalDifferentiation nd;

   PerceptronLayer l;

   Vector<double> parameters;

   Vector<double> inputs;

   Vector< Matrix<double> > parameters_Hessian_form;
   Vector< Matrix<double> > numerical_parameters_Hessian_form;

   // Test

   l.set(4, 2);

   parameters.set(10);
   parameters[0] =  0.41;
   parameters[1] = -0.68; 
   parameters[2] =  0.14; 
   parameters[3] = -0.50; 
   parameters[4] =  0.52; 
   parameters[5] = -0.70; 
   parameters[6] =  0.85; 
   parameters[7] = -0.18; 
   parameters[8] = -0.65; 
   parameters[9] =  0.05; 

   l.set_parameters(parameters);

   inputs.set(4);
   inputs[0] =  0.85;
   inputs[1] = -0.25;
   inputs[2] =  0.29;
   inputs[3] = -0.77;

   parameters_Hessian_form = l.calculate_parameters_Hessian_form(inputs, parameters);

   assert_true(parameters_Hessian_form.size() == 2, LOG);
   assert_true(parameters_Hessian_form[0].get_rows_number() == 10, LOG);
   assert_true(parameters_Hessian_form[0].get_columns_number() == 10, LOG);
   assert_true(parameters_Hessian_form[1].get_rows_number() == 10, LOG);
   assert_true(parameters_Hessian_form[1].get_columns_number() == 10, LOG);
   
   if(numerical_differentiation_tests)
   {
      numerical_parameters_Hessian_form = nd.calculate_Hessian_form(l, &PerceptronLayer::calculate_parameters_output, inputs, parameters);

      assert_true((parameters_Hessian_form[0]-numerical_parameters_Hessian_form[0]).calculate_absolute_value() < 1.0e-3, LOG);
      assert_true((parameters_Hessian_form[1]-numerical_parameters_Hessian_form[1]).calculate_absolute_value() < 1.0e-3, LOG);
   }

}



// void test_write_expression(void) method

void PerceptronLayerTest::test_write_expression(void)
{
   message += "test_write_expression\n";
}



// void run_test_case(void) method

void PerceptronLayerTest::run_test_case(void)
{
   message += "Running perceptron layer test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Assignment operators methods

   test_assignment_operator();

   // Get methods

   // PerceptronLayer arrangement

   test_count_inputs_number();
   test_count_perceptrons_number();

   // PerceptronLayer parameters

   test_count_parameters_number();
   test_count_cumulative_parameters_number();

   test_arrange_biases();
   test_arrange_synaptic_weights();
   test_arrange_parameters();

   // Activation functions

   test_get_activation_function();
   test_get_activation_function_name();

   test_get_activation_function();
   test_get_activation_function_name();

   // Display messages

   test_get_display();

   // Set methods

   test_set();
   test_set_default();

   // Perceptron layer parameters

   test_set_biases();
   test_set_biases();
   test_set_parameters();

   test_set_synaptic_weights();      
   test_set_synaptic_weights();
   test_set_parameters();

   // Activation functions

   test_set_activation_function();
   test_set_activation_function();

   // Parameters methods

   test_set_parameters();

   // Display messages

   test_set_display();

   // Initialization methods

   test_initialize_random();

   // Parameters initialization methods

   test_initialize_parameters();
   test_initialize_biases(); 
   test_initialize_synaptic_weights();
   test_initialize_parameters_uniform();
   test_initialize_parameters_normal();

   // Parameters initialization methods

   test_initialize_parameters();
   test_initialize_parameters_uniform();
   test_initialize_parameters_normal();

   // Parameters norm 

   test_calculate_parameters_norm();      

   // PerceptronLayer combination

   test_calculate_combination();

   test_calculate_combination_Jacobian();   
   test_calculate_combination_Hessian_form();

   // PerceptronLayer parameters combination

   test_calculate_combination_parameters_Jacobian();
   test_calculate_combination_parameters_Hessian_form();

   // PerceptronLayer activation 

   test_calculate_activation();
   test_calculate_activation_derivative();
   test_calculate_activation_second_derivative();

   // PerceptronLayer outputs 

   test_calculate_outputs();

   test_calculate_Jacobian();
   test_calculate_Hessian_form();

   // PerceptronLayer parameters outputs

   test_calculate_parameters_Jacobian();
   test_calculate_parameters_Hessian_form();

   // Expression methods

   test_write_expression();

   message += "End of perceptron layer test case\n";
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
