#include "Game.h"
using namespace std;


Game::Game(Player pWhitePlayer, Player pBlackPlayer): isThereAWinner(false), whitePlayer(pWhitePlayer), blackPlayer(pBlackPlayer)
{
	for (int i = 0; i < 16; i++)
	{
		board[whitePlayer.getPieces()[i][0].getXPos()][whitePlayer.getPieces()[i][0].getYPos()] = whitePlayer.getPieces()[i][0].getChararcter();
	}
	for (int i = 0; i < 16; i++)
	{
		board[blackPlayer.getPieces()[i][0].getXPos()][blackPlayer.getPieces()[i][0].getYPos()] = blackPlayer.getPieces()[i][0].getChararcter();
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
		if (sTemp.at(0) >= 97 && sTemp.at(0) <= 104 && sTemp.at(1) >= 49 && sTemp.at(1) <= 56) // based on ascii table
		{
			xtemp = sTemp.at(0) - 49 - 48; // convert to 0...7 depends on the letter char
			ytemp = sTemp.at(1) - 1 - 48; // convert to 0...7 depends on the number char
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
					if (sTemp.at(0) >= 97 && sTemp.at(0) <= 104 && sTemp.at(1) >= 49 && sTemp.at(1) <= 56) // based on ascii table
					{
						char nextxtemp, nextytemp;
						nextxtemp = sTemp.at(0) - (49 + 48); // convert to 0...7 depends on the letter char
						nextytemp = sTemp.at(1) - 1 - 48; // convert to 0...7 depends on the number char
						bool canMoveThat = 0; // 0 == no, 1 == can, 2 == can and it takes another piece
						if (isWhitesTurn)
							canMoveThat = whitePlayer.takeMove(xtemp, ytemp, nextxtemp, nextytemp);
						else
							canMoveThat = blackPlayer.takeMove(xtemp, ytemp, nextxtemp, nextytemp);
						if (canMoveThat)
						{
							if (this->board[nextxtemp][nextytemp] != '\0')
							{
								if (isWhitesTurn)
									blackPlayer.setTakenPiece(nextxtemp, nextytemp);
								else
									whitePlayer.setTakenPiece(nextxtemp, nextytemp);
							}
							this->board[nextxtemp][nextytemp] = this->board[xtemp][ytemp];
							this->board[xtemp][ytemp] = '\0';
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
						throw "One of the given coordinates is invalid.";
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
			throw "One of the given coordinates is invalid.";
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
	cout << "   -------------------------------  " << endl;
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
}

bool Game::getIsWhitesTurn() const
{
	return this->isWhitesTurn;
}

Game::~Game()
{
}
