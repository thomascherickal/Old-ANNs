/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   P R O B A B I L I S T I C   L A Y E R   T E S T   C L A S S   H E A D E R                                  */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __PROBABILISTICLAYERTEST_H__
#define __PROBABILISTICLAYERTEST_H__

// OpenNN includes

#include "../unit_testing.h"

#include "../../source/utilities/vector.h"
#include "../../source/utilities/matrix.h"

using namespace OpenNN;


class ProbabilisticLayerTest : public UnitTesting
{

#define STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // GENERAL CONSTRUCTOR

   explicit ProbabilisticLayerTest(void);


   // DESTRUCTOR

   virtual ~ProbabilisticLayerTest(void);

   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Assignment operators methods

   void test_assignment_operator(void);

   // Get methods

   // Probabilistic layer

   void test_count_probabilistic_neurons_number(void);

   // Output variables probabilistic postprocessing

   void test_get_probabilistic_layer_flag(void);

   // Display messages

   void test_get_display(void);

   // SET METHODS

   void test_set(void);
   void test_set_default(void);


   // Probabilistic postprocessing

   void test_set_probabilistic_flag(void);

   // Display messages

   void test_set_display(void);

   // Neural network initialization methods

   void test_initialize_random(void);

  // Probabilistic post-processing

   void test_calculate_outputs(void);
   void test_calculate_Jacobian(void);
   void test_calculate_Hessian_form(void);

   // Expression methods

   void test_get_layer_expression(void);

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
