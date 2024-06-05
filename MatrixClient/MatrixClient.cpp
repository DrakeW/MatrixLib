#include <iostream>
#include <string>
#include "MatrixInclude.h"

int ToTwo()
{
	return 2;
}

int main()
{
	srand(rand() ^ time(NULL));

	std::vector<mtx::matrix<float>> Tweights;
	std::vector<mtx::matrix<float>> Tnodes;
	std::vector<int> Tnet = { 3, 20, 3, 1};

	mtxai::NeurralNetSetup(&Tweights, &Tnodes, Tnet);

	std::vector<float> Tinput = { 0.5, 0.7, 0.2};
	std::vector<float> Ttarget = {1.0};

	std::vector<float> Tinput2 = { 20.0, 80.0, 50.0 };
	std::vector<float> Ttarget2 = {0.0};

	mtxai::NeuralNetTest(Tinput, Tweights, &Tnodes);

	for (int e = 0; e < 5000; e++)
	{
		mtxai::NeuralNetTrain(Tinput, Ttarget, &Tweights, &Tnodes);
		mtxai::NeuralNetTrain(Tinput2, Ttarget2, &Tweights, &Tnodes);
	}

	mtxai::NeuralNetTest(Tinput, Tweights, &Tnodes);

	for (int w = 0; w < Tweights.size(); w++)
	{
		std::cout << mtx::MatrixToString(Tweights[w]) << std::endl;
	}

	std::cout << mtx::MatrixToString(Tnodes[Tnodes.size() - 1]) << std::endl;

	mtxai::NeuralNetTest(Tinput2, Tweights, &Tnodes);

	std::cout << mtx::MatrixToString(Tnodes[Tnodes.size() - 1]) << std::endl;
	
	return 0;
}