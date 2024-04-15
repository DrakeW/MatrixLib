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

<<<<<<< Updated upstream
	mtx::matrix<int> Matrix(2, 3, 0);
	mtx::matrix<int> SecondMatrix(3, 2, 0);
	mtx::print(IntMatrixToString(Matrix));
	mtx::print(IntMatrixToString(SecondMatrix));
=======
	mtx::matrix<int> Matrix(4, 2, 0);
	mtx::matrix<int> SecondMatrix(3, 3, 0);
>>>>>>> Stashed changes
	mtx::print(mtx::IntMatrixToString(mtx::Multiply(Matrix, SecondMatrix)));
	
	return 0;
}