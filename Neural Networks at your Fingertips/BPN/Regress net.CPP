
#include "regress n.h"




class BPN {

private:
	Neuron Input_Layer[NO_INPUTS];
	Neuron Hidden_Layer[NO_HIDDEN];
	Neuron Output_Layer[NO_OUTPUTS];

	DP Outputs[NO_PATTERNS][NO_OUTPUTS];
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
	
	BPN (void);
	DP Error(int pattern_no);
	void Display(int p);
	void Train(void);
	void Test(void);
	
};

BPN::BPN(void)
{
	int i;
	
	for (i = 0; i < NO_INPUTS; i++) { 
		Input_Layer[i] =  Neuron(Input_Weights[i], NO_INPUTS);
	}
	for (i = 0; i < NO_HIDDEN; i++)  {
		Hidden_Layer[i] =  Neuron(Hidden_Weights[i], NO_HIDDEN);
		Hidden_Layer[i].SetBias(Hidden_Biases[i]);
	}
	for (i = 0; i < NO_OUTPUTS; i++) {
		Output_Layer[i] =  Neuron(Output_Weights[i], NO_HIDDEN);
		Output_Layer[i].SetBias(Output_Biases[i]);
	}
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
		Hidden_Layer[i].SetOutput(Activate(Hidden_Layer[i].Summation()));
	}

	for (i = 0; i < NO_HIDDEN; i++) 
		Hidden_Outputs[i] = Hidden_Layer[i].GetOutput();
}

void BPN::Activate_Output_Layer(int p)
{
	for (int i = 0; i < NO_OUTPUTS; i++) 
		Output_Layer[i].SetInputs(Hidden_Outputs);


	for (i = 0; i < NO_OUTPUTS; i++)
		Output_Layer[i].SetOutput(Outputs[p][i] = (Activate(Output_Layer[i].Summation())));
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
		Output_Error[i] = (Desired_Outputs[pattern_no][i] - Outputs[pattern_no][i])* Deriv(Outputs[pattern_no][i]);	
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
			Sum[j] += Output_Error[i] * Output_Layer[i].GetWeights()[j];

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
	return 0.5 * pow(Outputs[pattern_no][0] - Desired_Outputs[pattern_no][0], 2);
}


void BPN::Train(void)
{
	DP Total_Error = 1;
	DP counter = 0;
	//ofstream outfile = ofstream("withFCNN.dat");
	while ( counter < MAX_ITERATIONS) {
		Total_Error = 0;
		for (int i = 0; i < NO_PATTERNS; i++) {
			ActivateNet(i);
			
			BackPropogate(i);
			Total_Error += Error(i);
		}
		//EtaAdjust(Error(i));
			counter++;

		cout << counter << " " << Total_Error;
		cout << endl;
	}
	//outfile << counter << endl;
	//outfile.close();
}

void BPN::Test(void)
{
	int i, j;
	for (i = 0; i < NO_PATTERNS; i++)
		for (j = 0; j < NO_INPUTS; j++)
			Inputs[i][j] = TestInputs[i][j];

	for (i = 0; i < NO_PATTERNS; i++) {
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
	cout << Outputs[p][i];
	cout << endl;
	cout << endl << "OUTPUT ERROR" << endl;
	cout << Output_Error[0];
	//cin.get();
}

void main()
{
	BPN b;
	b.Train();
	b.Test();

}