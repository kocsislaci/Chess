#pragma once
#include <iostream>
#include "Human.h"

class Game
{
	Player whitePlayer();
	Player blackPlayer();
	char board[8][8];

public:

	Game();
	void init();
	void start();
	void help();
	void print();
	~Game();
};

