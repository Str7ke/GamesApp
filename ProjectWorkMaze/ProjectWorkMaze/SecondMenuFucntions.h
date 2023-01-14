#pragma once
#include "RPS.h"
#include "TicTac.h"
#include "BOOM.h"
#include "Files.h"
HANDLE console1 = GetStdHandle(STD_OUTPUT_HANDLE);
int selectedIndexGame = 0;
int selectedindexRecords = 0;

char menuGame[3][80]{
		"Rock,Paper & Siccors",
		"Tic,Tac",
		"BOOM"
};
char menuRecords[2][80]{
		"Show in console",
		"Export to txt",
		
};



void PrintGameMenu() {
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		if (i == selectedIndexGame) {
			SetConsoleTextAttribute(console1, 0x70);
			cout << "> " << menuGame[i] << endl;
			SetConsoleTextAttribute(console1, 0x07);
		}
		else {
			cout << menuGame[i] << endl;
		}
	}
}
void PrintRecordsMenu() {
	system("cls");
	for (int i = 0; i < 2; i++)
	{
		if (i == selectedindexRecords) {
			SetConsoleTextAttribute(console1, 0x70);
			cout << "> " << menuRecords[i] << endl;
			SetConsoleTextAttribute(console1, 0x07);
		}
		else {
			cout << menuRecords[i] << endl;
		}
	}
}
bool LogicGame(int key) {
	switch (key)
	{
	case w:
	case up:
		if (selectedIndexGame > 0)
			selectedIndexGame--;
		else if (selectedIndexGame == 0)
			selectedIndexGame = 3 - 1;
		break;
	case s:
	case down:
		if (selectedIndexGame < 3 - 1)
			selectedIndexGame++;
		else if (selectedIndexGame == 3 - 1)
			selectedIndexGame = 0;
		break;

	case enter:
		system("cls");
		if (selectedIndexGame == 0) {
			bool end2 = false;
			while (end2 == false) {
				// print
				PrintNames();
				

				// input
				int key2 = _getch();

				// logic
				if (LogicRPS(key2))
					break;
			}

		}

		else if (selectedIndexGame == 1) {
			ClearArea(area);
			Whosstep = 0;
			cout << "Enter First player name:", cin >> Firstname;
			cout << "Enter second player name:", cin >> SecondName;
			bool end3 = false;
			while (end3 == false) {
				// print
				Printarea();


				// input
				int key3 = _getch();

				// logic
				if (LogicT1(key3))
					break;

			}
		}

		else if (selectedIndexGame == 2) {
			Login();
			cout << "Enter mines count: ", cin >> MinesCount;
				AreaElement(areaUnvisible, areaX, areaY);
				AreaElement(areaVisible, areaX, areaY, '*');
				Randommines(areaUnvisible, areaX, areaY, MinesCount);
				MineFinder(areaUnvisible, areaX, areaY);
			bool end4 = false;
			while (end4 == false) {
				// print
				PrintBoom();


				// input
				int key4 = _getch();

				// logic
				if (LogicBoom(key4))
					break;
			}
		}
		

		// Exit


	case esc:
		system("cls");
		return true;
	}

	return false;
}

bool LogicRecords(int key) {
	switch (key)
	{
	case w:
	case up:
		if (selectedindexRecords > 0)
			selectedindexRecords--;
		else if (selectedindexRecords == 0)
			selectedindexRecords = 2 - 1;
		break;
	case s:
	case down:
		if (selectedindexRecords < 2 - 1)
			selectedindexRecords++;
		else if (selectedindexRecords == 2 - 1)
			selectedindexRecords = 0;
		break;
	case enter:
		system("cls");
		if (selectedindexRecords == 0)
		{
			cout << "To close click any button" << endl;
			FILE* file = fopen("Records.txt", "r");
			ReadAllText(file);
			fclose(file);
			_getch();

		}
		else if (selectedindexRecords == 1)
		{
			timer();
			_getch();

		}

	
	case esc:
		system("cls");
		return true;
	}

	return false;
}