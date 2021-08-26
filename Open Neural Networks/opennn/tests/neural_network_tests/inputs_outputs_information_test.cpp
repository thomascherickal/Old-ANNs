/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   I N P U T S - O U T P U T S   I N F O R M A T I O N   T E S T   C L A S S                                  */
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
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>   

// OpenNN incldues

#include "../../source/utilities/numerical_differentiation.h"
#include "../../source/neural_network/neural_network.h"

// Unit testing includes

#include "inputs_outputs_information_test.h"


using namespace OpenNN;


// GENERAL CONSTRUCTOR

InputsOutputsInformationTest::InputsOutputsInformationTest(void) : UnitTesting()
{
}


// DESTRUCTOR

InputsOutputsInformationTest::~InputsOutputsInformationTest(void)
{
}


// METHODS

// void test_constructor(void) method

void InputsOutputsInformationTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default constructor

   InputsOutputsInformation ioi1;

   assert_true(ioi1.count_inputs_number() == 0, LOG);
   assert_true(ioi1.count_outputs_number() == 0, LOG);

   // MultilayerPerceptron architecture constructor 

   InputsOutputsInformation ioi2(1, 2);

   assert_true(ioi2.count_inputs_number() == 1, LOG);
   assert_true(ioi2.count_outputs_number() == 2, LOG);

   // Copy constructor

   InputsOutputsInformation ioi3(ioi2);

   assert_true(ioi3.count_inputs_number() == 1, LOG);
   assert_true(ioi3.count_outputs_number() == 2, LOG);
}


// void test_destructor(void)

void InputsOutputsInformationTest::test_destructor(void)
{
   message += "test_destructor\n";
}


// void test_assignment_operator(void)

void InputsOutputsInformationTest::test_assignment_operator(void)
{
   message += "test_assignment_operator\n";

   InputsOutputsInformation ioi_1;
   InputsOutputsInformation ioi_2 = ioi_1;

   assert_true(ioi_2.count_inputs_number() == 0, LOG);
   assert_true(ioi_2.count_outputs_number() == 0, LOG);
}


// void test_count_inputs_number(void) method

void InputsOutputsInformationTest::test_count_inputs_number(void)
{
   message += "test_count_inputs_number\n";

   InputsOutputsInformation ioi;

   // Test

   ioi.set();
   assert_true(ioi.count_inputs_number() == 0, LOG);

   // Test

   ioi.set(1, 2);
   assert_true(ioi.count_inputs_number() == 1, LOG);

}


// void test_count_outputs_number(void) method

void InputsOutputsInformationTest::test_count_outputs_number(void)
{
   message += "test_count_outputs_number\n";

   InputsOutputsInformation ioi;

   // Test

   ioi.set();
   assert_true(ioi.count_outputs_number() == 0, LOG);

   // Test

   ioi.set(1, 2);
   assert_true(ioi.count_outputs_number() == 2, LOG);

}


// void test_set(void) method

void InputsOutputsInformationTest::test_set(void)
{
   message += "test_set\n";
}


// void test_set_default(void) method

void InputsOutputsInformationTest::test_set_default(void)
{
   message += "test_set_default\n";
}


// void test_get_inputs_name(void) method

void InputsOutputsInformationTest::test_get_inputs_name(void)
{
   message += "test_get_inputs_name\n";

   InputsOutputsInformation ioi;

   Vector<std::string> inputs_name = ioi.get_inputs_name();

   assert_true(inputs_name.size() == 0, LOG); 
}


// void test_get_outputs_name(void) method

void InputsOutputsInformationTest::test_get_outputs_name(void)
{
   message += "test_get_outputs_name\n";

   InputsOutputsInformation ioi;

   Vector<std::string> outputs_name = ioi.get_outputs_name();

   assert_true(outputs_name.size() == 0, LOG);
}


// void test_get_input_name(void) method

