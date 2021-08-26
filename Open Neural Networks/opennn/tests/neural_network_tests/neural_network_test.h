/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   N E U R A L   N E T W O R K   T E S T   C L A S S   H E A D E R                                            */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __NEURALNETWORKTEST_H__
#define __NEURALNETWORKTEST_H__

// OpenNN includes

#include "../unit_testing.h"

#include "../../source/utilities/matrix.h"
#include "../../source/utilities/matrix.h"

using namespace OpenNN;


class NeuralNetworkTest : public UnitTesting
{

#define STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // GENERAL CONSTRUCTOR

   explicit NeuralNetworkTest(void);


   // DESTRUCTOR

   virtual ~NeuralNetworkTest(void);

   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Assignment operators methods

   void test_assignment_operator(void);

   // Get methods

   void test_get_multilayer_perceptron_pointer(void);
   void test_get_inputs_outputs_information_pointer(void);
   void test_get_scaling_layer_pointer(void);
   void test_get_unscaling_layer_pointer(void);   
   void test_get_bounding_layer_pointer(void);
   void test_get_probabilistic_layer_pointer(void);
   void test_get_conditions_layer_pointer(void);
   void test_get_independent_parameters_pointer(void);

   void test_get_multilayer_perceptron_flag(void);
   void test_get_scaling_layer_flag(void);
   void test_get_unscaling_layer_flag(void);
   void test_get_bounding_layer_flag(void);
   void test_get_probabilistic_layer_flag(void);
   void test_get_conditions_layer_flag(void);

   // Inputs outptus information

   void test_arrange_inputs_outputs_information(void);

   // Inputs outputs statistics

   void test_arrange_inputs_outputs_statistics(void);

   // Display warning 

  // Parameters methods

   void test_count_parameters_number(void);
   void test_arrange_parameters(void);   

   // Display messages

   void test_get_display(void);

   // SET METHODS

   void test_set(void);
   void test_set_default(void);

   // MultilayerPerceptron architecture

   void test_set_network(void);

   // Variables information

   void test_set_variables_information(void);

   // Variables statistics

   void test_set_variables_statistics(void);

   // Variables scaling and unscaling

   void test_set_inputs_scaling_flag(void);
   void test_set_outputs_unscaling_flag(void);
   void test_set_variables_scaling_flag(void);

   // Conditions

   void test_set_conditions_layer_flag(void);

   // Variables bounds

   void test_set_outputs_bounds_flag(void);

   // Probabilistic postprocessing

   void test_set_probabilistic_flag(void);

   // Independent parameters

   void test_set_independent_parameters(void);

   // Parameters

   void test_set_parameters(void);

   // Scaling

   void test_set_scaling_flag(void);

   // Display messages

   void test_set_display_inputs_warning(void);
   void test_set_display(void);

   // Neural network initialization methods

   void test_initialize_random(void);

   // Parameters initialization methods

   void test_initialize_parameters(void);
   void test_initialize_parameters_uniform(void);
   void test_initialize_parameters_normal(void);

   // Parameters norm 

   void test_calculate_parameters_norm(void);

   // Output 

   void test_calculate_outputs(void);
   void test_calculate_output_data(void);

   void test_calculate_Jacobian(void);
   void test_calculate_Jacobian_data(void);

   void test_calculate_parameters_Jacobian(void);
   void test_calculate_parameters_Jacobian_data(void);

   // Expression methods

   // XML expression methods

   void test_write_expression(void);
   void test_save_expression(void);

   // Hinton diagram methods

   void test_get_Hinton_diagram_XML(void);   
   void test_save_Hinton_diagram_XML(void);

   // Serialization methods

   void test_to_XML(void);
   void test_from_XML(void);

   void test_print(void);

   void test_save(void);
   void test_load(void);

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
