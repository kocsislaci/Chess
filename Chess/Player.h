#pragma once
#include <string>
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include <math.h>

class Player
{
protected:
	std::string name;
	bool isWhite;
	bool isItsTurn;
	Piece *pieces;
public:
	Player();
	Player(bool);
	Player(Player&);
	bool getIsWhite() const;
	std::string getName() const;
	Piece* getPieces() const;
	int takeMove(char, char, char, char);
	void setTakenPiece(char, char);
	~Player();
};

