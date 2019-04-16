#pragma once
#include "Player.h"
#include <string>

class Human :
	public Player
{
	std::string name;
public:
	Human();
	~Human();
};

