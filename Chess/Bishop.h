#pragma once
#include "Piece.h"
class Bishop :
	public Piece
{
public:
	Bishop();
	Bishop(bool);
	bool move(char, char);
	~Bishop();
};

