#include "Game.h"
using namespace std;


Game::Game(Player pWhitePlayer, Player pBlackPlayer): isThereAWinner(false), whitePlayer(pWhitePlayer), blackPlayer(pBlackPlayer)
{
	
	Piece *temp = whitePlayer.getPieces();
	for (int i = 0; i < 16; i++)
	{
		board[temp[i].getXPos()][temp[i].getYPos()] = temp[i].getChararcter();
	}
	temp = blackPlayer.getPieces();
	for (int i = 0; i < 16; i++)
	{
		board[temp[i].getXPos()][temp[i].getYPos()] = temp[i].getChararcter();
	}
	
}

void Game::playGame()
{
	string sTemp;
	char cTemp;
	bool playerWantsToQuit = 0;

	while (!isThereAWinner && !playerWantsToQuit)
	{
		std::cout << "Commands: (M)ove	(Q)uit" << std::endl;
		std::cout << "Type only one character here: ";
		try
		{
			std::cin >> sTemp;
			if (sTemp.length() == 1)
			{
				
				cTemp = sTemp[0];
				switch (cTemp)
				{
				case 'm':
				case 'M':
					try
					{
						this->move();
					}
					catch (const char *err)
					{
						std::cout << err << std::endl;
					}
					break;
				case 'Q':
				case 'q':
					playerWantsToQuit = 1;
					break;
				default:
					std::cout << "Unknown command" << std::endl;
					break;
				}
			}
			else
			{
				throw "Just one character!";
			}
		}
		catch (const char *err)
		{
			std::cout << err << std::endl;
		}
	}
	std::cout << "Bye!" << std::endl;
}

void Game::move()
{
	string sTemp;
	if (isWhitesTurn)
		std::cout << "White's turn, alias " << whitePlayer.getName() << std::endl;
	else
		std::cout << "Black's turn, alias " << blackPlayer.getName() << std::endl;
	std::cout << "Move from: ";
	std::cin >> sTemp;
	if (sTemp.length() != 2)
	{
		throw "Not proper position. Please give a letter and a number.";
	}
	else
	{
		char xtemp, ytemp;
		xtemp = sTemp.at(0);
		xtemp -= 49; // convert to 0...7 depends on the letter
		ytemp = sTemp.at(1) -1;
		if (ytemp  <= 7 || ytemp >= 0 || xtemp <= 7 || xtemp >= 0)
		{
			bool isThereAPiece = 0;
			switch (char(board[xtemp][ytemp]))
			{
			case 'p':
				if (!isWhitesTurn)
				{
					isThereAPiece = 1;
					break;
				}
			case 'r':
				if (!isWhitesTurn)
				{
					isThereAPiece = 1;
					break;
				}
			case 'n':
				if (!isWhitesTurn)
				{
					isThereAPiece = 1;
					break;
				}
			case 'b':
				if (!isWhitesTurn)
				{
					isThereAPiece = 1;
					break;
				}
			case 'q':
				if (!isWhitesTurn)
				{
					isThereAPiece = 1;
					break;
				}
			case 'k':
				if (!isWhitesTurn)
				{
					isThereAPiece = 1;
					break;
				}
				throw "Not your piece.";
				break;

			case 'P':
				if (isWhitesTurn)
				{
					isThereAPiece = 1;
					break;
				}
			case 'R':
				if (isWhitesTurn)
				{
					isThereAPiece = 1;
					break;
				}
			case 'N':
				if (isWhitesTurn)
				{
					isThereAPiece = 1;
					break;
				}
			case 'B':
				if (isWhitesTurn)
				{
					isThereAPiece = 1;
					break;
				}
			case 'Q':
				if (isWhitesTurn)
				{
					isThereAPiece = 1;
					break;
				}
			case 'K':
				if (isWhitesTurn)
				{
					isThereAPiece = 1;
					break;
				}
				throw "Not your piece.";
				break;

			default:
				isThereAPiece = 0;
				break;
			}
			if (isThereAPiece)
			{
				std::cout << "Move with " << board[xtemp][ytemp] << " to: ";
				std::cin >> sTemp;
				if (sTemp.length() == 2)
				{
					char nextxtemp, nextytemp;
					nextxtemp = sTemp.at(0);
					nextxtemp -= 49; // convert to number
					nextytemp = sTemp.at(1) -1;
					if (nextytemp <= 7 || nextytemp >= 0 || nextxtemp <= 7 || nextxtemp >= 0)
					{
						int canMoveThat; // 0 == no, 1 == can, 2 == can and it takes another piece
						if (isWhitesTurn)
							canMoveThat = whitePlayer.takeMove(xtemp, ytemp, nextxtemp, nextytemp);
						else
							canMoveThat = blackPlayer.takeMove(xtemp, ytemp, nextxtemp, nextytemp);

						if (canMoveThat)
						{
							if (canMoveThat == 2)
							{
								if (isWhitesTurn)
									blackPlayer.setTakenPiece(nextxtemp, nextytemp);
								else
									whitePlayer.setTakenPiece(nextxtemp, nextytemp);
							}
							this->board[nextxtemp][nextytemp] = this->board[xtemp][ytemp];
							this->board[xtemp][ytemp] = '0';
							isWhitesTurn = !isWhitesTurn;
							print();
						}
						else
						{
							throw "Can't move that.";
						}
					}
					else
					{
						throw "Out of range.";
					}
				}
				else
				{
					throw "Not proper position. Please give a letter and a number.";
				}
			}
			else
			{
				throw "There is nothing in there.";
			}
		}
		else
		{
		throw "Out of range.";
		}
	}
}
char Game::getPieceOnPosition(char xpos, char ypos) const
{
	return this->board[xpos][ypos];
}
void Game::setPieceOnPosition(char xpos, char ypos, char piece)
{
	this->board[xpos][ypos] = piece;
}



void Game::print() const
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
			cout << "  |...|   |...|   |...|   |...|   | " << endl
				 
				 << (8 - i) << " |." << board[0][7 - i] << ".| " << board[1][7 - i] << " |." << board[2][7 - i] << ".| " << board[3][7 - i] << " |." << board[4][7 - i] <<  ".| " << board[5][7 - i] << " |." << board[6][7 - i] <<  ".| " << board[7][7 - i] <<  " | " << endl
				 
				 << "  |...|   |...|   |...|   |...|   | " << endl;
		}
		else
		{
			cout << "  |   |...|   |...|   |...|   |...| " << endl
				 
				 << (8 - i) << " | " << board[0][7 - i] << " |." << board[1][7 - i] << ".| " << board[2][7 - i] << " |." << board[3][7 - i] << ".| " << board[4][7 - i] << " |." << board[5][7 - i] << ".| " << board[6][7 - i] << " |." << board[7][7 - i] << ".| " << endl
				 
				 << "  |   |...|   |...|   |...|   |...| " << endl;
		}
		if (i < 7)
			cout << "  |---|---|---|---|---|---|---|---| " << endl;
	}
	cout << "   -------------------------------  " << endl 
		 << "    A   B   C   D   E   F   G   H   " << endl;

	if (0) // latter feature start
	{
		cout << "P" << endl;
	}
	else
	{
		cout << " " << endl;
	} // end
}



Game::~Game()
{
}
