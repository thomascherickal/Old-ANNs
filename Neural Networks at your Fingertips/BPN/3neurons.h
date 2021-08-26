#include "3defs.h"

class BPN;

class Neuron {
private:
	int NO_W;
	DP *Inputs;
	DP Output;
	DP *Weights;
	DP Activation;
	DP Bias;
public:
	Neuron(void) { };
	// Initialize the weights
	Neuron(const DP *W, int no) 
	{
		NO_W = no;
		Weights = new DP[no];
		for (int i = 0; i < NO_W; i++)
			Weights[i] = W[i];
		Inputs = new DP[NO_W];
	}
	//Set the output
	void SetOutput(DP out)
	{
		Output = out;
	}
	void SetBias(DP b)
	{
		
		Bias = b;
	}
	const DP* GetWeights(void) {
		return Weights;
	}
	DP GetOutput(void)
	{
		return Output;
	}
	DP GetActiv(void)
	{
		return Activation;
	}
	// Initialize the Inputs
	void SetInputs(const DP *X) 
	{
		for (int i = 0; i < NO_W; i++)
			Inputs[i] = X[i];
	}
	// Produce the Output
	DP Summation(void)
	{
		DP S = 0;
		for (int i = 0; i < NO_W; i++)
			S += Weights[i] * Inputs[i];
		return Activation = S;
	}

	void UpdateWeights(DP term)
	{
		
		for (int i = 0; i < NO_W; i++)
			Weights[i] = eta * term * Inputs[i] +  Weights[i];
	}


};




