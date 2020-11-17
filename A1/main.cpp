#include "animal.h"
#include "board.h"


int main()
{
	int size, c1row, c1col, c2row, c2col;
	cout << "Hello in the game" << endl << endl;
	cout << "Enter the size of the board: \n";
	cin >> size;

	//validation
	while (size < 9 || size > 12) {
		cout << "invalid. Size should be between 9 to 12" << endl;
		cin >> size;
	}

	cout << "\nSet the position of the Cat 1\n";
	cout << "Row of cat 1  "; cin >> c1row;
	cout << "\ncolumn of cat 1  "; cin >> c1col;

	cout << "\nSet the position of the Cat 2\n";
	cout << "Row of cat 2  "; cin >> c2row;
	cout << "\ncolumn of cat 2  "; cin >> c2col;

	//Setting the board
	Board Game(size, c1row, c1col, c2row, c2col);

	//creating a num of ojects in type animal represnting the farm animals 
	int anml_num;
	cout << "How many animals do you want in the Game?\n";
	cin >> anml_num;

	//will use 1D dynamic array to create multible objects
	animal* anml = new animal [anml_num];
	string name;  int row, col;

	//opening the file 
	ifstream inf;
	inf.open("Input.txt");

	if (inf.fail())
    {
		cout << "Error while opening the file\n";
		exit(1);
	}

	//dealing with every animal
	for (int i = 0; i < anml_num; i++)
	{
		cout << "\nEnter the name of animal " << i + 1 << ":  ";
		cin >> name;
		cout << "The row:  ";  
		cin >> row;
		cout << "The column:  ";
		cin >> col;

		*(anml + i) = animal(row, col, name); //initializing the object (the animal)
		
		//reading characters from the file in array
		char move[4];
		char current_position;
		string msg = "";


		for ( int j = 0; j < 4; j++) //char insertion
		{
			inf >> move[j];

			if ((*(anml + i)).move(move[j], size))
			{
				current_position = Game.getBoardCell((*(anml + i)).getRow(), (*(anml + i)).getColumn()); //assign the char in the cell of the current position of animal
				if (current_position == 'C')
				{
					msg = ": Eaten by Cat\n";
					break;
				}
				if (current_position == 'B')
				{
					msg = ": Escaped through the bridge\n";
					break;
				}
				if (j == 3 && current_position == '-' && msg == "")
				{
					msg = ": Starved .. Stuck inside the board\n";
				}
			}
			else
			{
				msg = ": Drowned outside the island\n";
				break; //to exit the loop*/
			}
		}
		cout << "\n" << name << msg << endl;
	}

	inf.close();
		
		Game.Print();
		delete[] anml;

		system("pause");
		return 0;
}