#include <iostream>
#include <string>
#include "MatrixClassDef.cpp"

int main()
{

	mtx::matrix<bool> Matrix(2, 3, true);
	mtx::matrix<bool> SecondMatrix(3, 2, true);
	mtx::print(MatrixToString(Matrix));
	mtx::print(MatrixToString(SecondMatrix));
	mtx::print(mtx::MatrixToString(mtx::Multiply(Matrix, SecondMatrix)));
	
	return 0;
}