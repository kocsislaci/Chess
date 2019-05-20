#include "Knight.h"
#include <math.h>


Knight::Knight()
{
	this->xpos = 0;
	this->ypos = 0;
}
Knight::Knight(bool pisWhite)
{
	this->xpos = 0;
	this->ypos = 0;
	this->isWhite = pisWhite;
	if (isWhite)
		this->character = 'N';
	else
		this->character = 'n';
}

bool Knight::move(char toxpos, char toypos)
{
	if (((abs(this->xpos - toxpos) == 2)  && (abs(this->ypos - toypos) == 1)) || ((abs(this->xpos - toxpos) == 1) && (abs(this->ypos - toypos) == 2)))
	{
		return 1;
	}
	else
		return 0;
}

Knight::~Knight()
{
}
