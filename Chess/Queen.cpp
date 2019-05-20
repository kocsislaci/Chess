#include "Queen.h"
#include <math.h>


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

bool Queen::move(char toxpos, char toypos) 
{
	if ((abs(this->xpos - toxpos) == abs(this->ypos - toypos)) || (abs(this->xpos - toxpos) == 0) || (abs(this->ypos - toypos) == 0))
	{
		return 1;
	}
	else
		return 0;
}

Queen::~Queen()
{
}
