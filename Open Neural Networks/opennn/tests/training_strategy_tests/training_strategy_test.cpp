/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   T R A I N I N G   S T R A T E G Y   T E S T   C L A S S                                                    */
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
#include "../../source/performance_functional/performance_functional.h"
#include "../../source/training_strategy/training_strategy.h"

// Unit testing includes

#include "training_strategy_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR 

TrainingStrategyTest::TrainingStrategyTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

TrainingStrategyTest::~TrainingStrategyTest(void)
{
}


// METHODS

// void test_constructor(void) method

void TrainingStrategyTest::test_constructor(void)
{
   message += "test_constructor\n"; 

   PerformanceFunctional pf;

   // Test

   TrainingStrategy ts1(&pf); 

   assert_true(ts1.get_performance_functional_pointer() != NULL, LOG);   

   // Test

   TrainingStrategy ts2; 

   assert_true(ts2.get_performance_functional_pointer() == NULL, LOG);   
}


// void test_destructor(void) method

void TrainingStrategyTest::test_destructor(void)
{
   message += "test_destructor\n"; 

   TrainingStrategy* ts = new TrainingStrategy(); 

   delete ts;
}


// void test_get_performance_functional_pointer(void) method

void TrainingStrategyTest::test_get_performance_functional_pointer(void)
{
   message += "test_get_performance_functional_pointer\n"; 
   
   TrainingStrategy ts;

   PerformanceFunctional* ofp = ts.get_performance_functional_pointer();

   assert_true(ofp == NULL, LOG);
}

// void test_get_display(void) method

void TrainingStrategyTest::test_get_display(void)
{
   message += "test_get_warning_gradient_norm\n"; 

   TrainingStrategy ts;

   ts.set_display(false);

   assert_true(ts.get_display() == false, LOG);
}


// void test_set(void) method

void TrainingStrategyTest::test_set(void)
{
   message += "test_set\n"; 
}


// void test_set_default(void) method

void TrainingStrategyTest::test_set_default(void)
{
   message += "test_set_default\n"; 
}


// void test_set_performance_functional_pointer(void) method

void TrainingStrategyTest::test_set_performance_functional_pointer(void)
{
   message += "test_set_performance_functional_pointer\n"; 
}


// void test_set_display(void) method

void TrainingStrategyTest::test_set_display(void)
{
   message += "test_set_display\n"; 
}


// void test_perform_training(void) method

void TrainingStrategyTest::test_perform_training(void)
{
   message += "test_perform_training\n";
}


// void test_to_XML(void) method

void TrainingStrategyTest::test_to_XML(void)
{
   message += "test_to_XML\n";
}


// void test_from_XML(void) method

void TrainingStrategyTest::test_from_XML(void)
{
   message += "test_from_XML\n";
}


// void test_print(void) method

void TrainingStrategyTest::test_print(void)
{
   message += "test_print\n";
}


// void test_save(void) method
// @todo

void TrainingStrategyTest::test_save(void)
{
   message += "test_save\n";

   TrainingStrategy ts;
//   ts.save("../data/opennn_tests/training_strategy.xml");
}


// void test_load(void) method
// @todo

void TrainingStrategyTest::test_load(void)
{
   message += "test_load\n";

   TrainingStrategy ts;
//   ts.save("../data/opennn_tests/training_strategy.xml");
//   ts.load("../data/opennn_tests/training_strategy.xml");
}


// void run_test_case(void) method

void TrainingStrategyTest::run_test_case(void)
{
   message += "Running training strategy test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_performance_functional_pointer();

   // Utilities
   
   test_get_display();

   // Set methods

   test_set();
   test_set_default();   

   test_set_performance_functional_pointer();

   // Utilities

   test_set_display();

   // Training methods

   test_perform_training();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   test_print();
   test_save();
   test_load();

   message += "End of training strategy test case...\n";
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

