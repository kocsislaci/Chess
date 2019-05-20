#pragma once
#include "Piece.h"
class Pawn :
	public Piece
{
	bool isInStartPos = 1;
public:
	Pawn();
	Pawn(bool);
	bool move(char, char);
	~Pawn();
};

