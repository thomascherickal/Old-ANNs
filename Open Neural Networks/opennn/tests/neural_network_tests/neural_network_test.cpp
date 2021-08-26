/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   N E U R A L   N E T W O R K   T E S T   C L A S S                                                          */
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

#include "../../source/utilities/numerical_differentiation.h"
#include "../../source/neural_network/neural_network.h"

// Unit testing includes

#include "neural_network_test.h"


using namespace OpenNN;


// GENERAL CONSTRUCTOR

NeuralNetworkTest::NeuralNetworkTest(void) : UnitTesting()
{
}


// DESTRUCTOR

NeuralNetworkTest::~NeuralNetworkTest(void)
{
}


// METHODS

// void test_constructor(void) method

void NeuralNetworkTest::test_constructor(void)
{
   message += "test_constructor\n";

   Vector<unsigned int> multilayer_perceptron_architecture; 

   // Default constructor

   NeuralNetwork nn1;

   assert_true(nn1.get_multilayer_perceptron_pointer() == NULL, LOG);
   assert_true(nn1.get_independent_parameters_pointer() == NULL, LOG);

   // Multilayer perceptron architecture constructor 

   multilayer_perceptron_architecture.set(3, 1);

   NeuralNetwork nn2(multilayer_perceptron_architecture);

   assert_true(nn2.get_multilayer_perceptron_pointer() != NULL, LOG);
   assert_true(nn2.get_independent_parameters_pointer() == NULL, LOG);

   // Independent parameters constructor

   NeuralNetwork nn4(1);

   assert_true(nn4.get_multilayer_perceptron_pointer() == NULL, LOG);
   assert_true(nn4.get_independent_parameters_pointer() != NULL, LOG);

   // One layer constructor 
   
   NeuralNetwork nn3(1, 2);

   assert_true(nn3.get_multilayer_perceptron_pointer() != NULL, LOG);
   assert_true(nn3.get_independent_parameters_pointer() == NULL, LOG);


   // Two layers constructor 

   NeuralNetwork nn5(1, 2, 3);

   assert_true(nn5.get_multilayer_perceptron_pointer() != NULL, LOG);
   assert_true(nn5.get_independent_parameters_pointer() == NULL, LOG);

   // File constructor

   nn1.save("../data/opennn_tests/neural_network.xml");
   NeuralNetwork nn6("../data/opennn_tests/neural_network.xml");

   // Copy constructor
}


// void test_destructor(void)

void NeuralNetworkTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_assignment_operator(void)

void NeuralNetworkTest::test_assignment_operator(void)
{
   message += "test_assignment_operator\n";

   NeuralNetwork nn1;
   NeuralNetwork nn2 = nn1;

   assert_true(nn2.get_multilayer_perceptron_pointer() == NULL, LOG);
   assert_true(nn2.get_independent_parameters_pointer() == NULL, LOG);
}


// void test_get_multilayer_perceptron_pointer(void) method

void NeuralNetworkTest::test_get_multilayer_perceptron_pointer(void)
{
   message += "test_get_multilayer_perceptron_pointer\n";

   NeuralNetwork nn;

   // Test

   nn.set();
   assert_true(nn.get_multilayer_perceptron_pointer() == NULL, LOG);
}


// void test_get_inputs_outputs_information_pointer(void) method

void NeuralNetworkTest::test_get_inputs_outputs_information_pointer(void)
{
   message += "test_get_inputs_outputs_information_pointer\n";

   NeuralNetwork nn;

   // Test

   nn.set();
   assert_true(nn.get_inputs_outputs_information_pointer() == NULL, LOG);
}


// void test_get_scaling_layer_pointer(void) method

void NeuralNetworkTest::test_get_scaling_layer_pointer(void)
{
   message += "test_get_scaling_layer_pointer\n";

   NeuralNetwork nn;

   // Test

   nn.set();
   assert_true(nn.get_scaling_layer_pointer() == NULL, LOG);
}


// void test_get_unscaling_layer_pointer(void) method

void NeuralNetworkTest::test_get_unscaling_layer_pointer(void)  
{
   message += "test_get_unscaling_layer_pointer\n";

   NeuralNetwork nn;

   // Test

   nn.set();
   assert_true(nn.get_unscaling_layer_pointer() == NULL, LOG);
}


// void test_get_bounding_layer_pointer(void) method

void NeuralNetworkTest::test_get_bounding_layer_pointer(void)
{
   message += "test_get_bounding_layer_pointer\n";

   NeuralNetwork nn;

   // Test

   nn.set();
   assert_true(nn.get_bounding_layer_pointer() == NULL, LOG);
}


// void test_get_probabilistic_layer_pointer(void) method

void NeuralNetworkTest::test_get_probabilistic_layer_pointer(void)
{
   message += "test_get_probabilistic_layer_pointer\n";

   NeuralNetwork nn;

   // Test

   nn.set();
   assert_true(nn.get_probabilistic_layer_pointer() == NULL, LOG);
}


// void test_get_conditions_layer_pointer(void) method

