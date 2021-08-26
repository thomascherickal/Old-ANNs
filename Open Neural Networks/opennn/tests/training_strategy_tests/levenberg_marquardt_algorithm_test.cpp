/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   L E V E N B E R G   M A R Q U A R D T   A L G O R I T H M   T E S T   C L A S S                            */
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

#include "../../source/utilities/matrix.h"
#include "../../source/utilities/matrix.h"
#include "../../source/data_set/data_set.h"
#include "../../source/neural_network/neural_network.h"
#include "../../source/performance_functional/sum_squared_error.h"
#include "../../source/training_strategy/levenberg_marquardt_algorithm.h"

// Unit testing includes

#include "levenberg_marquardt_algorithm_test.h"

using namespace OpenNN;

// GENERAL CONSTRUCTOR

LevenbergMarquardtAlgorithmTest::LevenbergMarquardtAlgorithmTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

LevenbergMarquardtAlgorithmTest::~LevenbergMarquardtAlgorithmTest(void)
{
}


// METHODS

// void test_constructor(void) method

void LevenbergMarquardtAlgorithmTest::test_constructor(void)
{
   message += "test_constructor\n"; 

   PerformanceFunctional pf;

   // Default constructor

   LevenbergMarquardtAlgorithm lma1; 
   assert_true(lma1.get_performance_functional_pointer() == NULL, LOG);   

   // Performance functional constructor

   LevenbergMarquardtAlgorithm lma2(&pf); 
   assert_true(lma2.get_performance_functional_pointer() != NULL, LOG);   
}


// void test_destructor(void) method

void LevenbergMarquardtAlgorithmTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_get_damping_parameter(void) method

void LevenbergMarquardtAlgorithmTest::test_get_damping_parameter(void)
{
   message += "test_get_damping_parameter\n";
}


// void test_get_damping_parameter_factor(void) method

void LevenbergMarquardtAlgorithmTest::test_get_damping_parameter_factor(void)
{
   message += "test_get_damping_parameter_factor\n";
}


// void test_get_minimum_damping_parameter(void) method

void LevenbergMarquardtAlgorithmTest::test_get_minimum_damping_parameter(void)
{
   message += "test_get_minimum_damping_parameter\n";
}


// void test_get_maximum_damping_parameter(void) method

void LevenbergMarquardtAlgorithmTest::test_get_maximum_damping_parameter(void)
{
   message += "test_get_maximum_damping_parameter\n";
}


// void test_set_damping_parameter(void) method

void LevenbergMarquardtAlgorithmTest::test_set_damping_parameter(void)
{
   message += "test_set_damping_parameter\n";
}


// void test_set_damping_parameter_factor(void) method

void LevenbergMarquardtAlgorithmTest::test_set_damping_parameter_factor(void)
{
   message += "test_set_damping_parameter_factor\n";
}


// void test_set_minimum_damping_parameter(void) method

void LevenbergMarquardtAlgorithmTest::test_set_minimum_damping_parameter(void)
{
   message += "test_set_minimum_damping_parameter\n";
}


// void test_set_maximum_damping_parameter(void) method

void LevenbergMarquardtAlgorithmTest::test_set_maximum_damping_parameter(void)
{
   message += "test_set_maximum_damping_parameter\n";
}


// void test_calculate_gradient(void) method

void LevenbergMarquardtAlgorithmTest::test_calculate_gradient(void)
{
   message += "test_calculate_gradient\n";

   NeuralNetwork nn;

   DataSet ds;

   PerformanceFunctional pf(&nn, &ds);

   Vector<double> terms;
   Matrix<double> Jacobian_terms;

   Vector<double> gradient;

   LevenbergMarquardtAlgorithm lma(&pf);

   // Test

   nn.set(2, 2, 2);
   nn.initialize_parameters_normal();

   ds.set(2, 2, 2);
   ds.initialize_data_normal();

   terms = pf.get_objective_term_pointer()->calculate_evaluation_terms();

   Jacobian_terms = pf.get_objective_term_pointer()->calculate_Jacobian_terms();

   gradient = lma.calculate_gradient(terms, Jacobian_terms);

   assert_true((gradient-pf.calculate_gradient()).calculate_absolute_value() < 1.0e-3, LOG);
}


// void test_calculate_Hessian_approximation(void) method
// @todo

