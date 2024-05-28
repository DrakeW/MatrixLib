#include <iostream>
#include <string>
#include "MatrixClassDef.cpp"

int ToTwo()
{
	return 2;
}

int main()
{

	srand(time(0));

	std::vector<mtx::matrix<float>> Tweights;
	std::vector<mtx::matrix<float>> Tnodes;
	std::vector<int> Tnet = { 3, 4, 3 };

	mtxai::NeurralNetSetup(&Tweights, &Tnodes, Tnet);

	std::vector<float> Tinput = { 0.5, 0.5, 0.3};

	mtxai::NeurralNetTest(Tinput, Tweights, &Tnodes);

	std::cout << mtxai::WeightInitFunc() << std::endl;

	for (int w = 0; w < Tweights.size(); w++)
	{
		std::cout << mtx::MatrixToString(Tweights[w]) << std::endl;
	}

	std::cout << mtx::MatrixToString(Tnodes[Tnodes.size() - 1]) << std::endl;
	
	return 0;
}