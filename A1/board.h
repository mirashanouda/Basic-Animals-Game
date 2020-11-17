#include "Header.h"

class Board
{
private:
	int boardSize;
	char** board; //not sure
public:
	Board(); //defult constructor //not in the assign
	Board(int size, int, int, int, int);
	char getBoardCell(int, int);
	void Print();
	~Board();
};