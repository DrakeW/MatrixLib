#include "Matrix.h"
#include <iostream>
#include "MatrixClassDef.cpp"

int ToTwo()
{
	return 2;
}

int main()
{
	mtx::matrix<int> Matrix(5, 5, 0);
	std::cout << mtx::IntMatrixToString(Matrix) << std::endl;
	std::vector<std::vector<int>> Fill = { {3, 3} };
	if (Matrix.Apply(&ToTwo, 1, 1))
	{
		std::cout << mtx::IntMatrixToString(Matrix) << std::endl;
	}
	return 0;
}