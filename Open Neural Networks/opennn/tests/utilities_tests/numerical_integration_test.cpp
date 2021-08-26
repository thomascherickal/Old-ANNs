/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   N U M E R I C A L   I N T E G R A T I O N   T E S T   C L A S S                                            */
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

#include "../../source/utilities/numerical_integration.h"

// Unit testing includes

#include "../performance_functional_tests/polynomial.h"

#include "numerical_integration_test.h"


using namespace OpenNN;


// GENERAL CONSTRUCTOR

NumericalIntegrationTest::NumericalIntegrationTest(void) : UnitTesting() 
{
}

// DESTRUCTOR

NumericalIntegrationTest::~NumericalIntegrationTest(void)
{
}


// void test_constructor(void) method

void NumericalIntegrationTest::test_constructor(void)
{
   message += "test_constructor\n";
}


// void test_destructor(void) method

void NumericalIntegrationTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_calculate_trapezoid_integral(void) method
//@todo
void NumericalIntegrationTest::test_calculate_trapezoid_integral(void)
{
   message += "test_calculate_trapezoid_integral\n";

   NumericalIntegration iof;

   // Case 1

   Vector<double> x_1(0, 1, 10);
   Vector<double> y_1(0, 1, 10);

   double integral_1 = iof.calculate_trapezoid_integral(x_1, y_1);

   assert_true(integral_1 == 50.0, LOG);
   
   // Case 2

   NeuralNetwork mlp(1);

   Polynomial p(&mlp);

   Vector<double> coefficients(0, 1, 4);

   p.set_coefficients(coefficients);   

//   double integral_2 = iof.calculate_Simpson_integral(&Polynomial());

//   double calculate_trapezoid_integral(const double& (*f)(double), double, double, const unsigned int&);  
}


// void test_calculate_Simpson_integral(void) method
//@todo
void NumericalIntegrationTest::test_calculate_Simpson_integral(void)
{
   message += "test_calculate_Simpson_integral\n";

   NumericalIntegration iof;

   // Case 1

   Vector<double> x_1(0.0, 1, 10.0);
   Vector<double> y_1(0.0, 1, 10.0);

   double integral_1 = iof.calculate_Simpson_integral(x_1, y_1);

   assert_true(integral_1 == 50.0, LOG);
}


// void run_test_case(void) method

void NumericalIntegrationTest::run_test_case(void)
{
   message += "Running numerical integration test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Integration methods

   test_calculate_trapezoid_integral();
   test_calculate_Simpson_integral();

   message += "End of numerical integration test case\n";
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
