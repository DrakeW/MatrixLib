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

	mtx::matrix<int> Matrix(5, 5, 0);
	std::cout << mtx::IntMatrixToString(Matrix) << std::endl;
	std::vector<std::vector<int>> Fill = { {3, 3} };
	if (Matrix.Apply(&ToTwo, 20, 20))
	{
		std::cout << mtx::IntMatrixToString(Matrix) << std::endl;
	}
	return 0;
}