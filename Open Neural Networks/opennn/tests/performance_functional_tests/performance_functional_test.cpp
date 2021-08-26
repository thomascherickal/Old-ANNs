/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   P E R F O R M A N C E   F U N C T I O N A L   T E S T   C L A S S                                          */
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

#include "../../source/performance_functional/performance_functional.h"

// Unit testing includes

#include "performance_functional_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

PerformanceFunctionalTest::PerformanceFunctionalTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

PerformanceFunctionalTest::~PerformanceFunctionalTest(void)
{
}


// METHODS

// void test_constructor(void) method

void PerformanceFunctionalTest::test_constructor(void)
{
   message += "test_constructor\n";

   PerformanceFunctional pf1;

   assert_true(pf1.get_objective_term_pointer() != NULL,	LOG);
   assert_true(pf1.get_regularization_term_pointer() == NULL,	LOG);
   assert_true(pf1.get_constraints_term_pointer() == NULL,	LOG);
}


// void test_destructor(void)

void PerformanceFunctionalTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_get_neural_network_pointer(void) method

void PerformanceFunctionalTest::test_get_neural_network_pointer(void)
{
   message += "test_get_neural_network_pointer\n";

   PerformanceFunctional pf;
   NeuralNetwork nn;

   // Test

   assert_true(pf.get_neural_network_pointer() == NULL,	LOG);

   // Test

   pf.set_neural_network_pointer(&nn);
   assert_true(pf.get_neural_network_pointer() != NULL,	LOG);
}


// void test_get_mathematical_model_pointer(void) method

void PerformanceFunctionalTest::test_get_mathematical_model_pointer(void)
{
   message += "test_get_mathematical_model_pointer\n";
}


// void test_get_data_set_pointer(void) method

void PerformanceFunctionalTest::test_get_data_set_pointer(void)
{
   message += "test_get_data_set_pointer\n";
}


// void test_get_objective_term_pointer(void) method

void PerformanceFunctionalTest::test_get_objective_term_pointer(void)
{
   message += "test_get_objective_term_pointer\n";
}


// void test_get_regularization_term_pointer(void) method

void PerformanceFunctionalTest::test_get_regularization_term_pointer(void)
{
   message += "test_get_regularization_term_pointer\n";
}


// void test_get_constraints_term_pointer(void) method

void PerformanceFunctionalTest::test_get_constraints_term_pointer(void)
{
   message += "test_get_constraints_term_pointer\n";
}


// void test_get_numerical_differentiation_pointer(void) method

void PerformanceFunctionalTest::test_get_numerical_differentiation_pointer(void)
{
   message += "test_get_numerical_differentiation_pointer\n";
}


// void test_get_display(void) method

void PerformanceFunctionalTest::test_get_display(void)
{
   message += "test_get_display\n";

   PerformanceFunctional pf;

   // Test

   pf.set_display(true);
   assert_true(pf.get_display() == true, LOG);

   pf.set_display(false);
   assert_true(pf.get_display() == false, LOG);
}


// void test_set_neural_network_pointer(void) method

void PerformanceFunctionalTest::test_set_neural_network_pointer(void)
{
   message += "test_set_neural_network_pointer\n";

   PerformanceFunctional pf;
   NeuralNetwork nn;

   // Test

   pf.set_neural_network_pointer(&nn);
   assert_true(pf.get_neural_network_pointer() != NULL, LOG);
}


// void test_set_numerical_differentiation(void) method

void PerformanceFunctionalTest::test_set_numerical_differentiation(void)
{
   message += "test_set_numerical_differentiation\n";
}


// void test_set_default(void) method

void PerformanceFunctionalTest::test_set_default(void)
{
   message += "test_set_default\n";

   PerformanceFunctional pf;

   // Test

   pf.set_default();
}


// void test_set_display(void) method

void PerformanceFunctionalTest::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_calculate_performance(void) method
// @todo

void PerformanceFunctionalTest::test_calculate_performance(void)
{
   message += "test_calculate_performance\n";

//   NeuralNetwork nn;

//   Vector<double> parameters;

//   PerformanceFunctional pf(&nn);

//   double performance;

   // Test

//   nn.set(1, 1);
  
//   performance = pf.calculate_evaluation();

//   parameters = nn.arrange_parameters();

//   performance = pf.calculate_evaluation(parameters);

//   assert_true(performance == performance, LOG);
}


// void test_calculate_gradient(void) method
// @todo

void PerformanceFunctionalTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";
   
//   NeuralNetwork nn;

//   PerformanceFunctional pf(&nn);

//   Vector<double> parameters;

   // Test

//   nn.set(1, 1, 1);

//   nn.initialize_parameters(0.0);

//   parameters = nn.arrange_parameters();

//   assert_true(pf.calculate_gradient(parameters) == 0.0, LOG);

}


// void test_calculate_gradient_norm(void) method

void PerformanceFunctionalTest::test_calculate_gradient_norm(void)
{
   message += "test_calculate_gradient_norm\n";
}


// void test_calculate_Hessian(void) method
// @todo

