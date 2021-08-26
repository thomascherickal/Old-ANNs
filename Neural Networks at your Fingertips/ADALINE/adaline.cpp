#include <stdio.h>
#include <math.h>

typedef long double DP;

const int NUM_WEIGHTS = 5;
const int NUM_PATTERNS = 5;
const DP eta = 1;
const DP LEAST_ERROR = 0.0001;
const DP MAX_ITER = 20;

typedef struct Adaline {
	DP Weights[NUM_WEIGHTS];
	DP Inputs[NUM_WEIGHTS];
	DP Bias;
	DP Output[NUM_WEIGHTS];
} ADALINE;

ADALINE A;

DP WV[NUM_WEIGHTS] = { 0.12, -0.22, -0.01, 0.09, -0.26 };
DP IV[NUM_PATTERNS][NUM_WEIGHTS] = {  
				{   -0.005,  0.043,  0.092,  0.089, -0.034 },
				{    0.074, -0.053,  0.096,  0.023,  0.042 },
				{	 0.092, -0.039,  0.103, -0.073, -0.091 },
				{    0.039, -0.090,  0.010,  0.035,  0.023 },
				{	-0.042,  0.029, -0.010,  0.092,  0.093 }
};

DP OV[NUM_PATTERNS] = { 0.081, -0.192, -0.051, 0.049, 0.019 };


void Initialize(int p)
{
	int i;
	for (i = 0; i < NUM_WEIGHTS; i++)
	{
		A.Weights[i] = WV[i];
		A.Inputs[i] = IV[p][i];
	}

	A.Bias = 0;
}

DP Activate(int p)
{
	int i;
	DP S = 0;
	for (i = 0; i < NUM_WEIGHTS; i++)
		S += A.Inputs[i] * A.Weights[i];
	return A.Output[p] = S + A.Bias;
}

DP Error(int i)
{
	return OV[i] - A.Output[i];
}


DP DeltaW(int i)
{
	return Error(i) * eta * A.Inputs[i];
}

void Display()
{
	int i;
	printf("\n\nADALINE\n");
	printf("\nOutputs");
	for (i = 0; i < NUM_WEIGHTS; i++)
		printf("\n%lf" , A.Output[i]);
}

void SimulateNet()
{
	int i, iter = 0;
	DP S;
	do	{
		S = 0;
		for (i = 0; i < NUM_PATTERNS; i++) {
			Initialize(i);
			Activate(i);
			A.Weights[i] += DeltaW(i);
			S += Error(i);
			Display();
		}

		iter++;
	} while (fabs(S) > LEAST_ERROR && iter < MAX_ITER); 
}



void main()
{
	SimulateNet();
	Display();
}