/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   I N P U T S - O U T P U T S   I N F O R M A T I O N   T E S T   C L A S S   H E A D E R                    */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __INPUTSOUTPUTSINFORMATIONTEST_H__
#define __INPUTSOUTPUTSINFORMATIONTEST_H__

// OpenNN includes

#include "../unit_testing.h"

#include "../../source/utilities/vector.h"
#include "../../source/utilities/matrix.h"

using namespace OpenNN;


class InputsOutputsInformationTest : public UnitTesting
{

#define STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // GENERAL CONSTRUCTOR

   explicit InputsOutputsInformationTest(void);


   // DESTRUCTOR

   virtual ~InputsOutputsInformationTest(void);

   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Assignment operators methods

   void test_assignment_operator(void);

   // Get methods

   // Inputs and outputs numbers

   void test_count_inputs_number(void);
   void test_count_outputs_number(void);

   // Input variables information

   void test_get_inputs_name(void);
   void test_get_input_name(void);

   void test_get_inputs_units(void);
   void test_get_input_units(void);

   void test_get_inputs_description(void);
   void test_get_input_description(void);

   // Output variables information

   void test_get_outputs_name(void);
   void test_get_output_name(void);

   void test_get_outputs_units(void);
   void test_get_output_units(void);

   void test_get_outputs_description(void);
   void test_get_output_description(void);

   // Variables information

   void test_get_variables_information(void);

   // Display messages

   void test_get_display(void);

   // SET METHODS

   void test_set(void);
   void test_set_default(void);

   // Input variables information

   void test_set_inputs_name(void);
   void test_set_input_name(void);

   void test_set_inputs_units(void);
   void test_set_input_units(void);

   void test_set_inputs_description(void);
   void test_set_input_description(void);

   // Output variables information

   void test_set_outputs_name(void);
   void test_set_output_name(void);

   void test_set_outputs_units(void);
   void test_set_output_units(void);

   void test_set_outputs_description(void);
   void test_set_output_description(void);

   // Variables information

   void test_set_variables_information(void);

   // Display messages

   void test_set_display(void);

   // Neural network initialization methods

   void test_initialize_random(void);

   // Serialization methods

   void test_to_XML(void);
   void test_from_XML(void);

   // Unit testing methods

   void run_test_case(void);
};


#endif



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
