/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.cimne.com/flood                                                                                        */
/*                                                                                                              */
/*   M O D E L   S E L E C T I O N   T E S T   C L A S S                                                        */
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
#include "../../source/training_strategy/gradient_descent.h"
#include "../../source/model_selection/model_selection.h"

// Unit testing includes

#include "model_selection_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

ModelSelectionTest::ModelSelectionTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

ModelSelectionTest::~ModelSelectionTest(void) 
{
}


// METHODS

// void test_constructor(void) method

void ModelSelectionTest::test_constructor(void)
{
   message += "test_constructor\n";
}


// void test_destructor(void) method

void ModelSelectionTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_get_training_strategy_pointer(void) method

void ModelSelectionTest::test_get_training_strategy_pointer(void)
{
   message += "test_get_training_algorithm_pointer\n";
}


// void test_get_hidden_layer_sizes(void) method
// @todo

void ModelSelectionTest::test_get_hidden_layer_sizes(void)
{
   message += "test_get_hidden_layer_sizes\n";

//   ModelSelection ms;

//   Vector<unsigned int> ghidden_perceptrons_numbers;

   // Test

//   hidden_perceptrons_numbers = ms.get_hidden_perceptrons_numbers();

//   assert_true(ghidden_perceptrons_numbers.size() == 0, LOG);

}


// void test_get_sample_size(void) method
// @todo

void ModelSelectionTest::test_get_sample_size(void)
{
   message += "test_get_sample_size\n";

//   ModelSelection ms;

//   unsigned int sample_size;

   // Test

//   sample_size = mos.get_sample_size();

//   assert_true(sample_size == 0, LOG);

}


// void test_get_display(void) method

void ModelSelectionTest::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set_training_strategy_pointer(void) method

void ModelSelectionTest::test_set_training_strategy_pointer(void)
{
   message += "test_set_training_strategy_pointer\n";
}


// void test_set_default(void) method

void ModelSelectionTest::test_set_default(void)
{
   message += "test_set_default\n";
}


// void test_set_hidden_layer_sizes(void) method

void ModelSelectionTest::test_set_hidden_layer_sizes(void)
{
   message += "test_set_hidden_layer_sizes\n";
}


// void test_set_sample_size(void) method

void ModelSelectionTest::test_set_sample_size(void)
{
   message += "test_set_sample_size\n";  
}


// void test_set_assays_numbers(void) method

void ModelSelectionTest::test_set_assays_numbers(void)
{
   message += "test_set_assays_numbers\n";
}


// void test_set_display(void) method

void ModelSelectionTest::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_perform_model_order_selection(void) method
// @todo

void ModelSelectionTest::test_perform_model_order_selection(void)
{
   message += "test_perform_model_order_selection\n";

   NeuralNetwork nn;

   DataSet ds;

   PerformanceFunctional pf(&nn, &ds);

   TrainingStrategy ts(&pf);

   ModelSelection ms(&ts);

//   Vector<int> hidden_layer_sizes;
//   int sample_size;

//   ModelSelection::ModelSelectionResults model_selection_results;

	// Test 

//   mlp.set(1, 1);

//   itds.set(10, 1, 1);
//   itds.initialize_data_normal();
//   itds.split_random_indices();

//   gd.set_maximum_epochs_number(1);
//   gd.set_display(false);

//   hidden_layer_sizes.set(1, 1);
//   mos.set_hidden_layer_sizes(hidden_layer_sizes);

//   sample_size = 1;
//   mos.set_sample_size(sample_size);

//   mos.set_display(false);

//   model_order_selection_data = mos.perform_model_order_selection();

//   assert_true(model_order_selection_data.parameters_data.get_rows_number() == 1, LOG);
//   assert_true(model_order_selection_data.parameters_data.get_columns_number() == 1, LOG);

//   assert_true(model_order_selection_data.training_objective_data.get_rows_number() == 1, LOG);
//   assert_true(model_order_selection_data.training_objective_data.get_columns_number() == 1, LOG);

//   assert_true(model_order_selection_data.validation_objective_data.get_rows_number() == 1, LOG);
//   assert_true(model_order_selection_data.validation_objective_data.get_columns_number() == 1, LOG);

}


// void test_to_XML(void) method
// @todo

void ModelSelectionTest::test_to_XML(void)   
{
	message += "test_to_XML\n";
   
//   ModelSelection ms;

//   TiXmlElement* mse = ms.to_XML();

//   assert_true(mse != NULL, LOG);
}


// void test_print(void) method

void ModelSelectionTest::test_print(void)
{
	message += "test_print\n";
}


// void test_save(void) method

void ModelSelectionTest::test_save(void)
{
	message += "test_save\n";
}


// void test_load(void) method
// @todo

void ModelSelectionTest::test_load(void)
{
   ModelSelection ms;

//   ms.set_display(false);

//   ms.save("../data/opennn_tests/model_selection.xml");

//   ms.load("../data/opennn_tests/model_selection.xml");

//   assert_true(ms.get_display() == false, LOG);
}


// void run_test_case(void) method

void ModelSelectionTest::run_test_case(void)
{
   message += "Running model selection test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_training_strategy_pointer();

   test_get_hidden_layer_sizes();
   test_get_sample_size();

   test_get_display();

   // Set methods

   test_set_training_strategy_pointer();

   test_set_default();

   test_set_hidden_layer_sizes();
   test_set_sample_size();

   test_set_assays_numbers();

   test_set_display();

   // Validation analysis methods

   test_perform_model_order_selection();

   // Serialization methods

   test_to_XML();   

   test_print();
   test_save();

   test_load();

   message += "End of model selection test case...\n";
}


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2012 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the s of the GNU Lesser General Public
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