void LevenbergMarquardtAlgorithmTest::test_calculate_Hessian_approximation(void)
{
   message += "test_calculate_Hessian_approximation\n";

   NeuralNetwork mlp;

   unsigned int network_parameters_number;

   DataSet itds;

   PerformanceFunctional pf(&mlp, &itds);

   pf.set_objective_term_type(PerformanceFunctional::SUM_SQUARED_ERROR);

   Matrix<double> Jacobian_terms;
   Matrix<double> Hessian;
   Matrix<double> Hessian_approximation;

   LevenbergMarquardtAlgorithm lma(&pf);
   
   // Test

   mlp.set(1,1,2);
   mlp.initialize_parameters(0.0);

   network_parameters_number = mlp.count_parameters_number();

   itds.set(2,1,2);
   itds.initialize_data(0.0);

   Jacobian_terms = pf.get_objective_term_pointer()->calculate_Jacobian_terms();

//   Hessian = pf.calculate_Hessian();

   Hessian_approximation = lma.calculate_Hessian_approximation(Jacobian_terms);

   assert_true(Hessian_approximation.get_rows_number() == network_parameters_number, LOG);
   assert_true(Hessian_approximation.get_columns_number() == network_parameters_number, LOG);
//   assert_true(Hessian_approximation.is_symmetric(), LOG);

   // Test

   mlp.set(1,1,2);
   mlp.initialize_parameters_normal();

   network_parameters_number = mlp.count_parameters_number();

   itds.set(10,1,2);
   itds.initialize_data_normal();

   Jacobian_terms = pf.get_objective_term_pointer()->calculate_Jacobian_terms();

   pf.set_objective_term_type(PerformanceFunctional::NORMALIZED_SQUARED_ERROR);

   Hessian_approximation = lma.calculate_Hessian_approximation(Jacobian_terms);

   assert_true(Hessian_approximation.get_rows_number() == network_parameters_number, LOG);
   assert_true(Hessian_approximation.get_columns_number() == network_parameters_number, LOG);
   assert_true(Hessian_approximation.is_symmetric(), LOG);
}


// void test_set_reserve_all_training_history(void) method

void LevenbergMarquardtAlgorithmTest::test_set_reserve_all_training_history(void)
{
   message += "test_set_reserve_all_training_history\n";

   LevenbergMarquardtAlgorithm lma;
   lma.set_reserve_all_training_history(true);

   assert_true(lma.get_reserve_parameters_history() == true, LOG);
   assert_true(lma.get_reserve_parameters_norm_history() == true, LOG);

   assert_true(lma.get_reserve_evaluation_history() == true, LOG);
   assert_true(lma.get_reserve_generalization_evaluation_history() == true, LOG);
   assert_true(lma.get_reserve_gradient_history() == true, LOG);
   assert_true(lma.get_reserve_gradient_norm_history() == true, LOG);
   assert_true(lma.get_reserve_inverse_Hessian_history() == true, LOG);

   assert_true(lma.get_reserve_damping_parameter_history() == true, LOG);
   assert_true(lma.get_reserve_elapsed_time_history() == true, LOG);
}


// void test_perform_training(void) method
// @todo

