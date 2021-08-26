
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

DP dabs(DP x)
{
	return	x > 0 ? x : -x;
}

const DP Input_Weights[NO_INPUTS][NO_INPUTS] = {
	{ 1, 1, 1 }, 
	{ 1, 1, 1 },
	{ 1, 1, 1 }
};

const DP Hidden_Weights[NO_HIDDEN][NO_INPUTS] = {
	{ 1, -1, -1 } , 
	{-1,  1, -1 } , 
	{-1, -1,  1 }
};

 const DP Output_Weights[NO_OUTPUTS][NO_HIDDEN] = {
	{ 1, 1, 1} 
};

/***************************************************************/
/*This particular application trains a XORNet network to identify */
/*  a 3 input XOR classification							   */
/***************************************************************/

		
const DP Inputs[NO_PATTERNS][NO_INPUTS] = {
	{ 0, 0, 0 },
	{ 0, 0, 1 },
	{ 0, 1, 0 },
	{ 0, 1, 1 },
	{ 1, 0, 0 },
	{ 1, 0, 1 },
	{ 1, 1, 0 },
	{ 1, 1, 1 }
};

const DP Desired_Outputs[NO_PATTERNS][NO_OUTPUTS] = {
	{ 0 },
	{ 1 }, 
	{ 1 },
	{ 0 },
	{ 1 },
	{ 0 },
	{ 0 },
	{ 0 }
};


DP HardLimiter(DP Out)
{
	return (Out > 0.5 ? 1.0 : 0.0 );
}


class XORNet;

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

};





class XORNet {

private:
	Neuron Input_Layer[NO_INPUTS];
	Neuron Hidden_Layer[NO_HIDDEN];
	Neuron Output_Layer[NO_OUTPUTS];

	DP Outputs[NO_OUTPUTS];
	DP Hidden_Outputs[NO_HIDDEN];
		
	void Activate_Input_Layer(int p);
	void Activate_Hidden_Layer(int p);
	void Activate_Output_Layer(int p);

	void ActivateNet(int pattern_no);

public:
	XORNet(void);
	void Display(int p);
	void Run(void);
	
};


XORNet::XORNet(void)
{
	int i;
	for (i = 0; i < NO_INPUTS; i++) 
		Input_Layer[i] =  Neuron(Input_Weights[i], NO_INPUTS);
	for (i = 0; i < NO_HIDDEN; i++) 
		Hidden_Layer[i] =  Neuron(Hidden_Weights[i], NO_HIDDEN);
	for (i = 0; i < NO_OUTPUTS; i++) 
		Output_Layer[i] =  Neuron(Output_Weights[i], NO_HIDDEN);
}

void XORNet::Activate_Input_Layer(int p)
{
	for (int i = 0; i < NO_INPUTS; i++) 
		Input_Layer[i].SetOutput(Inputs[p][i]);
}

void XORNet::Activate_Hidden_Layer(int p)
{
	
	for (int i = 0; i < NO_HIDDEN; i++) {
		Hidden_Layer[i].SetInputs(Inputs[p]);
		Hidden_Layer[i].SetOutput(HardLimiter(Hidden_Layer[i].Summation()));
	}

	for (i = 0; i < NO_HIDDEN; i++) 
		Hidden_Outputs[i] = Hidden_Layer[i].GetOutput();
}

void XORNet::Activate_Output_Layer(int p)
{
	for (int i = 0; i < NO_OUTPUTS; i++) 
		Output_Layer[i].SetInputs(Hidden_Outputs);


	for (i = 0; i < NO_OUTPUTS; i++)
		Output_Layer[i].SetOutput(Outputs[i] = (HardLimiter(Output_Layer[i].Summation())));
}

void XORNet::ActivateNet(int pattern_no)
{

	Activate_Input_Layer(pattern_no);
	Activate_Hidden_Layer(pattern_no);
	Activate_Output_Layer(pattern_no);

}


void XORNet::Run(void)
{
	for (int i = 0; i < NO_PATTERNS; i++) {
			ActivateNet(i);
			Display(i);
		  }
}

void XORNet::Display(int p)
{

	cout << endl << "INPUTS";

	for (int j = 0; j < NO_INPUTS; j++)
		cout << " " << Inputs[p][j];
	cout << endl;
	cout << endl << "HIDDEN WEIGHTS" << endl;

	for (int i = 0; i < NO_HIDDEN; i++) {
		for(int  j = 0; j < NO_HIDDEN; j++)
			cout << Hidden_Layer[i].GetWeights()[j] << "  ";
		cout << endl;
	}

	cout << endl << "OUTPUT WEIGHTS" << endl;

	for (i = 0; i < NO_OUTPUTS; i++) {
		for(int j = 0; j < NO_HIDDEN; j++)
			cout << Output_Layer[i].GetWeights()[j] << "  ";
		cout << endl;
	}
	
	cout << endl  << "OUTPUTS "<< endl;
	i = 0;
	cout.precision(12);
	cout << Outputs[i];
	cout.precision(6);
	cout << endl;
	cin.get();
}

void main()
{
	XORNet b;
	b.Run();


}