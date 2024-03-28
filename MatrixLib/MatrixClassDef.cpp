
#include "MatrixClass.h"
#include "Matrix.h"

namespace mtx
{
	template<typename t>
	bool matrix<t>::InsertData(int x, int y, t data)
	{
		if (typeid(data) = typeid(Data[0][0]))
		{
			Data[x][y] = data;
			return true;
		}
		return false;
	}

	template<typename t>
	bool matrix<t>::FillData(std::vector<std::vector<t>> data, int x, int y)
	{
		if ((x + data.size() < Data.size() && y + data[0].size() < VectorMaxHeight(data) && typeid(Data) = typeid(data)))
		{
			for (int X = 0; X < data.size(); X++)
			{
				for (int Y = 0; Y < data[X].size(); Y++)
				{
					Data[X + x][Y + y] = data[x][y];
				}
			}
			return true;
		}
		return false;
	}

}