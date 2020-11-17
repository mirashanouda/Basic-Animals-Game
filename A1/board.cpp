#include "board.h"

Board::Board() //Default constructor
{
	boardSize = 9;

	board = new char* [boardSize];

	for (int i = 0; i < boardSize; i++)
		*(board + i) = new char[boardSize];

	//initialization
	for (int i = 0; i < boardSize; i++)
		for (int j = 0; j < boardSize; j++)
			*(*(board + i) + j) = '-';
}

Board::Board(int size, int c1r, int c1c, int c2r, int c2c)
{
	boardSize = size;

	board = new char* [boardSize];

	for (int i = 0; i < boardSize; i++)
		*(board + i) = new char[boardSize];

	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			//setting the position of bridge in the last column and the middle row. 
			//*(*(board + (boardSize / 2)) + boardSize - 1) = 'B'; 

			if ((i == boardSize / 2) && (j == boardSize - 1))
				*(*(board + i) + j) = 'B';

			//setting the position of 2 cats
			// -1 because the computer counts from 0 but when we enter the valuse we will count from 1

			else if ((i == c1r) && (j == c1c))
				*(*(board + i) + j) = 'C';
			else if ((i == c2r) && (j == c2c))
				*(*(board + i) + j) = 'C';

			else
				*(*(board + i) + j) = '-';

		}
		cout << endl;
	}

}

char Board::getBoardCell(int r, int c)
{
	return *(*(board + r) + c);
}



void Board::Print()
{
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
			cout << (*(*(board + i) + j)) << "  ";

		cout << endl;
	}
}

Board::~Board()
{
	boardSize = 0;

	for (int i = 0; i < boardSize; i++)
		delete[] * (board + i);

	delete[] board;
	cout << "deleting the dynamic array" << endl;
}