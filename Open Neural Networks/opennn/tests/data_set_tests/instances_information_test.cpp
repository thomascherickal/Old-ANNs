/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   I N S T A N C E S   I N F O R M A T I O N   T E S T   C L A S S                                            */
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

#include "../../source/data_set/data_set.h"

// Unit testing includes

#include "../unit_testing.h"

#include "instances_information_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

InstancesInformationTest::InstancesInformationTest(void) : UnitTesting() 
{
}



// DESTRUCTOR

InstancesInformationTest::~InstancesInformationTest(void)
{
}


// METHODS

// void test_constructor(void)

void InstancesInformationTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Test

   InstancesInformation ii1(1);
  
   assert_true(ii1.count_training_instances_number() == 1, LOG);

   // Test

   InstancesInformation ii2(1);
   ii2.set_display(false);

   // Test

   InstancesInformation ii4;

   assert_true(ii4.count_training_instances_number() == 0, LOG);
   assert_true(ii4.count_generalization_instances_number() == 0, LOG);
   assert_true(ii4.count_testing_instances_number() == 0, LOG);

   InstancesInformation ii5(1);

   InstancesInformation ii6(ii5);

   assert_true(ii6.count_training_instances_number() == 1, LOG);
   assert_true(ii6.count_training_instances_number() == 1, LOG);
   assert_true(ii6.count_training_instances_number() == 1, LOG);
}


// void test_destructor(void)

void InstancesInformationTest::test_destructor(void)
{
   message += "test_destructor\n";

   InstancesInformation* iip = new InstancesInformation(1);

   delete iip;
}


// void test_assignment_operator(void) method

void InstancesInformationTest::test_assignment_operator(void)
{
   message += "test_assignment_operator\n";

   InstancesInformation ii1(1);
   InstancesInformation ii2 = ii1;

   assert_true(ii2.get_instances_number() == 1, LOG);
   
}


// void test_get_instances_number(void) method

void InstancesInformationTest::test_get_instances_number(void) 
{
   message += "test_get_instances_number\n";

   InstancesInformation ii;

   assert_true(ii.get_instances_number() == 0, LOG);
}


// void test_count_training_instances_number(void) method

void InstancesInformationTest::test_count_training_instances_number(void) 
{
   message += "test_count_training_instances_number\n";

   InstancesInformation ii;

   // Test

   ii.set();

   assert_true(ii.count_training_instances_number() == 0, LOG);

   // Test

   ii.set(1);

   assert_true(ii.count_training_instances_number() == 1, LOG);

}


// void test_get_training_indices(void) method

void InstancesInformationTest::test_get_training_indices(void) 
{
   message += "test_get_training_indices\n";

   InstancesInformation ii;

   Vector<unsigned int> training_indices;

   training_indices = ii.get_training_indices();

   assert_true(training_indices.size() == 0, LOG);
   
   ii.set(1);

   training_indices = ii.get_training_indices();

   assert_true(training_indices.size() == 1, LOG);

}


// void test_count_generalization_instances_number(void) method

void InstancesInformationTest::test_count_generalization_instances_number(void) 
{
   message += "test_count_generalization_instances_number\n";

   InstancesInformation ii;

   assert_true(ii.count_generalization_instances_number() == 0, LOG);
   
   ii.set(1);

   assert_true(ii.count_generalization_instances_number() == 0, LOG);
}


// void test_get_generalization_indices(void) method

void InstancesInformationTest::test_get_generalization_indices(void) 
{
   message += "test_get_generalization_indices\n";

   InstancesInformation ii;

   Vector<unsigned int> generalization_indices;

   generalization_indices = ii.get_generalization_indices();

   assert_true(generalization_indices.size() == 0, LOG);
   
   ii.set(1);

   generalization_indices = ii.get_generalization_indices();

   assert_true(generalization_indices.size() == 0, LOG);

}


// void test_count_testing_instances_number(void) method

void InstancesInformationTest::test_count_testing_instances_number(void) 
{
   message += "test_count_testing_instances_number\n";

   InstancesInformation ii;

   assert_true(ii.count_testing_instances_number() == 0, LOG);
   
   ii.set(1);

   assert_true(ii.count_testing_instances_number() == 0, LOG);

}


// void test_get_testing_indices(void) method

