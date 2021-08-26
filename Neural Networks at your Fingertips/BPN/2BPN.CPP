
#include "2neurons.h"



class BPN {

private:
	Neuron Input_Layer[NO_INPUTS];
	Neuron Hidden_Layer[NO_HIDDEN];
	Neuron Output_Layer[NO_OUTPUTS];

	DP Outputs[NO_OUTPUTS];
	DP Total_Error;
	DP Hidden_Outputs[NO_HIDDEN];
	DP Hidden_Error[NO_HIDDEN];
	DP Output_Error[NO_OUTPUTS];

	void Activate_Input_Layer(int p);
	void Activate_Hidden_Layer(int p);
	void Activate_Output_Layer(int p);

	void ActivateNet(int pattern_no);

	void BP_Hidden_Layer(int pattern_no);
	void BP_Output_Layer(int pattern_no);
	void BackPropogate(int pattern_no);

public:
	void Initialize(void);
	BPN (void);
	DP Error(int pattern_no);
	void Display(int p);
	void Train(void);
};

void BPN::Initialize(void)
{
	for(int i= 0; i < NO_HIDDEN; i++)
		Hidden_Layer[i].SetWeights(Hidden_Weights[i]);
	for(i = 0; i < NO_OUTPUTS; i++)
		Hidden_Layer[i].SetWeights(Output_Weights[i]);
}


BPN::BPN(void)
{
	int i;
	for (i = 0; i < NO_INPUTS; i++)
		Input_Layer[i] =  Neuron(Input_Weights[i], NO_INPUTS);
	for (i = 0; i < NO_HIDDEN; i++)
		Hidden_Layer[i] =  Neuron(Hidden_Weights[i], NO_HIDDEN);
	for (i = 0; i < NO_OUTPUTS; i++)
		Output_Layer[i] =  Neuron(Output_Weights[i], NO_HIDDEN);
}

void BPN::Activate_Input_Layer(int p)
{
	for (int i = 0; i < NO_INPUTS; i++)
		Input_Layer[i].SetOutput(Inputs[p][i]);
}


void BPN::Activate_Hidden_Layer(int p)
{


	for (int i = 0; i < NO_HIDDEN; i++) {
		Hidden_Layer[i].SetInputs(Inputs[p]);
		Hidden_Layer[i].SetOutput(HardLimiter(Hidden_Layer[i].Summation()));
	}

	for (i = 0; i < NO_HIDDEN; i++)
		Hidden_Outputs[i] = Hidden_Layer[i].GetOutput();
}

void BPN::Activate_Output_Layer(int p)
{
	
	for (int i = 0; i < NO_OUTPUTS; i++) 
		Output_Layer[i].SetInputs(Hidden_Outputs);


	for (i = 0; i < NO_OUTPUTS; i++)
		Output_Layer[i].SetOutput(Outputs[i] = (HardLimiter(Output_Layer[i].Summation())));
}

void BPN::ActivateNet(int pattern_no)
{

	Activate_Input_Layer(pattern_no);
	Activate_Hidden_Layer(pattern_no);
	Activate_Output_Layer(pattern_no);

}

void BPN::BP_Output_Layer(int pattern_no)
{
	
	for (int  i = 0; i < NO_OUTPUTS; i++)
		Output_Error[i] = (Desired_Outputs[pattern_no][i] - Outputs[i]) * Deriv(Outputs[i]);	
	for (i = 0; i < NO_OUTPUTS; i++)
		Output_Layer[i].UpdateWeights(Output_Error[i]);
	
 
}

void BPN::BP_Hidden_Layer(int pattern_no)
{

	DP Sum[NO_HIDDEN];

	
	for (int i = 0; i < NO_HIDDEN; i++)
		Sum[i]= 0;

	for (i = 0; i < NO_OUTPUTS; i++)
		for (int j = 0; j < NO_HIDDEN; j++) 
			Sum[j] = Output_Error[i] * Output_Layer[i].GetWeights()[j];

	for ( i = 0; i < NO_HIDDEN; i++)
		Hidden_Error[i] = Sum[i] * Deriv(Hidden_Layer[i].GetOutput());

	for ( i = 0; i < NO_HIDDEN; i++)
		Hidden_Layer[i].UpdateWeights(Hidden_Error[i]);
}

void BPN::BackPropogate(int pattern_no)
{
	
    BP_Output_Layer(pattern_no);
	BP_Hidden_Layer(pattern_no);
}

DP BPN::Error(int pattern_no)
{
	//for (int i = 0; i < NO_OUTPUTS; i++)
	return 0.5 * pow(Outputs[0] - Desired_Outputs[pattern_no][0], 2);
}

void BPN::Train(void)
{
	DP Total_Error = 1;
	DP counter = 0;
	while (dabs(Total_Error) >= LEAST_ERROR && counter < MAX_ITERATIONS) {
		Total_Error = 0;
		for (int i = 0; i < NO_PATTERNS; i++) {
			ActivateNet(i);
//			if (counter == 10000) i = i/0;
			
			BackPropogate(i);
			Total_Error += Error(i);
			//Display(i);
		  }
		//EtaAdjust(Total_Error);
		counter++;
		cout << counter << " " << Total_Error << endl;
	}
	cout << counter << endl;
	for (int i = 0; i < NO_PATTERNS; i++) {
			ActivateNet(i);
			BackPropogate(i);
			Display(i);
		  }
	
}

void BPN::Display(int p)
{

	cout << endl << "INPUTS" << endl;

	for (int j = 0; j < NO_INPUTS; j++)
		cout << " " << Inputs[p][j];
	cout << endl;
	cout << endl << "HIDDEN WEIGHTS" << endl;

	for (int i = 0; i < NO_HIDDEN; i++) {
		for(int  j = 0; j < NO_HIDDEN; j++)
			cout << Hidden_Layer[i].GetWeights()[j] << "  ";
		cout << endl;
	}
	
	cout << endl << "HIDDEN ERROR" << endl;
	for (i = 0; i < NO_HIDDEN; i++)
		cout << Hidden_Error[i] << " ";
	cout << endl;

	cout << endl << "HIDDEN OUTPUTS " << endl;
	for ( i = 0; i < NO_HIDDEN; i++) {
		for(int  j = 0; j < NO_HIDDEN; j++)
			cout << Hidden_Layer[i].GetOutput() << "  ";
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

	cout << endl << "OUTPUT ERROR" << endl;
	cout << Output_Error[0];
	cin.get();
}

void main()
{
	BPN b;
	b.Train();

}