void NeuralNetworkTest::test_get_conditions_layer_pointer(void)
{
   message += "test_get_conditions_layer_pointer\n";

   NeuralNetwork nn;

   // Test

   nn.set();
   assert_true(nn.get_conditions_layer_pointer() == NULL, LOG);
}


// void test_get_independent_parameters_pointer(void) method

void NeuralNetworkTest::test_get_independent_parameters_pointer(void)
{
   message += "test_get_independent_parameters_pointer\n";

   NeuralNetwork nn;

   // Test

   nn.set();
   assert_true(nn.get_independent_parameters_pointer() == NULL, LOG);
}


// void test_get_multilayer_perceptron_flag(void) method

void NeuralNetworkTest::test_get_multilayer_perceptron_flag(void)
{
   message += "test_get_multilayer_perceptron_flag\n";
}


// void test_get_scaling_layer_flag(void) method

void NeuralNetworkTest::test_get_scaling_layer_flag(void)
{
   message += "test_get_scaling_layer_flag\n";
}


// void test_get_unscaling_layer_flag(void) method

void NeuralNetworkTest::test_get_unscaling_layer_flag(void)
{
   message += "test_get_unscaling_layer_flag\n";
}


// void test_get_bounding_layer_flag(void) method

void NeuralNetworkTest::test_get_bounding_layer_flag(void)
{
   message += "test_get_bounding_layer_flag\n";
}


// void test_get_probabilistic_layer_flag(void) method

void NeuralNetworkTest::test_get_probabilistic_layer_flag(void)
{
   message += "test_get_probabilistic_layer_flag\n";
}


// void test_get_conditions_layer_flag(void) method

void NeuralNetworkTest::test_get_conditions_layer_flag(void)
{
   message += "test_get_conditions_layer_flag\n";
}


// void test_get_display(void) method

void NeuralNetworkTest::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set(void) method

void NeuralNetworkTest::test_set(void)
{
   message += "test_set\n";

   NeuralNetwork nn;

   // Test
}


// void test_set_default(void) method

void NeuralNetworkTest::test_set_default(void)
{
   message += "test_set_default\n";
}


// void test_arrange_inputs_outputs_information(void) method

void NeuralNetworkTest::test_arrange_inputs_outputs_information(void)
{
   message += "test_arrange_inputs_outputs_information\n";

   NeuralNetwork nn(1, 1, 1);

   Vector< Vector<std::string> > inputs_outputs_information = nn.arrange_inputs_outputs_information();

   unsigned int size = inputs_outputs_information.size();

   assert_true(size == 6, LOG);
}


// void test_arrange_inputs_outputs_statistics(void) method

void NeuralNetworkTest::test_arrange_inputs_outputs_statistics(void)
{
   message += "test_arrange_inputs_outputs_statistics\n";

   NeuralNetwork nn;

   // Test

   nn.construct_multilayer_perceptron();

   Vector< Vector<double> > inputs_outputs_statistics = nn.arrange_inputs_outputs_statistics();

   assert_true(inputs_outputs_statistics.size() == 8, LOG);
}


// void test_set_variables_information(void) method

void NeuralNetworkTest::test_set_variables_information(void)
{
   message += "test_set_variables_information\n";
}


// void test_set_variables_statistics(void) method

void NeuralNetworkTest::test_set_variables_statistics(void)
{
   message += "test_set_variables_statistics\n";
}


// void test_set_inputs_scaling_flag(void) method

void NeuralNetworkTest::test_set_inputs_scaling_flag(void)
{
   message += "test_set_inputs_scaling_flag\n";
}


// void test_set_outputs_unscaling_flag(void) method

void NeuralNetworkTest::test_set_outputs_unscaling_flag(void)
{
   message += "test_set_outputs_unscaling_flag\n";
}


// void test_set_variables_scaling_flag(void) method

void NeuralNetworkTest::test_set_variables_scaling_flag(void)
{
   message += "test_set_variables_scaling_flag\n";
}


// void test_set_conditions_layer_flag(void) method

void NeuralNetworkTest::test_set_conditions_layer_flag(void)
{
   message += "test_set_conditions_layer_flag\n";
}


// void test_set_outputs_bounds_flag(void) method

void NeuralNetworkTest::test_set_outputs_bounds_flag(void)
{
   message += "test_set_outputs_bounds_flag\n";
}


// void test_set_probabilistic_flag(void) method

void NeuralNetworkTest::test_set_probabilistic_flag(void)
{
   message += "test_set_probabilistic_flag\n";
}


// void test_set_independent_parameters(void) method

void NeuralNetworkTest::test_set_independent_parameters(void)
{
   message += "test_set_independent_parameters\n";
}


// void test_set_display_inputs_warning(void) method

void NeuralNetworkTest::test_set_display_inputs_warning(void)
{
   message += "test_set_display_inputs_warning\n";
}


// void test_set_display(void) method

void NeuralNetworkTest::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_count_parameters_number(void) method