void InputsOutputsInformationTest::test_get_input_name(void)
{
   message += "test_get_input_name\n";

   InputsOutputsInformation ioi(1, 1);

   ioi.set_input_name(0, "x");

   assert_true(ioi.get_input_name(0) == "x", LOG);

}


// void test_get_output_name(void) method

void InputsOutputsInformationTest::test_get_output_name(void)
{
   message += "test_get_output_name\n";

   InputsOutputsInformation ioi(1, 1);

   ioi.set_output_name(0, "y");

   assert_true(ioi.get_output_name(0) == "y", LOG);

}


// void test_get_inputs_units(void) method

void InputsOutputsInformationTest::test_get_inputs_units(void)
{
   message += "test_get_inputs_units\n";

   InputsOutputsInformation ioi;

   Vector<std::string> inputs_units = ioi.get_inputs_units();

   assert_true(inputs_units.size() == 0, LOG); 
}


// void test_get_outputs_units(void) method

void InputsOutputsInformationTest::test_get_outputs_units(void)
{
   message += "test_get_outputs_units\n";

   InputsOutputsInformation ioi;

   Vector<std::string> outputs_units = ioi.get_outputs_units();

   assert_true(outputs_units.size() == 0, LOG); 
}


// void test_get_input_units(void) method

void InputsOutputsInformationTest::test_get_input_units(void)
{
   message += "test_get_input_units\n";

   InputsOutputsInformation ioi(1, 1);

   ioi.set_input_units(0, "m");

   assert_true(ioi.get_input_units(0) == "m", LOG);

}


// void test_get_output_units(void) method

void InputsOutputsInformationTest::test_get_output_units(void)
{
   message += "test_get_output_units\n";

   InputsOutputsInformation ioi(1, 1);

   ioi.set_output_units(0, "m");

   assert_true(ioi.get_output_units(0) == "m", LOG);

}


// void test_get_inputs_description(void) method

void InputsOutputsInformationTest::test_get_inputs_description(void)
{
   message += "test_get_inputs_description\n";

   InputsOutputsInformation ioi;

   Vector<std::string> inputs_description = ioi.get_inputs_description();

   assert_true(inputs_description.size() == 0, LOG); 
}


// void test_get_outputs_description(void) method

void InputsOutputsInformationTest::test_get_outputs_description(void)
{
   message += "test_get_outputs_description\n";

   InputsOutputsInformation ioi;

   Vector<std::string> outputs_description = ioi.get_outputs_description();

   assert_true(outputs_description.size() == 0, LOG); 
}


// void test_get_input_description(void) method

void InputsOutputsInformationTest::test_get_input_description(void)
{
   message += "test_get_input_description\n";

   InputsOutputsInformation ioi(1, 1);

   ioi.set_input_description(0, "info");

   assert_true(ioi.get_input_description(0) == "info", LOG);

}


// void test_get_output_description(void) method

void InputsOutputsInformationTest::test_get_output_description(void)
{
   message += "test_get_output_description\n";

   InputsOutputsInformation ioi(1, 1);

   ioi.set_output_description(0, "info");

   assert_true(ioi.get_output_description(0) == "info", LOG);

}


// void test_get_variables_information(void) method
// @todo

void InputsOutputsInformationTest::test_get_variables_information(void)
{
   message += "test_get_variables_information\n";

//   InputsOutputsInformation ioi(1, 1);

//   Vector< Vector<std::string> > inputs_outputs_information = ioi.write_inputs_outputs_information();

//   unsigned int size = inputs_outputs_information.size();

//   assert_true(size == 6, LOG);

}


// void test_get_display(void) method

void InputsOutputsInformationTest::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set_inputs_name(void) method

void InputsOutputsInformationTest::test_set_inputs_name(void)
{
   message += "test_set_inputs_name\n";
}


// void test_set_outputs_name(void) method

void InputsOutputsInformationTest::test_set_outputs_name(void)
{
   message += "test_set_outputs_name\n";
}


// void test_set_input_name(void) method

