/****************************************************************************************************************/
/*                                                                                                              */ 
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   Y A C H T   R E S I S T A N C E   D E S I G N   A P P L I C A T I O N                                      */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */  
/****************************************************************************************************************/

// This is a function regression problem. 

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
      std::cout << "OpenNN. Yacht Resistance Design Application." << std::endl;	

      srand((unsigned)time(NULL));

      // Data set
  
      DataSet data_set;
	  
	  data_set.load_data("../data/yacht_resistance_design/delft.dat");

	  // Variables information

	  VariablesInformation* variables_information_pointer = data_set.get_variables_information_pointer();

	  variables_information_pointer->set_name(0, "longitudinal_center_buoyancy");
	  variables_information_pointer->set_name(1, "prismatic_coecient");
	  variables_information_pointer->set_name(2, "length_displacement_ratio");
	  variables_information_pointer->set_name(3, "beam_draught_ratio");
	  variables_information_pointer->set_name(4, "length_beam_ratio");
	  variables_information_pointer->set_name(5, "froude_number");
	  variables_information_pointer->set_name(6, "residuary_resistance");

      const Vector< Vector<std::string> > inputs_targets_information = variables_information_pointer->arrange_inputs_targets_information();

	  // Instances information

	  InstancesInformation* instances_information_pointer = data_set.get_instances_information_pointer();

      instances_information_pointer->split_random_indices();

      const Vector< Vector<double> > inputs_targets_statistics = data_set.scale_inputs_targets();  
  
      // Neural network

      const unsigned int inputs_number = data_set.get_variables_information().count_inputs_number();
      const unsigned int hidden_neurons_number = 9;
      const unsigned int outputs_number = data_set.get_variables_information().count_targets_number();

      NeuralNetwork neural_network(inputs_number, hidden_neurons_number, outputs_number);

	  neural_network.set_inputs_outputs_information(inputs_targets_information);
	  neural_network.set_inputs_outputs_statistics(inputs_targets_statistics);

	  neural_network.set_scaling_unscaling_layers_flag(false);

	  // Performance functional

      PerformanceFunctional performance_functional(&neural_network, &data_set);

	  // Training strategy 

	  TrainingStrategy training_strategy(&performance_functional);

      TrainingStrategy::Results training_strategy_results = training_strategy.perform_training();

	  neural_network.set_scaling_unscaling_layers_flag(true);

	  // Testing analysis
                  
      TestingAnalysis testing_analysis(&neural_network, &data_set);

	  FunctionRegressionTesting* function_regression_testing_pointer = testing_analysis.get_function_regression_testing_pointer();

	  FunctionRegressionTesting::LinearRegressionAnalysisResults linear_regression_analysis_results = function_regression_testing_pointer->perform_linear_regression_analysis();

      // Save results

      data_set.save("../data/yacht_resistance_design/neural_network.xml");

      neural_network.save("../data/yacht_resistance_design/neural_network.xml");
	  neural_network.save_expression("../data/yacht_resistance_design/expression.txt");

      training_strategy.save("../data/yacht_resistance_design/training_strategy.xml");
      training_strategy_results.save("../data/yacht_resistance_design/training_strategy_results.dat");

      linear_regression_analysis_results.save("../data/yacht_resistance_design/linear_regression_analysis_results.dat");

      return(0);
   }
   catch(std::exception& e)
   {
      std::cerr << e.what() << std::endl;

      return(1);
   }
}  
