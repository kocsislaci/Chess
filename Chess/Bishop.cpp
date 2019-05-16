#include "Bishop.h"



Bishop::Bishop()
{
	this->xpos = 0;
	this->ypos = 0;
}
Bishop::Bishop(bool pisWhite)
{
	this->xpos = 0;
	this->ypos = 0;
	this->isWhite = pisWhite;
	if (isWhite)
		this->character = 'B';
	else
		this->character = 'b';
}


Bishop::~Bishop()
{
}
