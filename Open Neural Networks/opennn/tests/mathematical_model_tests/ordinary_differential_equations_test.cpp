/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   O R D I N A R Y   D I F F E R E N T I A L   E Q U A T I O N S   T E S T   C L A S S                        */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

// OpenNN includes

#include "../../source/mathematical_model/ordinary_differential_equations.h"

// Unit testing includes

#include "mock_ordinary_differential_equations.h"
#include "ordinary_differential_equations_test.h"


using namespace OpenNN;


// GENERAL CONSTRUCTOR

OrdinaryDifferentialEquationsTest::OrdinaryDifferentialEquationsTest(void) : UnitTesting() 
{   
}


// DESTRUCTOR

OrdinaryDifferentialEquationsTest::~OrdinaryDifferentialEquationsTest(void)
{
}


// void test_constructor(void) method

void OrdinaryDifferentialEquationsTest::test_constructor(void)
{
   message += "test_constructor\n";
}


// void test_destructor(void) method

void OrdinaryDifferentialEquationsTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_get_points_number(void) method

void OrdinaryDifferentialEquationsTest::test_get_points_number(void)
{
   message += "test_get_points_number\n";
}


// void test_get_tolerance(void) method

void OrdinaryDifferentialEquationsTest::test_get_tolerance(void)
{
   message += "test_get_tolerance\n";

}


// void test_get_initial_size(void) method

void OrdinaryDifferentialEquationsTest::test_get_initial_size(void)
{
   message += "test_get_initial_size\n";

}


// void test_get_warning_size(void) method

void OrdinaryDifferentialEquationsTest::test_get_warning_size(void)
{
   message += "test_get_warning_size\n";
}


// void test_get_error_size(void) method

void OrdinaryDifferentialEquationsTest::test_get_error_size(void)
{
   message += "test_get_error_size\n";
}


// void test_get_display(void) method

void OrdinaryDifferentialEquationsTest::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set_default(void) method

void OrdinaryDifferentialEquationsTest::test_set_default(void)
{
   message += "test_set_default\n";
}


// void test_set_points_number(void) method

void OrdinaryDifferentialEquationsTest::test_set_points_number(void)
{
   message += "test_set_points_number\n";
}


// void test_set_tolerance(void) method

void OrdinaryDifferentialEquationsTest::test_set_tolerance(void)
{
   message += "test_set_tolerance\n";
}


// void test_set_initial_size(void) method

void OrdinaryDifferentialEquationsTest::test_set_initial_size(void)
{
   message += "test_set_initial_size\n";
}


// void test_set_warning_size(void) method

void OrdinaryDifferentialEquationsTest::test_set_warning_size(void)
{
   message += "test_set_warning_size\n";
}


// void test_set_error_size(void) method

void OrdinaryDifferentialEquationsTest::test_set_error_size(void)
{
   message += "test_set_error_size\n";
}


// void test_set_display(void) method

void OrdinaryDifferentialEquationsTest::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_calculate_Runge_Kutta_integral(void) method

// @todo

void OrdinaryDifferentialEquationsTest::test_calculate_Runge_Kutta_integral(void)
{
   message += "test_calculate_Runge_Kutta_integral\n";

//   MockOrdinaryDifferentialEquations mode;
//   NeuralNetwork nn;

//   Vector<double> initial_dependent_variables;


//   Matrix<double> data;

//   unsigned int points_number = 11;

//   mode.calculate_Runge_Kutta_solution(*this, 
//   x, y1, y2, y3, y4, y5,
//   &OrdinaryDifferentialEquationsTest::calculate_zero_dot,
//   &OrdinaryDifferentialEquationsTest::calculate_zero_dot,
//   &OrdinaryDifferentialEquationsTest::calculate_zero_dot,
//   &OrdinaryDifferentialEquationsTest::calculate_zero_dot,
//   &OrdinaryDifferentialEquationsTest::calculate_zero_dot,
//   nn, 0.0, 1.0, 
//   0.0, 0.0, 0.0, 0.0, 0.0);
   
//   assert_true(x[points_number-1] == 1.0, LOG);
//   assert_true(y1[points_number-1] == 0.0, LOG);
//   assert_true(y2[points_number-1] == 0.0, LOG);
//   assert_true(y3[points_number-1] == 0.0, LOG);
//   assert_true(y4[points_number-1] == 0.0, LOG);
//   assert_true(y5[points_number-1] == 0.0, LOG);

}


// void test_calculate_Runge_Kutta_Fehlberg_integral(void) method

void OrdinaryDifferentialEquationsTest::test_calculate_Runge_Kutta_Fehlberg_integral(void)
{
   message += "test_calculate_Runge_Kutta_Fehlberg_integral\n";
/*
   OrdinaryDifferentialEquations ode;
   NeuralNetwork nn;

   Vector<double> x;
   Vector<double> y; 

   unsigned int points_number = ode.calculate_Runge_Kutta_Fehlberg_solution(*this, 
   x, y,
   &OrdinaryDifferentialEquationsTest::calculate_zero_dot,
   nn, 0.0, 1.0, 
   0.0);

   assert_true(x[points_number-1] == 1.0, LOG);
   assert_true(y[points_number-1] == 0.0, LOG);
*/
}


// void test_to_XML(void) method   

void OrdinaryDifferentialEquationsTest::test_to_XML(void)   
{
   message += "test_to_XML\n";
}


// void test_from_XML(void) method

void OrdinaryDifferentialEquationsTest::test_from_XML(void)   
{
   message += "test_from_XML\n";
}


// void run_test_case(void) method

void OrdinaryDifferentialEquationsTest::run_test_case(void)
{
   message += "Running ordinary differential equations test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   test_get_points_number();

   test_get_tolerance();
   test_get_initial_size();
   test_get_warning_size();
   test_get_error_size();

   test_get_display();

   // Set methods

   test_set_default();

   test_set_points_number();

   test_set_tolerance();
   test_set_initial_size();
   test_set_warning_size();
   test_set_error_size();

   test_set_display();

   // Runge-Kutta methods

   test_calculate_Runge_Kutta_integral();

   // Runge-Kutta-Fehlberg methods

   test_calculate_Runge_Kutta_Fehlberg_integral();

   message += "End of ordinary differential equations test case\n";
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