void InstancesInformationTest::test_get_testing_indices(void) 
{
   message += "test_get_testing_indices\n";
 
   InstancesInformation ii;

   Vector<unsigned int> testing_indices;

   testing_indices = ii.get_testing_indices();

   assert_true(testing_indices.size() == 0, LOG);
   
   ii.set(1);

   testing_indices = ii.get_testing_indices();

   assert_true(testing_indices.size() == 0, LOG);
}


// void test_get_display(void) method

void InstancesInformationTest::test_get_display(void) 
{
   message += "test_get_display\n";

   InstancesInformation ii;

   ii.set_display(true);

   assert_true(ii.get_display() == true, LOG);

   ii.set_display(false);

   assert_true(ii.get_display() == false, LOG);
}


// void test_set(void) method

void InstancesInformationTest::test_set(void) 
{
   message += "test_set\n";

   InstancesInformation ii;

   // Instances and inputs and target variables

   ii.set(1);

   assert_true(ii.get_instances_number() == 1, LOG);
}


// void test_set_instances_number(void) method

void InstancesInformationTest::test_set_instances_number(void) 
{
   message += "test_set_instances_number\n";

   InstancesInformation ii(1);

   ii.set_instances_number(2);

   assert_true(ii.get_instances_number() == 2, LOG);
}


// void test_set_training_indices(void) method

void InstancesInformationTest::test_set_training_indices(void)
{
   message += "test_set_training_indices\n";

   InstancesInformation ii(1);
  
   Vector<unsigned int> new_training_indices(1, 0);

   ii.set_training_indices(new_training_indices);

   Vector<unsigned int> training_indices = ii.get_training_indices();

   assert_true(training_indices == new_training_indices, LOG);

}


// void test_set_generalization_indices(void) method

void InstancesInformationTest::test_set_generalization_indices(void)
{
   message += "test_set_generalization_indices\n";

   InstancesInformation ii(1);

   Vector<unsigned int> new_generalization_indices(1, 0);

   ii.set_generalization_indices(new_generalization_indices);

   Vector<unsigned int> generalization_indices = ii.get_generalization_indices();

   assert_true(generalization_indices == new_generalization_indices, LOG);

}


// void test_set_testing_indices(void) method

void InstancesInformationTest::test_set_testing_indices(void)
{
   message += "test_set_testing_indices\n";

   InstancesInformation ii(1);

   Vector<unsigned int> new_testing_indices(1, 0);

   ii.set_testing_indices(new_testing_indices);

   Vector<unsigned int> testing_indices = ii.get_testing_indices();

   assert_true(testing_indices == new_testing_indices, LOG);

}


// void test_set_training(void) method

void InstancesInformationTest::test_set_training(void)
{
   message += "test_set_training\n";
   
   InstancesInformation ii(1);
   ii.set_training();

   assert_true(ii.count_training_instances_number() == 1, LOG);
   assert_true(ii.count_generalization_instances_number() == 0, LOG);
   assert_true(ii.count_testing_instances_number() == 0, LOG);

   assert_true(ii.get_training_indices() == 0, LOG);

}


// void test_set_generalization(void) method

void InstancesInformationTest::test_set_generalization(void)
{
   message += "test_set_generalization\n";

   InstancesInformation ii(1);
   ii.set_generalization();

   assert_true(ii.count_training_instances_number() == 0, LOG);
   assert_true(ii.count_generalization_instances_number() == 1, LOG);
   assert_true(ii.count_testing_instances_number() == 0, LOG);

   assert_true(ii.get_generalization_indices() == 0, LOG);

}


// void test_set_testing(void) method

void InstancesInformationTest::test_set_testing(void)
{
   message += "test_set_testing\n";

   InstancesInformation ii(1);
   ii.set_testing();

   assert_true(ii.count_training_instances_number() == 0, LOG);
   assert_true(ii.count_generalization_instances_number() == 0, LOG);
   assert_true(ii.count_testing_instances_number() == 1, LOG);

   assert_true(ii.get_testing_indices() == 0, LOG);

}


// void test_set_display(void) method

void InstancesInformationTest::test_set_display(void) 
{
   message += "test_set_display\n";
}


// void test_split_given_indices(void) method

void InstancesInformationTest::test_split_given_indices(void) 
{
   message += "test_split_given_indices\n";
   
   InstancesInformation ii(1);

   Vector<unsigned int> training_indices;
   Vector<unsigned int> generalization_indices;
   Vector<unsigned int> testing_indices(1, 1);

   ii.split_given_indices(training_indices, generalization_indices, testing_indices);

   assert_true(ii.count_training_instances_number() == 0, LOG);
   assert_true(ii.count_generalization_instances_number() == 0, LOG);
   assert_true(ii.count_testing_instances_number() == 1, LOG);

}


