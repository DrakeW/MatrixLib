#include "Matrix.h"
#include <iostream>
#include "MatrixClassDef.cpp"

int main()
{
	mtx::matrix<int> Matrix(5, 5, 1);
	std::cout << mtx::IntMatrixToString(Matrix) << std::endl;
	std::vector<int> Fill = {3, 3};
	return 0;
}