#include "Board.h"
#include <iostream>

Board::Board()
{
	num_rows = 3;
	num_cols = 3;
	num_kval = 3;

	board_vec = new std::vector<std::vector<char>>(num_rows, std::vector<char>(num_cols));
	ResetBoard();
}

Board::Board(int nrows, int ncols, int kval)
{
	num_rows = nrows;
	num_cols = ncols;
	num_kval = kval;

	board_vec = new std::vector<std::vector<char>>(num_rows, std::vector<char>(num_cols));
	ResetBoard();
}

Board::~Board()
{
	
}

int Board::ReturnNumCols()
{
	return num_cols;
}

int Board::ReturnNumRows()
{
	return num_rows;
}

int Board::ReturnKValue()
{
	return num_kval;
}

void Board::PrintBoard()
{
	for (unsigned int i = 0; i < num_rows; ++i)
	{
		std::cout << std::endl;
		for (unsigned int j = 0; j < num_cols; ++j)
		{
			std::cout << " " << board_vec->at(i).at(j);
		}
	}
}

void Board::ResetBoard()
{
	for (unsigned int i = 0; i < num_rows; ++i)
	{
		for (unsigned int j = 0; j < num_cols; ++j)
		{
			board_vec->at(i).at(j) = '_';							//Filling blank for each board position;
		}
	}
}

char Board::GetVal(int row, int column)
{
	return board_vec->at(row).at(column);
}

bool Board::SetVal(int row, int column, char value)
{
	if (board_vec->at(row).at(column) == '_')
	{
		board_vec->at(row).at(column) = value;
		return true;
	}
	else
	{
		if (value == '_')
		{
			board_vec->at(row).at(column) = value;					//needed for undoing moves as the same function is called
			return true;
		}
		return false;	
	}
}