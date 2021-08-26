/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   D A T A   S E T   T E S T   C L A S S                                                                      */
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

#include "data_set_test.h"

using namespace OpenNN;

// GENERAL CONSTRUCTOR

DataSetTest::DataSetTest(void) : UnitTesting() 
{
}



// DESTRUCTOR

DataSetTest::~DataSetTest(void)
{
}


// METHODS

// void test_constructor(void)
// @todo

void DataSetTest::test_constructor(void)
{
   message += "test_constructor\n";

   TiXmlElement* ep = NULL;

   // Default constructor

   DataSet ds1;

   assert_true(ds1.get_instances_number() == 0, LOG);
   assert_true(ds1.get_variables_number() == 0, LOG);

   // Instances and variables number constructor

   DataSet ds2(1, 1);

   assert_true(ds2.get_instances_number() == 1, LOG);
   assert_true(ds2.get_variables_number() == 1, LOG);

   // Instances, inputs and targets numbers constructor

   DataSet ds3(1, 1, 1);

   assert_true(ds3.get_instances_number() == 1, LOG);
   assert_true(ds3.get_variables_number() == 2, LOG);

   // XML constructor

   ep = ds3.to_XML();

   DataSet ds4(ep);

//   assert_true(ds4.get_instances_number() == 1, LOG);
//   assert_true(ds4.get_variables_number() == 2, LOG);

   // File constructor

//   ds4.save("../data/opennn_tests/data_set.xml");

//   DataSet ds5("../data/opennn_tests/data_set.xml");

//   assert_true(ds5.get_instances_number() == 1, LOG);
//   assert_true(ds5.get_variables_number() == 2, LOG);

   // Copy constructor

//   DataSet ds6(ds5);

//   assert_true(ds6.get_instances_number() == 1, LOG);
//   assert_true(ds5.get_variables_number() == 2, LOG);

}


// void test_destructor(void)

void DataSetTest::test_destructor(void)
{
   message += "test_destructor\n";

   DataSet* dsp = new DataSet(1, 1, 1);

   delete dsp;
}


// void test_assignment_operator(void) method

void DataSetTest::test_assignment_operator(void)
{
   message += "test_assignment_operator\n";

   DataSet ds1(1, 1, 1);
   DataSet ds2 = ds1;

   assert_true(ds2.get_instances_number() == 1, LOG);
   assert_true(ds2.get_variables_number() == 2, LOG);
}


// void test_get_instances_number(void) method

void DataSetTest::test_get_instances_number(void) 
{
   message += "test_get_instances_number\n";

   DataSet ds;

   assert_true(ds.get_instances_number() == 0, LOG);
}


// void test_get_variables_number(void) method

void DataSetTest::test_get_variables_number(void) 
{
   message += "test_get_variables_number\n";

   DataSet ds;

   assert_true(ds.get_variables_number() == 0, LOG);
}


// void test_get_variables_information(void) method

void DataSetTest::test_get_variables_information(void) 
{
   message += "test_get_variables_information\n";

   DataSet ds(1, 3, 2);

   const VariablesInformation& variables_information = ds.get_variables_information();

   assert_true(variables_information.count_inputs_number() == 3, LOG);
   assert_true(variables_information.count_targets_number() == 2, LOG);
}


// void test_get_display(void) method

void DataSetTest::test_get_display(void) 
{
   message += "test_get_display\n";

   DataSet ds;

   ds.set_display(true);

   assert_true(ds.get_display() == true, LOG);

   ds.set_display(false);

   assert_true(ds.get_display() == false, LOG);
}


// void test_get_data(void) method

void DataSetTest::test_get_data(void) 
{
   message += "test_get_data\n";

   DataSet ds(1,1,1);

   ds.initialize_data(0.0);

   const Matrix<double>& data = ds.get_data();

   assert_true(data.get_rows_number() == 1, LOG);
   assert_true(data.get_columns_number() == 2, LOG);
   assert_true(data == 0.0, LOG);
}


// void test_arrange_training_data(void) method

void DataSetTest::test_arrange_training_data(void)
{
   message += "test_arrange_training_data\n";
}


// void test_arrange_generalization_data(void) method

void DataSetTest::test_arrange_generalization_data(void)
{
   message += "test_arrange_generalization_data\n";
}


// void test_arrange_testing_data(void) method

void DataSetTest::test_arrange_testing_data(void)
{
   message += "test_arrange_testing_data\n";
}


// void test_arrange_input_data(void) method

void DataSetTest::test_arrange_input_data(void) 
{
   message += "test_arrange_input_data\n";

   DataSet ds(1, 3, 2);

   unsigned int instances_number = ds.get_instances_number();
   unsigned int inputs_number = ds.get_variables_information().count_inputs_number();

   Matrix<double> input_data = ds.arrange_input_data();

   unsigned int rows_number = input_data.get_rows_number();
   unsigned int columns_number = input_data.get_columns_number();

   assert_true(instances_number == rows_number, LOG);
   assert_true(inputs_number == columns_number, LOG);
}


