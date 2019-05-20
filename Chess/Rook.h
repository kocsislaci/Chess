#pragma once
#include "Piece.h"
class Rook :
	public Piece
{
public:
	Rook();
	Rook(bool);
	bool move(char, char);
	~Rook();
};

