#include "Bishop.h"
#include <math.h>


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

bool Bishop::move(char toxpos, char toypos)
{
	if ((abs(this->xpos - toxpos) == abs(this->ypos - toypos)))
	{
		return 1;
	}
	else
		return 0;
}

Bishop::~Bishop()
{
}
