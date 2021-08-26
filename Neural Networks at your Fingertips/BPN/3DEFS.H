
#ifndef COMMON_FILES_INCLUDED
#define COMMON_FILES_INCLUDED
#include <iostream.h>
#include <math.h>
#include <stdlib.h>
#endif


const int NO_OUTPUTS  = 1;
const int NO_INPUTS   = 3;
const int NO_HIDDEN   = 3;
const int NO_PATTERNS = 8;


typedef double DP;

const DP MAX_ITERATIONS = 20000;
const DP LEAST_ERROR = 0.0001;
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

const DP Input_Weights[NO_INPUTS][NO_INPUTS] = {
	{ 1, 1, 1 }, 
	{ 1, 1, 1 },
	{ 1, 1, 1 }
};

const DP Hidden_Weights[NO_HIDDEN][NO_INPUTS] = {
	{ 0.3, 0.7, -0.4 } , 
	{-0.2,  0.5, 0.3 } , 
	{0.1, -0.6,  0.2 }
};

 const DP Output_Weights[NO_OUTPUTS][NO_HIDDEN] = {
	{ 0.1, -0.6, 0.4} 
};

/***************************************************************/
/*This particular application trains a BPN network to identify */
/*  a 3 input XOR classification							   */
/***************************************************************/

 const DP Hidden_Biases[NO_HIDDEN] = { 1, 1/2, -1 };
 const DP Output_Biases[NO_OUTPUTS] = { 1/2 };

		
const DP Inputs[NO_PATTERNS][NO_INPUTS] = {
	{ 0.3, 0.1, 0.6 },
	{ 0.2, -0.7, 0.1 },
	{ 0.6, 0.3, 0.6 },
	{ 0.2, -0.3, 0.5 },
	{ 0.1, -0.5, -0.7 },
	{ 0.1, 0.4, 0.4 },
	{ 0.5, 0.3, -0.8 },
	{ 0.3, -0.9, 0.1 }
};

const DP Desired_Outputs[NO_PATTERNS][NO_OUTPUTS] = {
	{ 0.78 },
	{ 0.91 }, 
	{ 0.31 },
	{ 0.54 },
	{ 0.63 },
	{ 0.21 },
	{ 0.73 },
	{ 0.10 }
};


DP eta = 0.5;

DP alpha = 0.2;
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

void EtaAdjust(DP T_E)
{
	DP R = dabs(T_E);
		int i = 0;
		if (R == 0) return;
		while ( (R *= 10) < 0.1 ) i++;
		eta = pow(10, i);
     
	
}