// void test_arrange_target_data(void) method

void DataSetTest::test_arrange_target_data(void) 
{
   message += "test_arrange_target_data\n";

   DataSet ds(1,3,2);

   unsigned int instances_number = ds.get_instances_number();
   unsigned int targets_number = ds.get_variables_information().count_targets_number();

   Matrix<double> target_data = ds.arrange_target_data();

   unsigned int rows_number = target_data.get_rows_number();
   unsigned int columns_number = target_data.get_columns_number();

   assert_true(instances_number == rows_number, LOG);
   assert_true(targets_number == columns_number, LOG);
}


// void test_get_instance(void) method

void DataSetTest::test_get_instance(void)
{
   message += "test_get_instance\n";

   DataSet ds;
   Vector<double> instance;

   // Test

   ds.set(1, 1, 1);
   ds.initialize_data(1.0);

   instance = ds.get_instance(0);

   assert_true(instance.size() == 2, LOG);
   assert_true(instance == 1.0, LOG);
}


// void test_get_training_instance(void) method

void DataSetTest::test_get_training_instance(void)
{
   message += "test_get_training_instance\n";

   DataSet ds;
   Vector<double> training_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1,1,1);
   ds.initialize_data(0.0);
  
   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_training();

   training_instance = ds.get_training_instance(0);

   assert_true(training_instance.size() == 2, LOG);
   assert_true(training_instance == 0.0, LOG);
}


// void test_get_generalization_instance(void) method

void DataSetTest::test_get_generalization_instance(void)
{
   message += "test_get_generalization_instance\n";

   DataSet ds;
   Vector<double> generalization_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1,1,1);
   ds.initialize_data(0.0);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_generalization();

   generalization_instance = ds.get_generalization_instance(0);

   assert_true(generalization_instance.size() == 2, LOG);
   assert_true(generalization_instance == 0.0, LOG);
}


// void test_get_testing_instance(void) method

void DataSetTest::test_get_testing_instance(void)
{
   message += "test_get_testing_instance\n";

   DataSet ds;
   Vector<double> testing_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1, 1, 1);
   ds.initialize_data(0.0);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_testing();

   testing_instance = ds.get_testing_instance(0);

   assert_true(testing_instance.size() == 2, LOG);
   assert_true(testing_instance == 0.0, LOG);
}


// void test_get_input_instance(void) method

void DataSetTest::test_get_input_instance(void)
{
   message += "test_get_input_instance\n";

   DataSet ds;
   Vector<double> input_instance;

   // Test

   ds.set(1, 1, 1);

   ds.initialize_data(1.0);

   input_instance = ds.get_input_instance(0);

   assert_true(input_instance.size() == 1, LOG);
   assert_true(input_instance == 1.0, LOG);
}


// void test_get_target_instance(void) method

void DataSetTest::test_get_target_instance(void)
{
   message += "test_get_target_instance\n";

   DataSet ds;
   Vector<double> target_instance;

   // Test

   ds.set(1, 1, 1);

   ds.initialize_data(1.0);

   target_instance = ds.get_target_instance(0);

   assert_true(target_instance.size() == 1, LOG);
   assert_true(target_instance == 1.0, LOG);
}


// void test_get_training_input_instance(void) method

void DataSetTest::test_get_training_input_instance(void) 
{
   message += "test_get_training_input_instance\n";

   DataSet ds;
   Vector<double> training_input_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1, 1, 1);
   ds.initialize_data(0.0);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_training();

   training_input_instance = ds.get_training_input_instance(0);

   assert_true(training_input_instance.size() == 1, LOG);
   assert_true(training_input_instance == 0.0, LOG);
}


// void test_get_training_target_instance(void) method

void DataSetTest::test_get_training_target_instance(void) 
{
   message += "test_get_training_target_instance\n";

   DataSet ds;
   Vector<double> training_target_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1,1,1);
   ds.initialize_data(0.0);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_training();

   training_target_instance = ds.get_training_target_instance(0);

   assert_true(training_target_instance.size() == 1, LOG);
   assert_true(training_target_instance == 0.0, LOG);
}


// void test_get_generalization_input_instance(void) method

void DataSetTest::test_get_generalization_input_instance(void) 
{
   message += "test_get_generalization_input_instance\n";

   DataSet ds;
   Vector<double> generalization_input_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1, 1, 1);
   ds.initialize_data(0.0);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_generalization();

   generalization_input_instance = ds.get_generalization_input_instance(0);

   assert_true(generalization_input_instance.size() == 1, LOG);
   assert_true(generalization_input_instance == 0.0, LOG);
}


// void test_get_generalization_target_instance(void) method

