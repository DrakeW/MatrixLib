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
		bool FillData(std::vector<std::vector<t>> data, int x, int y);
		bool Apply(t(*func)(t));
		bool Apply(t(*func)());
		bool Apply(t(*func)(t), int x, int y);
		bool Apply(t(*func)(t), int x, int y, int w, int h);
		bool Apply(t(*func)(), int x, int y);
		bool Apply(t(*func)(), int x, int y, int w, int h);

	};

}