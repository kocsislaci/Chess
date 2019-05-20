#include "Pawn.h"
#include <math.h>


Pawn::Pawn()
{
	this->xpos = 0;
	this->ypos = 0;
}
Pawn::Pawn(bool pisWhite)
{
	this->xpos = 0;
	this->ypos = 0;
	this->isWhite = pisWhite;
	if (isWhite)
		this->character = 'P';
	else
		this->character = 'p';
}

bool Pawn::move(char toxpos, char toypos)
{
	if (this->isWhite)
	{
		if (((this->xpos - toxpos) == 0) && (((toypos - this->ypos) == 1) || ((toypos - this->ypos) == 2 && isInStartPos)))
		{
			isInStartPos = 0;
			return 1;
		}
		else
			return 0;
	}
	else
	{
		if ((toxpos - xpos) == 0 && ((ypos - toypos) == 1 || ((ypos - toypos) == 2 && isInStartPos)))
		{
			isInStartPos = 0;
			return 1;
		}
		else
			return 0;
	}
}

Pawn::~Pawn()
{
}
