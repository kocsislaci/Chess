#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Human.h"
#include "AI.h"

enum xCoor {
	a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, h = 7
};

class Game
{
	Player whitePlayer;
	Player blackPlayer;
	char board[8][8] = { 0 };


public:
	void tempsetBoard(char piece)
	{
		board[0][0] = piece;
		board[0][7] = piece;
	}


	Game();
	void init();
	void start();
	void help();
	void print();
	~Game();
};

