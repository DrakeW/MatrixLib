#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "MatrixClass.h"

namespace mtx
{

	void print(std::string input)
	{
		std::cout << input << std::endl;
	}

	void(*ErrorFunc)(std::string) = &print;

	template<typename t>
	int MaxHeight(std::vector<std::vector<t>> data)
	{
		int max = 0;
		for (int x = 0; x < data.size(); x++)
		{
			if (data[x].size() > max)
			{
				max = data[x].size();
			}
		}
		return max;
	}

	template<typename t>
	int MaxHeight(matrix<t> mtx)
	{
		int max = 0;
		for (int x = 0; x < mtx.Data.size(); x++)
		{
			if (mtx.Data[x].size() > max)
			{
				max = mtx.Data[x].size();
			}
		}
		return max;
	}

	template<typename t>
	std::string IntMatrixToString(matrix<t> mtx)
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
			ErrorFunc("Multiply function failed! Matrix:\n" + IntMatrixToString(first) + " Cannot be multiplied by\nMatrix:\n" + IntMatrixToString(second));
			return result;
		}
	}
}