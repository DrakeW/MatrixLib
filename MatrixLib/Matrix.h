#pragma once

#include <vector>
#include "MatrixClass.h"

namespace mtx
{
	template<typename t>
	int VectorMaxHeight(std::vector<std::vector<t>> data)
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

}