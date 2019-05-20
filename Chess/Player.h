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
	Piece** pieces;
public:
	Player(bool);
	Player(Player&);
	bool getIsWhite() const;
	std::string getName() const;
	Piece** getPieces() const;
	bool takeMove(char, char, char, char);
	void setTakenPiece(char, char);
	~Player();
};

