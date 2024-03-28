#pragma once

#include <vector>

namespace mtx
{

	template<typename t>
	class matrix
	{

	public:

		matrix(int width, int height, t filler)
		{
			for (int x = 0; x < width; x++)
			{
				Data.push_back({});
				for (int y = 0; y < height; y++)
				{
					Data[x].push_back(filler);
				}
			}
		}

		std::vector<std::vector<t>> Data;

		bool InsertData(int x, int y, t data);
		bool InsertHorazontalListData(std::vector<t> data, int x, int y);
		bool FillData(std::vector<std::vector<t>> data, int x, int y);

	};

}