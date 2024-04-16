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

	mtx::matrix<int> Matrix(2, 3, 'i');
	mtx::matrix<int> SecondMatrix(3, 2, 'i');
	mtx::print(MatrixToString(Matrix));
	mtx::print(MatrixToString(SecondMatrix));
	//mtx::print(mtx::MatrixToString(mtx::Multiply(Matrix, SecondMatrix)));
	
	return 0;
}