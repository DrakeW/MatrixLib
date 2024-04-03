#include <iostream>
#include <string>
#include "MatrixClassDef.cpp"

int ToTwo(int x)
{
	return 2;
}

void NewPrint(std::string input)
{
	std::cout << "{Yay! this thing is working!} " << input << std::endl;
}

int main()
{
	mtx::ErrorFunc = &NewPrint;

	mtx::matrix<int> Matrix(2, 2, 0);
	mtx::matrix<int> SecondMatrix(2, 2, 0);
	mtx::print(mtx::IntMatrixToString(mtx::Multiply(Matrix, SecondMatrix)));
	
	return 0;
}