#include "Knight.h"



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


Knight::~Knight()
{
}