void DataSetTest::test_get_generalization_target_instance(void) 
{
   message += "test_get_generalization_target_instance\n";

   DataSet ds;
   Vector<double> generalization_target_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1, 1, 1);
   ds.initialize_data(0.0);

   instances_information_pointer = ds.get_instances_information_pointer();
   
   instances_information_pointer->set_generalization();

   generalization_target_instance = ds.get_generalization_target_instance(0);

   assert_true(generalization_target_instance.size() == 1, LOG);
   assert_true(generalization_target_instance == 0.0, LOG);
}


// void test_get_testing_input_instance(void) method

void DataSetTest::test_get_testing_input_instance(void) 
{
   message += "test_get_testing_input_instance\n";

   DataSet ds;
   Vector<double> testing_input_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1,1,1);
   ds.initialize_data(0.0);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_testing();

   testing_input_instance = ds.get_testing_input_instance(0);

   assert_true(testing_input_instance.size() == 1, LOG);
   assert_true(testing_input_instance == 0.0, LOG);
}


// void test_get_testing_target_instance(void) method

void DataSetTest::test_get_testing_target_instance(void) 
{
   message += "test_get_testing_target_instance\n";

   DataSet ds;
   Vector<double> testing_target_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1, 1, 1);
   ds.initialize_data(0.0);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_testing();

   testing_target_instance = ds.get_testing_target_instance(0);

   assert_true(testing_target_instance.size() == 1, LOG);
   assert_true(testing_target_instance == 0.0, LOG);
}


// void test_set(void) method

void DataSetTest::test_set(void) 
{
   message += "test_set\n";

   DataSet ds;

   // Instances and inputs and target variables

   ds.set(1, 2, 3);

   assert_true(ds.get_instances_number() == 1, LOG);
   assert_true(ds.get_variables_information().count_inputs_number() == 2, LOG);
   assert_true(ds.get_variables_information().count_targets_number() == 3, LOG);

   const Matrix<double>& data = ds.get_data();

   assert_true(data.get_rows_number() == 1, LOG);
   assert_true(data.get_columns_number() == 5, LOG);
}


// void test_set_instances_number(void) method

void DataSetTest::test_set_instances_number(void) 
{
   message += "test_set_instances_number\n";

   DataSet ds(1,1,1);

   ds.set_instances_number(2);

   assert_true(ds.get_instances_number() == 2, LOG);
}


// void test_set_variables_number(void) method

void DataSetTest::test_set_variables_number(void) 
{
   message += "test_set_variables_number\n";

   DataSet ds(1,1);

   ds.set_variables_number(2);

   assert_true(ds.get_variables_number() == 2, LOG);
}


// void test_set_display(void) method

void DataSetTest::test_set_display(void) 
{
   message += "test_set_display\n";
}


// void test_set_data(void) method

void DataSetTest::test_set_data(void) 
{
   message += "test_set_data\n";

   DataSet ds(1, 1, 1);

   Matrix<double> new_data(1, 2, 0.0);

   ds.set_data(new_data);

   Matrix<double> data = ds.get_data();

   assert_true(data == new_data, LOG);
}


// void test_set_instance(void) method

void DataSetTest::test_set_instance(void)
{
   message += "test_set_instance\n";

   DataSet ds(1, 1, 1);

   Vector<double> new_instance(2, 0.0);

   ds.set_instance(0, new_instance);

   Vector<double> instance = ds.get_instance(0);

   assert_true(instance == new_instance, LOG);
}


// void test_set_training_instance(void) method

void DataSetTest::test_set_training_instance(void)
{
   message += "test_set_training_instance\n";

   DataSet ds;
   Vector<double> new_training_instance;
   Vector<double> training_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1,1,1);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_training();

   new_training_instance.set(2, 0.0);

   ds.set_training_instance(0, new_training_instance);

   training_instance = ds.get_training_instance(0);

   assert_true(training_instance == new_training_instance, LOG);
}


// void test_set_generalization_instance(void) method

void DataSetTest::test_set_generalization_instance(void)
{
   message += "test_set_generalization_instance\n";

   DataSet ds;
   Vector<double> new_generalization_instance;
   Vector<double> generalization_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1,1,1);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_generalization();

   new_generalization_instance.set(2, 0.0);

   ds.set_generalization_instance(0, new_generalization_instance);

   generalization_instance = ds.get_generalization_instance(0);

   assert_true(generalization_instance == new_generalization_instance, LOG);
}


// void test_set_testing_instance(void) method

void DataSetTest::test_set_testing_instance(void)
{
   message += "test_set_testing_instance\n";

   DataSet ds;
   Vector<double> new_testing_instance;
   Vector<double> testing_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1, 1, 1);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_testing();

   new_testing_instance.set(2, 0.0);

   ds.set_testing_instance(0, new_testing_instance);

   testing_instance = ds.get_testing_instance(0);

   assert_true(testing_instance == new_testing_instance, LOG);
}


