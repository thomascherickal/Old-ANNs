/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   S I M P L E   F U N C T I O N   R E G R E S S I O N   A P P L I C A T I O N                                */
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
      std::cout << "OpenNN. Simple Function Regression Application." << std::endl;

      srand( (unsigned)time( NULL ) );

      // Data set object

      DataSet data_set;
      data_set.load_data("../data/simple_function_regression/simple_function_regression.dat");

	  VariablesInformation* variables_information_pointer = data_set.get_variables_information_pointer();

      variables_information_pointer->set_name(0,"x");   
      variables_information_pointer->set_name(1,"y");   

	  Vector< Vector<std::string> > inputs_targets_information = variables_information_pointer->arrange_inputs_targets_information();

	  InstancesInformation* instances_information_pointer = data_set.get_instances_information_pointer();

      instances_information_pointer->split_random_indices(0.75, 0.1, 0.25);
  
      const Vector< Vector<double> > inputs_targets_minimum_maximum = data_set.scale_inputs_targets_minimum_maximum();

      // Neural network

      NeuralNetwork neural_network(1, 3, 1);

      neural_network.set_inputs_outputs_information(inputs_targets_information);
      neural_network.set_inputs_outputs_minimums_maximums(inputs_targets_minimum_maximum);

      // Performance functional object
 
      PerformanceFunctional performance_functional(&neural_network, &data_set);

      // Training strategy

      TrainingStrategy training_strategy(&performance_functional);

	  training_strategy.perform_training();

	  neural_network.set_inputs_scaling_outputs_unscaling_methods("MeanStandardDeviation");

      // Testing analysis object

      TestingAnalysis testing_analysis(&neural_network, &data_set);

	  FunctionRegressionTesting::LinearRegressionAnalysisResults linear_regression_analysis_results = testing_analysis.get_function_regression_testing_pointer()->perform_linear_regression_analysis();
      
	  std::cout << "Linear regression parameters:\n" 
		        << "Intercept: " << linear_regression_analysis_results.linear_regression_parameters[0][0] << "\n"
				<< "Slope: " << linear_regression_analysis_results.linear_regression_parameters[0][1] << std::endl;

      // Save results

      data_set.save("../data/simple_function_regression/data_set.xml");

      neural_network.save("../data/simple_function_regression/neural_network.xml");
      neural_network.save_expression("../data/simple_function_regression/expression.txt");

      performance_functional.save("../data/simple_function_regression/performance_functional.xml");

      training_strategy.save("../data/simple_function_regression/training_strategy.xml");

	  linear_regression_analysis_results.save("../data/simple_function_regression/linear_regression_analysis_results.dat");

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
