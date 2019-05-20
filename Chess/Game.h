#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Player.h"



class Game
{
	Player whitePlayer;
	Player blackPlayer;
	char board[8][8] = { 0 };
	bool isThereAWinner = false;
	bool isWhitesTurn = true;
public:
	Game(Player, Player);
	void playGame();
	char getPieceOnPosition(char, char) const;
	void setPieceOnPosition(char, char, char);
	void move();
	void print() const;
	bool getIsWhitesTurn() const;
	~Game();
};

