/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   E A S O M   F U N C T I O N   C L A S S   H E A D E R                                                      */
/*                                                                                                              */
/*   Gilles Cadose                                                                                              */
/*   Carlos Vargas de la Fuente                                                                                 */
/*   Hebert Sotelo Aedo                                                                                         */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/


#ifndef __EASOMFUNCTION_H__
#define __EASOMFUNCTION_H__

// OpenNN includes

#include "../../source/opennn.h"

namespace OpenNN
{

class EasomFunction : public PerformanceTerm
{

#define PI 3.1415926536

public:

   // GENERAL CONSTRUCTOR

   explicit EasomFunction(NeuralNetwork*);

   // DESTRUCTOR

   virtual ~EasomFunction(void);


   // METHODS

   // Objective methods

   double calculate_evaluation(void) const;

   // Objective function gradient methods

   Vector<double> calculate_gradient(void) const;

   // Objective function Hessian methods

   Matrix<double> calculate_Hessian(void) const;

   Matrix<double> calculate_inverse_Hessian(void) const;

};

}

#endif


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2012 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the s of the GNU Lesser General Public
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
