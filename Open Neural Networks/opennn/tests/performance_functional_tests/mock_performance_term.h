/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   M O C K   P E R F O R M A N C E   T E R M   C L A S S   H E A D E R                                        */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __MOCKPERFORMANCETERM_H__
#define __MOCKPERFORMANCETERM_H__


// OpenNN includes

#include "../../source/utilities/numerical_integration.h"

#include "../../source/performance_functional/performance_term.h"


using namespace OpenNN;


class MockPerformanceTerm : public PerformanceTerm
{

public:

   // DEFAULT CONSTRUCTOR

   explicit MockPerformanceTerm(void);

   // GENERAL CONSTRUCTOR

   explicit MockPerformanceTerm(NeuralNetwork*);

   // DESTRUCTOR

   virtual ~MockPerformanceTerm(void); 

   // METHODS

   // Objective methods

   double calculate_evaluation_integrand(double) const;
   double calculate_evaluation(void) const;
   
   double calculate_evaluation(const Vector<double>&) const;

   Vector<double> calculate_gradient_integrand(double) const;
   Vector<double> calculate_gradient(void) const;

   Matrix<double> calculate_Hessian_integrand(double) const;
   Matrix<double> calculate_Hessian(void) const;


private:

   NumericalIntegration numerical_integration;
};


#endif


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
