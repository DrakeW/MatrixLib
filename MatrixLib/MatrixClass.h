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
		matrix(int width, int height)
		{
			for (int x = 0; x < width; x++)
			{
				Data.push_back({});
				for (int y = 0; y < height; y++)
				{
					Data[x].push_back({});
				}
			}
		}

		std::vector<std::vector<t>> Data;

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
		bool InsertData(int x, int y, t data);
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
		bool FillData(std::vector<std::vector<t>> data, int x, int y);
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
		bool Apply(t(*func)(t));
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
		bool Apply(t(*func)());
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
		bool Apply(t(*func)(t), int x, int y);
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
		bool Apply(t(*func)(t), int x, int y, int w, int h);
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
		bool Apply(t(*func)(), int x, int y);
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
		bool Apply(t(*func)(), int x, int y, int w, int h);

	};

}