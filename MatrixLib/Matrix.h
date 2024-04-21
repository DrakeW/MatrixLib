#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "MatrixClass.h"

namespace mtx
{
	/*
	"print" function:
	Arguments:
	string (input)
	Outputs:
	none
	Description:
		Prints the input to the console using std::cout from the iostream library
	Additional Notes:
		Used to print errors out to the console
	*/
	void print(std::string input)
	{
		std::cout << input.data() << std::endl;
	}

	/*
	"Errorfunc" variable
	Type:
		void function pointer with string input
	Initializer:
		Referance to "print" function
	Description:
		Used to access a function to print errors out to
	Additional Notes:
		Can be overridden for extra functionality
	*/
	void(*ErrorFunc)(std::string) = &print;

	/*
		MatrixToString function
		Arguments:
			matrix<int> (mtx)
		Outputs:
			string
		Description:
			Converts an int matrix into a string
		Additional Notes:
			Used in the multiplication function for error printing
	*/
	std::string MatrixToString(matrix<int> mtx)
	{
		std::string result;

		for (int y = 0; y < mtx.Data[0].size(); y++)
		{
			for (int x = 0; x < mtx.Data.size(); x++)
			{
				result.append(std::to_string(mtx.Data[x][y]));
			}
			result.append("\n");
		}

		return result;
	}

	/*
		MatrixToString function
		Arguments:
			matrix<float> (mtx)
		Outputs:
			string
		Description:
			Converts a float matrix into a string
		Additional Notes:
			Used in the multiplication function for error printing
	*/
	std::string MatrixToString(matrix<float> mtx)
	{
		std::string result;

		for (int y = 0; y < mtx.Data[0].size(); y++)
		{
			for (int x = 0; x < mtx.Data.size(); x++)
			{
				result.append(std::to_string(mtx.Data[x][y]));
			}
			result.append("\n");
		}

		return result;
	}

	/*
		MatrixToString function
		Arguments:
			matrix<bool> (mtx)
		Outputs:
			string
		Description:
			Converts a boolean matrix into a string
		Additional Notes:
			Used in the multiplication function for error printing
			Returned string is in true or false
	*/
	std::string MatrixToString(matrix<bool> mtx)
	{
		std::string result;

		for (int y = 0; y < mtx.Data[0].size(); y++)
		{
			for (int x = 0; x < mtx.Data.size(); x++)
			{
				if (mtx.Data[x][y])
				{
					result.append("true");
				}
				else
				{
					result.append("false");
				}
			}
			result.append("\n");
		}

		return result;
	}

	/*
		MatrixToString function
		Arguments:
			matrix<char> (mtx)
		Outputs:
			string
		Description:
			Converts a char matrix into a string
		Additional Notes:
			Used in the multiplication function for error printing
	*/
	std::string MatrixToString(matrix<char> mtx)
	{
		std::string result;

		for (int y = 0; y < mtx.Data[0].size(); y++)
		{
			for (int x = 0; x < mtx.Data.size(); x++)
			{
				result.push_back((char)(mtx.Data[x][y]));
			}
			result.append("\n");
		}

		return result;
	}

	/*
	"Multiply" function
	Arguments:
		matrix<t> first, matrix<t> second
	Outputs:
		matrix<t> (x = first.Data.size(), y = second.Data[0].size())
	Description:
		Multiplies the first matrix by the second matrix (first * second)
	Additional Notes:
		Will return a matrix of type t with a width and height of 1 filled with 0 on fail
		Will print an error message on fail
	*/
	template<typename t>
	matrix<t> Multiply(matrix<t> first, matrix<t> second)
	{
		if (first.Data.size() == second.Data[0].size())
		{
			matrix<t> result(second.Data.size(), first.Data[0].size(), 0);
			for (int fy = 0; fy < first.Data[0].size(); fy++)
			{
				for (int sx = 0; sx < second.Data.size(); sx++)
				{
					t DataEntry = 0;

					for (int e = 0; e < first.Data.size(); e++)
					{
						DataEntry += first.Data[e][fy] * second.Data[sx][e];
					}
					result.Data[sx][fy] = DataEntry;
				}

			}
			return result;
		}
		else
		{
			matrix<t> result(1, 1, 0);
			ErrorFunc("Multiply function failed! Matrix:\n" + MatrixToString(first) + " Cannot be multiplied by\nMatrix:\n" + MatrixToString(second));
			return result;
		}
	}
}

namespace mtxai
{
	void NeurralNetSetup(std::vector<mtx::matrix<float>>* weights, std::vector<mtx::matrix<float>>* nodes)
	{

	}
}