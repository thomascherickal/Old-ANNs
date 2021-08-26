/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   S I M P L E   C L A S S I F I C A T I O N   A P P L I C A T I O N                                          */
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
#include <sstream>
#include <time.h>
#include <stdexcept>

// OpenNN includes

#include "../../source/opennn.h"

using namespace OpenNN;

int main(void)
{
   try
   {
      std::cout << "OpenNN. Simple Pattern Recognition Application." << std::endl;

      srand( (unsigned)time( NULL ) );

      // Data set object

      DataSet data_set;
      data_set.load_data("../data/simple_pattern_recognition/simple_pattern_recognition.dat");

      VariablesInformation* variables_information_pointer = data_set.get_variables_information_pointer();

      variables_information_pointer->set_name(0, "x1");   
      variables_information_pointer->set_name(1, "x2");   
      variables_information_pointer->set_name(2, "y");   

      InstancesInformation* instances_information_pointer = data_set.get_instances_information_pointer();

      instances_information_pointer->split_random_indices(0.75, 0.0, 0.25);

      Vector< Vector<std::string> > variables_information = variables_information_pointer->arrange_inputs_targets_information();
   
      const Vector< Vector<double> > variables_statistics = data_set.scale_inputs();

      // Neural network object

      NeuralNetwork neural_network(2, 2, 1);

      neural_network.set_inputs_outputs_information(variables_information);
      neural_network.set_inputs_outputs_statistics(variables_statistics);

	  neural_network.set_scaling_layer_flag(false);

      // Performance functional
 
      PerformanceFunctional performance_functional(&neural_network, &data_set);

      // Training strategy

      TrainingStrategy training_strategy(&performance_functional);

	  TrainingStrategy::Results training_stategy_results = training_strategy.perform_training();

	  neural_network.set_scaling_layer_flag(true);

      // Testing analysis

      TestingAnalysis testing_analysis(&neural_network, &data_set);

	  testing_analysis.construct_pattern_recognition_testing();

	  PatternRecognitionTesting* pattern_recognition_testing_pointer = testing_analysis.get_pattern_recognition_testing_pointer();

      // Save results

      data_set.save("../data/simple_pattern_recognition/data_set.xml");
      data_set.load("../data/simple_pattern_recognition/data_set.xml");
   
      neural_network.save("../data/simple_pattern_recognition/neural_network.xml");
      neural_network.load("../data/simple_pattern_recognition/neural_network.xml");

      neural_network.save_expression("../data/simple_pattern_recognition/expression.txt");

      performance_functional.save("../data/simple_pattern_recognition/performance_functional.xml");
      performance_functional.load("../data/simple_pattern_recognition/performance_functional.xml");

      training_strategy.save("../data/simple_pattern_recognition/training_strategy.xml");
      training_strategy.load("../data/simple_pattern_recognition/training_strategy.xml");

      training_stategy_results.save("../data/simple_pattern_recognition/training_strategy_results.dat");

      pattern_recognition_testing_pointer->save_binary_classification_test("../data/simple_pattern_recognition/binary_classification_test.dat");
      pattern_recognition_testing_pointer->save_confusion("../data/simple_pattern_recognition/confusion.dat");

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
