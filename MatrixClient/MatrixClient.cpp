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

	mtx::matrix<bool> Matrix(2, 3, true);
	mtx::matrix<bool> SecondMatrix(3, 2, true);
	mtx::print(MatrixToString(Matrix));
	mtx::print(MatrixToString(SecondMatrix));
	mtx::print(mtx::MatrixToString(mtx::Multiply(Matrix, SecondMatrix)));
	
	return 0;
}