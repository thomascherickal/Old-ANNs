/****************************************************************************************************************/
/*                                                                                                              */ 
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   C A R   P R O B L E M   N E U R O C O M P U T I N G   A P P L I C A T I O N                                */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */  
/****************************************************************************************************************/

// This is a classical optimal control problem.

// System includes

#include <iostream>
#include <time.h>

// OpenNN includes

#include "../../source/opennn.h"

// Examples includes

#include "car_neurocomputing.h"


using namespace OpenNN;

int main(void)
{
   std::cout << "OpenNN Exception: Car Problem Neurocomputing Example\n"
             << "This example is under development." << std::endl;

   return(1);

/*
   try
   {
	  std::cout << "OpenNN. Car Problem Neurocomputing Application." << std::endl;

      srand((unsigned)time(NULL));

      // Problem parameters

	  double maximum_deceleration = -1.0;
	  double maximum_acceleration =  1.0;

      // Mathematical model

      CarNeurocomputing car_neurocomputing;
   
      car_neurocomputing.set_initial_independent_variable(0.0);
      car_neurocomputing.set_final_independent_variable(1.0);
   
      car_neurocomputing.set_initial_dependent_variable(0, 0.0);

      // Neural network

      NeuralNetwork neural_network(1, 3, 1);

	  {
		 neural_network.initialize_parameters_normal(0.0, 0.1);

         // Inputs outputs information

         neural_network.construct_inputs_outputs_information(); 

         InputsOutputsInformation* inputs_outputs_information_pointer = neural_network.get_inputs_outputs_information_pointer();

         inputs_outputs_information_pointer->set_input_name(0, "time");

         inputs_outputs_information_pointer->set_output_name(0, "acceleration");

		 // Conditions layer

		 // Bounding layer

         neural_network.construct_bounding_layer();

         BoundingLayer* bounding_layer_pointer = neural_network.get_bounding_layer_pointer();

         bounding_layer_pointer->set_lower_bound(0, maximum_deceleration);
         bounding_layer_pointer->set_upper_bound(0, maximum_acceleration);

         neural_network.set_bounding_layer_flag(true);

		 // Independent parameters

         neural_network.construct_independent_parameters();

         IndependentParameters* independent_parameters_pointer = neural_network.get_independent_parameters_pointer();

         independent_parameters_pointer->set_parameters_number(1); 

         independent_parameters_pointer->set_name(0, "final_time");   
         independent_parameters_pointer->set_lower_bound(0, 0.0);

         independent_parameters_pointer->set_parameter(0, 3.1415927);
	  }

      // Performance functional

      PerformanceFunctional performance_functional(&neural_network);

	  {
         // Objective term

		 IndependentParametersError* independent_parameters_error = new IndependentParametersError(&neural_network);

         independent_parameters_error->set_independent_parameter_error_weight(0, 1.0e-3);

         performance_functional.set_objective_term_pointer(independent_parameters_error);

		 Vector<double> parameters = neural_network.arrange_parameters();

		 // Constraints term

		 FinalSolutionsError* final_solutions_error_pointer = new FinalSolutionsError(&neural_network, &car_neurocomputing);

		 final_solutions_error_pointer->set_target_final_solution(0, 0.0);

		 final_solutions_error_pointer->set_final_solution_error_weight(0, 1.0);

		 performance_functional.set_constraints_term_pointer(final_solutions_error_pointer);

		 std::cout << final_solutions_error_pointer->calculate_evaluation() << std::endl;
		 std::cout << final_solutions_error_pointer->calculate_evaluation(parameters) << std::endl;
		 std::cout << final_solutions_error_pointer->calculate_gradient() << std::endl;
	  }

      // Training strategy

      TrainingStrategy training_strategy(&performance_functional);

	  {
		  // Initialization training algorithm

		  training_strategy.construct_initialization_training_algorithm(TrainingStrategy::RANDOM_SEARCH);

		  // Main training algorithm

		  training_strategy.construct_main_training_algorithm(TrainingStrategy::QUASI_NEWTON_METHOD);
	  }

      TrainingStrategy::Results training_strategy_results = training_strategy.perform_training();

	  const double final_time = neural_network.get_independent_parameters_pointer()->get_parameter(0);

	  car_neurocomputing.set_final_independent_variable(final_time);

      // Save results 

      car_neurocomputing.save_data(neural_network, "../data/car_problem_neurocomputing/car_neurocomputing_data.dat");

      neural_network.save("../data/car_problem_neurocomputing/neural_network.xml");
      neural_network.load("../data/car_problem_neurocomputing/neural_network.xml");

      neural_network.save_data("../data/car_problem_neurocomputing/neural_network_data.dat");
      neural_network.save_expression("../data/car_problem_neurocomputing/expression.txt");

      performance_functional.save("../data/car_problem_neurocomputing/performance_functional.xml");
      performance_functional.load("../data/car_problem_neurocomputing/performance_functional.xml");

	  training_strategy.save("../data/car_problem_neurocomputing/training_strategy.xml");
	  training_strategy.load("../data/car_problem_neurocomputing/training_strategy.xml");

	  training_strategy_results.save("../data/car_problem_neurocomputing/training_strategy_results.dat");

      return(0);
   }
   catch(std::exception& e)
   {
      std::cerr << e.what() << std::endl;

      return(1);
   }
*/
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