#include "Game.h"
using namespace std;


Game::Game()
{
}


Game::~Game()
{
}


void Game::print()
{
	cout << "   -------------------------------  ";
	if (0) // latter feature start
	{
		cout << "P" << endl;
	}
	else
	{
		cout << " " << endl;
	} // end

	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
		{
			cout << "  |   |...|   |...|   |...|   |...| " << endl
				 << (8 - i) << " | " << board[7-i][0] << " |." << board[7-i][1] << ".| " << board[7-i][2] << " |." << board[7-i][3] << ".| " << board[7-i][4] <<  " |." << board[7-i][5] << ".| " << board[7-i][6] <<  " |." << board[7-i][7] <<  ".| " << endl
				 << "  |   |...|   |...|   |...|   |...| " << endl;
		}
		else
		{
			cout << "  |...|   |...|   |...|   |...|   | " << endl
				 << (8 - i) << " |." << board[7-i][0] << ".| " << board[7-i][1] << " |." << board[7-i][2] << ".| " << board[7-i][3] << " |." << board[7-i][4] << ".| " << board[7-i][5] << " |." << board[7-i][6] << ".| " << board[7-i][7] << " | " << endl
				 << "  |...|   |...|   |...|   |...|   | " << endl;
		}
		if (i < 7)
			cout << "  |---|---|---|---|---|---|---|---| " << endl;
	}
	cout << "   -------------------------------  " << endl 
		 << "    a   b   c   d   e   f   g   h   " << endl;

	if (0) // latter feature start
	{
		cout << "P" << endl;
	}
	else
	{
		cout << " " << endl;
	} // end
}