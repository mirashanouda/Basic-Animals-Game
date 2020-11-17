#include "Header.h"

class animal
{
private:
	int rowPosition;
	int columnPosition;
	string name;
public:
	animal();
	animal(int, int, string);
	bool move(char, int);
	int getRow();
	int getColumn();
};