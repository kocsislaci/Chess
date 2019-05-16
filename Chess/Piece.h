#pragma once


class Piece
{
protected:
	bool isWhite;
	char character;
	char xpos;
	char ypos;
	bool isTaken = 0;
	static unsigned value;
public:
	Piece();
	Piece(bool);
	void setPos(char x, char y);
	void setTaken();
	char getXPos() const;
	char getYPos() const;
	char getChararcter() const;
	~Piece();
};

