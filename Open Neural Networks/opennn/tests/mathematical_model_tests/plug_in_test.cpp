/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   P L U G - I N   T E S T   C L A S S                                                                        */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

// OpenNN includes

#include "../../source/mathematical_model/plug_in.h"

// Unit testing includes

#include "plug_in_test.h"


using namespace OpenNN;


// GENERAL CONSTRUCTOR

PlugInTest::PlugInTest(void) : UnitTesting() 
{   
}


// DESTRUCTOR

PlugInTest::~PlugInTest(void)
{
}


// void test_get_template_filename(void) method

void PlugInTest::test_get_template_filename(void)
{
   message += "test_get_template_filename\n";
}


// void test_get_input_filename(void) method

void PlugInTest::test_get_input_filename(void)
{
   message += "test_get_input_filename\n";
}


// void test_get_script_filename(void) method

void PlugInTest::test_get_script_filename(void)
{
   message += "test_get_script_filename\n";
}


// void test_get_output_filename(void) method

void PlugInTest::test_get_output_filename(void)
{
   message += "test_get_output_filename\n";
}


// void test_get_input_flags(void) method

void PlugInTest::test_get_input_flags(void)
{
   message += "test_get_input_flags\n";
}


// void test_get_display(void) method

void PlugInTest::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set_template_filename(void) method

void PlugInTest::test_set_template_filename(void)
{
   message += "test_set_template_filename\n";
}


// void test_set_input_filename(void) method

void PlugInTest::test_set_input_filename(void)
{
   message += "test_set_input_filename\n";
}


// void test_set_script_filename(void) method

void PlugInTest::test_set_script_filename(void)
{
   message += "test_set_script_filename\n";
}


// void test_set_output_filename(void) method

void PlugInTest::test_set_output_filename(void)
{
   message += "test_set_output_filename\n";
}


// void test_set_input_flags(void) method

void PlugInTest::test_set_input_flags(void)
{
   message += "test_set_input_flags\n";
}


// void test_set_display(void) method

void PlugInTest::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_write_input_file(void) method
// @todo
void PlugInTest::test_write_input_file(void)
{
   message += "test_write_input_file\n";

   //NeuralNetwork nn;

   //PlugIn mmpi(&nn);

   //Vector<std::string> input_flags;

   //// Test

   //nn.set(3);

   //nn.get_independent_parameters_pointer()->set_parameter(0, 1.0);
   //nn.get_independent_parameters_pointer()->set_parameter(1, 3.0);
   //nn.get_independent_parameters_pointer()->set_parameter(2, 5.0);

   //mmpi.set_template_filename("../data/opennn_tests/template.dat");
   //mmpi.set_input_filename("../data/opennn_tests/input.dat");

   //input_flags.set(3);
   //input_flags[0] = "input_flag_1";
   //input_flags[1] = "input_flag_3";
   //input_flags[2] = "input_flag_5";
   //
   //mmpi.set_input_flags(input_flags);

   //mmpi.write_input_file();

}


// void test_run_script(void) method

void PlugInTest::test_run_script(void)
{
   message += "test_run_script\n";

   PlugIn mmpi;

   // Test

//   mmpi.set_script_filename("..\\Data\\Script");

//   mmpi.run_script();

}


// void test_read_output_file(void) method

void PlugInTest::test_read_output_file(void)
{
   message += "test_read_output_file\n";

   PlugIn mmpi;

   std::string output_filename;

   // Test

   output_filename = "../data/Output.dat";
   mmpi.set_output_filename(output_filename);
}


// void test_read_output_file_header(void) method

void PlugInTest::test_read_output_file_header(void)
{
   message += "test_read_output_file_header\n";
}


// void test_calculate_output_data(void) method
// @todo

void PlugInTest::test_calculate_output_data(void)
{
   
   message += "test_calculate_output_data\n";

   PlugIn mmpi;

   std::string template_filename;
   std::string input_filename;
   std::string script_filename;
   std::string output_filename;

   Vector<std::string> input_flags;

   Vector<double> input_values;

   Matrix<double> outut_values;

   // Test

   template_filename = "../data/Template.dat";
   input_filename = "../data/Input.dat";
   script_filename = "../data/Batch.dat";
   output_filename = "../data/Output.dat";
   

   mmpi.set_template_filename(template_filename);
   mmpi.set_input_filename(input_filename);
   mmpi.set_script_filename(script_filename);
   mmpi.set_output_filename(output_filename);

   input_flags.set(2);
   input_flags[0] = "input_flag_1";
   input_flags[1] = "input_flag_2";

   mmpi.set_input_flags(input_flags);

//   mmpi.write_input_file();

}


// void test_to_XML(void) method   

void PlugInTest::test_to_XML(void)   
{
   message += "test_to_XML\n";
}


// void test_from_XML(void) method

void PlugInTest::test_from_XML(void)   
{
   message += "test_from_XML\n";
}


// void test_save(void) method

void PlugInTest::test_save(void)
{
   message += "test_save\n";

   PlugIn mmpi;

   std::string template_filename;
   std::string input_filename;
   std::string script_filename;
   std::string output_filename;

   Vector<std::string> input_flags;

   bool display;

   Vector<double> input_values;

   Matrix<double> outut_values;

   // Test

   template_filename = "../data/template.dat";
   input_filename = "../data/input.dat";
   script_filename = "../data/batch.dat";
   output_filename = "../data/output.dat";
   

   mmpi.set_template_filename(template_filename);
   mmpi.set_input_filename(input_filename);
   mmpi.set_script_filename(script_filename);
   mmpi.set_output_filename(output_filename);

   input_flags.set(2);
   input_flags[0] = "input_flag_1";
   input_flags[1] = "input_flag_2";

   mmpi.set_input_flags(input_flags);

   display = false;

   mmpi.set_display(display);

   mmpi.save("../data/opennn_tests/plug_in.xml");

   mmpi.load("../data/opennn_tests/plug_in.xml");

   assert_true(mmpi.get_template_filename() == template_filename, LOG);
   assert_true(mmpi.get_input_filename() == input_filename, LOG);
   assert_true(mmpi.get_script_filename() == script_filename, LOG);
   assert_true(mmpi.get_output_filename() == output_filename, LOG);
   assert_true(mmpi.get_input_flags() == input_flags, LOG);

}


// void test_load(void) method

void PlugInTest::test_load(void)
{
   message += "test_load\n";
}


// void run_test_case(void) method

void PlugInTest::run_test_case(void)
{
   message += "Running plug-in test case...\n";  

   test_get_template_filename();
   test_get_input_filename();

   test_get_script_filename();

   test_get_output_filename();

   test_get_input_flags();
   test_get_display();

   // Set methods

   test_set_template_filename();
   test_set_input_filename();

   test_set_script_filename();

   test_set_output_filename();

   test_set_input_flags();
   test_set_display();

   // Plug-In methods

   test_write_input_file();

   test_run_script();

   test_read_output_file();

   test_read_output_file_header();

   test_calculate_output_data();

   // Serialization methods

   test_to_XML();   
   test_from_XML();   

   test_save();
   test_load();

   message += "End of plug-in test case...\n";  
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
