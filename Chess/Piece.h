#pragma once
class Piece
{
protected:
	bool isWhite;
	char pos[2];
	bool isTaken;
public:
	Piece();
	void move();
	~Piece();
};

