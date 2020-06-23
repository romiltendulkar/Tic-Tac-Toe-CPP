#pragma once

#include <vector>

/**
	The board class will be used so the board can be dynamically created in size based on m and n
	The k Value for MNK game is also associated with this class
*/
class Board
{
public:
	/**
		The default constructor for board will create a standard tic tac toe board. ie:- 3 x 3
	*/
	Board();

	/**
		Constructor for board that creates the board based on the three integers passed

		\param nrows | the number of rows on the board.
		\param ncols | the number of columns on the board.
		\param kval  | the k value of the mnk game.
	*/
	Board(int nrows, int ncols, int kval);

	~Board();

	/**
		Returns the number of rows on the board
	*/
	int ReturnNumRows();
	
	/**
		Returns the number of columns on the board
	*/
	int ReturnNumCols();

	/**
		Return the value of K for the MNK game.
	*/
	int ReturnKValue();

	/**
		Prints the board to the console
	*/
	void PrintBoard();

	/**
		Sets the board to our default value "_"
	*/
	void ResetBoard();
	
	/**
		Returns the board value for the position provided
		\param row | The row position of desired value
		\param column | The column position of desired value
	*/
	char GetVal(int row, int column);

	/**
		Sets value for the position provided if valid, sets value and returns true if valid, false if not
		\param row | The row position where value is to be set
		\param column | The column position where value is to be set
		\param value | The value to be set
	*/
	bool SetVal(int row, int column, char value);

private:
	int num_rows, num_cols, num_kval;		//Represent the number of rows, columns and the K value for the mnk
	std::vector<std::vector<char>>* board_vec;	// The vector that holds the data for the Board
};