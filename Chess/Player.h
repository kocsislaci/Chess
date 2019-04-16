#pragma once
#include <string>
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

class Player
{
protected:
	const std::string name;
	bool isWhite;
	bool isItsTurn;
	unsigned moveCounter;
	Piece *pieces;
	Piece *takenPieces;
public:
	Player();
	void init();
	void setColour();
	void setItsTurn();
	void getItsTurn();
	void takeMove();
	void castling();
	~Player();
};

