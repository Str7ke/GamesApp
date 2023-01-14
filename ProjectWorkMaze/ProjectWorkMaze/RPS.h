#pragma once
char names[3][15]{
	"ROCK",
	"PAPER",
	"SCISSORS"
};
HANDLE consoleR = GetStdHandle(STD_OUTPUT_HANDLE);

int selectedindexRPS = 0;
//int selectedindexRPS = 0;



void PrintNames() {
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		if (i == selectedindexRPS) {
			SetConsoleTextAttribute(consoleR, 0x70);
			cout << "> " << names[i] << endl;
			SetConsoleTextAttribute(consoleR, 0x07);
		}
		else {
			cout << names[i] << endl;
		}
	}
}

int compChooise;

// random number
int CompChooise() {
	srand(time(0));
	


	  compChooise = rand() % 3 ;

	//1 means Rock
	//2 means Paper
	//3 means Scissors
	return compChooise;
}

bool LogicRPS(int key) {
	switch (key)
	{
	case w:
	case up:
		if (selectedindexRPS > 0)
			selectedindexRPS--;
		else if (selectedindexRPS == 0)
			selectedindexRPS = 3 - 1;
		break;
	case s:
	case down:
		if (selectedindexRPS < 3 - 1)
			selectedindexRPS++;
		else if (selectedindexRPS == 3 - 1)
			selectedindexRPS = 0;
		break;

	case enter:
		system("cls");
		CompChooise();
		cout << "your choice is: " << names[selectedindexRPS] << endl;
		cout << "computer's choice is: " << names[compChooise] << endl;

		if (selectedindexRPS == 0)
		{
			if (compChooise == 1)
				cout << "computer wins! paper wraps rock." << endl;
			else if (compChooise == 2)
				cout << "you win! paper wraps rock." << endl;
			else if (compChooise == 0)
				cout << "tie. play again win the game." << endl;
		}
			
		else if (selectedindexRPS == 1)
		{
			if (compChooise == 0)
				cout << "you win! paper wraps rock." << endl;
			else if (compChooise == 2)
				cout << "computer wins! scissors cut paper." << endl;
			else if (compChooise == 1)
				cout << "tie. play again win the game." << endl;
		}

		else if (selectedindexRPS == 2)
		{
			if (compChooise == 0)
				cout << "computer wins! rock smashes scissors." << endl;
			else if (compChooise == 1)
				cout << "you win! scissors cut paper." << endl;
			else if (compChooise == 2)
				cout << "tie. play again win the game." << endl;
		}	
		_getch();
	case esc:
		system("cls");
		return true;
	}
	return false;
}
	