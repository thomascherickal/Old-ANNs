/****************************************************************************************************************/
/*                                                                                                              */ 
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   P I M A   I N D I A N S   D I A B E T E S   A P P L I C A T I O N                                          */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */  
/****************************************************************************************************************/

// This is a pattern recognition problem.

// System includes

#include <iostream>
#include <time.h>

// OpenNN includes

#include "../../source/opennn.h"

using namespace OpenNN;

int main(void)
{
   try
   {
      std::cout << "OpenNN. Pima Indians Diabetes Application." << std::endl;	 

      srand((unsigned)time(NULL));

      // Data set 

      DataSet data_set;
      
	  data_set.load_data("../data/pima_indians_diabetes/pima_indians_diabetes.dat");

	  // Variables information

      VariablesInformation* variables_information_pointer = data_set.get_variables_information_pointer(); 

      variables_information_pointer->set_name(0, "pregnant");

      variables_information_pointer->set_name(1, "glucose");

      variables_information_pointer->set_name(2, "pressure");
      variables_information_pointer->set_units(2, "mmHg");

      variables_information_pointer->set_name(3, "thickness");
      variables_information_pointer->set_units(3, "mm");

      variables_information_pointer->set_name(4, "insulin");
      variables_information_pointer->set_units(4, "muU/ml");

      variables_information_pointer->set_name(5, "mass_index");
      variables_information_pointer->set_units(5, "kg/m2");

      variables_information_pointer->set_name(6, "pedigree");	  

      variables_information_pointer->set_name(7, "age");	  

      variables_information_pointer->set_name(8, "diabetes");	  

      const Vector< Vector<std::string> > inputs_targets_information = variables_information_pointer->arrange_inputs_targets_information();

	  // Instances information

      InstancesInformation* instances_information_pointer = data_set.get_instances_information_pointer();

      instances_information_pointer->split_random_indices(0.75, 0.0, 0.25);

      const Vector< Vector<double> > inputs_targets_statistics = data_set.scale_inputs_minimum_maximum();

	  //data_set.print_data();

      // Neural network 
	  
      NeuralNetwork neural_network(8, 6, 1);

      neural_network.set_inputs_outputs_information(inputs_targets_information); 
      neural_network.set_inputs_outputs_statistics(inputs_targets_statistics); 

	  neural_network.set_scaling_unscaling_layers_flag(false);

      // Performance functional

      PerformanceFunctional performance_functional(&neural_network, &data_set);

      // Training strategy

      TrainingStrategy training_strategy(&performance_functional);

      TrainingStrategy::Results training_strategy_results = training_strategy.perform_training();

	  neural_network.set_scaling_layer_flag(true);

      // Testing analysis

      TestingAnalysis testing_analysis(&neural_network, &data_set);

	  testing_analysis.construct_pattern_recognition_testing();

	  PatternRecognitionTesting* pattern_recognition_testing_pointer = testing_analysis.get_pattern_recognition_testing_pointer();

      // Save results

      data_set.save("../data/pima_indians_diabetes/data_set.xml");

      neural_network.save("../data/pima_indians_diabetes/neural_network.xml");
      neural_network.save_expression("../data/pima_indians_diabetes/expression.txt");

      training_strategy.save("../data/pima_indians_diabetes/training_strategy.xml");
      training_strategy_results.save("../data/pima_indians_diabetes/training_strategy_results.dat");

      pattern_recognition_testing_pointer->save_confusion("../data/pima_indians_diabetes/confusion.dat");   
      pattern_recognition_testing_pointer->save_binary_classification_test("../data/pima_indians_diabetes/binary_classification_test.dat");   

      return(0);
   }
   catch(std::exception& e)
   {
      std::cerr << e.what() << std::endl;

	  return(1);
   }
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
