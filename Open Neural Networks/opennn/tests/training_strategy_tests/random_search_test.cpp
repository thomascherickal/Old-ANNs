/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   R A N D O M   S E A R C H   T E S T   C L A S S                                                            */
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
#include "../../source/training_strategy/random_search.h"

// Unit testing includes

#include "random_search_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR 

RandomSearchTest::RandomSearchTest(void) : UnitTesting()
{
}


// DESTRUCTOR

/// Destructor.

RandomSearchTest::~RandomSearchTest(void)
{
}

// METHODS

// void test_constructor(void) method

void RandomSearchTest::test_constructor(void)
{
   message += "test_constructor\n"; 

   PerformanceFunctional pf;

   // Default constructor

   RandomSearch rs1; 
   assert_true(rs1.get_performance_functional_pointer() == NULL, LOG);   

   // Performance functional constructor

   RandomSearch rs2(&pf); 
   assert_true(rs2.get_performance_functional_pointer() != NULL, LOG);   
}


// void test_destructor(void) method

void RandomSearchTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_get_training_rate_reduction_factor(void) method

void RandomSearchTest::test_get_training_rate_reduction_factor(void)
{
   message += "test_get_training_rate_reduction_factor\n";
}


// void test_get_reserve_parameters_history(void) method

void RandomSearchTest::test_get_reserve_parameters_history(void)
{
   message += "test_get_reserve_parameters_history\n";
}


// void test_get_reserve_parameters_norm_history(void) method

void RandomSearchTest::test_get_reserve_parameters_norm_history(void)
{
   message += "test_get_reserve_parameters_norm_history\n";
}


// void test_get_reserve_evaluation_history(void) method

void RandomSearchTest::test_get_reserve_evaluation_history(void)
{
   message += "test_get_reserve_evaluation_history\n";
}


// void test_set_training_rate_reduction_factor(void) method

void RandomSearchTest::test_set_training_rate_reduction_factor(void)
{
   message += "test_set_training_rate_reduction_factor\n";
}


// void test_set_reserve_parameters_history(void) method

void RandomSearchTest::test_set_reserve_parameters_history(void)
{
   message += "test_set_reserve_parameters_history\n";
}


// void test_set_reserve_parameters_norm_history(void) method

void RandomSearchTest::test_set_reserve_parameters_norm_history(void)
{
   message += "test_set_reserve_parameters_norm_history\n";
}


// void test_set_reserve_evaluation_history(void) method

void RandomSearchTest::test_set_reserve_evaluation_history(void)
{
   message += "test_set_reserve_evaluation_history\n";
}


// void test_calculate_training_direction(void) method

void RandomSearchTest::test_calculate_training_direction(void)
{
   message += "test_calculate_training_direction\n";
}


// void test_perform_training(void) method

// @todo

void RandomSearchTest::test_perform_training(void)
{
   message += "test_perform_training\n";

   NeuralNetwork nn;

   PerformanceFunctional pf(&nn);

   RandomSearch rs(&pf);

   // Test 

   nn.set(1, 1);
   
   pf.destruct_all_terms();
   pf.construct_regularization_term(PerformanceFunctional::NEURAL_PARAMETERS_NORM);

   rs.set_display(false);
   rs.set_maximum_epochs_number(5),

   rs.set_reserve_all_training_history(true);

   rs.set_display_period(1);
   
   RandomSearch::RandomSearchResults* rstr = rs.perform_training();

   assert_true(rstr != NULL, LOG);   

   delete rstr;

}


// void test_set_reserve_all_training_history(void) method

void RandomSearchTest::test_set_reserve_all_training_history(void)
{
   message += "test_set_reserve_all_training_history\n";

   RandomSearch rs;
   rs.set_reserve_all_training_history(true);
}


// void test_to_XML(void) method

void RandomSearchTest::test_to_XML(void)
{
   message += "test_to_XML\n";

   RandomSearch rs;

   TiXmlElement* random_search_element = rs.to_XML();

   assert_true(random_search_element != NULL, LOG);   
}


// void test_from_XML(void) method

void RandomSearchTest::test_from_XML(void)
{
   message += "test_from_XML\n";

   RandomSearch rs;
}


// void run_test_case(void) method

void RandomSearchTest::run_test_case(void)
{
   message += "Running random search test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor(); 

   // Get methods

   test_get_training_rate_reduction_factor();

   test_get_reserve_parameters_history();
   test_get_reserve_parameters_norm_history();

   test_get_reserve_evaluation_history();

   // Set methods

   test_set_training_rate_reduction_factor();

   test_set_reserve_parameters_history();
   test_set_reserve_parameters_norm_history();

   test_set_reserve_evaluation_history();

   // Training methods

   test_calculate_training_direction();

   test_perform_training();

   // Training history methods

   test_set_reserve_all_training_history();

   // Utiltity methods

   test_to_XML();
   test_from_XML();

   message += "End of random search test case...\n";
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
