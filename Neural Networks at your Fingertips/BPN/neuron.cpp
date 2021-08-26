#include "defs.h"

class Neuron {
private:
	DP Inputs[NO_INPUTS];
	DP Weights[NO_INPUTS];
	DP Output;
public:
	Neuron(void) { };
	// Initialize the weights
	Neuron(DP W[NO_INPUTS]) 
	{
		for (int i = 0; i < NO_INPUTS; i++)
			Weights[i] = W[i];
	}
	// Initialize the Inputs
	void SetInputs(DP X[NO_INPUTS]) 
	{
		for (int i = 0; i < NO_INPUTS; i++)
			Inputs[i] = X[i];
	}
	// Produce the Output
	DP Activate(void)
	{
		DP S = 0;
		for (int i = 0; i < NO_INPUTS; i++)
			S += Weights[i] * Inputs[i];
		return Output =  1 / ( 1 + exp(-S) );
	}
};