// void test_set_input_instance(void)

void DataSetTest::test_set_input_instance(void)
{
   message += "test_set_input_instance\n";
}


// void test_set_target_instance(void)

void DataSetTest::test_set_target_instance(void)
{
   message += "test_set_target_instance\n";
}


// void test_set_training_input_instance(void) method

void DataSetTest::test_set_training_input_instance(void)
{
   message += "test_set_training_input_instance\n";

   DataSet ds;
   Vector<double> new_training_input_instance;
   Vector<double> training_input_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1, 1, 1);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_training();

   new_training_input_instance.set(1, 0.0);

   ds.set_training_input_instance(0, new_training_input_instance);

   training_input_instance = ds.get_training_input_instance(0);

   assert_true(training_input_instance == new_training_input_instance, LOG);
}


// void test_set_training_target_instance(void) method

void DataSetTest::test_set_training_target_instance(void)
{
   message += "test_set_training_target_instance\n";

   DataSet ds;

   Vector<double> new_training_target_instance;
   Vector<double> training_target_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1, 1, 1);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_training();

   new_training_target_instance.set(1, 0.0);

   ds.set_training_target_instance(0, new_training_target_instance);

   training_target_instance = ds.get_training_target_instance(0);

   assert_true(training_target_instance == new_training_target_instance, LOG);
}


// void test_set_generalization_input_instance(void) method

void DataSetTest::test_set_generalization_input_instance(void)
{
   message += "test_set_generalization_input_instance\n";

   DataSet ds;
   Vector<double> new_generalization_input_instance;
   Vector<double> generalization_input_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1, 1, 1);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_generalization();

   new_generalization_input_instance.set(1, 0.0);

   ds.set_generalization_input_instance(0, new_generalization_input_instance);

   generalization_input_instance = ds.get_generalization_input_instance(0);

   assert_true(generalization_input_instance == new_generalization_input_instance, LOG);
}


// void test_set_generalization_target_instance(void) method

void DataSetTest::test_set_generalization_target_instance(void)
{
   message += "test_set_generalization_target_instance\n";

   DataSet ds;
   Vector<double> new_generalization_target_instance;
   Vector<double> generalization_target_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1, 1, 1);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_generalization();

   new_generalization_target_instance.set(1, 0.0);

   ds.set_generalization_target_instance(0, new_generalization_target_instance);

   generalization_target_instance = ds.get_generalization_target_instance(0);

   assert_true(generalization_target_instance == new_generalization_target_instance, LOG);
}


// void test_set_testing_input_instance(void) method

void DataSetTest::test_set_testing_input_instance(void)
{
   message += "test_set_testing_input_instance\n";

   DataSet ds;

   Vector<double> new_testing_input_instance;
   Vector<double> testing_input_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1, 1, 1);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_testing();

   new_testing_input_instance.set(1, 0.0);

   ds.set_testing_input_instance(0, new_testing_input_instance);

   testing_input_instance = ds.get_testing_input_instance(0);

   assert_true(testing_input_instance == new_testing_input_instance, LOG);
}


// void test_set_testing_target_instance(void) method

void DataSetTest::test_set_testing_target_instance(void)
{
   message += "test_set_testing_target_instance\n";

   DataSet ds;

   Vector<double> new_testing_target_instance;
   Vector<double> testing_target_instance;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(1, 1, 1);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_testing();

   new_testing_target_instance.set(1, 0.0);

   ds.set_testing_target_instance(0, new_testing_target_instance);

   testing_target_instance = ds.get_testing_target_instance(0);

   assert_true(testing_target_instance == new_testing_target_instance, LOG);
}


// void test_add_instance(void) method

void DataSetTest::test_add_instance(void) 
{
   message += "test_add_instance\n";

   DataSet ds(1,1,1);

   Vector<double> new_instance(2, 0.0);

   ds.add_instance(new_instance);

   assert_true(ds.get_instances_number() == 2, LOG);

   Vector<double> instance = ds.get_instance(1);

   assert_true(instance == new_instance, LOG);
}


// void test_subtract_instance(void) method

void DataSetTest::test_subtract_instance(void) 
{
   message += "test_subtract_instance\n";

   DataSet ds(3, 1, 1);

   ds.subtract_instance(1);

   assert_true(ds.get_instances_number() == 2, LOG);
}


// void test_calculate_data_statistics(void) method

void DataSetTest::test_calculate_data_statistics(void) 
{
   message += "test_calculate_data_statistics\n";

   DataSet ds(2,2,2);
   ds.initialize_data(0.0);

   Vector< Vector<double> > statistics = ds.calculate_data_statistics();

   assert_true(statistics.size() == 4, LOG);
   assert_true(statistics[0] == 0.0, LOG);
   assert_true(statistics[1] == 0.0, LOG);
   assert_true(statistics[2] == 0.0, LOG);
   assert_true(statistics[3] == 0.0, LOG);
}


