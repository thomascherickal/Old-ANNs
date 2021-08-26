/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   I N S T A N C E S   I N F O R M A T I O N   T E S T    C L A S S   H E A D E R                             */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __INSTANCESINFORMATIONTEST_H__
#define __INSTANCESINFORMATIONTEST_H__

// System included

#include <string>

// Tests includes

#include "../unit_testing.h"

using namespace OpenNN;

class InstancesInformationTest : public UnitTesting 
{

#define STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:  

   // GENERAL CONSTRUCTOR

   explicit InstancesInformationTest(void);


   // DESTRUCTOR

   virtual ~InstancesInformationTest(void);
    // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Assignment operators methods

   void test_assignment_operator(void);

   // Get methods

   void test_get_instances_number(void);

   // Instances methods 

   void test_count_training_instances_number(void);
   void test_get_training_indices(void);

   void test_count_generalization_instances_number(void);
   void test_get_generalization_indices(void);

   void test_count_testing_instances_number(void);
   void test_get_testing_indices(void);

   void test_get_display(void);

   // Set methods

   void test_set(void);

   void test_set_instances_number(void);

   // Instances methods

   void test_set_training_indices(void);
   void test_set_generalization_indices(void);
   void test_set_testing_indices(void);

   void test_set_training(void);
   void test_set_generalization(void);
   void test_set_testing(void);

   void test_set_display(void);

   // Data splitting methods

   void test_split_given_indices(void);
   void test_split_random_indices(void);

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
