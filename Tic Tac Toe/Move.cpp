#include "Move.h"

Move::Move(int xpos, int ypos, char val)
{
	x_position = xpos;
	y_position = ypos;
	value = val;
}

Move::~Move()
{

}

int Move::ReturnX()
{
	return x_position;
}

int Move::ReturnY()
{
	return y_position;
}

char Move::ReturnValue()
{
	return value;
}