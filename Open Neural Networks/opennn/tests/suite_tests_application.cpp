/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   S U I T E   T E S T S  A P P L I C A T I O N                                                               */
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
#include <time.h>

// OpenNN includes

#include "../source/utilities/matrix.h"
#include "unit_testing.h"

// Unit testing includes

#include "utilities_tests/vector_test.h"
#include "utilities_tests/matrix_test.h"
#include "utilities_tests/numerical_differentiation_test.h"
#include "utilities_tests/numerical_integration_test.h"
#include "utilities_tests/ordinary_differential_equations_test.h"
#include "utilities_tests/linear_algebraic_equations_test.h"

#include "data_set_tests/instances_information_test.h"
#include "data_set_tests/variables_information_test.h"
#include "data_set_tests/data_set_test.h"

#include "mathematical_model_tests/mathematical_model_test.h"
#include "mathematical_model_tests/ordinary_differential_equations_test.h"
#include "mathematical_model_tests/plug_in_test.h"

#include "neural_network_tests/perceptron_test.h"
#include "neural_network_tests/perceptron_layer_test.h"
#include "neural_network_tests/multilayer_perceptron_test.h"
#include "neural_network_tests/scaling_layer_test.h"
#include "neural_network_tests/unscaling_layer_test.h"
#include "neural_network_tests/bounding_layer_test.h"
#include "neural_network_tests/probabilistic_layer_test.h"
#include "neural_network_tests/conditions_layer_test.h"
#include "neural_network_tests/inputs_outputs_information_test.h"
#include "neural_network_tests/independent_parameters_test.h"
#include "neural_network_tests/neural_network_test.h"

#include "performance_functional_tests/performance_term_test.h"
#include "performance_functional_tests/performance_functional_test.h"
#include "performance_functional_tests/sum_squared_error_test.h"
#include "performance_functional_tests/mean_squared_error_test.h"
#include "performance_functional_tests/root_mean_squared_error_test.h"
#include "performance_functional_tests/normalized_squared_error_test.h"
#include "performance_functional_tests/minkowski_error_test.h"
#include "performance_functional_tests/cross_entropy_error_test.h"
#include "performance_functional_tests/inverse_sum_squared_error_test.h"
#include "performance_functional_tests/final_solutions_error_test.h"
#include "performance_functional_tests/independent_parameters_error_test.h"
#include "performance_functional_tests/outputs_integrals_test.h"
#include "performance_functional_tests/neural_parameters_norm_test.h"
#include "performance_functional_tests/solutions_error_test.h"

#include "training_strategy_tests/training_algorithm_test.h"
#include "training_strategy_tests/random_search_test.h"
#include "training_strategy_tests/evolutionary_algorithm_test.h"
#include "training_strategy_tests/gradient_descent_test.h"
#include "training_strategy_tests/conjugate_gradient_test.h"
#include "training_strategy_tests/quasi_newton_method_test.h"
#include "training_strategy_tests/newton_method_test.h"
#include "training_strategy_tests/levenberg_marquardt_algorithm_test.h"
#include "training_strategy_tests/training_strategy_test.h"

#include "model_selection_tests/model_selection_test.h"

#include "testing_analysis_tests/function_regression_testing_test.h"
#include "testing_analysis_tests/pattern_recognition_testing_test.h"
#include "testing_analysis_tests/time_series_prediction_testing_test.h"
#include "testing_analysis_tests/inverse_problem_testing_test.h"
#include "testing_analysis_tests/testing_analysis_test.h"

using namespace OpenNN;

