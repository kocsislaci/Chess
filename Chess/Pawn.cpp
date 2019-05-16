#include "Pawn.h"



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

Pawn::~Pawn()
{
}