// void test_calculate_training_instances_statistics(void)

void DataSetTest::test_calculate_training_instances_statistics(void)
{
   message += "test_calculate_training_instances_statistics\n";

   DataSet ds;
   Vector< Vector<double> > training_instances_statistics;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(2, 2, 2);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_training();

   ds.initialize_data(0.0);

   ds.calculate_training_instances_statistics();

}


// void test_calculate_generalization_instances_statistics(void)

void DataSetTest::test_calculate_generalization_instances_statistics(void)
{
   message += "test_calculate_generalization_instances_statistics\n";

   DataSet ds;
   Vector< Vector<double> > generalization_instances_statistics;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(2,2,2);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_generalization();

   ds.initialize_data(0.0);

   generalization_instances_statistics = ds.calculate_generalization_instances_statistics();
}


// void test_calculate_testing_instances_statistics(void)

void DataSetTest::test_calculate_testing_instances_statistics(void)
{
   message += "test_calculate_testing_instances_statistics\n";

   DataSet ds;
   Vector< Vector<double> > testing_instances_statistics;

   InstancesInformation* instances_information_pointer;

   // Test

   ds.set(2, 2, 2);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->set_testing();
   
   ds.initialize_data(0.0);

   testing_instances_statistics = ds.calculate_testing_instances_statistics();
}


// void test_calculate_instances_statistics(void) method

void DataSetTest::test_calculate_instances_statistics(void)
{
   message += "test_calculate_instances_statistics\n";

   DataSet ds;

   Vector< Vector<double> > instances_statistics;

   InstancesInformation* instances_information_pointer;

   // Teset

   ds.set(6, 2, 2);

   instances_information_pointer = ds.get_instances_information_pointer();
   instances_information_pointer->split_random_indices(2, 2, 2);

   ds.initialize_data(0.0);

   instances_statistics = ds.calculate_instances_statistics();
}


// void test_calculate_input_variables_statistics(void)

void DataSetTest::test_calculate_input_variables_statistics(void)
{
   message += "test_calculate_input_variables_statistics\n";
}


// void test_calculate_targets_statistics(void)

void DataSetTest::test_calculate_targets_statistics(void)
{
   message += "test_calculate_targets_statistics\n";
}


// void test_calculate_variables_statistics(void)

void DataSetTest::test_calculate_variables_statistics(void)
{
   message += "test_calculate_variables_statistics\n";
}


// void test_scale_data_mean_standard_deviation(void) method

void DataSetTest::test_scale_data_mean_standard_deviation(void)  
{
   message += "test_scale_data_mean_standard_deviation\n";
}


// void test_scale_data_minimum_maximum(void) method

void DataSetTest::test_scale_data_minimum_maximum(void) 
{
   message += "test_scale_data_minimum_maximum\n";
}


// void test_scale_inputs_mean_standard_deviation(void) method

void DataSetTest::test_scale_inputs_mean_standard_deviation(void) 
{
   message += "test_scale_inputs_mean_standard_deviation\n";

   DataSet ds(2, 2, 2);
   ds.initialize_data(0.0);

   ds.set_display(false);

   Matrix<double> input_data = ds.arrange_input_data();

   Vector<double> mean(2, 0.0);
   Vector<double> standard_deviation(2, 1.0);

   ds.scale_inputs_mean_standard_deviation(mean, standard_deviation);

   Matrix<double> new_input_data = ds.arrange_input_data();

   assert_true(new_input_data == input_data, LOG);

}


// void test_scale_targets_mean_standard_deviation(void) method

void DataSetTest::test_scale_targets_mean_standard_deviation(void) 
{
   message += "test_scale_targets_mean_standard_deviation\n";

   DataSet ds(2,2,2);
   ds.initialize_data(0.0);

   ds.set_display(false);

   Matrix<double> target_data = ds.arrange_target_data();

   Vector<double> mean(2, 0.0);
   Vector<double> standard_deviation(2, 1.0);

   ds.scale_targets_mean_standard_deviation(mean, standard_deviation);

   Matrix<double> new_target_data = ds.arrange_target_data();

   assert_true(new_target_data == target_data, LOG);
}


// void test_scale_inputs_minimum_maximum(void) method

void DataSetTest::test_scale_inputs_minimum_maximum(void) 
{
   message += "test_scale_inputs_minimum_maximum\n";

   DataSet ds(2, 2, 2);
   ds.initialize_data(0.0);

   ds.set_display(false);

   Matrix<double> input_data = ds.arrange_input_data();

   Vector<double> minimum(2, -1.0);
   Vector<double> maximum(2,  1.0);

   ds.scale_inputs_minimum_maximum(minimum, maximum);

   Matrix<double> new_input_data = ds.arrange_input_data();

   assert_true(new_input_data == input_data, LOG);
}


// void test_scale_targets_minimum_maximum(void) method

