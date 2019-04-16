#pragma once
class Piece
{
protected:
	bool isWhite;
	char pos[2];
	bool isTaken;
	static unsigned value;
public:
	Piece();
	virtual void setValue() = 0;
	unsigned getValue();
	virtual void setColour() = 0;
	virtual void move() = 0;
	~Piece();
};

