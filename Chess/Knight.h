#pragma once
#include "Piece.h"
class Knight :
	public Piece
{
public:
	Knight();
	Knight(bool);
	bool move(char, char);
	~Knight();
};

