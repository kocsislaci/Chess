#include "Piece.h"

unsigned Piece::value = 0;

Piece::Piece()
{
	this->xpos = 0;
	this->ypos = 0;
}
Piece::Piece(bool pisWhite)
{
	this->xpos = 0;
	this->ypos = 0;
	this->isWhite = pisWhite;
}

void Piece::setPos(char x, char y) 
{
	this->xpos = x;
	this->ypos = y;
}
void Piece::setTaken()
{
	isTaken = 1;
	this->setPos(-1, -1);
}
char Piece::getXPos() const
{
	return this->xpos;
}
char Piece::getYPos() const
{
	return this->ypos;
}
char Piece::getChararcter() const
{
	return this->character;
}
Piece::~Piece()
{
}
