#include "Player.h"
#include <iostream>


Player::Player(bool pIsWhite)
{
	this->isWhite = pIsWhite;
	this->isItsTurn = pIsWhite;
	while (name.empty())
	{
		std::cout << "Please choose a nickname (max 10 characters): ";
		std::string temp;
		try
		{
			std::cin >> temp;
			if (temp.length() > 10)
			{
				throw "Too long";
			}
			else
			{
				name.append(temp);
			}
		}
		catch (std::string err)
		{
			std::cout << err << std::endl;
		}
	}

	pieces = new Piece*[16];
	int i;
	for (i = 0; i < 8; i++)
	{
		pieces[i] = new Pawn(this->isWhite);
		if (this->isWhite)
			pieces[i][0].setPos(i, 1);
			
		else
			pieces[i][0].setPos(i, 6);
	}

	for (i = 8; i < 10; i++)
	{
		pieces[i] = new Rook(this->isWhite);
		if (i == 8)
		{
			if (this->isWhite)
				pieces[i][0].setPos(0, 0);
			else
				pieces[i][0].setPos(0, 7);
		}
		else
		{
			if (this->isWhite)
				pieces[i][0].setPos(7, 0);
			else
				pieces[i][0].setPos(7, 7);
		}
	}
	for (i = 10; i < 12; i++)
	{
		pieces[i] = new Knight(this->isWhite);
		if (i == 10)
		{
			if (this->isWhite)
				pieces[i][0].setPos(1, 0);
			else
				pieces[i][0].setPos(1, 7);
		}
		else
		{
			if (this->isWhite)
				pieces[i][0].setPos(6, 0);
			else
				pieces[i][0].setPos(6, 7);
		}
	}
	for (i = 12; i < 14; i++)
	{
		pieces[i] = new Bishop(this->isWhite);
		if (i == 12)
		{
			if (this->isWhite)
				pieces[i][0].setPos(2, 0);
			else
				pieces[i][0].setPos(2, 7);
		}
		else
		{
			if (this->isWhite)
				pieces[i][0].setPos(5, 0);
			else
				pieces[i][0].setPos(5, 7);
		}
	}
		pieces[14] = new Queen(this->isWhite);
		if (this->isWhite)
			pieces[14][0].setPos(3, 0);
		else
			pieces[14][0].setPos(3, 7);
		pieces[15] = new King(this->isWhite);
		if (this->isWhite)
			pieces[15][0].setPos(4, 0);
		else
			pieces[15][0].setPos(4, 7);
}

Player::Player(Player& theOther)
{
	this->name = theOther.name;
	this->isWhite = theOther.isWhite;
	this->isItsTurn = theOther.isItsTurn;
	this->pieces = new Piece*[16];
	int i;
	for (i = 0; i < 8; i++)
	{
		pieces[i] = new Pawn(this->isWhite);
	}
	for (i = 8; i < 10; i++)
	{
		pieces[i] = new Rook(this->isWhite);
	}
	for (i = 10; i < 12; i++)
	{
		pieces[i] = new Knight(this->isWhite);
	}
	for (i = 12; i < 14; i++)
	{
		pieces[i] = new Bishop(this->isWhite);
	}
	pieces[14] = new Queen(this->isWhite);
	pieces[15] = new King(this->isWhite);
	for (int i = 0; i < 16; i++)
	{
		this->pieces[i][0] = theOther.pieces[i][0];
	}
}

bool Player::getIsWhite() const
{
	return this->isWhite;
}

std::string Player::getName() const
{
	return this->name;
}

Piece** Player::getPieces() const
{
	return pieces;
}

bool Player::takeMove(char xpos, char ypos, char toxpos, char toypos)
{
	bool success = 0;
	for (int i = 0; i < 16; i++)
	{
		if (pieces[i][0].getXPos() == xpos && pieces[i][0].getYPos() == ypos)
		{
			success = pieces[i][0].move(toxpos, toypos);
			if (success)
			{
				pieces[i][0].setPos(toxpos, toypos);
			}
			break;
		}
	}
	return success;
}

void Player::setTakenPiece(char toxpos, char toypos)
{
	for (int i = 0; i < 16; i++)
	{
		if (pieces[i][0].getXPos() == toxpos && pieces[i][0].getYPos() == toypos)
		{
			pieces[i][0].setTaken();
			break;
		}
	}
}

Player::~Player()
{
	for (int i = 0; i < 16; i++)
	{
		delete[] pieces[i];
	}
	delete[] pieces;
}
