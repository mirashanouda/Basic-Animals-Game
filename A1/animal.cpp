#include "animal.h"

//Default constructor
animal::animal() : rowPosition(0), columnPosition(0), name(" ")
{
}

//Constructor
animal::animal(int row, int col, string n) : rowPosition(row), columnPosition(col), name(n)
{
}


bool animal::move(char c, int boundary) //this function checks the position of animal if it's inside the board or not
{
	switch (c)
	{
		case 'U':
			rowPosition--;
			break;
		case 'D':
			rowPosition++;
			break;
		case 'R':
			columnPosition++;
			break;
		case 'L':
			columnPosition--;
			break;
	}
	if ((rowPosition >= boundary) || (columnPosition >= boundary) || (rowPosition < 0) || (columnPosition < 0))
		return false;
	return true;
}

int animal::getRow() {
	return rowPosition;
}
int animal::getColumn() {
	return columnPosition;
}