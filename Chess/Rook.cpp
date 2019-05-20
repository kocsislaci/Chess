#include "Rook.h"
#include <math.h>


Rook::Rook()
{
	this->xpos = 0;
	this->ypos = 0;
}
Rook::Rook(bool pisWhite)
{
	this->xpos = 0;
	this->ypos = 0;
	this->isWhite = pisWhite;
	if (isWhite)
		this->character = 'R';
	else
		this->character = 'r';
}

bool Rook::move(char toxpos, char toypos)
{
	if ((abs(this->xpos - toxpos) == 0) || (abs(this->ypos - toypos) == 0))
	{
		return 1;
	}
	else
		return 0;
}

Rook::~Rook()
{
}
