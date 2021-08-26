/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   C A T E N A R Y   P R O B L E M   A P P L I C A T I O N                                                    */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

// This is a classical problem in the calculus of variations.

// System includes

#include <iostream>
#include <time.h>

// OpenNN includes

#include "../../source/opennn.h"

// Examples includes

#include "potential_energy.h"
#include "../geodesic_problem/arc_length.h"

using namespace OpenNN;

int main(void)
{
   std::cout << "OpenNN Exception: Catenary Problem Example\n"
             << "This example is under development." << std::endl;

   return(1);

/*
   try
   {
      std::cout << "OpenNN. Catenary Problem Application." << std::endl;	

      srand( (unsigned)time( NULL ) );

	  // Problem parameters

	  const double xa =  0.0;
	  const double ya =  1.0;

	  const double xb =  1.0;
	  const double yb =  1.0;

	  const double length = 1.5;

      // Mathematical models

      PotentialEnergy potential_energy;

	  potential_energy.set_initial_independent_variable(xa);
	  potential_energy.set_final_independent_variable(xb);

      ArcLength arc_length;

	  arc_length.set_initial_independent_variable(xa);
	  arc_length.set_final_independent_variable(xb);

      // Neural network

      NeuralNetwork neural_network(1, 3, 1);

	  {
         // Inputs-outputs information 

         neural_network.construct_inputs_outputs_information();

         InputsOutputsInformation* inputs_outputs_information_pointer = neural_network.get_inputs_outputs_information_pointer();
      
         inputs_outputs_information_pointer->set_input_name(0, "x");
         inputs_outputs_information_pointer->set_output_name(0, "y");

		 // Scaling layer

         neural_network.construct_scaling_layer();

         ScalingLayer* scaling_layer_pointer = neural_network.get_scaling_layer_pointer();

         scaling_layer_pointer->set_minimum(0, xa);
         scaling_layer_pointer->set_maximum(0, xb);

         neural_network.set_scaling_layer_flag(false);

		 // Unscaling layer

         neural_network.construct_unscaling_layer();

         UnscalingLayer* unscaling_layer_pointer = neural_network.get_unscaling_layer_pointer();

         unscaling_layer_pointer->set_minimum(0, 0.0);
         unscaling_layer_pointer->set_maximum(0, yb);

         neural_network.set_unscaling_layer_flag(false);

		 // Conditions layer

         neural_network.construct_conditions_layer();

         ConditionsLayer* conditions_layer_pointer = neural_network.get_conditions_layer_pointer();

	     conditions_layer_pointer->set_external_input_value(0, xa);
   	     conditions_layer_pointer->set_external_input_value(1, xb);

	     conditions_layer_pointer->set_output_value(0, 0, ya);
	     conditions_layer_pointer->set_output_value(0, 1, yb);

	     neural_network.set_conditions_layer_flag(true);

		 // Bounding layer 

		 neural_network.construct_bounding_layer();
   
		 BoundingLayer* bounding_layer_pointer = neural_network.get_bounding_layer_pointer();

		 bounding_layer_pointer->set_lower_bound(0, 0.0);
		 bounding_layer_pointer->set_upper_bound(0, 1.0);
	  }

      // Performance functional 

      PerformanceFunctional performance_functional(&neural_network);

	  {
         // Objective term

         FinalSolutionsError* final_solutions_error = new FinalSolutionsError(&neural_network, &potential_energy);

   	     final_solutions_error->set_final_solution_error_weight(0, 1.0);

         performance_functional.set_objective_term_pointer(final_solutions_error);

		 Vector<double> parameters = neural_network.arrange_parameters();

		 std::cout << final_solutions_error->calculate_evaluation() << std::endl;
		 std::cout << final_solutions_error->calculate_evaluation(parameters) << std::endl;
		 std::cout << final_solutions_error->calculate_gradient() << std::endl;

		 // Constratints term 

         FinalSolutionsError* constraints_term_pointer = new FinalSolutionsError(&neural_network, &arc_length);

		 constraints_term_pointer->set_target_final_solution(0, length);

         performance_functional.set_constraints_term_pointer(constraints_term_pointer);

		 std::cout << constraints_term_pointer->calculate_evaluation() << std::endl;
		 std::cout << constraints_term_pointer->calculate_evaluation(parameters) << std::endl;
		 std::cout << constraints_term_pointer->calculate_gradient() << std::endl;

		 std::cout << performance_functional.calculate_evaluation() << std::endl;
		 std::cout << performance_functional.calculate_evaluation(parameters) << std::endl;
		 std::cout << performance_functional.calculate_gradient() << std::endl;

	  }

      // Training strategy

      TrainingStrategy training_strategy(&performance_functional);

      TrainingStrategy::Results training_strategy_results = training_strategy.perform_training();

      // Save results 

      potential_energy.save("../data/catenary_problem/potential_energy.xml");
      potential_energy.load("../data/catenary_problem/potential_energy.xml");

      potential_energy.save_data(neural_network, "../data/catenary_problem/potential_energy_data.dat");

	  arc_length.save("../data/catenary_problem/arc_length.xml");
	  arc_length.load("../data/catenary_problem/arc_length.xml");

      arc_length.save_data(neural_network, "../data/catenary_problem/arc_length_data.dat");

      neural_network.save("../data/catenary_problem/neural_network.xml");
      neural_network.load("../data/catenary_problem/neural_network.xml");

      neural_network.save_data("../data/catenary_problem/neural_network_data.dat");
      neural_network.save_expression("../data/catenary_problem/expression.txt");

      performance_functional.save("../data/catenary_problem/performance_functional.xml");
      performance_functional.load("../data/catenary_problem/performance_functional.xml");

      training_strategy.save("../data/catenary_problem/training_strategy.xml");
      training_strategy.load("../data/catenary_problem/training_strategy.xml");
      training_strategy_results.save("../data/catenary_problem/training_strategy_results.xml");

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
