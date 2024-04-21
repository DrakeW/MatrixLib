#include <iostream>
#include <string>
#include "MatrixClassDef.cpp"

int ToTwo()
{
	return 2;
}

int main()
{

	mtx::matrix<int> Matrix(2, 3, 1);
	mtx::matrix<int> SecondMatrix(3, 2, 1);
	Matrix.Apply(&ToTwo);
	mtx::print(MatrixToString(Matrix));
	mtx::print(MatrixToString(SecondMatrix));
	mtx::print(mtx::MatrixToString(mtx::Multiply(Matrix, SecondMatrix)));
	
	return 0;
}