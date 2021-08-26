/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   V A R I A B L E S   I N F O R M A T I O N   T E S T   C L A S S                                            */
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

#include "../../source/opennn.h"

// Unit testing includes

#include "variables_information_test.h"

// TinyXml includes

#include "../../parsers/tinyxml/tinyxml.h"

using namespace OpenNN;

// GENERAL CONSTRUCTOR

VariablesInformationTest::VariablesInformationTest(void) : UnitTesting() 
{
}


// DESTRUCTOR

VariablesInformationTest::~VariablesInformationTest(void)
{
}


// METHODS

// void test_constructor(void)

void VariablesInformationTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default constructor

   VariablesInformation vi1;

   assert_true(vi1.get_variables_number() == 0, LOG);
   assert_true(vi1.count_inputs_number() == 0, LOG);
   assert_true(vi1.count_targets_number() == 0, LOG);

   // Variables number constructor

   VariablesInformation vi2(1);

   assert_true(vi2.get_variables_number() == 1, LOG);
   assert_true(vi2.count_inputs_number() == 1, LOG);
   assert_true(vi2.count_targets_number() == 1, LOG);

   // XML constructor

   // Copy constructor 

   VariablesInformation vi5(1, 1);

   VariablesInformation vi6(vi5);

   assert_true(vi6.get_variables_number() == 2, LOG);
   assert_true(vi6.count_inputs_number() == 1, LOG);
   assert_true(vi6.count_targets_number() == 1, LOG);   
}


// void test_destructor(void)

void VariablesInformationTest::test_destructor(void)
{
   message += "test_destructor\n";

}


// void test_assignment_operator(void) method

void VariablesInformationTest::test_assignment_operator(void)
{
   message += "test_assignment_operator\n";

   VariablesInformation vi1(2);
   VariablesInformation vi2 = vi1;

   assert_true(vi2.count_inputs_number() == 1, LOG);
   assert_true(vi2.count_targets_number() == 1, LOG);
}


// void test_get_variables_number(void) method

void VariablesInformationTest::test_get_variables_number(void) 
{
   message += "test_get_variables_number\n";

   VariablesInformation vi;

   assert_true(vi.get_variables_number() == 0, LOG);
}


// void test_count_inputs_number(void) method

void VariablesInformationTest::test_count_inputs_number(void) 
{
   message += "test_count_inputs_number\n";

   VariablesInformation vi;

   assert_true(vi.count_inputs_number() == 0, LOG);
}


// void test_get_inputs_indices(void) method

void VariablesInformationTest::test_get_inputs_indices(void)
{
   message += "test_get_inputs_indices\n";

   VariablesInformation vi;

   Vector<unsigned int> inputs_indices = vi.get_inputs_indices();

   assert_true(inputs_indices.size() == 0, LOG);
}


// void test_count_targets_number(void) method

void VariablesInformationTest::test_count_targets_number(void) 
{
   message += "test_count_targets_number\n";

   VariablesInformation vi;

   assert_true(vi.count_targets_number() == 0, LOG);
}


// void test_get_targets_indices(void) method

void VariablesInformationTest::test_get_targets_indices(void)
{
   message += "test_get_targets_indices\n";

   VariablesInformation vi;

   Vector<unsigned int> targets_indices = vi.get_targets_indices();

   assert_true(targets_indices.size() == 0, LOG);
}


// void test_get_names(void) method

void VariablesInformationTest::test_get_names(void)
{
   message += "test_get_names\n";

   VariablesInformation vi;

   Vector<std::string> names = vi.get_names();

   assert_true(names.size() == 0, LOG);
}


// void test_get_name(void) method

void VariablesInformationTest::test_get_name(void)
{
   message += "test_get_name\n";
}


// void test_get_inputs_name(void) method

void VariablesInformationTest::test_get_inputs_name(void)
{
   message += "test_get_inputs_name\n";
}


// void test_get_targets_name(void) method

void VariablesInformationTest::test_get_targets_name(void)
{
   message += "test_get_targets_name\n";
}


// void test_get_units(void) method

void VariablesInformationTest::test_get_units(void)
{
   message += "test_get_units\n";

   VariablesInformation vi;

   Vector<std::string> units = vi.get_units();

   assert_true(units.size() == 0, LOG);
}


// void test_get_units(void) method

void VariablesInformationTest::test_get_unit(void)
{
   message += "test_get_unit\n";
}


// void test_get_inputs_units(void) method

void VariablesInformationTest::test_get_inputs_units(void)
{
   message += "test_get_inputs_units\n";
}


// void test_get_targets_units(void) method

void VariablesInformationTest::test_get_targets_units(void)
{
   message += "test_get_targets_units\n";
}


// void test_get_descriptions(void) method

void VariablesInformationTest::test_get_descriptions(void)
{
   message += "test_get_descriptions\n";

   VariablesInformation vi;

   Vector<std::string> descriptions = vi.get_descriptions();

   assert_true(descriptions.size() == 0, LOG);
}


