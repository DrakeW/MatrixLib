
#include "MatrixClass.h"
#include "Matrix.h"

namespace mtx
{
	template<typename t>
	bool matrix<t>::InsertData(int x, int y, t data)
	{
		if (typeid(data) == typeid(Data[0][0]))
		{
			Data[x][y] = data;
			return true;
		}
		ErrorFunc("InsertData function failed!");
		return false;
	}

	template<typename t>
	bool matrix<t>::FillData(std::vector<std::vector<t>> data, int x, int y)
	{
		if (typeid(data[0][0]) == typeid(Data[0][0]) && x + data.size() <= Data.size() && y + data[0].size() <= MaxHeight(Data))
		{
			for (int X = 0; X < data.size(); X++)
			{
				for (int Y = 0; Y < data[X].size(); Y++)
				{
					Data[X + x][Y + y] = data[X][Y];
				}
			}
			return true;
		}
		ErrorFunc("FillData function failed!");
		return false;
	}

	template<typename t>
	bool matrix<t>::Apply(t(*func)(t), int x, int y)
	{
		if (typeid(t) == typeid(Data[x][y]))
		{
			Data[x][y] = func(Data[x][y]);
			return true;
		}
		ErrorFunc("Apply function failed!");
		return false;
	}

	template<typename t>
	bool matrix<t>::Apply(t(*func)(t), int x, int y, int w, int h)
	{
		if (typeid(t) == typeid(Data[x][y]) && w + x <= Data.size() && h + x <= Data[x].size())
		{
			for (int X = 0; X < w; X++)
			{
				for (int Y = 0; Y < h; Y++)
				{
					Data[X + x][Y + y] = func(Data[X + x][Y + y]);
				}
			}
			return true;
		}
		mtx::ErrorFunc("Apply function failed sorta!");
		return false;
	}

	template<typename t>
	bool matrix<t>::Apply(t(*func)(), int x, int y)
	{
		if (typeid(t) == typeid(Data[x][y]))
		{
			Data[x][y] = func();
			return true;
		}
		ErrorFunc("Apply function failed!");
		return false;
	}

	template<typename t>
	bool matrix<t>::Apply(t(*func)(), int x, int y, int w, int h)
	{
		if (typeid(t) == typeid(Data[x][y]) && w + x <= Data.size() && h + x <= Data[x].size())
		{
			for (int X = 0; X < w; X++)
			{
				for (int Y = 0; Y < h; Y++)
				{
					Data[X + x][Y + y] = func();
				}
			}
			return true;
		}
		ErrorFunc("Apply function failed!");
		return false;
	}

	template<typename t>
	bool matrix<t>::Apply(t(*func)(t))
	{
		if (typeid(t) == typeid(Data[0][0]))
		{
			for (int X = 0; X < Data.size(); X++)
			{
				for (int Y = 0; Y < Data[X].size(); Y++)
				{
					Data[X][Y] = func(Data[X][Y]);
				}
			}
			return true;
		}
		ErrorFunc("Apply function failed!");
		return false;
	}

	template<typename t>
	bool matrix<t>::Apply(t(*func)())
	{
		if (typeid(t) == typeid(Data[0][0]))
		{
			for (int X = 0; X < Data.size(); X++)
			{
				for (int Y = 0; Y < Data[X].size(); Y++)
				{
					Data[X][Y] = func();
				}
			}
			return true;
		}
		ErrorFunc("Apply function failed!");
		return false;
	}

}