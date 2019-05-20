#include "King.h"
#include <math.h>


King::King()
{
	this->xpos = 0;
	this->ypos = 0;
}
King::King(bool pisWhite)
{
	this->xpos = 0;
	this->ypos = 0;
	this->isWhite = pisWhite;
	if (isWhite)
		this->character = 'K';
	else
		this->character = 'k';
}

bool King::move(char toxpos, char toypos) 
{
	if ((abs(this->xpos - toxpos) == 1) && (abs(this->ypos - toypos) == 1))
	{
		return 1;
	}
	else
		return 0;
}

King::~King()
{
}
