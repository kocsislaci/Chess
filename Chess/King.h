#pragma once
#include "Piece.h"
class King :
	public Piece
{
	bool isInMate;
	bool wasInMate;
	bool didMove;
public:
	King();
	~King();
};