void DataSetTest::test_scale_targets_minimum_maximum(void) 
{
   message += "test_scale_targets_minimum_maximum\n";

   DataSet ds(2,2,2);
   ds.initialize_data(0.0);

   ds.set_display(false);

   Matrix<double> target_data = ds.arrange_target_data();

   Vector<double> minimum(2, -1.0);
   Vector<double> maximum(2,  1.0);

   ds.scale_targets_minimum_maximum(minimum, maximum);

   Matrix<double> new_target_data = ds.arrange_target_data();

   assert_true(new_target_data == target_data, LOG);
}


// void test_scale_variables_mean_standard_deviation(void) method

void DataSetTest::test_scale_variables_mean_standard_deviation(void) 
{
   message += "test_scale_variables_mean_standard_deviation\n";
  
   DataSet ds(2, 2, 2);
   ds.initialize_data(0.0);

   ds.set_display(false);

   Matrix<double> data = ds.get_data();

   Vector< Vector<double> > statistics = ds.scale_inputs_targets_mean_standard_deviation();

   Matrix<double> new_data = ds.get_data();
   
   assert_true(statistics.size() == 8, LOG);
   assert_true(new_data == data, LOG);
}


// void test_scale_variables_minimum_maximum(void) method

void DataSetTest::test_scale_variables_minimum_maximum(void) 
{
   message += "test_scale_variables_minimum_maximum\n";
   
   DataSet ds(2,2,2);
   ds.initialize_data(0.0);

   ds.set_display(false);

   Matrix<double> data = ds.get_data();

   Vector< Vector<double> > variables_minimum_maximum = ds.scale_inputs_targets_minimum_maximum();

   Matrix<double> new_data = ds.get_data();
   
   assert_true(variables_minimum_maximum.size() == 8, LOG);
   assert_true(new_data == data, LOG);
}


// void test_unscale_data_mean_standard_deviation(void) method

void DataSetTest::test_unscale_data_mean_standard_deviation(void)
{
   message += "test_unscale_data_mean_standard_deviation\n";
}


// void test_unscale_data_minimum_maximum(void) method

void DataSetTest::test_unscale_data_minimum_maximum(void)
{
   message += "test_unscale_data_minimum_maximum\n";
}


// void test_unscale_inputs_mean_standard_deviation(void) method

void DataSetTest::test_unscale_inputs_mean_standard_deviation(void) 
{
   message += "test_unscale_inputs_mean_standard_deviation\n";
   
   DataSet ds(2, 2, 2);
   ds.initialize_data(0.0);

   ds.set_display(false);

   Matrix<double> input_data = ds.arrange_input_data();

   Vector<double> mean(2, 0.0);
   Vector<double> standard_deviation(2, 1.0);

   ds.unscale_inputs_mean_standard_deviation(mean, standard_deviation);

   Matrix<double> new_input_data = ds.arrange_input_data();

   assert_true(new_input_data == input_data, LOG);
}


// void test_unscale_targets_mean_standard_deviation(void) method

void DataSetTest::test_unscale_targets_mean_standard_deviation(void) 
{
   message += "test_unscale_targets_mean_standard_deviation\n";
   
   DataSet ds(2, 2, 2);
   ds.initialize_data(0.0);

   ds.set_display(false);

   Matrix<double> target_data = ds.arrange_target_data();

   Vector<double> mean(2, 0.0);
   Vector<double> standard_deviation(2, 1.0);

   ds.unscale_targets_mean_standard_deviation(mean, standard_deviation);

   Matrix<double> new_target_data = ds.arrange_target_data();

   assert_true(new_target_data == target_data, LOG);
}


// void test_unscale_variables_mean_standard_deviation(void) method

void DataSetTest::test_unscale_variables_mean_standard_deviation(void) 
{
   message += "test_unscale_variables_mean_standard_deviation\n";
}


// void test_unscale_inputs_minimum_maximum(void) method

void DataSetTest::test_unscale_inputs_minimum_maximum(void) 
{
   message += "test_unscale_inputs_minimum_maximum\n"; 
}


// void test_unscale_targets_minimum_maximum(void) method

void DataSetTest::test_unscale_targets_minimum_maximum(void) 
{
   message += "test_unscale_targets_minimum_maximum\n";
   
   DataSet ds(2, 2, 2);
   ds.initialize_data(0.0);

   ds.set_display(false);

   Matrix<double> target_data = ds.arrange_target_data();

   Vector<double> minimum(2, -1.0);
   Vector<double> maximum(2,  1.0);

   ds.unscale_targets_minimum_maximum(minimum, maximum);

   Matrix<double> new_target_data = ds.arrange_target_data();

   assert_true(new_target_data == target_data, LOG);
}


// void test_unscale_variables_minimum_maximum(void) method

void DataSetTest::test_unscale_variables_minimum_maximum(void) 
{
   message += "test_unscale_variables_minimum_maximum\n"; 
}


