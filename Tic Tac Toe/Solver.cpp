#include <iostream>
#include "Solver.h"

Solver::Solver()
{
	
}

Solver::~Solver()
{

}

bool Solver::WinCheck(Board* gboard, Move* moveMade)
{
	if (gboard->ReturnKValue() == 1)
	{
		return true;
	}
	if (!WinCheckHorizontal(gboard, moveMade))
	{
		if (!WinCheckVertical(gboard, moveMade))
		{
			if (!WinCheckDiagonal(gboard, moveMade))
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		return true;
	}
}

bool Solver::WinCheckHorizontal(Board* gboard, Move* moveMade)
{
	int consecutive = 1;		//used to count the amount of consecutive occurences;
	
	for (int i = moveMade->ReturnY() - 1; i >= 0; --i)
	{
		if (gboard->GetVal(moveMade->ReturnX(), i) == moveMade->ReturnValue())
		{
			++consecutive;
			if (consecutive >= gboard->ReturnKValue())																	//Check  in the row behind where move was made
			{
				return true;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = moveMade->ReturnY() + 1; i < gboard->ReturnNumCols(); ++i)
	{
		if (gboard->GetVal(moveMade->ReturnX(), i) == moveMade->ReturnValue())
		{
			++consecutive;
			if (consecutive >= gboard->ReturnKValue())																//Check ahead of move
			{
				return true;
			}
		}
		else
		{
			break;
		}
	}
	return false;
}

bool Solver::WinCheckVertical(Board* gboard, Move* moveMade)
{
	int consecutive = 1;

	for (int i = moveMade->ReturnX() - 1; i >= 0; --i)
	{
		if (gboard->GetVal(i, moveMade->ReturnY()) == moveMade->ReturnValue())
		{
			++consecutive;
			if (consecutive >= gboard->ReturnKValue())
			{
				return true;																		//check above
			}
		}
		else 
		{
			break;
		}
	}

	for (int i = moveMade->ReturnX() + 1; i < gboard->ReturnNumRows(); ++i)
	{
		if (gboard->GetVal(i, moveMade->ReturnY()) == moveMade->ReturnValue())
		{
			++consecutive;
			if (consecutive >= gboard->ReturnKValue())												//check below
			{
				return true;
			}
		}
		else
		{
			break;
		}
	}

	return false;
}

bool Solver::WinCheckDiagonal(Board* gboard, Move* moveMade)
{
	int consecutive = 1;
	bool flag = false;			//just using this to bounds check the diagonals
	int i = 1;
	while (!flag)
	{
		

		int j = moveMade->ReturnX() - i;
		int k = moveMade->ReturnY() - i;

		if (j >= 0 && k >= 0)
		{
			if (gboard->GetVal(j, k) == moveMade->ReturnValue())
			{
				++consecutive;
				if (consecutive >= gboard->ReturnKValue())								//check top left diagonally
				{
					return true;
				}
				++i;
			}
			else
			{
				flag = true;
			}
		}
		else
		{
			flag = true;
		}
	}
	i = 1;
	flag = false;
	while(!flag)
	{

		int j = moveMade->ReturnX() + i;
		int k = moveMade->ReturnY() + i;

		if (j < gboard->ReturnNumRows() && k < gboard->ReturnNumCols())
		{
			if (gboard->GetVal(j, k) == moveMade->ReturnValue())
			{
				++consecutive;
				if (consecutive >= gboard->ReturnKValue())									//check bottom right	
				{
					return true;
				}
				++i;
			}
			else
			{
				flag = true;
			}
		}
		else
		{
			flag = true;
		}
	}
	i = 1;
	consecutive = 1;
	flag = false;
	while (!flag)
	{

		int j = moveMade->ReturnX() + i;
		int k = moveMade->ReturnY() - i;

		if (j < gboard->ReturnNumRows() && k >= 0)
		{
			if (gboard->GetVal(j, k) == moveMade->ReturnValue())
			{
				++consecutive;
				if (consecutive >= gboard->ReturnKValue())							//check bottom left
				{
					return true;
				}
				++i;
			}
			else
			{
				flag = true;
			}
		}
		else
		{
			flag = true;
		}
	}
	i = 1;
	flag = false;
	while (!flag)
	{

		int j = moveMade->ReturnX() - i;
		int k = moveMade->ReturnY() + i;

		if (j >= 0 && k < gboard->ReturnNumCols())
		{
			if (gboard->GetVal(j, k) == moveMade->ReturnValue())						//check top right
			{
				++consecutive;
				if (consecutive >= gboard->ReturnKValue())
				{
					return true;
				}
				++i;
			}
			else
			{
				flag = true;
			}
		}
		else
		{
			flag = true;
		}
	}
	return false;
}

bool Solver::DrawCheck(Board* gboard, int moves)
{
	if (moves == ((gboard->ReturnNumCols() * gboard->ReturnNumRows()) - 1))
	{
		if ((moves % 2) == 0)
		{
			if (DrawHorizontal(gboard, 'x'))
			{
				return true;
			}
			if (DrawVertical(gboard, 'x'))
			{
				return true;
			}
			if (DrawDiagonal(gboard, 'x'))
			{
				return true;
			}
			return false;
		}
		else
		{
			if (DrawHorizontal(gboard, 'o'))
			{
				return true;
			}

			if (DrawVertical(gboard, 'o'))
			{
				return true;
			}
			if (DrawDiagonal(gboard, 'o'))
			{
				return true;
			}
			return false;
		}
	}
	else
	{
		if (DrawHorizontal(gboard, 'x'))
		{
			return true;
		}

		if (DrawVertical(gboard, 'x'))
		{
			return true;
		}
		if (DrawDiagonal(gboard, 'x'))
		{
			return true;
		}
		if (DrawHorizontal(gboard, 'o'))
		{
			return true;
		}
		if (DrawVertical(gboard, 'o'))
		{
			return true;
		}
		if (DrawDiagonal(gboard, 'o'))
		{
			return true;
		}
		return false;
	}
	
	
}

bool Solver::DrawHorizontal(Board* gboard, char value)
{
	for (int i = 0; i < gboard->ReturnNumRows(); ++i)
	{
		for (int j = 0; j < gboard->ReturnNumCols(); ++j)
		{
			if (gboard->GetVal(i, j) == value || gboard->GetVal(i, j) == '_')
			{
				int consecutive = 1;
				bool flag = true;
				int k = 1;
				while (flag)
				{
					int m = j + k;
					if (m < gboard->ReturnNumCols())
					{
						if (gboard->GetVal(i, m) == value || gboard->GetVal(i, m) == '_')
						{
							++consecutive;
							++k;
							if (consecutive >= gboard->ReturnKValue())
							{
								return true;
							}
						}
						else
						{
							flag = false;
						}
					}
					else
					{
						flag = false;
					}
				}
			}
		}
	}
	return false;
}

bool Solver::DrawVertical(Board* gboard, char value)
{
	for (int i = 0; i < gboard->ReturnNumCols(); ++i)
	{
		for (int j = 0; j < gboard->ReturnNumRows(); ++j)
		{
			if (gboard->GetVal(j, i) == value || gboard->GetVal(j, i) == '_')
			{
				int consecutive = 1;
				bool flag = true;
				int k = 1;
				while (flag)
				{
					int m = j + k;
					if (m < gboard->ReturnNumRows())
					{
						if (gboard->GetVal(m, i) == value || gboard->GetVal(m, i) == '_')
						{
							++consecutive;
							++k;
							if (consecutive >= gboard->ReturnKValue())
							{
								return true;
							}
						}
						else
						{
							flag = false;
						}
					}
					else
					{
						flag = false;
					}
				}
			}
		}
	}
	return false;
}

bool Solver::DrawDiagonal(Board* gboard, char value)
{
	for (int i = 0; i < gboard->ReturnNumRows(); ++i)
	{
		for (int j = 0; j < gboard->ReturnNumCols(); ++j)
		{
			
			if (gboard->GetVal(i, j) == value || gboard->GetVal(i, j) == '_')
			{
				int consecutive = 1;
				bool flag = true;
				int k = 1;
				while (flag)
				{
					int m = i + k;
					int n = j + k;
					if (m < gboard->ReturnNumRows() && n < gboard->ReturnNumCols())
					{
						if (gboard->GetVal(m, n) == value || gboard->GetVal(m, n) == '_')
						{
							++consecutive;
							++k;
							if (consecutive >= gboard->ReturnKValue())
							{
								return true;
							}
						}
						else
						{
							flag = false;
						}
					}
					else
					{
						flag = false;
					}
				}

				consecutive = 1;
				flag = true;
				k = 1;
				while (flag)
				{
					int m = i - k;
					int n = j + k;
					if (m >= 0 && n < gboard->ReturnNumCols())
					{
						if (gboard->GetVal(m, n) == value || gboard->GetVal(m, n) == '_')
						{
							++consecutive;
							++k;
							if (consecutive >= gboard->ReturnKValue())
							{
								return true;
							}
						}
						else
						{
							flag = false;
						}
					}
					else
					{
						flag = false;
					}
				}
			}
			
		}
	}
	return false;
}