// void test_split_random_indices(void) method

void InstancesInformationTest::test_split_random_indices(void) 
{
   message += "test_split_random_indices\n";

   unsigned int training_instances_number = 0;
   unsigned int generalization_instances_number = 0;
   unsigned int testing_instances_number = 0;

   InstancesInformation ii(12);

   // All data for training

   ii.split_random_indices(1.0, 0.0, 0.0);
  
   training_instances_number = ii.count_training_instances_number();
   generalization_instances_number = ii.count_generalization_instances_number();
   testing_instances_number = ii.count_testing_instances_number();

   assert_true(training_instances_number == 12, LOG);
   assert_true(generalization_instances_number == 0, LOG);
   assert_true(testing_instances_number == 0, LOG);

   // All data for generalization 

   ii.split_random_indices(0.0, 10.0, 0.0);
  
   training_instances_number = ii.count_training_instances_number();
   generalization_instances_number = ii.count_generalization_instances_number();
   testing_instances_number = ii.count_testing_instances_number();

   assert_true(training_instances_number == 0, LOG);
   assert_true(generalization_instances_number == 12, LOG);
   assert_true(testing_instances_number == 0, LOG);

   // All data for testing 

   ii.split_random_indices(0.0, 0.0, 100.0);
  
   training_instances_number = ii.count_training_instances_number();
   generalization_instances_number = ii.count_generalization_instances_number();
   testing_instances_number = ii.count_testing_instances_number();

   assert_true(training_instances_number == 0, LOG);
   assert_true(generalization_instances_number == 0, LOG);
   assert_true(testing_instances_number == 12, LOG);

   // Split data for training, generalization and testing

   ii.split_random_indices(0.5, 0.25, 0.25);
  
   training_instances_number = ii.count_training_instances_number();
   generalization_instances_number = ii.count_generalization_instances_number();
   testing_instances_number = ii.count_testing_instances_number();

   assert_true(training_instances_number == 6, LOG);
   assert_true(generalization_instances_number == 3, LOG);
   assert_true(testing_instances_number == 3, LOG);

   // Split data for training, generalization and testing

   ii.split_random_indices(2.0, 1.0, 1.0);
  
   training_instances_number = ii.count_training_instances_number();
   generalization_instances_number = ii.count_generalization_instances_number();
   testing_instances_number = ii.count_testing_instances_number();

   assert_true(training_instances_number == 6, LOG);
   assert_true(generalization_instances_number == 3, LOG);
   assert_true(testing_instances_number == 3, LOG);

   // Test

   ii.set_instances_number(10);
   ii.split_random_indices();

   training_instances_number = ii.count_training_instances_number();
   generalization_instances_number = ii.count_generalization_instances_number();
   testing_instances_number = ii.count_testing_instances_number();

   assert_true(training_instances_number == 6, LOG);
   assert_true(generalization_instances_number == 2, LOG);
   assert_true(testing_instances_number == 2, LOG);

}


// void test_to_XML(void) method

void InstancesInformationTest::test_to_XML(void) 
{
   message += "test_to_XML\n";

   InstancesInformation ii;

   TiXmlElement* instances_information_element = ii.to_XML();

   assert_true(instances_information_element != NULL, LOG);
}


// void test_from_XML(void) method

void InstancesInformationTest::test_from_XML(void) 
{
   message += "test_from_XML\n";

   InstancesInformation ii;

   TiXmlElement* element = ii.to_XML();
   
   ii.from_XML(element);

}


// void run_test_case(void) method

void InstancesInformationTest::run_test_case(void)
{
   message += "Running instances information test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Assignment operators methods

   test_assignment_operator();

   // Get methods

   test_get_instances_number();

   // Instances methods 

   test_count_training_instances_number();
   test_get_training_indices();

   test_count_generalization_instances_number();
   test_get_generalization_indices();

   test_count_testing_instances_number();
   test_get_testing_indices();

   test_get_display();

   // Set methods

   test_set();

   // Instances methods

   test_set_training_indices();
   test_set_generalization_indices();
   test_set_testing_indices();

   test_set_training();
   test_set_generalization();
   test_set_testing();

   test_set_display();

   // Data methods

   test_set_instances_number();

   // Data splitting methods

   test_split_given_indices();
   test_split_random_indices();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   message += "End of instances information test case...\n";
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