// void test_initialize_data(void) method

void DataSetTest::test_initialize_data(void)
{
   message += "test_initialize_data\n";
}


// void test_to_XML(void) method

void DataSetTest::test_to_XML(void) 
{
   message += "test_to_XML\n";

   DataSet ds;

   TiXmlElement* data_set_element = ds.to_XML();

   assert_true(data_set_element != NULL, LOG);
}


// void test_from_XML(void) method

void DataSetTest::test_from_XML(void) 
{
   message += "test_from_XML\n";

   DataSet ds;

   TiXmlElement* ep;
   
   // Test

   ep = ds.to_XML();

   ds.from_XML(ep);



}


// void test_print(void) method

void DataSetTest::test_print(void) 
{
   message += "test_print\n";

   DataSet ds;

   ds.set_display(false);

   ds.print();
}


// void test_save(void) method

void DataSetTest::test_save(void) 
{
   message += "test_save\n";
 
   DataSet ds;

   ds.set_display(false);

   ds.save("../data/opennn_tests/data_set.xml");
}


// void test_load(void) method

void DataSetTest::test_load(void) 
{
   message += "test_load\n";

   DataSet ds;
   DataSet ds_copy;

   Matrix<double> data;

   // Test

   ds.set();

   ds.save("../data/opennn_tests/data_set.xml");
   ds.load("../data/opennn_tests/data_set.xml");

   // Test;

   ds.set();

   data.set(1, 2, 0.0);

   data.save("../data/opennn_tests/data.dat");

   ds.set_data_filename("../data/opennn_tests/data.dat");

   ds.get_variables_information_pointer()->set_name(0, "x");
   ds.get_variables_information_pointer()->set_units(0, "[m]");
   ds.get_variables_information_pointer()->set_description(0, "distance");

   ds.get_variables_information_pointer()->set_name(1, "y");
   ds.get_variables_information_pointer()->set_units(1, "[s]");
   ds.get_variables_information_pointer()->set_description(1, "time");

   ds.save("../data/opennn_tests/data_set.xml");
   ds_copy.load("../data/opennn_tests/data_set.xml");

   assert_true(ds_copy.get_variables_number() == 2, LOG);
   assert_true(ds_copy.get_instances_number() == 1, LOG);

   assert_true(ds_copy.get_variables_information_pointer()->get_name(0) == "x", LOG);
   assert_true(ds_copy.get_variables_information_pointer()->get_unit(0) == "[m]", LOG);
   assert_true(ds_copy.get_variables_information_pointer()->get_description(0) == "distance", LOG);

   assert_true(ds_copy.get_variables_information_pointer()->get_name(1) == "y", LOG);
   assert_true(ds_copy.get_variables_information_pointer()->get_unit(1) == "[s]", LOG);
   assert_true(ds_copy.get_variables_information_pointer()->get_description(1) == "time", LOG);
}


// void test_print_data(void) method

void DataSetTest::test_print_data(void)
{
   message += "test_print_data\n";
}


// void test_save_data(void) method

void DataSetTest::test_save_data(void)
{
   message += "test_save_data\n";

   DataSet ds(2,2,2);

   ds.set_display(false);

   ds.save_data("../data/opennn_tests/data.dat");
}


// void test_load_data(void) method

void DataSetTest::test_load_data(void) 
{
   message += "test_load_data\n";
 
   DataSet ds(2, 2, 2);

   ds.initialize_data(0.0);

   ds.set_display(false);

   ds.save_data("../data/opennn_tests/data_set.dat");

   ds.load_data("../data/opennn_tests/data_set.dat");

   Matrix<double> data = ds.get_data();

   assert_true(ds.get_data() == 0.0, LOG);
}


// void test_get_data_statistics(void) method

void DataSetTest::test_get_data_statistics(void)
{
   message += "test_get_data_statistics\n";

   DataSet ds(1,1,1);
}


// void test_print_data_statistics(void) method

void DataSetTest::test_print_data_statistics(void)
{
   message += "test_print_data_statistics\n";
}


// void test_get_training_instances_statistics(void) method

void DataSetTest::test_get_training_instances_statistics(void)
{
   message += "test_get_training_instances_statistics\n";

}


// void test_save_training_instances_statistics(void) method

void DataSetTest::test_save_training_instances_statistics(void)
{
   message += "test_save_training_instances_statistics\n";
}


// void test_print_training_instances_statistics(void) method

void DataSetTest::test_print_training_instances_statistics(void)
{
   message += "test_print_training_instances_statistics\n";
}


// void test_get_generalization_instances_statistics(void) method

void DataSetTest::test_get_generalization_instances_statistics(void)
{
   message += "test_get_generalization_instances_statistics\n";
}


// void test_save_generalization_instances_statistics(void) method

void DataSetTest::test_save_generalization_instances_statistics(void)
{
   message += "test_save_generalization_instances_statistics\n";
}


