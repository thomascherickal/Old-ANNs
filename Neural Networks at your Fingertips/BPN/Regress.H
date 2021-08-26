
#ifndef COMMON_FILES_INCLUDED
#define COMMON_FILES_INCLUDED
#include <iostream.h>
#include <math.h>
#include <stdlib.h>
#include <fstream.h>
#endif


const int NO_OUTPUTS  = 1;
const int NO_INPUTS   = 4;
const int NO_HIDDEN   = 4;
const int NO_PATTERNS = 4;

const int NO_TEST	  = 4;

typedef double DP;

const DP MAX_ITERATIONS = 50000;
/*
DP pow(DP x, int y)
{
	int z = 0;
	DP R = 1;
	while (z < y) { R *= x, z++; }
	return R;
}

DP fact(DP x)
{
	DP r = 1;
	if ( x == 0 || x == 1) return 1;
	else
		for (DP i = 1; i <= x; i++)
			r *= i;
	return r;
}
*/
DP dabs(DP x)
{
	return	x > 0 ? x : -x;
}
/*********************************************/
/* RANDOM Weights with  values               */
/*********************************************/

DP Input_Weights[NO_INPUTS][NO_INPUTS];
const DP Hidden_Weights[NO_HIDDEN][NO_INPUTS] = {
	{ -0.1, 0.5, 0.2, 0.1},
	{ 0.1 ,0.5, -0.6, 0.1},
	{ -0.3 ,0.6, -0.1, 0.9},
	{ 0.1 ,-0.3, 0.5, 0.4}
};

 const DP Output_Weights[NO_OUTPUTS][NO_HIDDEN] = {
	{ 0.7, 0.3, 0.2, 0.3} 
};

/***************************************************************/
/*This particular application trains a BPN network to perform  */
/*  a non linear regression     							   */
/***************************************************************/

 const DP Hidden_Biases[NO_HIDDEN] = { 1, 1/2, -1 };
 const DP Output_Biases[NO_OUTPUTS] = { 1/2 };

		
DP Inputs[NO_PATTERNS][NO_INPUTS] = {
	{ -0.2, 0.1, 0.1, 0.2},
	{ 0.2 ,-0.1, 0.2, -0.1},
	{ -0.3, 0.2, 0.1, -0.1},
	{ 0.5, -0.3, 0.4 ,-0.1}
};

 DP Desired_Outputs[NO_PATTERNS][NO_OUTPUTS] = {
	{ 0.4 },
	{ 0.2},
	{ 0.1}, 	
	{ 0.5},
};

DP TestInputs[NO_PATTERNS][NO_INPUTS] = {
	{ 1, 0, 0, 0 },
	{ 0, 1, 0, 0 },
	{ 0, 0, 1, 0 },
	{ 0, 0, 0, 1 }
};

DP Test_Outputs[NO_PATTERNS][NO_OUTPUTS];


DP eta = 1;
DP alpha = 0;

/***********************************************************/
/*               SOME USEFUL FUNCTIONS                     */
/***********************************************************/

DP Activate(DP S)
{
	return 1 / ( 1 + exp(-S));
}

DP HardLimiter(DP Out)
{
	return (Out > 0.5 ? 1.0 : 0.0 );
}

DP Deriv(DP y)
{
	return y * (1 - y);
}

/***************************************************************************/
/*						FUZZY LOGIC CONTROLLER                             */
/***************************************************************************/


const DP NO_ERROR		= 0;
const DP LEAST_ERROR	= 0.00001;
const DP LITTLE_ERROR	= 0.0001;
const DP SMALL_ERROR	= 0.001;
const DP MEDIUM_ERROR	= 0.01;
const DP MODERATE_ERROR	= 0.1;
const DP HIGH_ERROR     = 1;
 
void EtaAdjust(DP T_E)
{
	if (T_E < LEAST_ERROR) eta = 10000;
	else {
		if (T_E < LITTLE_ERROR) 
			eta = 1000;
	    else if (T_E < SMALL_ERROR)
			eta = 100;
		else if (T_E < MEDIUM_ERROR) 
			eta = 10 ;
		else if (T_E < MODERATE_ERROR) 
			eta = 1;
		else if (T_E < HIGH_ERROR) 
			eta = 0.5;
		else
			eta = 0.1;
	}       
	
}