void NeuralNetworkTest::test_count_parameters_number(void)
{
   message += "test_count_parameters_number\n";

   NeuralNetwork nn;

   IndependentParameters* ip;

   // Test

   nn.set();
   assert_true(nn.count_parameters_number() == 0, LOG);

   // Test

   nn.set(1, 1, 1);
   assert_true(nn.count_parameters_number() == 4, LOG);

   // Test

   nn.set(1);
   assert_true(nn.count_parameters_number() == 1, LOG);

   // Test

   nn.set(1, 1, 1);

   ip = new IndependentParameters(1);
   nn.set_independent_parameters_pointer(ip);
   
   assert_true(nn.count_parameters_number() == 5, LOG);
}


// void test_arrange_parameters(void) method  

void NeuralNetworkTest::test_arrange_parameters(void)   
{
   message += "test_arrange_parameters\n";

   NeuralNetwork nn;
   Vector<double> parameters;

   IndependentParameters* ip;

   // Test

   nn.set();
   parameters = nn.arrange_parameters();

   assert_true(parameters.size() == 0, LOG);

   // Test

   nn.set(1, 1, 1);

   ip = new IndependentParameters(1);
   nn.set_independent_parameters_pointer(ip);
   nn.initialize_parameters(0.0);
   parameters = nn.arrange_parameters();

   assert_true(parameters.size() == 5, LOG);
   assert_true(parameters == 0.0, LOG);

   // Test

   nn.set();
   ip = new IndependentParameters(1);
   nn.set_independent_parameters_pointer(ip);
   nn.initialize_parameters(0.0);
   parameters = nn.arrange_parameters();
   assert_true(parameters.size() == 1, LOG);
   assert_true(parameters == 0.0, LOG);

   // Test

   nn.set(1,1,1);
   ip = new IndependentParameters(1);
   nn.set_independent_parameters_pointer(ip);
   nn.initialize_parameters(0.0);
   parameters = nn.arrange_parameters();
   assert_true(parameters.size() == 5, LOG);
   assert_true(parameters == 0.0, LOG);
}


// void test_set_parameters(void) method

void NeuralNetworkTest::test_set_parameters(void)
{
   message += "test_set_parameters\n";

   Vector<unsigned int> multilayer_perceptron_architecture;
   NeuralNetwork nn;

   unsigned int parameters_number;
   Vector<double> parameters;

   // Test

   nn.set_parameters(parameters);   

   parameters = nn.arrange_parameters();
   assert_true(parameters.size() == 0, LOG);

   // Test

   multilayer_perceptron_architecture.set(2, 2);
   nn.set(multilayer_perceptron_architecture);

   nn.construct_independent_parameters();

   nn.get_independent_parameters_pointer()->set_parameters_number(2);

   parameters_number = nn.count_parameters_number();

   parameters.set(0.0, 1.0, parameters_number-1);
   nn.set_parameters(parameters);   
   parameters = nn.arrange_parameters();

   assert_true(parameters.size() == parameters_number, LOG);
   assert_true(parameters[0] == 0.0, LOG);
   assert_true(parameters[parameters_number-1] == parameters_number-1.0, LOG); 
}


// void test_set_scaling_flag(void) method

void NeuralNetworkTest::test_set_scaling_flag(void)
{
   message += "test_set_scaling_flag\n";
}


// void test_initialize_random(void) method
// @todo
void NeuralNetworkTest::test_initialize_random(void)
{
   message += "test_initialize_random\n";

   NeuralNetwork nn;

//   unsigned int inputs_number;
//   unsigned int layers_number;
//   Vector<unsigned int> multilayer_perceptron_architecture;

//   unsigned int independent_parameters_number;

   // Test

   nn.set();

   nn.initialize_random();

//   assert_true(nn.get_multilayer_perceptron_pointer() != NULL, LOG); 
//   assert_true(nn.get_scaling_layer_pointer() != NULL, LOG); 

//   inputs_number = nn.count_inputs_number();

//   assert_true(inputs_number >= 1 && inputs_number <= 10, LOG); 

//   layers_number = nn.count_layers_number();

//   assert_true(layers_number >= 1 && layers_number <= 10, LOG); 

//   multilayer_perceptron_architecture = nn.get_layers_size();

//   assert_true(multilayer_perceptron_architecture >= 1 && multilayer_perceptron_architecture <= 10, LOG); 

//   independent_parameters_number = nn.get_independent_parameters_number();

//   assert_true(independent_parameters_number >= 1 && independent_parameters_number <= 10, LOG); 
}


// void test_initialize_parameters(void) method
// @todo

void NeuralNetworkTest::test_initialize_parameters(void)
{
//   message += "test_initialize_parameters\n";

//   NeuralNetwork nn;
//   Vector<double> parameters;

//   IndependentParameters* ipp;

   // Test

//   nn.set(1, 1, 1);

//   ipp = new IndependentParameters(1);

//   nn.initialize_parameters_normal(1.0, 0.0);
//   parameters = nn.arrange_parameters();
//   assert_true(parameters == 1.0, LOG);
}


// void test_initialize_parameters_uniform(void) method

