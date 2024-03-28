#include "Matrix.h"
#include "MatrixClassDef.cpp"
#include <iostream>

int main()
{
	mtx::matrix<int> Matrix(5, 5, 1);
	std::cout << mtx::IntMatrixToString(Matrix) << std::endl;
	std::vector<std::vector<int>> Fill = { {2, 2}, {3, 3} };
	if(Matrix.FillData(Fill, 2, 1))
		std::cout << mtx::IntMatrixToString(Matrix) << std::endl;
	return 0;
}