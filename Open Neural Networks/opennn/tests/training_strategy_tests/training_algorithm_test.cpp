/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   T R A I N I N G   A L G O R I T H M   T E S T   C L A S S                                                  */
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

// Unit testing includes

#include "mock_training_algorithm.h"

#include "training_algorithm_test.h"


using namespace OpenNN;


// GENERAL CONSTRUCTOR 

TrainingAlgorithmTest::TrainingAlgorithmTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

TrainingAlgorithmTest::~TrainingAlgorithmTest(void)
{
}


// METHODS


// void test_constructor(void) method

void TrainingAlgorithmTest::test_constructor(void)
{
   message += "test_constructor\n"; 

   PerformanceFunctional pf;

   // Test

   MockTrainingAlgorithm mta2; 

   assert_true(mta2.get_performance_functional_pointer() == NULL, LOG);   

   // Test

   MockTrainingAlgorithm mta1(&pf); 

   assert_true(mta1.get_performance_functional_pointer() != NULL, LOG);   
}


// void test_destructor(void) method

void TrainingAlgorithmTest::test_destructor(void)
{
   message += "test_destructor\n"; 
}


// void test_get_performance_functional_pointer(void) method

void TrainingAlgorithmTest::test_get_performance_functional_pointer(void)
{
   message += "test_get_performance_functional_pointer\n"; 
   
   MockTrainingAlgorithm mta;

   PerformanceFunctional* ofp = mta.get_performance_functional_pointer();

   assert_true(ofp == NULL, LOG);
}


// void test_get_display(void) method

void TrainingAlgorithmTest::test_get_display(void)
{
   message += "test_get_warning_gradient_norm\n"; 

   MockTrainingAlgorithm mta;

   mta.set_display(false);

   assert_true(mta.get_display() == false, LOG);
}


// void test_set(void) method

void TrainingAlgorithmTest::test_set(void)
{
   message += "test_set\n"; 
}


// void test_set_default(void) method

void TrainingAlgorithmTest::test_set_default(void)
{
   message += "test_set_default\n"; 
}


// void test_set_performance_functional_pointer(void) method

void TrainingAlgorithmTest::test_set_performance_functional_pointer(void)
{
   message += "test_set_performance_functional_pointer\n"; 
}


// void test_set_display(void) method

void TrainingAlgorithmTest::test_set_display(void)
{
   message += "test_set_display\n"; 
}


// void test_perform_training(void) method

void TrainingAlgorithmTest::test_perform_training(void)
{
   message += "test_perform_training\n";
}


// void test_to_XML(void) method

void TrainingAlgorithmTest::test_to_XML(void)
{
   message += "test_to_XML\n";
}
   

// void test_from_XML(void) method

void TrainingAlgorithmTest::test_from_XML(void)
{
   message += "test_from_XML\n";
}


// void test_print(void) method

void TrainingAlgorithmTest::test_print(void)
{
   message += "test_print\n";
}


// void test_save(void) method

void TrainingAlgorithmTest::test_save(void)
{
   message += "test_save\n";

   MockTrainingAlgorithm mta;
   mta.save("../data/opennn_tests/mock_training_algorithm.xml");
}


// void test_load(void) method

void TrainingAlgorithmTest::test_load(void)
{
   message += "test_load\n";

   MockTrainingAlgorithm mta;
   mta.save("../data/opennn_tests/mock_training_algorithm.xml");
   mta.load("../data/opennn_tests/mock_training_algorithm.xml");
}



// void run_test_case(void) method

void TrainingAlgorithmTest::run_test_case(void)
{
   message += "Running training algorithm test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_performance_functional_pointer();
   test_get_display();

   // Set methods

   test_set_performance_functional_pointer();
   test_set_display();

   test_set();
   test_set_default();   

   // Training methods

   test_perform_training();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   test_print();
   test_save();
   test_load();

   message += "End of training algorithm test case...\n";
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