void NeuralNetworkTest::test_initialize_parameters_uniform(void)
{
   message += "test_initialize_parameters_uniform\n";

   NeuralNetwork nn;
   Vector<double> parameters;

   // Test

   nn.set(1,1,1);
   nn.initialize_parameters_uniform();
   parameters = nn.arrange_parameters();
   assert_true(parameters >= -1.0, LOG);
   assert_true(parameters <=  1.0, LOG);   
}


// void test_initialize_parameters_normal(void) method

void NeuralNetworkTest::test_initialize_parameters_normal(void)
{
   message += "test_initialize_parameters_normal\n";

   NeuralNetwork nn;
   Vector<double> network_parameters;

   // Test

   nn.set(1,1,1);      
   nn.initialize_parameters_normal(1.0, 0.0);
   network_parameters = nn.arrange_parameters();
   assert_true(network_parameters == 1.0, LOG);
}


// void test_calculate_parameters_norm(void) method

void NeuralNetworkTest::test_calculate_parameters_norm(void)
{
   message += "test_calculate_parameters_norm\n";

   NeuralNetwork nn;
   double parameters_norm;

   // Test 

   nn.set();

   parameters_norm = nn.calculate_parameters_norm();

   assert_true(parameters_norm == 0.0, LOG);
}


// void test_calculate_outputs(void) method

void NeuralNetworkTest::test_calculate_outputs(void)
{
   message += "test_calculate_outputs\n";

   NeuralNetwork nn;
   Vector<double> inputs;
   Vector<double> outputs;

   // Test

   nn.set(3, 4, 2);
   nn.initialize_parameters(0.0);

   inputs.set(3, 0.0);

   outputs = nn.calculate_outputs(inputs);

   assert_true(outputs == 0.0, LOG);

   // Test

   nn.set(1,1,1);
   nn.initialize_parameters(0.0);

   inputs.set(1, 0.0);

   outputs = nn.calculate_outputs(inputs);

   assert_true(outputs == 0.0, LOG);
}


// void test_calculate_output_data(void) method

void NeuralNetworkTest::test_calculate_output_data(void)
{
   message += "test_calculate_output_data\n";

   NeuralNetwork nn;

   Matrix<double> input_data;
   Matrix<double> output_data;
   
   // Test

   nn.set(1,1,1);
   nn.initialize_parameters(0.0);

   input_data.set(2, 1, 0.0);
   output_data = nn.calculate_output_data(input_data);

   assert_true(output_data.get_rows_number() == 2, LOG);
}