// void test_print_generalization_instances_statistics(void) method

void DataSetTest::test_print_generalization_instances_statistics(void)
{
   message += "test_print_generalization_instances_statistics\n";
}


// void test_get_testing_instances_statistics(void) method

void DataSetTest::test_get_testing_instances_statistics(void)
{
   message += "test_get_testing_instances_statistics\n";
}


// void test_save_testing_instances_statistics(void) method

void DataSetTest::test_save_testing_instances_statistics(void)
{
   message += "test_save_testing_instances_statistics\n";
}


// void test_print_testing_instances_statistics(void) method

void DataSetTest::test_print_testing_instances_statistics(void)
{
   message += "test_print_testing_instances_statistics\n";
}


// void test_get_instances_statistics(void) method

void DataSetTest::test_get_instances_statistics(void)
{
   message += "test_get_instances_statistics\n";
}


// void test_save_instances_statistics(void) method

void DataSetTest::test_save_instances_statistics(void)
{
   message += "test_save_instances_statistics\n";
}


// void test_print_instances_statistics(void) method

void DataSetTest::test_print_instances_statistics(void)
{
   message += "test_print_instances_statistics\n";
}


// void run_test_case(void) method

void DataSetTest::run_test_case(void)
{
   message += "Running data set test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Assignment operators methods

   test_assignment_operator();

   // Get methods

   test_get_instances_number();
   test_get_variables_number();
 
   test_get_variables_information();

   test_get_display();

   // Data methods

   test_get_data();

   test_arrange_training_data();
   test_arrange_generalization_data();
   test_arrange_testing_data();

   test_arrange_input_data();
   test_arrange_target_data();

   // Instance methods

   test_get_instance();

   test_get_training_instance();
   test_get_generalization_instance();
   test_get_testing_instance();

   test_get_input_instance();
   test_get_target_instance();

   test_get_training_input_instance();
   test_get_training_target_instance();

   test_get_generalization_input_instance();
   test_get_generalization_target_instance();

   test_get_testing_target_instance();
   test_get_testing_input_instance();

   // Set methods

   test_set();

   test_set_display();

   // Data methods

   test_set_data();

   test_set_instances_number();
   test_set_variables_number();

   // Instance methods

   test_set_instance();

   test_set_training_instance();
   test_set_generalization_instance();
   test_set_testing_instance();

   test_set_input_instance();
   test_set_target_instance();

   test_set_training_input_instance();
   test_set_training_target_instance();
   
   test_set_generalization_target_instance();
   test_set_generalization_input_instance();

   test_set_testing_input_instance();
   test_set_testing_target_instance();

   // Data resizing methods

   test_add_instance();
   test_subtract_instance();

   // Initialization methods

   test_initialize_data();

   // Statistics methods

   test_calculate_data_statistics();

   test_calculate_training_instances_statistics();
   test_calculate_generalization_instances_statistics();
   test_calculate_testing_instances_statistics();

   test_calculate_instances_statistics();

   test_calculate_input_variables_statistics();
   test_calculate_targets_statistics();
  
   test_calculate_variables_statistics();

   // Data scaling

   test_scale_data_mean_standard_deviation();  
   test_scale_data_minimum_maximum(); 

   // Input variables scaling

   test_scale_inputs_mean_standard_deviation();
   test_scale_inputs_minimum_maximum();

   // Target variables scaling

   test_scale_targets_mean_standard_deviation();
   test_scale_targets_minimum_maximum();

   // Input-target variables scaling

   test_scale_variables_mean_standard_deviation();
   test_scale_variables_minimum_maximum();

   // Data unscaling

   test_unscale_data_mean_standard_deviation();
   test_unscale_data_minimum_maximum();

   // Input variables unscaling

   test_unscale_inputs_mean_standard_deviation();
   test_unscale_inputs_minimum_maximum();

   // Target variables unscaling

   test_unscale_targets_mean_standard_deviation();
   test_unscale_targets_minimum_maximum();

   // Input-target variables unscaling

   test_unscale_variables_mean_standard_deviation();
   test_unscale_variables_minimum_maximum();

   // Serialization methods

   test_to_XML();
   test_from_XML();

   test_print();
   test_save();
   test_load();

   test_print_data();
   test_save_data();
   test_load_data();

   test_get_data_statistics();
   test_print_data_statistics();

   test_get_training_instances_statistics();
   test_print_training_instances_statistics();
   test_save_training_instances_statistics();

   test_get_generalization_instances_statistics();
   test_print_generalization_instances_statistics();
   test_save_generalization_instances_statistics();

   test_get_testing_instances_statistics();
   test_print_testing_instances_statistics();
   test_save_testing_instances_statistics();

   test_get_instances_statistics();
   test_print_instances_statistics();
   test_save_instances_statistics();

   message += "End of data set test case...\n";
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

