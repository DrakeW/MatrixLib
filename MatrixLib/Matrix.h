#pragma once

#include <vector>
#include <string>
#include "MatrixClass.h"

namespace mtx
{
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

		for (int x = 0; x < mtx.Data.size(); x++)
		{
			for (int y = 0; y < mtx.Data[x].size(); y++)
			{
				result.append(std::to_string(mtx.Data[x][y]));
			}
			result.append("\n");
		}

		return result;
	}
}