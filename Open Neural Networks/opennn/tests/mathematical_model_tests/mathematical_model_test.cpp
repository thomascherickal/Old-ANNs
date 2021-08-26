/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   M A T H E M A T I C A L   M O D E L   T E S T   C L A S S                                                  */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

// OpenNN includes

#include "../../source/mathematical_model/mathematical_model.h"

// Unit testing includes

#include "mathematical_model_test.h"


using namespace OpenNN;


// GENERAL CONSTRUCTOR

MathematicalModelTest::MathematicalModelTest(void) : UnitTesting() 
{   
}


// DESTRUCTOR

MathematicalModelTest::~MathematicalModelTest(void)
{
}


// void test_get_display(void) method

void MathematicalModelTest::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set_display(void) method

void MathematicalModelTest::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_to_XML(void) method   

void MathematicalModelTest::test_to_XML(void)   
{
   message += "test_to_XML\n";

   MathematicalModel mm;

   TiXmlElement* e;
   
   // Test

   e = mm.to_XML();

   assert_true(e != NULL, LOG);

}


// void test_from_XML(void) method

// @todo

void MathematicalModelTest::test_from_XML(void)   
{
   message += "test_from_XML\n";

   MathematicalModel mm1;
   MathematicalModel mm2;

   TiXmlElement* e;
   
   // Test

   mm1.from_XML(NULL);

   // Test

   e = mm1.to_XML();

   assert_true(e != NULL, LOG);   

//   mm2.from_XML(e);

//   assert_true(mm1 == mm2, LOG);   
}


// void test_save(void) method

void MathematicalModelTest::test_save(void)
{
   message += "test_save\n";

   MathematicalModel mm;

   // Test

   mm.save("../data/opennn_tests/mathematical_model.xml");

}


// void test_load(void) method
// @todo

void MathematicalModelTest::test_load(void)
{
   message += "test_load\n";

   MathematicalModel mm;

   // Test

   mm.save("../data/opennn_tests/mathematical_model.xml");
//   mm.load("../data/opennn_tests/mathematical_model.xml");
}


// void run_test_case(void) method


void MathematicalModelTest::run_test_case(void)
{
   message += "Running mathematical model test case...\n";  

   // Constructor and destructor methods

   // Get methods

   test_get_display();

   // Set methods

   test_set_display();

   // Serialization methods

   test_to_XML();   
   test_from_XML();   

   test_save();
   test_load();

   message += "End of mathematical model test case...\n";  
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
