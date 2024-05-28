
#include "MatrixClass.h"
#include "Matrix.h"

namespace mtx
{
	/*
	"InsertData" function
	Arguments:
		int (x), int (y), t (data)
	Outputs:
		boolean
	Description:
		Inserts data at an x y position in a matrix
		Returns true if successful
	Additional Notes:
		Data type inserted must be the same data type as the matrix
	*/
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

	/*
	"FillData" function
	Arguments:
		std::vector<std::vector<t>> (data), int (x), int (y(
	Outputs:
		boolean
	Description:
		Fills data in a square at an x y position in a matrix using a 2D vector as input
		Returns true if successful
	Additional Notes:
		Data type inserted must be the same data type as the matrix
		Data size inserted must not exceed the bounds of the matrix
	*/
	template<typename t>
	bool matrix<t>::FillData(std::vector<std::vector<t>> data, int x, int y)
	{
		if (typeid(data[0][0]) == typeid(Data[0][0]) && x + data.size() <= Data.size() && y + data[0].size() <= Data[0].size())
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

	/*
	Apply function
	Arguments:
		t(*func)(t), int (x), int (y)
	Outputs:
		boolean
	Description:
		Applies a function at an x y position in the matrix
		Returns true if successful
	Additional Notes:
		Inputed function return value and arguments must be the same as matrix data type
		Enters the matrix data being edited as the argument into the function
	*/
	template<typename t>
	bool matrix<t>::Apply(t(*func)(t), int x, int y)
	{
		if (typeid(t) == typeid(Data[x][y]) && x <= Data.size() && y <= Data[0].size())
		{
			Data[x][y] = func(Data[x][y]);
			return true;
		}
		ErrorFunc("Apply function failed! (function with input, x y position)");
		return false;
	}

	/*
	Apply function
	Arguments:
		t(*func)(t), int (x), int (y), int (w), int (h)
	Outputs:
		boolean
	Description:
		Applies a function in a rectangle with a width of w and a height of h at an x y position in the matrix
		Returns true if successful
	Additional Notes:
		Inputed function return value and arguments must be the same as matrix data type
		Enters the matrix data being edited as the argument into the function (one at a time)
	*/
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
		ErrorFunc("Apply function failed! (function with input, x y position, w h fill)");
		return false;
	}

	/*
	Apply function
	Arguments:
		t(*func)(), int (x), int (y)
	Outputs:
		boolean
	Description:
		Applies a function at an x y position in the matrix
		Returns true if successful
	Additional Notes:
		Inputed function return value must be the same as matrix data type
	*/
	template<typename t>
	bool matrix<t>::Apply(t(*func)(), int x, int y)
	{
		if (typeid(t) == typeid(Data[x][y]) && x <= Data.size() && y <= Data[0].size())
		{
			Data[x][y] = func();
			return true;
		}
		ErrorFunc("Apply function failed! (function no input, x y position)");
		return false;
	}

	/*
	Apply function
	Arguments:
		t(*func)(t), int (x), int (y), int (w), int (h)
	Outputs:
		boolean
	Description:
		Applies a function in a rectangle with a width of w and a height of h at an x y position in the matrix
		Returns true if successful
	Additional Notes:
		Inputed function return value must be the same as matrix data type
	*/
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
		ErrorFunc("Apply function failed! (function no input, x y position, w h fill)");
		return false;
	}

	/*
	Apply function
	Arguments:
		t(*func)(t)
	Outputs:
		boolean
	Description:
		Applies a function to all data in the matrix
		Returns true if successful
	Additional Notes:
		Inputed function return value and arguments must be the same as matrix data type
		Enters the matrix data being edited as the argument into the function (one at a time)
	*/
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
		ErrorFunc("Apply function failed! (function with input)");
		return false;
	}

	/*
	Apply function
	Arguments:
		t(*func)(t)
	Outputs:
		boolean
	Description:
		Applies a function to all data in the matrix
		Returns true if successful
	Additional Notes:
		Inputed function return value must be the same as matrix data type
	*/
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
		ErrorFunc("Apply function failed! (function no input)");
		return false;
	}
	 
}