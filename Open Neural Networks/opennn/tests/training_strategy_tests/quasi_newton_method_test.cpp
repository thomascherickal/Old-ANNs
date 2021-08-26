/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */ 
/*   Q U A S I - N E W T O N   M E T H O D   T E S T   C L A S S                                                */
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

#include "../../source/neural_network/neural_network.h"
#include "../../source/training_strategy/quasi_newton_method.h"


// Unit testing includes

#include "quasi_newton_method_test.h"


using namespace OpenNN;


// GENERAL CONSTRUCTOR

QuasiNewtonMethodTest::QuasiNewtonMethodTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

/// Destructor.

QuasiNewtonMethodTest::~QuasiNewtonMethodTest(void)
{

}


// METHODS

// void test_constructor(void) method

void QuasiNewtonMethodTest::test_constructor(void)
{
   message += "test_constructor\n"; 

   PerformanceFunctional pf;

   // Default constructor

   QuasiNewtonMethod qnm1; 
   assert_true(qnm1.get_performance_functional_pointer() == NULL, LOG);   

   // Objective functional constructor

   QuasiNewtonMethod qnm2(&pf); 
   assert_true(qnm2.get_performance_functional_pointer() != NULL, LOG);   

}


// void test_destructor(void) method

void QuasiNewtonMethodTest::test_destructor(void)
{
}


// void test_get_inverse_Hessian_approximation_method(void) method

void QuasiNewtonMethodTest::test_get_inverse_Hessian_approximation_method(void)
{
   message += "test_get_inverse_Hessian_approximation_method\n";

   QuasiNewtonMethod qnm;

   qnm.set_inverse_Hessian_approximation_method(QuasiNewtonMethod::DFP);
   assert_true(qnm.get_inverse_Hessian_approximation_method() == QuasiNewtonMethod::DFP, LOG);

   qnm.set_inverse_Hessian_approximation_method(QuasiNewtonMethod::BFGS);
   assert_true(qnm.get_inverse_Hessian_approximation_method() == QuasiNewtonMethod::BFGS, LOG);
}



// void test_get_inverse_Hessian_approximation_method_name(void) method

void QuasiNewtonMethodTest::test_get_inverse_Hessian_approximation_method_name(void)
{
   message += "test_get_inverse_Hessian_approximation_method_name\n";
}


// void test_set_inverse_Hessian_approximation_method(void) method

void QuasiNewtonMethodTest::test_set_inverse_Hessian_approximation_method(void)
{
   message += "test_set_training_direction_method\n";

   QuasiNewtonMethod qnm;

   qnm.set_inverse_Hessian_approximation_method(QuasiNewtonMethod::BFGS);
   assert_true(qnm.get_inverse_Hessian_approximation_method() == QuasiNewtonMethod::BFGS, LOG);
}


// void test_calculate_DFP_inverse_Hessian_approximation(void) method

// @todo

void QuasiNewtonMethodTest::test_calculate_DFP_inverse_Hessian_approximation(void)
{
   message += "test_calculate_DFP_inverse_Hessian_approximation\n";

   DataSet ds(2, 1, 1);
   ds.initialize_data_normal();
   NeuralNetwork nn(1, 1);
   PerformanceFunctional pf(&nn, &ds);
   QuasiNewtonMethod qnm(&pf);

   // Test 

   nn.initialize_parameters(1.0);

   Vector<double> old_parameters = nn.arrange_parameters();
   Vector<double> old_gradient = pf.calculate_gradient();
   Matrix<double> old_inverse_Hessian = pf.calculate_inverse_Hessian();

   nn.initialize_parameters(-0.5);

   Vector<double> parameters = nn.arrange_parameters();
   Vector<double> gradient = pf.calculate_gradient();
//   Matrix<double> inverse_Hessian = pf.calculate_inverse_Hessian();

//   Matrix<double> DFP_inverse_Hessian 
//   = qnm.calculate_DFP_inverse_Hessian(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian);

//   assert_true(DFP_inverse_Hessian == inverse_Hessian, LOG);

   // Test 

   nn.initialize_parameters(1.0e-3);

   old_parameters = nn.arrange_parameters();
   old_gradient = pf.calculate_gradient();
   old_inverse_Hessian = pf.calculate_inverse_Hessian();

   nn.initialize_parameters(1.0e-6);

   parameters = nn.arrange_parameters();
   gradient = pf.calculate_gradient();
//   inverse_Hessian = mpf.calculate_inverse_Hessian();

//   DFP_inverse_Hessian = mpf.calculate_DFP_inverse_Hessian(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian);

//   assert_true(DFP_inverse_Hessian == inverse_Hessian, LOG);

   // Test 

   nn.initialize_parameters(1.0e-6);

   old_parameters = nn.arrange_parameters();
   old_gradient = pf.calculate_gradient();
   old_inverse_Hessian = pf.calculate_inverse_Hessian();

   nn.initialize_parameters(1.0e-9);

   parameters = nn.arrange_parameters();
   gradient = pf.calculate_gradient();
//   inverse_Hessian = mpf.calculate_inverse_Hessian();

//   DFP_inverse_Hessian = mpf.calculate_DFP_inverse_Hessian(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian);

//   assert_true(DFP_inverse_Hessian == inverse_Hessian, LOG);

   // Test 

   old_parameters.initialize(1.0e-3);
   parameters.initialize(1.0e-6);

   old_gradient.initialize(1.0e-3);
   gradient.initialize(1.0e-6);

   old_inverse_Hessian[0][0] = 0.75;
   old_inverse_Hessian[0][1] = -0.25;
   old_inverse_Hessian[1][0] = -0.25;
   old_inverse_Hessian[1][1] = 0.75;

//   DFP_inverse_Hessian = mpf.calculate_DFP_inverse_Hessian(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian);

}


