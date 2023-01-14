#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
using namespace std;
#include "timer.h"
#include "Enums.h"
#include "MainMenuFunctions.h"


int main()
{

	bool end = false;
	while (end == false) {
		// print
		PrintMenu();

		// input
		int key = _getch();

		// logic
		if (Logic(key))
			break;
	}

	cout << "Thank you for using my application)))" << endl;
	HeartMaker();
}