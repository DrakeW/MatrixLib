#include "Matrix.h"
#include "MatrixClassDef.cpp"
#include <iostream>

int main()
{
	mtx::matrix<int> Matrix(3, 3, 1);
	std::cout << mtx::IntMatrixToString(Matrix) << std::endl;
	std::vector<std::vector<int>> Fill = { {2, 2}, {2, 2} };
	if(Matrix.FillData(Fill, 0, 0))
		std::cout << mtx::IntMatrixToString(Matrix) << std::endl;
	return 0;
}