void PerformanceFunctionalTest::test_calculate_Hessian(void)
{
   message += "test_calculate_Hessian\n";

//   NeuralNetwork nn;
//   unsigned int parameters_number;
//   Vector<double> parameters;
   
//   PerformanceFunctional pf(&nn);
//   Matrix<double> Hessian;

//   nn.set(1, 1, 1);

//   nn.initialize_parameters(0.0);

//   parameters_number = nn.count_parameters_number();
//   parameters = nn.arrange_parameters();

//   Hessian = pf.calculate_Hessian(parameters);

//   assert_true(Hessian.get_rows_number() == parameters_number, LOG);
//   assert_true(Hessian.get_columns_number() == parameters_number, LOG);

//   nn.set();

//   nn.initialize_parameters(0.0);

//   parameters_number = nn.count_parameters_number();
//   parameters = nn.arrange_parameters();

//   Hessian = pf.calculate_Hessian(parameters);

//   assert_true(Hessian.get_rows_number() == parameters_number, LOG);
//   assert_true(Hessian.get_columns_number() == parameters_number, LOG);

//   nn.set(1, 1);

//   nn.initialize_parameters(0.0);

//   parameters_number = nn.count_parameters_number();
//   parameters = nn.arrange_parameters();

//   Hessian = pf.calculate_Hessian(parameters);

//   assert_true(Hessian.get_rows_number() == parameters_number, LOG);
//   assert_true(Hessian.get_columns_number() == parameters_number, LOG);

}


// void test_calculate_inverse_Hessian(void) method

void PerformanceFunctionalTest::test_calculate_inverse_Hessian(void)
{
   message += "test_calculate_inverse_Hessian\n";

   NeuralNetwork nn(1, 1, 1);

   PerformanceFunctional pf(&nn);

//   Matrix<double> Hessian = pf.calculate_Hessian();

//   assert_true(pf.calculate_inverse_Hessian() == Hessian.calculate_inverse(), LOG);

}


// void test_calculate_vector_dot_Hessian(void) method

void PerformanceFunctionalTest::test_calculate_vector_dot_Hessian(void)
{
   message += "test_calculate_vector_dot_Hessian\n";

//   NeuralNetwork nn(1, 1);

//   unsigned int parameters_number = nn.count_parameters_number();

//   PerformanceFunctional pf(&nn);

//   Vector<double> vector(0.0, 1.0, parameters_number-1.0);

//   Matrix<double> Hessian = pf.calculate_Hessian();

//   assert_true(pf.calculate_vector_dot_Hessian(vector) == vector.dot(Hessian), LOG);

}


// void test_calculate_zero_order_Taylor_approximation(void) method

void PerformanceFunctionalTest::test_calculate_zero_order_Taylor_approximation(void)
{
   message += "test_calculate_zero_order_Taylor_approximation\n";
}


// void test_calculate_first_order_Taylor_approximation(void) method

void PerformanceFunctionalTest::test_calculate_first_order_Taylor_approximation(void)
{
   message += "test_calculate_first_order_Taylor_approximation\n";
}


// void test_calculate_second_order_Taylor_approximation(void) method

void PerformanceFunctionalTest::test_calculate_second_order_Taylor_approximation(void)
{
   message += "test_calculate_second_order_Taylor_approximation\n";
}


// void test_calculate_directional_performance(void) method

void PerformanceFunctionalTest::test_calculate_directional_performance(void)
{
   message += "test_calculate_directional_performance\n";
}


// void test_calculate_directional_performance_derivative(void) method

void PerformanceFunctionalTest::test_calculate_directional_performance_derivative(void)
{
   message += "test_calculate_directional_performance_derivative\n";
}


// void test_calculate_directional_performance_second_derivative(void) method

void PerformanceFunctionalTest::test_calculate_directional_performance_second_derivative(void)
{
   message += "test_calculate_directional_performance_second_derivative\n";
}


// void test_to_XML(void) method
// @todo

void PerformanceFunctionalTest::test_to_XML(void)
{
   message += "test_to_XML\n";

//   PerformanceFunctional pf;

//   TiXmlElement* performance_functional_element = pf.to_XML();

//   assert_true(performance_functional_element != NULL, LOG);
}


// void test_from_XML(void) method
// @todo

void PerformanceFunctionalTest::test_from_XML(void)
{
   message += "test_from_XML\n";
}


// void test_print(void) method
// @todo

void PerformanceFunctionalTest::test_print(void)
{
   message += "test_print\n";

//   PerformanceFunctional pf;

//   pf.print();
}


// void test_save(void) method
// @todo

void PerformanceFunctionalTest::test_save(void)
{
   message += "test_save\n";

//   PerformanceFunctional pf;

//   pf.save("../data/opennn_tests/performance_functional.xml");

}


// void test_load(void) method
// @todo

void PerformanceFunctionalTest::test_load(void)
{
   message += "test_load\n";

//   PerformanceFunctional pf;

//   pf.save("../data/opennn_tests/performance_functional.xml");
//   pf.load("../data/opennn_tests/performance_functional.xml");
}


// void test_print_information(void) method
// @todo

void PerformanceFunctionalTest::test_print_information(void)
{
   message += "test_print_information\n";

//   PerformanceFunctional pf;

//   pf.print_information();
}


// void run_test_case(void) method

void PerformanceFunctionalTest::run_test_case(void)
{
   message += "Running performance functional test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_neural_network_pointer();
   test_get_mathematical_model_pointer();
   test_get_data_set_pointer();

   test_get_objective_term_pointer();
   test_get_regularization_term_pointer();
   test_get_constraints_term_pointer();

   test_get_numerical_differentiation_pointer();

   test_get_display();

   // Set methods

   test_set_neural_network_pointer();
   test_set_numerical_differentiation();

   test_set_default();

   test_set_display();

   // Performance methods

   test_calculate_performance();

   test_calculate_gradient();

   test_calculate_gradient_norm();

   test_calculate_Hessian();

   test_calculate_directional_performance();

   test_calculate_inverse_Hessian();

   test_calculate_vector_dot_Hessian();

   // Taylor approximation methods

   test_calculate_zero_order_Taylor_approximation();
   test_calculate_first_order_Taylor_approximation();
   test_calculate_second_order_Taylor_approximation();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   test_print();
   test_save();
   test_load();

   test_print_information();

   message += "End of performance functional test case...\n";
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