int main(void)
{
   std::cout << "Open Neural Networks Library. Test Suite Application." << std::endl;   

   try
   {

      srand((unsigned)time(NULL));

      std::string message;
      unsigned int tests_count = 0;
      unsigned int tests_passed_count = 0;
      unsigned int tests_failed_count = 0;

      //
      // U T I L I T I E S   T E S T S
      // 

      // Vector test

      VectorTest vector_test;
      vector_test.run_test_case();
      message += vector_test.get_message();
      tests_count += vector_test.get_tests_count(); 
      tests_passed_count += vector_test.get_tests_passed_count();
      tests_failed_count += vector_test.get_tests_failed_count();

      // Matrix test

      MatrixTest matrix_test;
      matrix_test.run_test_case();
      tests_count += matrix_test.get_tests_count(); 
      tests_passed_count += matrix_test.get_tests_passed_count();
      tests_failed_count += matrix_test.get_tests_failed_count();   

      // Numerical differentiation test

      NumericalDifferentiationTest test_numerical_differentiation;
      test_numerical_differentiation.run_test_case();
      message += test_numerical_differentiation.get_message();
      tests_count += test_numerical_differentiation.get_tests_count(); 
      tests_passed_count += test_numerical_differentiation.get_tests_passed_count();
      tests_failed_count += test_numerical_differentiation.get_tests_failed_count();

      // Numerical integration test

      NumericalIntegrationTest test_numerical_integration;
      test_numerical_integration.run_test_case();
      message += test_numerical_integration.get_message();
      tests_count += test_numerical_integration.get_tests_count(); 
      tests_passed_count += test_numerical_integration.get_tests_passed_count();
      tests_failed_count += test_numerical_integration.get_tests_failed_count();
   
      // Linear algebraic equations test

      LinearAlgebraicEquationsTest linear_algebraic_equations_test;
      linear_algebraic_equations_test.run_test_case();
      message += linear_algebraic_equations_test.get_message();
      tests_count += linear_algebraic_equations_test.get_tests_count(); 
      tests_passed_count += linear_algebraic_equations_test.get_tests_passed_count();
      tests_failed_count += linear_algebraic_equations_test.get_tests_failed_count();

      //
      // D A T A   S E T   T E S T S
      // 

      // Variables information test

      VariablesInformationTest variables_information_test;
      variables_information_test.run_test_case();
      message += variables_information_test.get_message();
      tests_count += variables_information_test.get_tests_count(); 
      tests_passed_count += variables_information_test.get_tests_passed_count();
      tests_failed_count += variables_information_test.get_tests_failed_count();

      // Instances information set

      InstancesInformationTest instances_information_test;
      instances_information_test.run_test_case();
      message += instances_information_test.get_message();
      tests_count += instances_information_test.get_tests_count(); 
      tests_passed_count += instances_information_test.get_tests_passed_count();
      tests_failed_count += instances_information_test.get_tests_failed_count();

      // Data set test

      DataSetTest data_set_test;
      data_set_test.run_test_case();
      message += data_set_test.get_message();
      tests_count += data_set_test.get_tests_count(); 
      tests_passed_count += data_set_test.get_tests_passed_count();
      tests_failed_count += data_set_test.get_tests_failed_count();

      //
      // M A T H E M A T I C A L   M O D E L   T E S T S
      // 

      MathematicalModelTest mathematical_model_test;
      mathematical_model_test.run_test_case();
      message += mathematical_model_test.get_message();
      tests_count += mathematical_model_test.get_tests_count(); 
      tests_passed_count += mathematical_model_test.get_tests_passed_count();
      tests_failed_count += mathematical_model_test.get_tests_failed_count();

      OrdinaryDifferentialEquationsTest ordinary_differential_equations_test;
      ordinary_differential_equations_test.run_test_case();
      message += ordinary_differential_equations_test.get_message();
      tests_count += ordinary_differential_equations_test.get_tests_count(); 
      tests_passed_count += ordinary_differential_equations_test.get_tests_passed_count();
      tests_failed_count += ordinary_differential_equations_test.get_tests_failed_count();

      PlugInTest plug_in_test;
      plug_in_test.run_test_case();
      message += plug_in_test.get_message();
      tests_count += plug_in_test.get_tests_count(); 
      tests_passed_count += plug_in_test.get_tests_passed_count();
      tests_failed_count += plug_in_test.get_tests_failed_count();

      //
      // N E U R A L   N E T W O R K   T E S T S
      // 

      // Perceptron test

      PerceptronTest perceptron_test;
      perceptron_test.run_test_case();
      message += perceptron_test.get_message();
      tests_count += perceptron_test.get_tests_count(); 
      tests_passed_count += perceptron_test.get_tests_passed_count();
      tests_failed_count += perceptron_test.get_tests_failed_count();

      // Perceptron layer test

      PerceptronLayerTest perceptron_layer_test;
      perceptron_layer_test.run_test_case();
      message += perceptron_layer_test.get_message();
      tests_count += perceptron_layer_test.get_tests_count(); 
      tests_passed_count += perceptron_layer_test.get_tests_passed_count();
      tests_failed_count += perceptron_layer_test.get_tests_failed_count();

      // Multilayer perceptron test

      MultilayerPerceptronTest multilayer_perceptron_test;
      multilayer_perceptron_test.run_test_case();
      message += multilayer_perceptron_test.get_message();
      tests_count += multilayer_perceptron_test.get_tests_count(); 
      tests_passed_count += multilayer_perceptron_test.get_tests_passed_count();
      tests_failed_count += multilayer_perceptron_test.get_tests_failed_count();

      // Scaling layer test

      ScalingLayerTest scaling_layer_test;
      scaling_layer_test.run_test_case();
      message += scaling_layer_test.get_message();
      tests_count += scaling_layer_test.get_tests_count(); 
      tests_passed_count += scaling_layer_test.get_tests_passed_count();
      tests_failed_count += scaling_layer_test.get_tests_failed_count();

      // Unscaling layer test

      UnscalingLayerTest unscaling_layer_test;
      unscaling_layer_test.run_test_case();
      message += unscaling_layer_test.get_message();
      tests_count += unscaling_layer_test.get_tests_count(); 
      tests_passed_count += unscaling_layer_test.get_tests_passed_count();
      tests_failed_count += unscaling_layer_test.get_tests_failed_count();

      // Bounding layer test

      BoundingLayerTest bounding_layer_test;
      bounding_layer_test.run_test_case();
      message += bounding_layer_test.get_message();
      tests_count += bounding_layer_test.get_tests_count(); 
      tests_passed_count += bounding_layer_test.get_tests_passed_count();
      tests_failed_count += bounding_layer_test.get_tests_failed_count();

      // Probabilistic layer test

      ProbabilisticLayerTest probabilistic_layer_test;
      probabilistic_layer_test.run_test_case();
      message += probabilistic_layer_test.get_message();
      tests_count += probabilistic_layer_test.get_tests_count(); 
      tests_passed_count += probabilistic_layer_test.get_tests_passed_count();
      tests_failed_count += probabilistic_layer_test.get_tests_failed_count();

      // Conditions layer test

      ConditionsLayerTest conditions_layer_test;
      conditions_layer_test.run_test_case();
      message += conditions_layer_test.get_message();
      tests_count += conditions_layer_test.get_tests_count(); 
      tests_passed_count += conditions_layer_test.get_tests_passed_count();
      tests_failed_count += conditions_layer_test.get_tests_failed_count();

      // Inputs-outputs information test 

      InputsOutputsInformationTest inputs_outputs_information_test;
      inputs_outputs_information_test.run_test_case();
      message += inputs_outputs_information_test.get_message();
      tests_count += inputs_outputs_information_test.get_tests_count(); 
      tests_passed_count += inputs_outputs_information_test.get_tests_passed_count();
      tests_failed_count += inputs_outputs_information_test.get_tests_failed_count();

      // Independent parameters test 

      IndependentParametersTest independent_parameters_test;
      independent_parameters_test.run_test_case();
      message += independent_parameters_test.get_message();
      tests_count += independent_parameters_test.get_tests_count(); 
      tests_passed_count += independent_parameters_test.get_tests_passed_count();
      tests_failed_count += independent_parameters_test.get_tests_failed_count();

      // Neural network test

      NeuralNetworkTest neural_network_test;
      neural_network_test.run_test_case();
      message += neural_network_test.get_message();
      tests_count += neural_network_test.get_tests_count(); 
      tests_passed_count += neural_network_test.get_tests_passed_count();
      tests_failed_count += neural_network_test.get_tests_failed_count();

      //
      // P E R F O R M A N C E   F U N C T I O N A L   T E S T S
      // 

      // Performance term test

      PerformanceTermTest performance_term_test;
      performance_term_test.run_test_case();
      message += performance_term_test.get_message();
      tests_count += performance_term_test.get_tests_count(); 
      tests_passed_count += performance_term_test.get_tests_passed_count();
      tests_failed_count += performance_term_test.get_tests_failed_count();

      // Sum squared error test

      SumSquaredErrorTest test_sum_squared_error;
      test_sum_squared_error.run_test_case();
      message += test_sum_squared_error.get_message();
      tests_count += test_sum_squared_error.get_tests_count(); 
      tests_passed_count += test_sum_squared_error.get_tests_passed_count();
      tests_failed_count += test_sum_squared_error.get_tests_failed_count();

      // Mean squared error test

      MeanSquaredErrorTest test_mean_squared_error;
      test_mean_squared_error.run_test_case();
      message += test_mean_squared_error.get_message();
      tests_count += test_mean_squared_error.get_tests_count(); 
      tests_passed_count += test_mean_squared_error.get_tests_passed_count();
      tests_failed_count += test_mean_squared_error.get_tests_failed_count();

      // Root mean squared error test

      RootMeanSquaredErrorTest test_root_mean_squared_error;
      test_root_mean_squared_error.run_test_case();
      message += test_root_mean_squared_error.get_message();
      tests_count += test_root_mean_squared_error.get_tests_count(); 
      tests_passed_count += test_root_mean_squared_error.get_tests_passed_count();
      tests_failed_count += test_root_mean_squared_error.get_tests_failed_count();

      // Normalized squared error test

      NormalizedSquaredErrorTest normalized_squared_error_test;
      normalized_squared_error_test.run_test_case();
      message += normalized_squared_error_test.get_message();
      tests_count += normalized_squared_error_test.get_tests_count(); 
      tests_passed_count += normalized_squared_error_test.get_tests_passed_count();
      tests_failed_count += normalized_squared_error_test.get_tests_failed_count();

      // Minkowski error test

      MinkowskiErrorTest Minkowski_error_test;
      Minkowski_error_test.run_test_case();
      message += Minkowski_error_test.get_message();
      tests_count += Minkowski_error_test.get_tests_count(); 
      tests_passed_count += Minkowski_error_test.get_tests_passed_count();
      tests_failed_count += Minkowski_error_test.get_tests_failed_count();

      // Cross entropy error test

      CrossEntropyErrorTest cross_entropy_error_test;
      cross_entropy_error_test.run_test_case();
      message += cross_entropy_error_test.get_message();
      tests_count += cross_entropy_error_test.get_tests_count(); 
      tests_passed_count += cross_entropy_error_test.get_tests_passed_count();
      tests_failed_count += cross_entropy_error_test.get_tests_failed_count();

	  // Independent parameters error test

      IndependentParametersErrorTest independent_parameters_error_test;
      independent_parameters_error_test.run_test_case();
      message += independent_parameters_error_test.get_message();
      tests_count += independent_parameters_error_test.get_tests_count(); 
      tests_passed_count += independent_parameters_error_test.get_tests_passed_count();
      tests_failed_count += independent_parameters_error_test.get_tests_failed_count();

      // Inverse sum squared error test

      InverseSumSquaredErrorTest test_inverse_sum_squared_error;
      test_inverse_sum_squared_error.run_test_case();
      message += test_inverse_sum_squared_error.get_message();
      tests_count += test_inverse_sum_squared_error.get_tests_count(); 
      tests_passed_count += test_inverse_sum_squared_error.get_tests_passed_count();
      tests_failed_count += test_inverse_sum_squared_error.get_tests_failed_count();

	  // Neural parameters norm test

      NeuralParametersNormTest test_neural_parameters_norm;
      test_neural_parameters_norm.run_test_case();
      message += test_neural_parameters_norm.get_message();
      tests_count += test_neural_parameters_norm.get_tests_count(); 
      tests_passed_count += test_neural_parameters_norm.get_tests_passed_count();
      tests_failed_count += test_neural_parameters_norm.get_tests_failed_count();

	  // Outputs integrals test

      OutputsIntegralsTest test_outputs_integrals;
      test_outputs_integrals.run_test_case();
      message += test_outputs_integrals.get_message();
      tests_count += test_outputs_integrals.get_tests_count(); 
      tests_passed_count += test_outputs_integrals.get_tests_passed_count();
      tests_failed_count += test_outputs_integrals.get_tests_failed_count();

	  // Final solutions error test

      FinalSolutionsErrorTest final_solutions_error_test;
      final_solutions_error_test.run_test_case();
      message += final_solutions_error_test.get_message();
      tests_count += final_solutions_error_test.get_tests_count(); 
      tests_passed_count += final_solutions_error_test.get_tests_passed_count();
      tests_failed_count += final_solutions_error_test.get_tests_failed_count();

	  // Solutions error test

      SolutionsErrorTest test_solutions_error;
      test_solutions_error.run_test_case();
      message += test_solutions_error.get_message();
      tests_count += test_solutions_error.get_tests_count(); 
      tests_passed_count += test_solutions_error.get_tests_passed_count();
      tests_failed_count += test_solutions_error.get_tests_failed_count();

      // Performance functional test

      PerformanceFunctionalTest performance_functional_test;
      performance_functional_test.run_test_case();
      message += performance_functional_test.get_message();
      tests_count += performance_functional_test.get_tests_count(); 
      tests_passed_count += performance_functional_test.get_tests_passed_count();
      tests_failed_count += performance_functional_test.get_tests_failed_count();

      //
      // T R A I N I N G   S T R A T E G Y   T E S T S
      // 

      // Training algorithm test

      TrainingAlgorithmTest training_algorithm_test;
      training_algorithm_test.run_test_case();
      message += training_algorithm_test.get_message();
      tests_count += training_algorithm_test.get_tests_count(); 
      tests_passed_count += training_algorithm_test.get_tests_passed_count();
      tests_failed_count += training_algorithm_test.get_tests_failed_count();
	  
      // Random search test

      RandomSearchTest random_search_test;
      random_search_test.run_test_case();
      message += random_search_test.get_message();
      tests_count += random_search_test.get_tests_count(); 
      tests_passed_count += random_search_test.get_tests_passed_count();
      tests_failed_count += random_search_test.get_tests_failed_count();

      // Evolutionary algorithm test

      EvolutionaryAlgorithmTest evolutionary_algorithm_test;
      evolutionary_algorithm_test.run_test_case();
      message += evolutionary_algorithm_test.get_message();
      tests_count += evolutionary_algorithm_test.get_tests_count(); 
      tests_passed_count += evolutionary_algorithm_test.get_tests_passed_count();
      tests_failed_count += evolutionary_algorithm_test.get_tests_failed_count();

      // Gradient descent test

      GradientDescentTest gradient_descent_test;
      gradient_descent_test.run_test_case();
      message += gradient_descent_test.get_message();
      tests_count += gradient_descent_test.get_tests_count(); 
      tests_passed_count += gradient_descent_test.get_tests_passed_count();
      tests_failed_count += gradient_descent_test.get_tests_failed_count();

      // Newton method test

      NewtonMethodTest Newton_method_test;
      Newton_method_test.run_test_case();
      message += Newton_method_test.get_message();
      tests_count += Newton_method_test.get_tests_count(); 
      tests_passed_count += Newton_method_test.get_tests_passed_count();
      tests_failed_count += Newton_method_test.get_tests_failed_count();

      // Conjugate gradient test

      ConjugateGradientTest test_conjugate_gradient;
      test_conjugate_gradient.run_test_case();
      message += test_conjugate_gradient.get_message();
      tests_count += test_conjugate_gradient.get_tests_count(); 
      tests_passed_count += test_conjugate_gradient.get_tests_passed_count();
      tests_failed_count += test_conjugate_gradient.get_tests_failed_count();

      // Quasi-Newton method test

      QuasiNewtonMethodTest quasi_Newton_method_test;
      quasi_Newton_method_test.run_test_case();
      message += quasi_Newton_method_test.get_message();
      tests_count += quasi_Newton_method_test.get_tests_count(); 
      tests_passed_count += quasi_Newton_method_test.get_tests_passed_count();
      tests_failed_count += quasi_Newton_method_test.get_tests_failed_count();

      // Levenberg-Marquardt algorithm test

      LevenbergMarquardtAlgorithmTest test_Levenberg_Marquardt_algorithm;
      test_Levenberg_Marquardt_algorithm.run_test_case();
      message += test_Levenberg_Marquardt_algorithm.get_message();
      tests_count += test_Levenberg_Marquardt_algorithm.get_tests_count(); 
      tests_passed_count += test_Levenberg_Marquardt_algorithm.get_tests_passed_count();
      tests_failed_count += test_Levenberg_Marquardt_algorithm.get_tests_failed_count();

      // Training strategy test

      TrainingStrategyTest test_training_strategy;
      test_training_strategy.run_test_case();
      message += test_training_strategy.get_message();
      tests_count += test_training_strategy.get_tests_count(); 
      tests_passed_count += test_training_strategy.get_tests_passed_count();
      tests_failed_count += test_training_strategy.get_tests_failed_count();

      //
      // M O D E L   S E L E C T I O N   T E S T S
      // 

      // Model selection test

      ModelSelectionTest test_model_selection;
      test_model_selection.run_test_case();
      message += test_model_selection.get_message();
      tests_count += test_model_selection.get_tests_count(); 
      tests_passed_count += test_model_selection.get_tests_passed_count();
      tests_failed_count += test_model_selection.get_tests_failed_count();

      //
      // T E S T I N G   A N A L Y S I S   T E S T S
      // 

      // Function regression testing test

      FunctionRegressionTestingTest test_function_regression_testing;
      test_function_regression_testing.run_test_case();
      message += test_function_regression_testing.get_message();
      tests_count += test_function_regression_testing.get_tests_count(); 
      tests_passed_count += test_function_regression_testing.get_tests_passed_count();
      tests_failed_count += test_function_regression_testing.get_tests_failed_count();

      // Pattern recognition testing test

      PatternRecognitionTestingTest test_pattern_recognition_testing;
      test_pattern_recognition_testing.run_test_case();
      message += test_pattern_recognition_testing.get_message();
      tests_count += test_pattern_recognition_testing.get_tests_count(); 
      tests_passed_count += test_pattern_recognition_testing.get_tests_passed_count();
      tests_failed_count += test_pattern_recognition_testing.get_tests_failed_count();

      // Time series prediction testing test

      TimeSeriesPredictionTestingTest test_time_series_prediction_testing;
      test_time_series_prediction_testing.run_test_case();
      message += test_time_series_prediction_testing.get_message();
      tests_count += test_time_series_prediction_testing.get_tests_count(); 
      tests_passed_count += test_time_series_prediction_testing.get_tests_passed_count();
      tests_failed_count += test_time_series_prediction_testing.get_tests_failed_count();

      // Inverse problem testing test

      InverseProblemTestingTest inverse_problem_testing_test;
      inverse_problem_testing_test.run_test_case();
      message += inverse_problem_testing_test.get_message();
      tests_count += inverse_problem_testing_test.get_tests_count(); 
      tests_passed_count += inverse_problem_testing_test.get_tests_passed_count();
      tests_failed_count += inverse_problem_testing_test.get_tests_failed_count();

      // Testing analysis test

      TestingAnalysisTest test_testing_analysis;
      test_testing_analysis.run_test_case();
      message += test_testing_analysis.get_message();
      tests_count += test_testing_analysis.get_tests_count(); 
      tests_passed_count += test_testing_analysis.get_tests_passed_count();
      tests_failed_count += test_testing_analysis.get_tests_failed_count();

      // Test suite

      std::cout << message << "\n"
                << "OpenNN test suite results:\n"
                << "Tests run: " << tests_count << "\n"
                << "Tests passed: " << tests_passed_count << "\n"
                << "Tests failed: " << tests_failed_count << "\n";

      if(tests_failed_count == 0)
      {
	     std::cout << "Test OK" << std::endl;
      }
      else
      {
	     std::cout << "Test NOT OK. " << tests_failed_count << " tests failed" << std::endl;
      } 

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
