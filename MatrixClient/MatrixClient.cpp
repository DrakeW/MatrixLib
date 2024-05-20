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

	for(int i = 0; i < Tweights.size; i++ )
	
	return 0;
}