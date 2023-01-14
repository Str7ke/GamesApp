#pragma once
#include "SecondMenuFucntions.h"
#include "Files.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

int selectedIndex = 0;
int selectedindex = 0;

char menu[4][80]{
		"Games",
		"Records in Boom",
		"About how i make this project",
		"Exit"


};


void PrintMenu() {
	system("cls");
	for (int i = 0; i < 4; i++)
	{
		if (i == selectedIndex) {
			SetConsoleTextAttribute(console, 0x70);
			cout << "> " << menu[i] << endl;
			SetConsoleTextAttribute(console, 0x07);
		}
		else {
			cout << menu[i] << endl;
		}
	}
}



bool Logic(int key) {
	switch (key)
	{
	case KEYBOARD_KEYS::w:
	case up:
		if (selectedIndex > 0)
			selectedIndex--;
		else if (selectedIndex == 0)
			selectedIndex = 4 - 1;
		break;
	case KEYBOARD_KEYS::s:
	case down:
		if (selectedIndex < 4 - 1)
			selectedIndex++;
		else if (selectedIndex == 4 - 1)
			selectedIndex = 0;
		break;

	case enter:
		system("cls");
		if (selectedIndex == 0) {
			bool end = false;
			while (end == false) {
				// print
				PrintGameMenu();

				// input
				int key = _getch();

				// logic
				if (LogicGame(key))
					break;
			}
			
		}
		else if (selectedIndex == 1) {
			bool end = false;
			while (end == false) {
				// print
				PrintRecordsMenu();

				// input
				int key = _getch();

				// logic
				if (LogicRecords(key))
					break;
			}

		}
		else if (selectedIndex == 2) {
			cout << "To see all of text open conosle full" << endl;
			cout <<"If u open full or console was open click any button"<< endl;
			_getch();
			system("cls");
			FILE* file1 = fopen("C:\\Users\\User\\Desktop\\AboutUs.txt", "r");
			ReadAllText(file1);
			cout << "To close this menu click any button" << endl;
			_getch();
			return false;

		}
		else if (selectedIndex == 3) {
			return true;

		}
		
		

		


	case esc:
		system("cls");
		return false;
	}

	return false;
}

//from internet
void HeartMaker() {
	int n, row, col;
	n = 6;
	for (row = 0; row < n; row++)
	{
		for (col = 0; col < n + 1; col++)
			if ((row == 0 && col % 3 != 0) || (row == 1 && col % 3 == 0) || (row - col == 2) || (row + col == 8))
				cout << ("*");
			else
				cout << (" ");

		cout << ("\n");
	}
	
}