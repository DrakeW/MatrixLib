#pragma once

#include <vector>

namespace mtx
{

	/*
	"matrix" class
	Constructors:
		1:
		matrix class constructor
		Arguments:
			int (width), int (height), t (filler
		Outputs:
			None
		Description:
			Creates the matrix with a width of width and a height of height
			Fills the whole matrix with filler
		Additional Notes:
			None
		2:
		matrix class constructor
		Arguments;
			int (width), int (height)
		Outputs:
			None
		Description
			Creates a matrix with a width of width and a height of height
			Does not give it any value
		Additional Notes:
			Alocates the space for the matrix, but no data is entered
	Functions:
		Apply
		InsertData
		FillData
	Variables:
		std::vector<std::vector<t>> Data
	Description:
		A basic 2D matrix
	Additional Notes:
		None
	*/
	template<typename t>
	class matrix
	{

	public:

		/*
		matrix class constructor
		Arguments:
			int (width), int (height), t (filler
		Outputs:
			None
		Description:
			Creates the matrix with a width of width and a height of height
			Fills the whole matrix with filler
		Additional Notes:
			None
		*/
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

		/*
		matrix class constructor
		Arguments;
			int (width), int (height)
		Outputs:
			None
		Description
			Creates a matrix with a width of width and a height of height
			Does not give it any value
		Additional Notes:
			Alocates the space for the matrix, but no data is entered
		*/
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

		/*
		"Data" variable
		Type:
			std::vector<std::vector<t>>
		Initializer:
			None - set in constructor
		Description:
			Two dimensional vector of type t
			Holds the data for the matrix
		Additional Notes:
			Starts with no data or value, as this is done in the constructor
		*/
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