// void test_calculate_BFGS_inverse_Hessian_approximation(void) method

void QuasiNewtonMethodTest::test_calculate_BFGS_inverse_Hessian_approximation(void)
{
   message += "test_calculate_BFGS_inverse_Hessian_approximation\n";

   NeuralNetwork nn(2);

   PerformanceFunctional mpf(&nn);

   nn.initialize_parameters(1.0);

   Vector<double> old_parameters = nn.arrange_parameters();
   Vector<double> old_gradient = mpf.calculate_gradient();
   Matrix<double> old_inverse_Hessian = mpf.calculate_inverse_Hessian();

   nn.initialize_parameters(-0.5);

   Vector<double> parameters = nn.arrange_parameters();
   Vector<double> gradient = mpf.calculate_gradient();
   Matrix<double> inverse_Hessian = mpf.calculate_inverse_Hessian();

//   Matrix<double> BFGS_inverse_Hessian 
//   = mpf.calculate_BFGS_inverse_Hessian(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian);

//   assert_true(BFGS_inverse_Hessian == inverse_Hessian, LOG);

}


// void test_calculate_inverse_Hessian_approximation(void) method
// @todo

void QuasiNewtonMethodTest::test_calculate_inverse_Hessian_approximation(void)
{
   message += "test_calculate_inverse_Hessian_approximation\n";

   NeuralNetwork nn(1, 1);
   DataSet ds(2, 1, 1);
   ds.initialize_data_normal();
   PerformanceFunctional pf(&nn, &ds);
   QuasiNewtonMethod qnm(&pf);

   qnm.set_inverse_Hessian_approximation_method(QuasiNewtonMethod::DFP);

   nn.initialize_parameters(1.0);

   Vector<double> old_parameters = nn.arrange_parameters();
   Vector<double> old_gradient = pf.calculate_gradient();
//   Matrix<double> old_inverse_Hessian = pf.calculate_inverse_Hessian();

   nn.initialize_parameters(-0.5);

   Vector<double> parameters = nn.arrange_parameters();
   Vector<double> gradient = pf.calculate_gradient();
//   Matrix<double> inverse_Hessian = pf.calculate_inverse_Hessian();

//   Matrix<double> inverse_Hessian_approximation
//   = qnm.calculate_inverse_Hessian_approximation(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian);

//   assert_true(inverse_Hessian_approximation == inverse_Hessian, LOG);

   qnm.set_inverse_Hessian_approximation_method(QuasiNewtonMethod::DFP);

   nn.initialize_parameters(1.0);

   old_parameters = nn.arrange_parameters();
   old_gradient = pf.calculate_gradient();
//   old_inverse_Hessian = pf.calculate_inverse_Hessian();

   nn.initialize_parameters(-0.5);

   parameters = nn.arrange_parameters();
   gradient = pf.calculate_gradient();
//   inverse_Hessian = pf.calculate_inverse_Hessian();

//   inverse_Hessian_approximation
//   = qnm.calculate_inverse_Hessian_approximation(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian);

//   assert_true(inverse_Hessian_approximation == inverse_Hessian, LOG);

   // Test 

   old_parameters.initialize(1.0e-3);
   parameters.initialize(1.0e-6);

   old_gradient.initialize(1.0e-3);
   gradient.initialize(1.0e-6);

//   old_inverse_Hessian[0][0] = 0.75;
//   old_inverse_Hessian[0][1] = -0.25;
//   old_inverse_Hessian[1][0] = -0.25;
//   old_inverse_Hessian[1][1] = 0.75;

//   inverse_Hessian_approximation
//   = qnm.calculate_inverse_Hessian_approximation(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian);

}


