#pragma once
HANDLE console3 = GetStdHandle(STD_OUTPUT_HANDLE);
int selectedindexX;
int selectedindexY;
char Firstname[20];
char SecondName[20];
char area[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
int Whosstep = 0;



void ClearArea(char area[][3]) {
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			area[j][i] = ' ';
		}
		
	}


}

void Printarea() {
	system("cls");
	if (Whosstep % 2 == 0)
		cout << Firstname << "  Your turn" << endl;
	else if (Whosstep % 2 != 0)
		cout << SecondName << "  Your turn" << endl;

	
	for (int j = 0; j < 3; j++)
	{


		for (int i = 0; i < 3; i++)
		{
			if (i == selectedindexX && j == selectedindexY) {
				SetConsoleTextAttribute(console3, 0x70);
				cout << area[j][i]<<" | ";
				SetConsoleTextAttribute(console3, 0x07);
			}
			else {
				cout << area[j][i] << " | ";
			}

		}
		cout << endl;
		cout << "___________" << endl;
	}
}
void Turns() {
	if (area[selectedindexY][selectedindexX]==' ')	
		Whosstep += 1;	
}

bool LogicT1(int key) {


	//switch (tolower(key))
	switch (key)
	{
	case KEYBOARD_KEYS::w:
	case KEYBOARD_KEYS::up:
		if (selectedindexY > 0)
			selectedindexY--;
		else if (selectedindexY == 0)
			selectedindexY = 3 - 1;
		break;


	case KEYBOARD_KEYS::s:
	case KEYBOARD_KEYS::down:
		if (selectedindexY < 3 - 1)
			selectedindexY++;
		else if (selectedindexY == 3 - 1)
			selectedindexY = 0;
		break;



	case KEYBOARD_KEYS::a:
	case KEYBOARD_KEYS::left:
		if (selectedindexX > 0)
			selectedindexX--;
		else if (selectedindexX == 0)
			selectedindexX = 3 - 1;
		break;

	case KEYBOARD_KEYS::d:
	case KEYBOARD_KEYS::right:
		if (selectedindexX < 3 - 1)
			selectedindexX++;
		else if (selectedindexX == 3 - 1)
			selectedindexX = 0;
		break;


	case enter:
		system("cls");
		Turns();
		
		 if (area[selectedindexY][selectedindexX] == ' ' && (Whosstep % 2 != 0)) {
					area[selectedindexY][selectedindexX] = 'X';
					
					
		 }
		 
		 else if (area[selectedindexY][selectedindexX] == ' ' && (Whosstep % 2 == 0)) {
		 	area[selectedindexY][selectedindexX] = 'O';
		 
		 
		 }


		if ((area[0][0] == 'X' && area[1][1] == 'X' && area[2][2]=='X' || area[0][0] == 'O' && area[1][1] == 'O' && area[2][2] == 'O')) {
			if (area[0][0] == 'X') {
				cout << Firstname << "  Wins!!!" << endl;
				_getch(); 
				return true; 
			}
				if (area[0][0] == 'O') {
					cout << Firstname << "  Wins!!!" << endl;
					_getch();
					return true;
				}
		}

		if ((area[0][2] == 'X' && area[1][1] == 'X' && area[2][0] == 'X' || area[0][2] == 'O' && area[1][1] == 'O' && area[2][0] == 'O')) {
			if (area[0][0] == 'X') {
				cout << Firstname << "  Wins!!!" << endl;
				_getch();
				return true;
			}
			if (area[0][0] == 'O') {
				cout << Firstname << "  Wins!!!" << endl;
				_getch();
				return true;
			}
		}
		for (int i = 0; i < 3; i++) {
			
			if (area[i][0] == area[i][1] && area[i][1] == area[i][2]) { 
				if (area[i][0] == 'X') {
					cout << Firstname << "  Wins!!!" << endl;
					_getch();
					return true;
				}
				if (area[i][0] == 'O') {
					cout << SecondName << "  Wins!!!" << endl;
					_getch();
					return true;
				}
			}
			if (area[0][i] == area[1][i] && area[1][i] == area[2][i]) { 
				if (area[0][i] == 'X') {
					cout << Firstname << "  Wins!!!" << endl;
					_getch();
					return true;
				}
				if (area[0][i] == 'O') {
					cout << SecondName << "  Wins!!!" << endl;
					_getch();
					return true;
				}
			}			
		}
		 
		int winner = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (area[i][j] != ' ')
				{
					winner += 1;
				}
			}
		}
		if (winner == 9) {
			cout << "Nobody wins,get ptactice to win your enemy!";
			_getch();
			return true;
		}
		

	}

	


	return false;
}