#include "Player.h"
#include <iostream>

Player::Player()
{
}

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

	pieces = new Piece[16];
	int i;
	for (i = 0; i < 8; i++)
	{
		pieces[i] = Pawn(this->isWhite);
		if (this->isWhite)
			pieces[i].setPos(i, 1);
		else
			pieces[i].setPos(i, 6);
	}

	for (i = 8; i < 10; i++)
	{
		pieces[i] = Rook(this->isWhite);
		if (i == 8)
		{
			if (this->isWhite)
				pieces[i].setPos(0, 0);
			else
				pieces[i].setPos(0, 7);
		}
		else
		{
			if (this->isWhite)
				pieces[i].setPos(7, 0);
			else
				pieces[i].setPos(7, 7);
		}
	}
	for (i = 10; i < 12; i++)
	{
		pieces[i] = Knight(this->isWhite);
		if (i == 10)
		{
			if (this->isWhite)
				pieces[i].setPos(1, 0);
			else
				pieces[i].setPos(1, 7);
		}
		else
		{
			if (this->isWhite)
				pieces[i].setPos(6, 0);
			else
				pieces[i].setPos(6, 7);
		}
	}
	for (i = 12; i < 14; i++)
	{
		pieces[i] = Bishop(this->isWhite);
		if (i == 12)
		{
			if (this->isWhite)
				pieces[i].setPos(2, 0);
			else
				pieces[i].setPos(2, 7);
		}
		else
		{
			if (this->isWhite)
				pieces[i].setPos(5, 0);
			else
				pieces[i].setPos(5, 7);
		}
	}
		pieces[14] = Queen(this->isWhite);
		if (this->isWhite)
			pieces[14].setPos(3, 0);
		else
			pieces[14].setPos(3, 7);
		pieces[15] = King(this->isWhite);
		if (this->isWhite)
			pieces[15].setPos(4, 0);
		else
			pieces[15].setPos(4, 7);
}

Player::Player(Player& theOther)
{
	this->name = theOther.name;
	this->isWhite = theOther.isWhite;
	this->isItsTurn = theOther.isItsTurn;
	this->pieces = new Piece[16];
	for (int i = 0; i < 16; i++)
	{
		this->pieces[i] = theOther.pieces[i];
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
Piece* Player::getPieces() const
{
	return pieces;
}
int Player::takeMove(char xpos, char ypos, char toxpos, char toypos)
{
	char characterToMove = '\0';
	int success = 0;
	for (int i = 0; i < 16; i++)
	{
		if (pieces[i].getXPos() == xpos && pieces[i].getYPos() == ypos)
		{
			characterToMove = pieces[i].getChararcter();
		}
	}
	switch (characterToMove)
	{
	case 'p':
		if ((xpos - toxpos) == 0 && (ypos - toypos) == 1)
			success = 1;
		if (abs(double(xpos - toxpos)) == 1 && (ypos - toypos) == 1)
			success = 2;
		break;
	case 'P':
		if ((xpos - toxpos) == 0 && (toypos - ypos) == 1)
			success = 1;
		if (abs(double(xpos - toxpos)) == 1 && (toypos - ypos) == 1)
			success = 2;
		break;
	case 'r':
	case 'R':
		
		break;
	case 'n':
	case 'N':
		break;
	case 'b':
	case 'B':

		break;
	case 'q':
	case 'Q':
		break;
	case 'k':
	case 'K':

		break;
	default:
		break;
	}
	success = 1;
		return success;
}
void Player::setTakenPiece(char toxpos, char toypos)
{
	for (int i = 0; i < 16; i++)
	{
		if (pieces[i].getXPos() == toxpos && pieces[i].getYPos() == toypos)
		{
			pieces[i].setTaken();
		}
	}
}
Player::~Player()
{
	delete[] pieces;
}
