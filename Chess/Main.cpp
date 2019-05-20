#include <iostream>
#include "Game.h"

int main()
{
	Player player1(true);
	Player player2(false);
	Game game1(player1, player2);
	game1.print();
	game1.playGame();
	return 0;
}