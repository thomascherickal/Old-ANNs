/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   S O L U T I O N S   E R R O R   T E S T   C L A S S                                                        */
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

#include "../../source/performance_functional/solutions_error.h"

// Unit testing includes

#include "solutions_error_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

SolutionsErrorTest::SolutionsErrorTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

SolutionsErrorTest::~SolutionsErrorTest(void) 
{
}


// METHODS

// void test_constructor(void) method

void SolutionsErrorTest::test_constructor(void)
{
   message += "test_constructor\n";
}


// void test_destructor(void) method

void SolutionsErrorTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_calculate_constraints(void) method

void SolutionsErrorTest::test_calculate_constraints(void)   
{
   message += "test_calculate_constraints\n";
}


// void test_to_XML(void) method

void SolutionsErrorTest::test_to_XML(void)   
{
	message += "test_to_XML\n"; 
}


// void test_from_XML(void) method

void SolutionsErrorTest::test_from_XML(void)
{
	message += "test_from_XML\n"; 
}


// void run_test_case(void) method

void SolutionsErrorTest::run_test_case(void)
{
   message += "Running solutions error test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   // Set methods

   // Constraints methods

   test_calculate_constraints();   

   // Serialization methods

   test_to_XML();   
   test_from_XML();

   message += "End of solutions error test case...\n";
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
