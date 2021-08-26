/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   M O C K   P E R F O R M A N C E   T E R M   C L A S S                                                      */
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
#include <fstream>
#include <cmath>


// Unit testing includes

#include "mock_performance_term.h"


using namespace OpenNN;


// DEFAULT CONSTRUCTOR

MockPerformanceTerm::MockPerformanceTerm(void) : PerformanceTerm()
{
}


// GENERAL CONSTRUCTOR

MockPerformanceTerm::MockPerformanceTerm(NeuralNetwork* new_neural_network_pointer)
: PerformanceTerm(new_neural_network_pointer)
{
}


// DESTRUCTOR

/// Destructor.

MockPerformanceTerm::~MockPerformanceTerm(void) 
{
}


// METHODS


// double calculate_evaluation_integrand(double, double) const method

double MockPerformanceTerm::calculate_evaluation_integrand(double x) const
{
   Vector<double> input(1, x);

   Vector<double> output = neural_network_pointer->calculate_outputs(input);

   return(output[0]*output[0]);   
}


// double calculate_evaluation(void) const method

double MockPerformanceTerm::calculate_evaluation(void) const
{
//   double trapezoid_integral = 
//   numerical_integration.calculate_trapezoid_integral(*this, 
//   &MockPerformanceTerm::calculate_evaluation_integrand,
//   0.0, 1.0, 101);

//   return(trapezoid_integral);

	return(0.0);
}


// double calculate_evaluation(const Vector<double>&) const method

double MockPerformanceTerm::calculate_evaluation(const Vector<double>& parameters) const
{
   // Control sentence (if debug)

   #ifdef _DEBUG 

   unsigned int size = parameters.size();

   unsigned int parameters_number = neural_network_pointer->count_parameters_number();

   if(size != parameters_number)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Error: MockPerformanceTerm class." << std::endl
             << "double calculate_evaluation(const Vector<double>&) const method." << std::endl
             << "Size (" << size << ") must be equal to number of parameters (" << parameters_number << ")." << std::endl;

      std::logic_error e(buffer.str());

	  throw e;
   }

   #endif

   NeuralNetwork neural_network_copy(*neural_network_pointer);

   neural_network_copy.set_parameters(parameters);

   MockPerformanceTerm mock_objective_term_copy(*this);

   mock_objective_term_copy.set_neural_network_pointer(&neural_network_copy);

   return(mock_objective_term_copy.calculate_evaluation());
}


// Vector<double> calculate_gradient_integrand(double) const
// @todo

Vector<double> MockPerformanceTerm::calculate_gradient_integrand(double x) const
{
   const MultilayerPerceptron* multilayer_perceptron_pointer = neural_network_pointer->get_multilayer_perceptron_pointer();

   const unsigned int layers_number = multilayer_perceptron_pointer->count_layers_number();

   Vector<double> input(1, x);

   Vector< Vector< Vector<double> > > first_order_forward_propagation = multilayer_perceptron_pointer->calculate_first_order_forward_propagation(input);

   Vector< Vector<double> >& layers_activation = first_order_forward_propagation[0];
   Vector< Vector<double> >& layers_activation_derivative = first_order_forward_propagation[1];

   Vector<double>& output = layers_activation[layers_number-1];

   Vector<double> output_objective_gradient(1, 2.0*output[0]);

   Vector< Vector<double> > layers_delta = calculate_layers_delta(layers_activation_derivative, output_objective_gradient);

   Vector<double> objective_gradient_integrand;// = calculate_point_objective_gradient(input, layers_activation, layers_delta);

   return(objective_gradient_integrand);
}


// Vector<double> calculate_gradient(void) const method
// @todo

Vector<double> MockPerformanceTerm::calculate_gradient(void) const 
{
//    Vector<double> trapezoid_integral = 
//    numerical_integration.calculate_trapezoid_integral(*this, 
//    &MockPerformanceTerm::calculate_gradient_integrand,
//    0.0, 1.0, 101);

//    return(trapezoid_integral);

   Vector<double> v;

   return(v);
}


// Matrix<double> calculate_Hessian_integrand(double) const method
// @todo

Matrix<double> MockPerformanceTerm::calculate_Hessian_integrand(double) const
{
   Matrix<double> objective_Hessian_integrand;

   return(objective_Hessian_integrand);
}


// Matrix<double> calculate_Hessian(void) const method
// @todo

Matrix<double> MockPerformanceTerm::calculate_Hessian(void) const
{
   Matrix<double> objective_Hessian;

   return(objective_Hessian);
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

