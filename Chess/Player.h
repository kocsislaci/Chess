#pragma once
#include "Piece.h"

class Player
{
protected:
	bool isWhite;
	unsigned moveCounter;
	Piece *pieces = nullptr;
public:
	Player();
	void takeMove();
	void castling();
	~Player();
};

