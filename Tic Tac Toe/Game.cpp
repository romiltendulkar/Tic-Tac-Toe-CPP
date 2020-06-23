
#include <iostream>
#include "Game.h"


Game::Game(Board* gamebd)
{
	game_board = gamebd;
	game_end = false;

	board_solver = new Solver();
	moves_stack = new std::stack<Move*>();
}

Game::~Game()
{

}

bool Game::GameFinished()
{
	return game_end;
}

void Game::Update()
{
	TurnMenu();
	game_board->PrintBoard(); 
}

void Game::MakeMove()
{
	bool goodmove = false;
	int xpos, ypos;
	while (!goodmove)
	{
		std::cout << "\n Enter the x position where you want to mark: ";
		std::cin >> xpos;
		while (xpos >= game_board->ReturnNumRows())
		{
			std::cout << "\n Enter a position within bounds: ";
			std::cin >> xpos;
		}
		std::cout << "\n Enter the y position where you want to mark: ";
		std::cin >> ypos;
		while (ypos >= game_board->ReturnNumCols())
		{
			std::cout << "\n Enter a position within bounds: ";
			std::cin >> ypos;
		}

		if ((moves_made % 2) == 0)
		{
			goodmove = game_board->SetVal(xpos, ypos, 'x');
			if (goodmove)
			{
				Move* saveMove = new Move(xpos, ypos, 'x');
				moves_stack->push(saveMove);
			}
		}
		else
		{
			goodmove = game_board->SetVal(xpos, ypos, 'o');
			if (goodmove)
			{
				Move* saveMove = new Move(xpos, ypos, 'o');
				moves_stack->push(saveMove);
			}
		}

		if (!goodmove)
		{
			std::cout << "\n Position already occupied please make new move";
		}

		
		
	}
	++moves_made;
}

void Game::TurnMenu()
{
	bool choiceMade = false;			//defines whether a valid choice has been made
	int choice;
	while(!choiceMade)
	{
		std::cout << "\n\n------------Turn Menu-------------";
		std::cout << "\n1) Make your Move";
		std::cout << "\n2) Undo Move";
		std::cout << "\n3) Stop Playing\n";
		std::cin >> choice;

		switch (choice)
		{
			case 1:
				MakeMove();
				if (board_solver->WinCheck(game_board,moves_stack->top()))
				{
					std::cout << "\n " << moves_stack->top()->ReturnValue() << " has won\n\n";		//After we make a move we need to perform draw and win checks
					game_end = true;
				}
				if (!board_solver->DrawCheck(game_board, moves_made))
				{
					std::cout << "\n The Game ends in a draw\n\n";
					game_end = true;
				}
				choiceMade = true;
				break;
			case 2:
				if (moves_made == 0)
				{
					std::cout << "\nCant undo as no moves have been made ";
					choiceMade = true;
				}
				else
				{
					UndoMove();
					moves_stack->pop();															//No draw/win checks are needed in undo as we already know that it couldnt have been a draw or win
					choiceMade = true;
				}
				break;
			case 3:
				choiceMade = true;
				game_end = true;
				break;
			default:
				std::cout << "\n Please make a valid choice";
				break;
		}
	}


}

void Game::UndoMove()
{
	Move* lastMove = moves_stack->top();
	int xpos, ypos;

	xpos = lastMove->ReturnX();
	ypos = lastMove->ReturnY();
	game_board->SetVal(xpos, ypos, '_');
	--moves_made;
	

}