

#pragma once
#include "Player.h"



class AI :
	public Player
{
	char difficulty;
public:
	AI();
	AI(std::string, bool);
	void setDifficulty();
	void getDifficulty();
	~AI();
};

