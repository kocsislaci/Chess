#pragma once


class Piece
{
protected:
	bool isWhite;
	char character;
	char xpos;
	char ypos;
	bool isTaken;
public:
	Piece();
	Piece(bool);
	virtual bool move(char, char) = 0;
	void setPos(char x, char y);
	void setTaken();
	char getXPos() const;
	char getYPos() const;
	char getChararcter() const;
	virtual ~Piece();
};

