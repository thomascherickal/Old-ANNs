/****************************************************************************************************************/
/*                                                                                                              */ 
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   I R I S   P L A N T   A P P L I C A T I O N                                                                */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */  
/****************************************************************************************************************/

// This is a classical pattern recognition problem.

// System includes

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <time.h>

// OpenNN includes

#include "../../source/opennn.h"

using namespace OpenNN;

int main(void)
{
   try
   {
      std::cout << "OpenNN. Iris Plant Application." << std::endl;	

      srand((unsigned)time(NULL));

      // Data set 
  
      DataSet data_set;

      data_set.load_data("../data/iris_plant/iris_plant.dat");    

      // Variables information

      VariablesInformation* variables_information_pointer = data_set.get_variables_information_pointer(); 

	  const Vector<unsigned int> inputs_indices(0, 1, 3);
	  const Vector<unsigned int> targets_indices(4, 1, 6);

	  variables_information_pointer->set_inputs_indices(inputs_indices);
	  variables_information_pointer->set_targets_indices(targets_indices);

      variables_information_pointer->set_name(0, "sepal_length");
      variables_information_pointer->set_units(0, "centimeters");

      variables_information_pointer->set_name(1, "sepal_width");
      variables_information_pointer->set_units(1, "centimeters");

      variables_information_pointer->set_name(2, "petal_length");
      variables_information_pointer->set_units(2, "centimeters");

      variables_information_pointer->set_name(3, "petal_width");
      variables_information_pointer->set_units(3, "centimeters");

      variables_information_pointer->set_name(4, "iris_setosa");
      variables_information_pointer->set_name(5, "iris_versicolour");
      variables_information_pointer->set_name(6, "iris_virginica");	  

      const Vector< Vector<std::string> > inputs_targets_information = variables_information_pointer->arrange_inputs_targets_information();

	  // Instances information
    
      InstancesInformation* instances_information_pointer = data_set.get_instances_information_pointer(); 

      instances_information_pointer->split_random_indices(75.0, 0.0, 25.0);
   
      const Vector< Vector<double> > inputs_targets_statistics = data_set.scale_inputs_minimum_maximum();   

      // Neural network

      NeuralNetwork neural_network(4, 6, 3);

      neural_network.set_inputs_outputs_information(inputs_targets_information);
      
	  neural_network.set_inputs_outputs_statistics(inputs_targets_statistics);

	  ScalingLayer* scaling_layer_pointer = neural_network.get_scaling_layer_pointer();

      neural_network.set_scaling_unscaling_layers_flag(false);

      // Performance functional

      PerformanceFunctional performance_functional(&neural_network, &data_set);

      // Training strategy

      TrainingStrategy training_strategy(&performance_functional);

      TrainingStrategy::Results training_strategy_results = training_strategy.perform_training();

      scaling_layer_pointer->set_scaling_method(ScalingLayer::MeanStandardDeviation);

      // Pattern recognition testing
                  
      TestingAnalysis testing_analysis(&neural_network, &data_set);

	  testing_analysis.construct_pattern_recognition_testing();

	  PatternRecognitionTesting* pattern_recognition_testing_pointer = testing_analysis.get_pattern_recognition_testing_pointer();

      // Save results

      data_set.save("../data/iris_plant/data_set.xml");

      neural_network.save("../data/iris_plant/neural_network.xml");
      neural_network.save_expression("../data/iris_plant/expression.txt");   

	  training_strategy.save("../data/iris_plant/training_strategy.xml");
	  training_strategy_results.save("../data/iris_plant/training_strategy_results.dat");

      pattern_recognition_testing_pointer->save_confusion("../data/iris_plant/confusion.dat");

      return(0);
   }
   catch(std::exception& e)
   {
      std::cout << e.what() << std::endl;		 

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
