#include <iostream>
#include <string>
#include "MatrixClassDef.cpp"

int ToTwo()
{
	return 2;
}

int main()
{

	std::vector<mtx::matrix<float>> Tweights;
	std::vector<mtx::matrix<float>> Tnodes;
	std::vector<int> tnet = { 3, 3, 3 };

	mtxai::NeurralNetSetup(&Tweights, &Tnodes, tnet);

	for (int i = 0; i < Tnodes.size(); i++)
	{
		std::cout << mtx::MatrixToString(Tnodes[i]) << std::endl;
	}
	
	return 0;
}