// void test_calculate_Jacobian(void) method
// @todo
void NeuralNetworkTest::test_calculate_Jacobian(void)
{
   message += "test_calculate_Jacobian\n";

   // One layer

   NeuralNetwork nn;

   Vector<unsigned int> multilayer_perceptron_architecture;   

   Vector<double> inputs;
   Matrix<double> Jacobian;

//   Vector<double> inputs_minimum;
//   Vector<double> inputs_maximum;

//   Vector<double> inputs_mean;
//   Vector<double> inputs_standard_deviation;

//   Vector<double> outputs_minimum;
//   Vector<double> outputs_maximum;

//   Vector<double> outputs_mean;
//   Vector<double> outputs_standard_deviation;

//   mmlp.set_display(false);


   NumericalDifferentiation nd;
   Matrix<double> numerical_Jacobian;

   // Test

   nn.set(1, 1, 1);
   nn.initialize_parameters(0.0);
   inputs.set(1, 0.0);
   Jacobian = nn.calculate_Jacobian(inputs);
   assert_true(Jacobian == 0.0, LOG);    

   // Test

   nn.set(3, 4, 2);
   nn.initialize_parameters(0.0);
   inputs.set(3, 0.0);
   Jacobian = nn.calculate_Jacobian(inputs);
   assert_true(Jacobian == 0.0, LOG);    

   // Test

   if(numerical_differentiation_tests)
   {
      nn.set(3, 4, 2);
      nn.initialize_parameters(0.0);
      inputs.set(3, 0.0);
      Jacobian = nn.calculate_Jacobian(inputs);
      numerical_Jacobian = nd.calculate_Jacobian(nn, &NeuralNetwork::calculate_outputs, inputs);
      assert_true((Jacobian-numerical_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
   }

   // Test

   multilayer_perceptron_architecture.set(3, 1);   
   nn.set(multilayer_perceptron_architecture);
   nn.initialize_parameters(0.0);
   inputs.set(1, 0.0);
   Jacobian = nn.calculate_Jacobian(inputs);
   assert_true(Jacobian == 0.0, LOG);    

   // Test

   multilayer_perceptron_architecture.set(3);   
   multilayer_perceptron_architecture[0] = 3;
   multilayer_perceptron_architecture[1] = 4;
   multilayer_perceptron_architecture[2] = 1;

   nn.set(multilayer_perceptron_architecture);

   nn.initialize_parameters(0.0);
   inputs.set(3, 0.0);
   Jacobian = nn.calculate_Jacobian(inputs);
   assert_true(Jacobian == 0.0, LOG);    

   // Test

   if(numerical_differentiation_tests)
   {
      multilayer_perceptron_architecture.set(3);   
      multilayer_perceptron_architecture[0] = 3;
      multilayer_perceptron_architecture[1] = 4;
      multilayer_perceptron_architecture[2] = 1;

      nn.set(multilayer_perceptron_architecture);

      inputs.set(3);
      inputs[0] = 0.0;
      inputs[1] = 1.0;
      inputs[2] = 2.0;

      Jacobian = nn.calculate_Jacobian(inputs);
      numerical_Jacobian = nd.calculate_Jacobian(nn, &NeuralNetwork::calculate_outputs, inputs);
      assert_true((Jacobian-numerical_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
   }

   // Scaling and unscaling test

//   if(numerical_differentiation_tests)
//   {
//      nn.set(2, 3);

//      nn.set_variables_scaling_flag(true);

//      nn.set_variables_scaling_method(NeuralNetwork::MinimumMaximum);

//      nn.set_input_minimum(0, -0.3);
//      nn.set_input_minimum(1, -0.2);
     
//      nn.set_input_maximum(0, 0.0);
//      nn.set_input_maximum(1, 0.1);

//      nn.set_output_minimum(0, -1.0);
//      nn.set_output_minimum(1, -4.1);
//      nn.set_output_minimum(2, -8.2);
     
//      nn.set_output_maximum(0, 1.0);
//      nn.set_output_maximum(1, 7.2);
//      nn.set_output_maximum(2, 6.0);

//      inputs.set(2);
//      inputs.initialize_normal();

//      Jacobian = nn.calculate_Jacobian(inputs);
//      numerical_Jacobian = nd.calculate_Jacobian(nn, &NeuralNetwork::calculate_outputs, inputs);

//      assert_true((Jacobian-numerical_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
//   }

   // Scaling and unscaling test

//   if(numerical_differentiation_tests)
//   {
//      nn.set(2, 3);

//      nn.set_variables_scaling_flag(true);

//      nn.set_variables_scaling_method(NeuralNetwork::MeanStandardDeviation);

//      nn.set_input_mean(0, -0.3);
//      nn.set_input_mean(1, -0.2);
     
//      nn.set_input_standard_deviation(0, 0.2);
//      nn.set_input_standard_deviation(1, 0.1);

//      nn.set_output_mean(0, -1.0);
//      nn.set_output_mean(1, -4.1);
//      nn.set_output_mean(2, -8.2);
     
//      nn.set_output_standard_deviation(0, 1.0);
//      nn.set_output_standard_deviation(1, 7.2);
//      nn.set_output_standard_deviation(2, 6.0);

//      inputs.set(2);
//      inputs.initialize_normal();

//      Jacobian = nn.calculate_Jacobian(inputs);
//      numerical_Jacobian = nd.calculate_Jacobian(nn, &NeuralNetwork::calculate_outputs, inputs);

//      assert_true((Jacobian-numerical_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
//   }

   // Conditions test

//   mmlp.set(1, 1, 1);

//   mmlp.initialize_parameters(0.0);
//   inputs.set(1, 0.0);
//   Jacobian = mmlp.calculate_Jacobian(inputs);

//   assert_true(Jacobian == 0.0, LOG);    

   // Conditions test

   // Lower and upper bounds test

   // Probabilistic postprocessing test
}


// void test_calculate_Jacobian_data(void) method

void NeuralNetworkTest::test_calculate_Jacobian_data(void)
{
   message += "test_calculate_Jacobian_data\n";
}


// void test_calculate_parameters_Jacobian(void) method
// @todo

void NeuralNetworkTest::test_calculate_parameters_Jacobian(void)
{
   message += "test_calculate_parameters_Jacobian\n";

   NumericalDifferentiation nd;

   NeuralNetwork nn;

   Vector<unsigned int> multilayer_perceptron_architecture;
//   unsigned int outputs_number;

//   unsigned int parameters_number;
  
   Vector<double> inputs;

   Vector<double> parameters;
   Matrix<double> parameters_Jacobian;
   Matrix<double> numerical_parameters_Jacobian;

   // Test

   nn.set(1, 1); 

//   outputs_number = nn.count_outputs_number();

//   parameters_number = nn.count_parameters_number();

   nn.initialize_parameters(0.0);

   inputs.set(1, 0.0);

//   parameters_Jacobian = nn.calculate_parameters_Jacobian(inputs);

//   assert_true(parameters_Jacobian.get_rows_number() == outputs_number, LOG);
//   assert_true(parameters_Jacobian.get_columns_number() == parameters_number, LOG);

   if(numerical_differentiation_tests)
   {
//      parameters = nn.arrange_parameters();

//      numerical_parameters_Jacobian = nd.calculate_Jacobian(nn, &NeuralNetwork::calculate_parameters_output, inputs, parameters);

//      assert_true((parameters_Jacobian-numerical_parameters_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
   }

   // Test

   if(numerical_differentiation_tests)
   {
//      nn.set(2, 1); 

//      nn.initialize_parameters(0.0);

//      inputs.set(2, 0.0);

//      parameters_Jacobian = nn.calculate_parameters_Jacobian(inputs);

//      parameters = nn.arrange_parameters();
//      numerical_parameters_Jacobian = nd.calculate_Jacobian(nn, &NeuralNetwork::calculate_parameters_output, inputs, parameters);

 //     assert_true((parameters_Jacobian-numerical_parameters_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
   }

   // Test

   if(numerical_differentiation_tests)
   {
//      nn.set(1, 2); 

//      nn.initialize_parameters(0.0);

//      inputs.set(1, 0.0);

//      parameters_Jacobian = nn.calculate_parameters_Jacobian(inputs);

//      parameters = nn.arrange_parameters();
//      numerical_parameters_Jacobian = nd.calculate_Jacobian(nn, &NeuralNetwork::calculate_parameters_output, inputs, parameters);

//      assert_true((parameters_Jacobian-numerical_parameters_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
   }

   // Test

   if(numerical_differentiation_tests)
   {
//      nn.set(2, 3); 

//      nn.initialize_parameters(0.0);

//      inputs.set(2, 0.0);

//      parameters_Jacobian = nn.calculate_parameters_Jacobian(inputs);

//      parameters = nn.arrange_parameters();
//      numerical_parameters_Jacobian = nd.calculate_Jacobian(nn, &NeuralNetwork::calculate_parameters_output, inputs, parameters);

//      assert_true((parameters_Jacobian-numerical_parameters_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
   }

   // Test

//   nn.set(3, 4, 2); 

//   outputs_number = nn.count_outputs_number();
//   parameters_number = nn.count_parameters_number();

//   inputs.set(3, 3.1415927);
   
//   parameters_Jacobian = nn.calculate_parameters_Jacobian(inputs);

//   assert_true(parameters_Jacobian.get_rows_number() == outputs_number, LOG);
//   assert_true(parameters_Jacobian.get_columns_number() == parameters_number, LOG);

   if(numerical_differentiation_tests)
   {
//      parameters = nn.arrange_parameters();
//      numerical_parameters_Jacobian = nd.calculate_Jacobian(nn, &NeuralNetwork::calculate_parameters_output, inputs, parameters);

//      assert_true((parameters_Jacobian-numerical_parameters_Jacobian).calculate_absolute_value() < 1.0e-3, LOG);
   }

   // Test

//   multilayer_perceptron_architecture.set(12, -3, 2);

//   nn.set(7, multilayer_perceptron_architecture);

//   outputs_number = nn.count_outputs_number();
//   parameters_number = nn.count_parameters_number();

//   inputs.set(7, 3.1415927);
   
//   parameters_Jacobian = nn.calculate_parameters_Jacobian(inputs);

//   assert_true(parameters_Jacobian.get_rows_number() == outputs_number, LOG);
//   assert_true(parameters_Jacobian.get_columns_number() == parameters_number, LOG);

   if(numerical_differentiation_tests)
   {
//    parameters = nn.arrange_parameters();
//      numerical_parameters_Jacobian = nd.calculate_Jacobian(nn, &NeuralNetwork::calculate_parameters_output, inputs, parameters);

//     assert_true((parameters_Jacobian-numerical_parameters_Jacobian).calculate_absolute_value() < 1.0e-5, LOG);
   }

}


// void test_calculate_parameters_Jacobian_data(void) method
// @todo
void NeuralNetworkTest::test_calculate_parameters_Jacobian_data(void)
{
   message += "test_calculate_parameters_Jacobian_data\n";
}


// void test_to_XML(void) method

void NeuralNetworkTest::test_to_XML(void)
{
   message += "test_to_XML\n";

   NeuralNetwork  nn;

   TiXmlElement* nnep;
   
   // Test
   
   nnep = nn.to_XML();

   assert_true(nnep != NULL, LOG);

   // Test

   nn.initialize_random();

   nnep = nn.to_XML();

   assert_true(nnep != NULL, LOG);
}


// void test_from_XML(void) method

void NeuralNetworkTest::test_from_XML(void)
{
   message += "test_from_XML\n";

   NeuralNetwork  nn;

   TiXmlElement* nnep;
   
   // Test
   
   nn.from_XML(NULL);

   // Test

   nn.initialize_random();

   nnep = nn.to_XML();

   nn.from_XML(nnep);
}


// void print(void) method
// @todo

void NeuralNetworkTest::test_print(void)
{
   message += "test_print\n";

   // Empty neural network
 
   NeuralNetwork mlp1;
   //mlp1.print();

   // Only network architecture

   NeuralNetwork mlp2(2, 4, 3);
   //mlp2.print();

   // Only independent parameters

   NeuralNetwork mlp3(2);
   //mlp3.print();

   // Both network architecture and independent parameters

   NeuralNetwork mlp4(1, 1, 1);
//   mlp4.set_independent_parameters(1);
   //mlp4.print();

   //mlp5.print();

   // Units

   // Description
}


// void test_save(void) method
// @todo

void NeuralNetworkTest::test_save(void)
{
   message += "test_save\n";

   NeuralNetwork nn;

   // Empty multilayer perceptron
 
   nn.set();
   nn.save("../data/opennn_tests/neural_network.xml");

   // Only network architecture

   nn.set(2, 4, 3);
   nn.save("../data/opennn_tests/neural_network.xml");

   // Only independent parameters

   nn.set(2);
   nn.save("../data/opennn_tests/neural_network.xml");

   // Both network architecture and independent parameters

   nn.set(1, 1, 1);
//   nn.set_independent_parameters(1);
//   nn.save("../data/opennn_tests/neural_network.xml");

   // Name

   nn.set(1,1,1);
//   nn.set_independent_parameters(1);

//   nn.set_input_name(0, "InputName");
//   nn.set_output_name(0, "OutputName");
//   nn.set_independent_parameter_name(0, "IndependentParameterName");

//   nn.set_input_units(0, "InputUnits");
//   nn.set_output_units(0, "OutputUnits");
//   nn.set_independent_parameter_units(0, "IndependentParameterUnits");

//   nn.set_input_description(0, "InputDescription");
//   nn.set_output_description(0, "OutputDescription");
//   nn.set_independent_parameter_description(0, "IndependentParameterDescription");

//   nn.save("../data/opennn_tests/neural_network.xml");

   // Units

   // Description
}


// void test_load(void) method
// @todo

void NeuralNetworkTest::test_load(void)
{
   message += "test_load\n";

   // Empty multilayer perceptron

   NeuralNetwork mlp1;
   mlp1.save("../data/opennn_tests/neural_network.xml");
//   mlp1.load("../data/opennn_tests/neural_network.xml");

//   assert_true(mlp1.count_inputs_number() == 0, LOG);
//   assert_true(mlp1.count_layers_number() == 0, LOG);
//   assert_true(mlp1.count_outputs_number() == 0, LOG);
//   assert_true(mlp1.get_independent_parameters_number() == 0, LOG);

   // Only network architecture

//   NeuralNetwork mlp2(2, 4, 3);

//   mlp2.set_input_name(0, "Input 1");
//   mlp2.set_output_name(2, "Output 3");

//   mlp2.set_input_units(1, "[m]");
//   mlp2.set_output_units(0, "[s-1]");

//   mlp2.set_input_description(0, "Description of input variable 1");
//   mlp2.set_output_description(1, "Description of output variable 2");

//   mlp2.set_input_mean(0, 2.0);
//   mlp2.set_input_standard_deviation(1, 0.5);

//   mlp2.set_input_minimum(0, -2.0);
//   mlp2.set_input_maximum(1, -0.5);

//   mlp2.set_output_mean(2, 20.0);
//   mlp2.set_output_standard_deviation(0, 0.05);

//   mlp2.set_output_minimum(0, -20.0);
//   mlp2.set_output_maximum(2, -0.05);

//   mlp2.save("../data/opennn_tests/neural_network.xml");
//   mlp2.load("../data/opennn_tests/neural_network.xml");

//   assert_true(mlp2.count_inputs_number() == 2, LOG);
//   assert_true(mlp2.count_layers_number() == 2, LOG);
//   assert_true(mlp2.get_layer_size(0) == 4, LOG);
//   assert_true(mlp2.count_outputs_number() == 3, LOG);
//   assert_true(mlp2.get_independent_parameters_number() == 0, LOG);

//   assert_true(mlp2.get_input_name(0) == "Input 1", LOG);
//   assert_true(mlp2.get_output_name(2) == "Output 3", LOG);
  
//   assert_true(mlp2.get_input_units(1) == "[m]", LOG);
//   assert_true(mlp2.get_output_units(0) == "[s-1]", LOG);

//   assert_true(mlp2.get_input_description(0) == "Description of input variable 1", LOG);
//   assert_true(mlp2.get_output_description(1) == "Description of output variable 2", LOG);

//   assert_true(mlp2.get_input_mean(0) == 2.0, LOG);
//   assert_true(mlp2.get_input_standard_deviation(1) == 0.5, LOG);
//   assert_true(mlp2.get_input_minimum(0) == -2.0, LOG);
//   assert_true(mlp2.get_input_maximum(1) == -0.5, LOG);

//   assert_true(mlp2.get_output_mean(2) == 20.0, LOG);
//   assert_true(mlp2.get_output_standard_deviation(0) == 0.05, LOG);
//   assert_true(mlp2.get_output_minimum(0) == -20.0, LOG);
//   assert_true(mlp2.get_output_maximum(2) == -0.05, LOG);

   // Only independent parameters

//   NeuralNetwork mlp3(3);

//   mlp3.set_independent_parameter_name(0, "Independent parameter 1");
//   mlp3.set_independent_parameter_units(1, "[kg]");
//   mlp3.set_independent_parameter_description(2, "Description of independent parameter 3");

//   mlp3.set_independent_parameter_mean(0, 2.0);
//   mlp3.set_independent_parameter_standard_deviation(1, 0.5);
//   mlp3.set_independent_parameter_minimum(0, -2.0);
//   mlp3.set_independent_parameter_maximum(1, -0.5);

//   mlp3.save("../data/opennn_tests/neural_network.xml");
//   mlp3.load("../data/opennn_tests/neural_network.xml");
   
//   assert_true(mlp3.count_inputs_number() == 0, LOG);
//   assert_true(mlp3.count_layers_number() == 0, LOG);
//   assert_true(mlp3.count_outputs_number() == 0, LOG);
//   assert_true(mlp3.get_independent_parameters_number() == 3, LOG);

//   assert_true(mlp3.get_independent_parameter_name(0) == "Independent parameter 1", LOG);
//   assert_true(mlp3.get_independent_parameter_units(1) == "[kg]", LOG);
//   assert_true(mlp3.get_independent_parameter_description(2) == "Description of independent parameter 3", LOG);

//   assert_true(mlp3.get_independent_parameter_mean(0) == 2.0, LOG);
//   assert_true(mlp3.get_independent_parameter_standard_deviation(1) == 0.5, LOG);
//   assert_true(mlp3.get_independent_parameter_minimum(0) == -2.0, LOG);
//   assert_true(mlp3.get_independent_parameter_maximum(1) == -0.5, LOG);
}


// void test_write_expression(void) method  
// @todo

void NeuralNetworkTest::test_write_expression(void)
{
   message += "test_write_expression\n";

   NeuralNetwork nn;
   std::string expression;

   // Test

//   expression = nn.write_expression();

   // Test

   nn.set(1, 1, 1);
   nn.initialize_parameters(-1.0);
//   expression = nn.write_expression();

   // Test

   nn.set(2, 1, 1);
   nn.initialize_parameters(-1.0);
//   expression = nn.write_expression();

   // Test

   nn.set(1, 2, 1);
   nn.initialize_parameters(-1.0);
//   expression = nn.write_expression();

   // Test

   nn.set(1, 1, 2);
   nn.initialize_parameters(-1.0);
//   expression = nn.write_expression();

   // Test

   nn.set(2, 2, 2);
   nn.initialize_parameters(-1.0);
//   expression = nn.write_expression();

   // Test

//   Vector<unsigned int> multilayer_perceptron_architecture(3, 2);
//   nn.set(2, multilayer_perceptron_architecture);
//   nn.initialize_parameters(-1.0);
//   expression = nn.write_expression();

}


// void test_get_Hinton_diagram_XML(void) method

void NeuralNetworkTest::test_get_Hinton_diagram_XML(void)
{
   message += "test_get_Hinton_diagram_XML\n";
}


// void test_save_Hinton_diagram_XML(void) method

void NeuralNetworkTest::test_save_Hinton_diagram_XML(void)
{
   message += "test_save_Hinton_diagram_XML\n";
}


// void run_test_case(void) method

void NeuralNetworkTest::run_test_case(void)
{
   message += "Running neural network test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Assignment operators methods

   test_assignment_operator();

   // Get methods

   test_get_multilayer_perceptron_pointer();
   test_get_inputs_outputs_information_pointer();
   test_get_scaling_layer_pointer();
   test_get_unscaling_layer_pointer();   
   test_get_bounding_layer_pointer();
   test_get_probabilistic_layer_pointer();
   test_get_conditions_layer_pointer();
   test_get_independent_parameters_pointer();

   test_get_multilayer_perceptron_flag();
   test_get_scaling_layer_flag();
   test_get_unscaling_layer_flag();
   test_get_bounding_layer_flag();
   test_get_probabilistic_layer_flag();

   // Variables information

   test_arrange_inputs_outputs_information();

   // Variables statistics

   test_arrange_inputs_outputs_statistics();

   // Variables scaling and unscaling

 
   // Parameters methods

   test_count_parameters_number();
   test_arrange_parameters();   

   // Display messages

   test_get_display();

   // Set methods

   test_set();
   test_set_default();

   // Variables information

   test_set_variables_information();

   // Variables statistics

   test_set_variables_statistics();

   // Variables scaling and unscaling

   test_set_inputs_scaling_flag();
   test_set_outputs_unscaling_flag();
   test_set_variables_scaling_flag();

   // Conditions

   test_set_conditions_layer_flag();

   // Variables bounds

   test_get_bounding_layer_flag();

   // Probabilistic postprocessing

   test_set_probabilistic_flag();

   // Independent parameters

   test_set_independent_parameters();

   // Parameters methods

   test_set_parameters();

   // Scaling and unscaling methods

   test_set_scaling_flag();

   // Display messages

   test_set_display();

   // Neural network initialization methods

   test_initialize_random();

   // Parameters initialization methods

   test_initialize_parameters();
   test_initialize_parameters_uniform();
   test_initialize_parameters_normal();

   // Parameters norm 

   test_calculate_parameters_norm();

   // Output 

   test_calculate_outputs();
   test_calculate_output_data();

   test_calculate_Jacobian();
   test_calculate_Jacobian_data();

   test_calculate_parameters_Jacobian();
   test_calculate_parameters_Jacobian_data();

   // Expression methods

   test_write_expression();

   // Hinton diagram methods

   test_get_Hinton_diagram_XML();

   test_save_Hinton_diagram_XML();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   test_print();
   test_save();

   test_load();

   message += "End of neural network test case\n";
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
