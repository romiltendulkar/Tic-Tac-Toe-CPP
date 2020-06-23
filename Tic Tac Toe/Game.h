#pragma once

#include <stack>
#include "Board.h"
#include "Move.h"
#include "Solver.h"

/**
	This class is used for the actual gameplay implementation
	It implements the turn by turn gameplay we need
*/
class Game
{
public:
	/**
		Stores the Board pointer and initiates the move stack

		\param gamebd | the pointer to the board
	*/
	Game(Board* gamebd);
	
	/**
		Destructor for the game class
	*/
	~Game();

	/**
		The function for the standard game loop
	*/
	void Update();

	/**
		Returns the bool defining the current state of the game
	*/
	bool GameFinished();

	/**
		This function is used to make a move and performs all the checks necessary
	*/
	void MakeMove();

	/**
		The Turn Menu provides the menu for the turn by turn play 
	*/
	void TurnMenu();

	/**
		This function reverts the last move performed. Revert can be done all the way to the empty board.
	*/
	void UndoMove();

private:
	Board* game_board;				//pointer to the board used for the game
	Solver* board_solver;			//pointer to solver that does win and draw checks
	bool game_end;					//bool to show status of the game
	int moves_made = 0;				//move counter for turn by turn play

	std::stack<Move*> *moves_stack;	//moves stored in this stack and popped from during undo
};