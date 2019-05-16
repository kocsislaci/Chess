#include "King.h"



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

King::~King()
{
}
