#include "Human.h"

Human::Human()
{
}

Human::Human(std::string pname, bool pIsWhite)
{
	this->name = pname;
	this->isWhite = pIsWhite;
}


Human::~Human()
{
}
