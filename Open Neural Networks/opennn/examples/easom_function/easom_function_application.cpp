/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   E A S O M   F U N C T I O N   A P P L I C A T I O N                                                        */
/*                                                                                                              */
/*   Gilles Cadose                                                                                              */
/*   Carlos Vargas de la Fuente                                                                                 */
/*   Hebert Sotelo Aedo                                                                                         */
/*                                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*                                                                                                              */
/****************************************************************************************************************/

// This is a benchmark function optimization problem.

// System includes

#include <iostream>
#include <time.h>
#include <stdexcept>

// OpenNN includes

#include "../../source/opennn.h"

// Examples includes

#include "easom_function.h"


using namespace OpenNN;

int main(void)
{
   std::cout << "OpenNN Exception: Easom Function Example\n"
             << "This example is under development." << std::endl;

   return(1);

/*
   try
   {
      std::cout << "OpenNN. Easom Function Application." << std::endl;

      srand( (unsigned)time( NULL ) );

      // Neural network

      NeuralNetwork neural_network(2);

      neural_network.construct_independent_parameters();

      IndependentParameters* independent_parameters_pointer = neural_network.get_independent_parameters_pointer();

      independent_parameters_pointer->set_name(0, "x");
      independent_parameters_pointer->set_name(1, "y");
   
      independent_parameters_pointer->set_minimum(0, -100.0);
      independent_parameters_pointer->set_minimum(1, -100.0);
   
      independent_parameters_pointer->set_maximum(0, 100.0);
      independent_parameters_pointer->set_maximum(1, 100.0);

      independent_parameters_pointer->initialize_parameters_uniform(-100.0, 100.0);

      independent_parameters_pointer->set_scaling_method(IndependentParameters::MinimumMaximum);

      // Performance functional
   
      PerformanceFunctional performance_functional(&neural_network);

      EasomFunction ef(&neural_network);

      // Initial guess

      Vector<double> initial_guess(2, 1.0);

      independent_parameters_pointer->set_parameters(initial_guess);

      std::cout << "Initial guess:\n"
	            << initial_guess << std::endl;

      // Evaluation

      double evaluation = performance_functional.calculate_evaluation();
 
      std::cout << "Evaluation:\n"
                << evaluation << std::endl;
  
      // Gradient vector

      Vector<double> gradient = performance_functional.calculate_gradient();
 
      std::cout << "Gradient:\n"
	            << gradient << std::endl;

      // Hessian matrix
 
      Matrix<double> hessian = performance_functional.calculate_Hessian();

      std::cout << "Hessian:\n"
	            << hessian; 
 
      // Training strategy

      TrainingStrategy training_strategy(&performance_functional);

      TrainingStrategy::Results training_strategy_results = training_strategy.perform_training();

      // Print minimal argument

      const Vector<double> minimal_argument = independent_parameters_pointer->get_parameters();

      std::cout << "Minimal argument:\n"
		   	    << minimal_argument << std::endl;

      // Save results

      neural_network.save("../data/easom_function/neural_network.xml");

      training_strategy.save("../data/easom_function/training_strategy.xml");
      training_strategy_results.save("../data/easom_function/training_strategy_results.dat");

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
