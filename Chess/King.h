#pragma once
#include "Piece.h"
class King :
	public Piece
{
public:
	King();
	King(bool);
	bool move(char, char);
	~King();
};

