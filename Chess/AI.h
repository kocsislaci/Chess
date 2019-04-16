#pragma once
#include "Player.h"
#include <string>

class AI :
	public Player
{
	std::string name;
	char difficulty;
public:
	AI();
	~AI();
};

