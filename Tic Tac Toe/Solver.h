#pragma once

#include "Move.h"
#include "Board.h"

/**
	This class is used to check whether the game has been won or has drawn.
*/
class Solver
{
public:
	
	Solver();
	~Solver();
	
	/**
		This function calls the other win checking functions as are required

		\param gboard | the board that the game is being played on
		\param moveMade | the last move that was made
	*/
	bool WinCheck(Board *gboard, Move *moveMade);

	/**
		This function checks the row the last move was played on for win condition

		\param gboard | the board that the game is being played on
		\param moveMade | the last move that was made
	*/
	bool WinCheckHorizontal(Board *gboard, Move *moveMade);

	/**
		This function checks the column the last move was played on for win condition
		
		\param gboard | the board that the game is being played on
		\param moveMade | the last move that was made
	*/
	bool WinCheckVertical(Board *gboard, Move *moveMade);

	/**
		This function checks the diagonals where the last move was made for win condition

		\param gboard | the board that the game is being played on
		\param moveMade | the last move that was made
	*/
	bool WinCheckDiagonal(Board *gboard, Move *moveMade);

	/**
		this functions calls the other functions required to detect early draw
		returns true if a win is still possible for one player

		\param gboard | pointer to the board that game is being played on
		\param moves | needed when last move is left and one player has a winning move but is not the one playing
	*/
	bool DrawCheck(Board* gboard, int moves);

	/**
		this function checks rows to see if a win is still possible for the player 
		returns true if win is still possible

		\param gboard | the board that the game is being played on
		\param value  | the value corresponding to the player to check for ie:- X or O

	*/
	bool DrawHorizontal(Board* gboard, char value);

	/**
		this function checks columns to see if a win is still possible for the player
		returns true if win is still possible

		\param gboard | the board that the game is being played on
		\param value  | the value corresponding to the player to check for ie:- X or O

	*/
	bool DrawVertical(Board* gboard, char value);

	/**
		this function checks diagonals to see if a win is still possible for the player
		returns true if win is still possible

		\param gboard | the board that the game is being played on
		\param value  | the value corresponding to the player to check for ie:- X or O

	*/
	bool DrawDiagonal(Board* gboard, char value);

	

private:
	
};