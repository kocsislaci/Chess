#include "Rook.h"



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

Rook::~Rook()
{
}
