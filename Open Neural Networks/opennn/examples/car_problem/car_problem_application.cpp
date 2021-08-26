/****************************************************************************************************************/
/*                                                                                                              */ 
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   C A R    A P P L I C A T I O N                                                                             */
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

#include "car.h"


using namespace OpenNN;

int main(void)
{
   std::cout << "OpenNN Exception: Car Problem Example\n"
             << "This example is under development." << std::endl;

   return(1);

/*
   try
   {
      std::cout << "OpenNN. Car Problem Application." << std::endl;

      srand((unsigned)time(NULL));

      // Problem parameters

      const double maximum_acceleration = 1.0;
      const double maximum_deceleration = 1.0;

      const double final_position = 1.0;
      const double final_velocity = 0.0;

      // Mathematical model

      Car car;

      // Neural network

      NeuralNetwork neural_network(1, 3, 2);
      {
         neural_network.initialize_parameters_normal(0.0, 0.1);

         // Inputs-outputs information

         neural_network.construct_inputs_outputs_information(); 

         InputsOutputsInformation* inputs_outputs_information_pointer = neural_network.get_inputs_outputs_information_pointer();

         inputs_outputs_information_pointer->set_input_name(0, "time");

         inputs_outputs_information_pointer->set_output_name(0, "throttle_acceleration");
         inputs_outputs_information_pointer->set_output_name(1, "bracking_deceleration");

         // Scaling layer

         neural_network.construct_scaling_layer();

         ScalingLayer* scaling_layer_pointer = neural_network.get_scaling_layer_pointer();

         scaling_layer_pointer->set_minimum(0, 0.0);

         neural_network.set_scaling_layer_flag(false);

         // Unscaling layer

         neural_network.construct_unscaling_layer();

         UnscalingLayer* unscaling_layer_pointer = neural_network.get_unscaling_layer_pointer();

         unscaling_layer_pointer->set_minimum(0, 0.0);
         unscaling_layer_pointer->set_maximum(0, maximum_acceleration);

         unscaling_layer_pointer->set_minimum(1, -maximum_deceleration);
         unscaling_layer_pointer->set_maximum(1, 0.0);

         neural_network.set_unscaling_layer_flag(true);

	 // Bounding layer

         neural_network.construct_bounding_layer();

         BoundingLayer* bounding_layer_pointer = neural_network.get_bounding_layer_pointer();

         bounding_layer_pointer->set_lower_bound(0, 0.0);
         bounding_layer_pointer->set_upper_bound(0, maximum_acceleration);

         bounding_layer_pointer->set_lower_bound(1, -maximum_deceleration);
         bounding_layer_pointer->set_upper_bound(1, 0.0);

         // Independent parameters

         neural_network.construct_independent_parameters();

         IndependentParameters* independent_parameters_pointer = neural_network.get_independent_parameters_pointer();

         independent_parameters_pointer->set_parameters_number(1); 
         independent_parameters_pointer->set_parameter(0, 3.1415927);

         independent_parameters_pointer->set_name(0, "final_time");   

         independent_parameters_pointer->set_lower_bound(0, 0.0);

         independent_parameters_pointer->set_bounding_flag(true);
      }

      // Performance functional 

      PerformanceFunctional performance_functional(&neural_network, &car);

      {
         // Objective term

         IndependentParametersError* independent_parameters_error = new IndependentParametersError(&neural_network);

         independent_parameters_error->set_independent_parameter_error_weight(0, 1.0e-3);

         performance_functional.set_objective_term_pointer(independent_parameters_error);

         Vector<double> parameters = neural_network.arrange_parameters();

         std::cout << independent_parameters_error->calculate_evaluation() << std::endl;
         std::cout << independent_parameters_error->calculate_evaluation(parameters) << std::endl;
         std::cout << independent_parameters_error->calculate_gradient() << std::endl;

         // Constraints term

         FinalSolutionsError* final_solutions_error = new FinalSolutionsError(&neural_network, &car);

         final_solutions_error->set_target_final_solution(0, final_position);
         final_solutions_error->set_target_final_solution(1, final_velocity);

         final_solutions_error->set_final_solution_error_weight(0, 1.0);
         final_solutions_error->set_final_solution_error_weight(1, 1.0);

         std::cout << final_solutions_error->calculate_evaluation() << std::endl;
         std::cout << final_solutions_error->calculate_evaluation(parameters) << std::endl;
         std::cout << final_solutions_error->calculate_gradient() << std::endl;

         performance_functional.set_constraints_term_pointer(final_solutions_error);

         std::cout << performance_functional.calculate_evaluation() << std::endl;
         std::cout << performance_functional.calculate_evaluation(parameters) << std::endl;
         std::cout << performance_functional.calculate_gradient() << std::endl;
      }

      // Training strategy

      TrainingStrategy training_strategy(&performance_functional);
      {
         training_strategy.construct_initialization_training_algorithm(TrainingStrategy::EVOLUTIONARY_ALGORITHM);

         training_strategy.construct_main_training_algorithm(TrainingStrategy::GRADIENT_DESCENT);
      }

      const TrainingStrategy::Results training_strategy_results = training_strategy.perform_training();

      const double final_time = neural_network.get_independent_parameters_pointer()->get_parameter(0);

      car.set_final_independent_variable(final_time);

      // Save results

      car.save("../data/car_problem/car.xml");
      car.save_data(neural_network, "../data/car_problem/car_data.dat");

      neural_network.save("../data/car_problem/neural_network.xml");
      neural_network.save_expression("../data/car_problem/expression.txt");
      neural_network.save_data("../data/car_problem/neural_network_data.dat");

      performance_functional.save("../data/car_problem/performance_functional.xml");

      training_strategy.save("../data/car_problem/training_strategy.xml");
      training_strategy_results.save("../data/car_problem/training_strategy_results.dat");

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
