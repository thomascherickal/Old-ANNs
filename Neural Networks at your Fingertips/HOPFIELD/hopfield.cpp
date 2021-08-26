
#include "neurons.h"



class Hopfield {

private:
	Neuron HopNet[NO_ELEMENTS];
	
	DP Outputs[NO_ELEMENTS];

	DP Old_Outputs[NO_ELEMENTS];
	DP New_Outputs[NO_ELEMENTS];
		
	void IterateNet(int i);
	void InitializeWeights(void);
	void SetUpNetwork(void);
	void ReplaceZeros(void);
	void ReplaceMinusOnes(void);
public:
	Hopfield(void);
	DP Convergence(void);
	void Display(void);
	void Train(void);
	
};

Hopfield::Hopfield(void)
{
	srand(4711);
	ReplaceZeros();
	InitializeWeights();
	ReplaceMinusOnes();
}

void Hopfield::ReplaceZeros()
{
	for (int i = 0; i < NO_VECTORS; i++)
	{
		for (int j = 0; j < NO_ELEMENTS; j++) {
			Vectors[i][j] = (Vectors[i][j] == 0) ? -1 : 1;
			Inputs[i][j] = (Inputs[i][j] == 0) ? -1 : 1;
		}
	}
}

void Hopfield::ReplaceMinusOnes()
{
	for (int j = 0; j < NO_ELEMENTS; j++) 
			Outputs[j] = (Outputs[j] == -1.00) ? 0 : 1;

	for (int i = 0; i < NO_VECTORS; i++)
	{
		for (int j = 0; j < NO_ELEMENTS; j++) {
			Vectors[i][j] = (Vectors[i][j] == -1) ? 0 : 1;
			Inputs[i][j] = (Inputs[i][j] == -1) ? 0 : 1;
		}
	}
}

void Hopfield::SetUpNetwork(void)
{
	int i;
	for (i = 0; i < NO_ELEMENTS; i++)
	{
		HopNet[i].SetOutput(Outputs[i] = Inputs[INPUT_NO][i]);
	}
}

void Hopfield::IterateNet(int i)
{
	int j;
	DP S;

		S = 0;
	
		for (j = 0; j < NO_ELEMENTS; j++)
		{
			S += Weights[i][j] * HopNet[j].GetOutput();
		}

		Old_Outputs[i] = HopNet[i].GetOutput();
		New_Outputs[i] = !HardLimiter(S) ? Old_Outputs[i] : HardLimiter(S);


	
		HopNet[i].SetOutput(Outputs[i] = New_Outputs[i]);


}


void Hopfield::InitializeWeights(void)
{
	int i, j, l;
	for (i = 0; i < NO_ELEMENTS; i++)
	{
		for (j = 0; j < NO_ELEMENTS; j++)
		{
			Weights[i][j] = 0;
			if (i == j ) continue;
			for (l = 0; l < NO_VECTORS; l++)
				Weights[i][j] += Vectors[l][i] * Vectors[l][j];
			Weights[i][j] /= NO_ELEMENTS;
		}
	}
}


void Hopfield::Train(void)
{
	int iter = 0, i;
	ReplaceZeros();
	SetUpNetwork();
	do
	{
		i = rand() % NO_ELEMENTS;
		IterateNet(i);
		iter++;

	} while (iter < MAX_ITERATIONS);
	cout << "Iterations " << iter << endl;
	cout << "Convergence " << Convergence() << endl;
	ReplaceMinusOnes();
	Display();
}

DP Hopfield::Convergence()
{ 
	int i;
	DP S = 0;
	for (i = 0; i < NO_ELEMENTS; i++)
	{
		S += fabs(Old_Outputs[i] - New_Outputs[i]);
	}
	return S;
}

void Hopfield::Display(void)
{
	int i, l;
	cout << endl << "Vectors" << endl;
	for (l = 0; l < NO_VECTORS; l++)
	{
		cout << endl ;
		for (i = 0; i < NO_ELEMENTS; i++)
		{
			cout << Vectors[l][i];
			if (((i + 1) % MODULUS == 0 )&& i) cout << endl;
		}
		cout << endl ;
	}

		cout << endl << "Inputs" << endl;

		cout << endl ;
		for (i = 0; i < NO_ELEMENTS; i++)
		{
			cout << Inputs[INPUT_NO][i];
			if (((i + 1) % MODULUS == 0 )&& i) cout << endl;
		}
		cout << endl ;

	cout << endl << "Final Output" << endl;
		for (i = 0; i < NO_ELEMENTS; i++)
		{
			cout << Outputs[i];
			if (((i + 1) % MODULUS == 0 )&& i) cout << endl;
		}
	

}

void main()
{
	Hopfield h;
	h.Train();
	getch();

}