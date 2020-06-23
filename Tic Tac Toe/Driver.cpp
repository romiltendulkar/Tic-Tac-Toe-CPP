#include <iostream>
#include "Board.h"
#include "Game.h"

Board* InitializeBoard()
{
	int nRows, nCols, kval;		//Represent the number of rows, columns and the K value for the mnk
	bool kBool = false;					//Bool used to ensure a proper Kvalue
	std::cout << "\n Enter the num of rows on the board: ";
	std::cin >> nRows;
	std::cout << "\n Enter the num of cols on the board: ";
	std::cin >> nCols;
	std::cout << "\n Enter the K value for the game: ";
	std::cin >> kval;
	while (!kBool)
	{
		if ((kval > nRows) && (kval > nCols))
		{
			kBool = false;
			std::cout << "\n Incorrect value for K, please enter a valid value: ";
			std::cin >> kval;
		}
		else if (kval <= 0)
		{
			kBool = false;
			std::cout << "\n Incorrect value for K, please enter a valid value: ";
			std::cin >> kval;
		}
		else
		{
			kBool = true;
		}
	} 
	Board* createdBoard = new Board(nRows, nCols, kval);
	return createdBoard;
}

int main()
{
	Board* gameBoard = InitializeBoard();
	Game* ourGame = new Game(gameBoard);
	while (!ourGame->GameFinished())
	{
		ourGame->Update();
	}
	return 0;
}