void InputsOutputsInformationTest::test_set_input_name(void)
{
   message += "test_set_input_name\n";
}


// void test_set_output_name(void) method

void InputsOutputsInformationTest::test_set_output_name(void)
{
   message += "test_set_output_name\n";
}


// void test_set_inputs_units(void) method

void InputsOutputsInformationTest::test_set_inputs_units(void)
{
   message += "test_set_inputs_units\n";
}


// void test_set_input_units(void) method

void InputsOutputsInformationTest::test_set_input_units(void)
{
   message += "test_set_input_units\n";
}


// void test_set_outputs_units(void) method

void InputsOutputsInformationTest::test_set_outputs_units(void)
{
   message += "test_set_outputs_units\n";
}


// void test_set_output_units(void) method

void InputsOutputsInformationTest::test_set_output_units(void)
{
   message += "test_set_output_units\n";
}


// void test_set_inputs_description(void) method

void InputsOutputsInformationTest::test_set_inputs_description(void)
{
   message += "test_set_inputs_description\n";
}


// void test_set_outputs_description(void) method

void InputsOutputsInformationTest::test_set_outputs_description(void)
{
   message += "test_set_outputs_description\n";
}


// void test_set_input_description(void) method

void InputsOutputsInformationTest::test_set_input_description(void)
{
   message += "test_set_input_description\n";
}


// void test_set_output_description(void) method

void InputsOutputsInformationTest::test_set_output_description(void)
{
   message += "test_set_output_description\n";
}


// void test_set_variables_information(void) method

void InputsOutputsInformationTest::test_set_variables_information(void)
{
   message += "test_set_variables_information\n";
}


// void test_set_display(void) method

void InputsOutputsInformationTest::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_initialize_random(void) method

void InputsOutputsInformationTest::test_initialize_random(void)
{
   message += "test_initialize_random\n";

   InputsOutputsInformation ioi;

   // Test

   ioi.initialize_random();
}


// void test_to_XML(void) method

void InputsOutputsInformationTest::test_to_XML(void)
{
   message += "test_to_XML\n";

   InputsOutputsInformation  ioi;

   TiXmlElement* inputs_outputs_information_element = ioi.to_XML();

   assert_true(inputs_outputs_information_element != NULL, LOG);
}


// void test_from_XML(void) method

void InputsOutputsInformationTest::test_from_XML(void)
{
   message += "test_from_XML\n";

   InputsOutputsInformation  ioi;

   TiXmlElement* ioie;

   // Test

   ioi.from_XML(NULL);

   // Test

   ioie = ioi.to_XML();

   ioi.from_XML(ioie);
}


// void run_test_case(void) method

void InputsOutputsInformationTest::run_test_case(void)
{
   message += "Running inputs-outputs information test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Assignment operators methods

   test_assignment_operator();

   // Get methods

   // Input and outputs numbers

   test_count_inputs_number();
   test_count_outputs_number();

   // Input variables information

   test_get_inputs_name();
   test_get_input_name();

   test_get_inputs_units();
   test_get_input_units();

   test_get_inputs_description();
   test_get_input_description();

   // Output variables information

   test_get_outputs_name();
   test_get_output_name();

   test_get_outputs_units();
   test_get_output_units();

   test_get_outputs_description();
   test_get_output_description();

   // Variables information

   test_get_variables_information();

   // Display messages

   test_get_display();

   // Set methods

   test_set();
   test_set_default();


   // Input variables information

   test_set_inputs_name();
   test_set_input_name();

   test_set_inputs_units();
   test_set_input_units();

   test_set_inputs_description();
   test_set_input_description();

   // Output variables information

   test_set_outputs_name();
   test_set_output_name();

   test_set_outputs_units();
   test_set_output_units();

   test_set_outputs_description();
   test_set_output_description();

   // Variables information

   test_set_variables_information();

   // Display messages

   test_set_display();

   // Neural network initialization methods

   test_initialize_random();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   message += "End of inputs-outputs information test case\n";
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
