#include "Queen.h"



Queen::Queen()
{
	this->xpos = 0;
	this->ypos = 0;
}
Queen::Queen(bool pisWhite)
{
	this->xpos = 0;
	this->ypos = 0;
	this->isWhite = pisWhite;
	if (isWhite)
		this->character = 'Q';
	else
		this->character = 'q';
}

Queen::~Queen()
{
}