// void test_get_description(void) method

void VariablesInformationTest::test_get_description(void)
{
   message += "test_get_description\n";
}


// void test_get_inputs_description(void) method

void VariablesInformationTest::test_get_inputs_description(void)
{
   message += "test_get_inputs_description\n";
}


// void test_get_target_descriptions(void) method

void VariablesInformationTest::test_get_target_descriptions(void)
{
   message += "test_get_target_descriptions\n";
}


// void test_get_information(void) method

void VariablesInformationTest::test_get_information(void) 
{
   message += "test_get_information\n";

   VariablesInformation vi(1);

   Vector< Vector<std::string> > variables_information = vi.arrange_inputs_targets_information();

   unsigned int size = variables_information.size();

   assert_true(size == 6, LOG);
}


// void test_get_display(void) method

void VariablesInformationTest::test_get_display(void) 
{
   message += "test_get_display\n";

   VariablesInformation vi;

   vi.set_display(true);

   assert_true(vi.get_display() == true, LOG);

   vi.set_display(false);

   assert_true(vi.get_display() == false, LOG);
}


// void test_set(void) method

void VariablesInformationTest::test_set(void) 
{
   message += "test_set\n";

   VariablesInformation vi;

   // Instances and inputs and target variables

   vi.set(1);

   assert_true(vi.count_inputs_number() == 1, LOG);
   assert_true(vi.count_targets_number() == 1, LOG);
}


// void test_set_variables_number(void) method

void VariablesInformationTest::test_set_variables_number(void) 
{
   message += "test_set_number\n";

   VariablesInformation vi(1);

   vi.set_variables_number(2);

   assert_true(vi.get_variables_number() == 2, LOG);
}


// void test_set_inputs_indices(void) method

void VariablesInformationTest::test_set_inputs_indices(void)
{
   message += "test_set_inputs_indices\n";
}


// void test_set_targets_indices(void) method

void VariablesInformationTest::test_set_targets_indices(void)
{
   message += "test_set_targets_indices\n";
}


// void test_set_input(void) method

void VariablesInformationTest::test_set_input(void)
{
   message += "test_set_input\n";
}


// void test_set_target(void) method

void VariablesInformationTest::test_set_target(void)
{
   message += "test_set_target\n";
}


// void test_set_names(void) method

void VariablesInformationTest::test_set_names(void)
{
   message += "test_set_names\n";
}


// void test_set_name(void) method

void VariablesInformationTest::test_set_name(void)
{
   message += "test_set_name\n";
}


// void test_set_units(void) method

void VariablesInformationTest::test_set_units(void)
{
   message += "test_set_units\n";
}


// void test_set_unit(void) method

void VariablesInformationTest::test_set_unit(void)
{
   message += "test_set_unit\n";
}


// void test_set_descriptions(void) method

void VariablesInformationTest::test_set_descriptions(void)
{
   message += "test_set_descriptions\n";
}


// void test_set_description(void) method

void VariablesInformationTest::test_set_description(void)
{
   message += "test_set_description\n";
}


// void test_set_display(void) method

void VariablesInformationTest::test_set_display(void) 
{
   message += "test_set_display\n";
}


// void test_to_XML(void) method

void VariablesInformationTest::test_to_XML(void) 
{
   message += "test_to_XML\n";

   VariablesInformation vi;

   TiXmlElement* element = vi.to_XML();

   assert_true(element != NULL, LOG);
}


// void test_from_XML(void) method

void VariablesInformationTest::test_from_XML(void) 
{
   message += "test_from_XML\n";

   VariablesInformation vi;

   TiXmlElement* element = vi.to_XML();

   vi.from_XML(element);

}


// void run_test_case(void) method

void VariablesInformationTest::run_test_case(void)
{
   message += "Running variables information test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Assignment operators methods

   test_assignment_operator();

   // Get methods

   test_get_variables_number();

   // Variables methods

   test_count_inputs_number();
   test_get_inputs_indices();

   test_count_targets_number();
   test_get_targets_indices();

   // Information methods

   test_get_names();
   test_get_name();

   test_get_inputs_name();
   test_get_targets_name();

   test_get_units();
   test_get_units();

   test_get_inputs_units();
   test_get_targets_units();

   test_get_descriptions();
   test_get_description();

   test_get_inputs_description();
   test_get_target_descriptions();
 
   test_get_information();

   test_get_display();

   // Set methods

   test_set();

   // Variables methods

   test_set_inputs_indices();
   test_set_targets_indices();

   test_set_input();
   test_set_target();

   // Information methods

   test_set_names();
   test_set_name();

   test_set_units();
   test_set_unit();

   test_set_descriptions();
   test_set_description();

   test_set_display();

   // Data methods

   test_set_variables_number();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   message += "End of variables information test case...\n";
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

