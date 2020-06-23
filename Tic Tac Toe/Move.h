#pragma once

/**
	The move class is used to store the data for each move,
	we can use this class later to rollback moves
*/
class Move
{
public:
	/**
		Constructor for the move class, sets the values required for the move

		\param xpos | row position where the move is made
		\param ypos | column position where the move is made	
		\param val  | the value of the player making the move, ie:- X or O
	*/
	Move(int xpos, int ypos, char val);

	/**
		Destructor
	*/
	~Move();

	/**
		Returns the row position of the move
	*/
	int ReturnX();

	/**
		Returns the column position of the move
	*/
	int ReturnY();

	/**
		Returns whether the move was a X or a O
	*/
	char ReturnValue();

private:
	int x_position, y_position;		//Row and column position
	char value;						//Value made by move IE:- X or O
};