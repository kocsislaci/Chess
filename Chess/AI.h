#pragma once
#include "Player.h"

enum difficulties {
	easiest = 1, easy = 2, moderate = 3, hard = 4
};


class AI :
	public Player
{
	char difficulty;
public:
	AI();
	void setDifficulty();
	void getDifficulty();
	~AI();
};

