/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   S U M   S Q U A R E D   E R R O R   T E S T   C L A S S                                                    */
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
#include "../../source/mathematical_model/mathematical_model.h"

#include "../../source/neural_network/neural_network.h"

#include "../../source/performance_functional/inverse_sum_squared_error.h"

// Unit testing includes

#include "inverse_sum_squared_error_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

InverseSumSquaredErrorTest::InverseSumSquaredErrorTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

InverseSumSquaredErrorTest::~InverseSumSquaredErrorTest(void) 
{
}


// METHODS

// void test_constructor(void) method

void InverseSumSquaredErrorTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default

   InverseSumSquaredError isse1;

   assert_true(isse1.get_neural_network_pointer() == NULL, LOG);
   assert_true(isse1.get_mathemtaical_model_pointer() == NULL, LOG);
   assert_true(isse1.get_data_set_pointer() == NULL, LOG);

   // Neural network,  mathematical model and data set

   NeuralNetwork nn2;
   MathematicalModel mm2;
   DataSet ds2;

   InverseSumSquaredError isse2(&nn2, &mm2, &ds2);

   assert_true(isse2.get_neural_network_pointer() != NULL, LOG);
   assert_true(isse2.get_mathemtaical_model_pointer() != NULL, LOG);
   assert_true(isse2.get_data_set_pointer() != NULL, LOG);
}


// void test_destructor(void) method

void InverseSumSquaredErrorTest::test_destructor(void)
{
   message += "test_destructor\n";

   InverseSumSquaredError* isse = new InverseSumSquaredError();

   delete isse;
}


// void test_calculate_evaluation(void) method

void InverseSumSquaredErrorTest::test_calculate_evaluation(void)   
{
   message += "test_calculate_evaluation\n";
}


// void test_calculate_generalization_evaluation(void) method

void InverseSumSquaredErrorTest::test_calculate_generalization_evaluation(void)   
{
   message += "test_calculate_generalization_evaluation\n";
}


// void test_to_XML(void) method

void InverseSumSquaredErrorTest::test_to_XML(void)   
{
	message += "test_to_XML\n"; 
}


// void test_from_XML(void) method

void InverseSumSquaredErrorTest::test_from_XML(void)
{
   message += "test_from_XML\n"; 
}


// void run_test_case(void) method

void InverseSumSquaredErrorTest::run_test_case(void)
{
   message += "Running inverse sum squared error test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   // Set methods

   // Objective methods

   test_calculate_evaluation();   
   test_calculate_generalization_evaluation();

   // Serialization methods

   test_to_XML();   
   test_from_XML();

   message += "End of inverse sum squared error test case...\n";
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