void LevenbergMarquardtAlgorithmTest::test_perform_training(void)
{
   message += "test_perform_training\n";

   NeuralNetwork mlp;
   
   DataSet itds;
   
   PerformanceFunctional pf(&mlp, &itds);
   Vector<double> gradient;

   LevenbergMarquardtAlgorithm lma(&pf);

//   double old_performance;
//   double performance;
   double minimum_parameters_increment_norm;
   double performance_goal;
   double minimum_performance_increase;
   double gradient_norm_goal;
//   double gradient_norm;

   // Test

   mlp.set(1, 1, 1);
   mlp.initialize_parameters_normal();

   itds.set(2, 1, 1);
   itds.initialize_data_normal();

//   old_performance = pf.calculate_evaluation();

   lma.set_display(false);

//   lma.perform_training();

//   performance = pf.calculate_evaluation();

//   assert_true(performance < old_performance, LOG);

   // Minimum parameters increment norm

   mlp.initialize_parameters_normal();

   minimum_parameters_increment_norm = 0.1;

   lma.set_minimum_parameters_increment_norm(minimum_parameters_increment_norm);
   lma.set_performance_goal(0.0);
   lma.set_minimum_performance_increase(0.0);
   lma.set_gradient_norm_goal(0.0);
   lma.set_maximum_epochs_number(1000);
   lma.set_maximum_time(1000.0);

//   lma.perform_training();

   // Performance goal

   mlp.initialize_parameters_normal();

   performance_goal = 0.1;

   lma.set_minimum_parameters_increment_norm(0.0);
   lma.set_performance_goal(performance_goal);
   lma.set_minimum_performance_increase(0.0);
   lma.set_gradient_norm_goal(0.0);
   lma.set_maximum_epochs_number(1000);
   lma.set_maximum_time(1000.0);

//   lma.perform_training();

//   performance = pf.calculate_evaluation();

//   assert_true(performance < performance_goal, LOG);

   // Minimum evaluation improvement

   mlp.initialize_parameters_normal();

   minimum_performance_increase = 0.1;

   lma.set_minimum_parameters_increment_norm(0.0);
   lma.set_performance_goal(0.0);
   lma.set_minimum_performance_increase(minimum_performance_increase);
   lma.set_gradient_norm_goal(0.0);
   lma.set_maximum_epochs_number(1000);
   lma.set_maximum_time(1000.0);

//   lma.perform_training();

   // Gradient norm goal 

   mlp.initialize_parameters_normal();

   gradient_norm_goal = 0.1;

   lma.set_minimum_parameters_increment_norm(0.0);
   lma.set_performance_goal(0.0);
   lma.set_minimum_performance_increase(0.0);
   lma.set_gradient_norm_goal(gradient_norm_goal);
   lma.set_maximum_epochs_number(1000);
   lma.set_maximum_time(1000.0);

//   lma.perform_training();

   gradient = pf.calculate_gradient();
//   gradient_norm = gradient.calculate_norm();

//   assert_true(gradient_norm < gradient_norm_goal, LOG);

}


// void test_resize_training_history(void) method

void LevenbergMarquardtAlgorithmTest::test_resize_training_history(void)
{
   message += "test_resize_training_history\n";

   LevenbergMarquardtAlgorithm lma;

   lma.set_reserve_all_training_history(true);

   LevenbergMarquardtAlgorithm::LevenbergMarquardtAlgorithmResults lmatr;

   lmatr.resize_training_history(1);

   assert_true(lmatr.parameters_history.size() == 1, LOG);
   assert_true(lmatr.parameters_norm_history.size() == 1, LOG);

   assert_true(lmatr.evaluation_history.size() == 1, LOG);
   assert_true(lmatr.generalization_evaluation_history.size() == 1, LOG);  
   assert_true(lmatr.gradient_history.size() == 1, LOG);
   assert_true(lmatr.gradient_norm_history.size() == 1, LOG);
   assert_true(lmatr.Hessian_approximation_history.size() == 1, LOG);

   assert_true(lmatr.damping_parameter_history.size() == 1, LOG);
   assert_true(lmatr.elapsed_time_history.size() == 1, LOG);

}


// void test_to_XML(void) method   

void LevenbergMarquardtAlgorithmTest::test_to_XML(void)   
{
   message += "test_to_XML\n";

   LevenbergMarquardtAlgorithm lma;

   TiXmlElement* lmae = lma.to_XML();
   
   assert_true(lmae != NULL, LOG);
}


// void test_from_XML(void) method

void LevenbergMarquardtAlgorithmTest::test_from_XML(void)
{
   message += "test_from_XML\n";

   LevenbergMarquardtAlgorithm lma;
}


// void run_test_case(void) method

void LevenbergMarquardtAlgorithmTest::run_test_case(void)
{
   message += "Running Levenberg-Marquardt algorithm test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_damping_parameter();

   test_get_damping_parameter_factor();

   test_get_minimum_damping_parameter();
   test_get_maximum_damping_parameter();

   // Set methods

   test_set_damping_parameter();

   test_set_damping_parameter_factor();

   test_set_minimum_damping_parameter();
   test_set_maximum_damping_parameter();

   // Training methods

   test_calculate_gradient();
   test_calculate_Hessian_approximation();

   test_perform_training();

   // Training history methods

   test_set_reserve_all_training_history();
   test_resize_training_history();

   // Serialization methods

   test_to_XML();   
   test_from_XML();

   message += "End of Levenberg-Marquardt algorithm test case\n";
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
