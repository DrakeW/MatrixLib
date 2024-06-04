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
	std::vector<int> Tnet = { 3, 60, 50, 3};

	mtxai::NeurralNetSetup(&Tweights, &Tnodes, Tnet);

	std::vector<float> Tinput = { 10, 20, 15};
	std::vector<float> Ttarget = { 0, 0, 1};

	std::vector<float> Tinput2 = { 20, 80, 50 };
	std::vector<float> Ttarget2 = { 1, 0, 0 };

	mtxai::NeurralNetTest(Tinput, Tweights, &Tnodes);

	for (int e = 0; e < 5000; e++)
	{
		mtxai::NeurralNetTrain(Tinput, Ttarget, &Tweights, &Tnodes);
		mtxai::NeurralNetTrain(Tinput2, Ttarget2, &Tweights, &Tnodes);
	}

	mtxai::NeurralNetTest(Tinput, Tweights, &Tnodes);

	for (int w = 0; w < Tweights.size(); w++)
	{
		std::cout << mtx::MatrixToString(Tweights[w]) << std::endl;
	}

	std::cout << mtx::MatrixToString(Tnodes[Tnodes.size() - 1]) << std::endl;

	mtxai::NeurralNetTest(Tinput2, Tweights, &Tnodes);

	std::cout << mtx::MatrixToString(Tnodes[Tnodes.size() - 1]) << std::endl;
	
	return 0;
}