// void test_calculate_training_direction(void) method

void QuasiNewtonMethodTest::test_calculate_training_direction(void)
{
   message += "test_calculate_training_direction\n";
}


// void test_perform_training(void) method

void QuasiNewtonMethodTest::test_perform_training(void)
{
   message += "test_perform_training\n";

   DataSet ds(3, 1, 1);
   ds.initialize_data_normal();
   NeuralNetwork nn(1, 1);
   PerformanceFunctional pf(&nn, &ds);
   QuasiNewtonMethod qnm(&pf);
   qnm.set_inverse_Hessian_approximation_method(QuasiNewtonMethod::DFP);

   nn.initialize_parameters(3.1415927);

//   double old_performance = pf.calculate_evaluation();

   qnm.set_maximum_epochs_number(2),
   qnm.set_display(false);

//   qnm.perform_training();

//   double performance = pf.calculate_evaluation();

//   assert_true(performance < old_performance, LOG);

   // Minimum parameters increment norm

   nn.initialize_parameters(3.1415927);

   double minimum_parameters_increment_norm = 0.1;

   qnm.set_minimum_parameters_increment_norm(minimum_parameters_increment_norm);
   qnm.set_performance_goal(0.0);
   qnm.set_minimum_performance_increase(0.0);
   qnm.set_gradient_norm_goal(0.0);
   qnm.set_maximum_epochs_number(10);
   qnm.set_maximum_time(1000.0);

//   qnm.perform_training();
/*
   // Performance goal

   nn.initialize_parameters(3.1415927);

   double performance_goal = 0.1;

   qnm.set_minimum_parameters_increment_norm(0.0);
   qnm.set_performance_goal(performance_goal);
   qnm.set_minimum_performance_increase(0.0);
   qnm.set_gradient_norm_goal(0.0);
   qnm.set_maximum_epochs_number(10);
   qnm.set_maximum_time(1000.0);

   qnm.perform_training();

   performance = pf.calculate_evaluation();

//   assert_true(performance < performance_goal, LOG);

   // Minimum evaluation improvement

   nn.initialize_parameters(3.1415927);

   double minimum_performance_increase = 0.1;

   qnm.set_minimum_parameters_increment_norm(0.0);
   qnm.set_performance_goal(0.0);
   qnm.set_minimum_performance_increase(minimum_performance_increase);
   qnm.set_gradient_norm_goal(0.0);
   qnm.set_maximum_epochs_number(10);
   qnm.set_maximum_time(1000.0);

   qnm.perform_training();

   // Gradient norm goal 

   nn.initialize_parameters(3.1415927);

   double gradient_norm_goal = 0.1;

   qnm.set_minimum_parameters_increment_norm(0.0);
   qnm.set_performance_goal(0.0);
   qnm.set_minimum_performance_increase(0.0);
   qnm.set_gradient_norm_goal(gradient_norm_goal);
   qnm.set_maximum_epochs_number(10);
   qnm.set_maximum_time(1000.0);

   qnm.perform_training();

//   double gradient_norm = pf.calculate_gradient_norm();
//   assert_true(gradient_norm < gradient_norm_goal, LOG);
*/
}


// void test_to_XML(void) method

void QuasiNewtonMethodTest::test_to_XML(void)   
{
   message += "test_to_XML\n";

   QuasiNewtonMethod qnm;

   TiXmlElement* qnme = qnm.to_XML();
   assert_true(qnme != NULL, LOG);

}


// void test_load(void) method

void QuasiNewtonMethodTest::test_load(void)
{
   message += "test_load\n";

   QuasiNewtonMethod qnm;

   TiXmlElement* qnme = qnm.to_XML();
   qnm.from_XML(qnme);
}


// void test_set_reserve_all_training_history(void) method

void QuasiNewtonMethodTest::test_set_reserve_all_training_history(void)
{
   message += "test_set_reserve_all_training_history\n";

   QuasiNewtonMethod qnm;
   qnm.set_reserve_all_training_history(true);
}


// void run_test_case(void) method

void QuasiNewtonMethodTest::run_test_case(void)
{
   message += "Running quasi-Newton method test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor(); 

   // Get methods

   test_get_inverse_Hessian_approximation_method();
   test_get_inverse_Hessian_approximation_method_name();

   // Set methods

   test_set_inverse_Hessian_approximation_method();

   // Training methods

   test_calculate_inverse_Hessian_approximation();
   test_calculate_training_direction();

   test_perform_training();

   // Training history methods

   test_set_reserve_all_training_history();

   // Serialization methods

   test_to_XML();   
   test_load();

   message += "End of quasi-Newton method test case\n";
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
