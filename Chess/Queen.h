#pragma once
#include "Piece.h"
class Queen :
	public Piece
{
public:
	Queen();
	Queen(bool);
	bool move(char, char);
	~Queen();
};

