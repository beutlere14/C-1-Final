// EBFinalC++1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/* Eli Beutler
Began work on 8/7/2022
C++ 1 Final
*/
#include <iostream> // standard
#include <cstdlib> // for random
#include <ctime> // for random
#include <Windows.h> // for beep
#include <fstream> // for accessing other files
#include <string> // for string stuff life funding number of vowels
#include <vector> // for vector functionality
#include <cctype> // allows for differentiation between capital and lowercase

using namespace std; //allowing for certain formatting within code below

#include "FinalHeaderC++1.h"




int main()
{
	srand(time(0)); // for setting randomizer

	cout << "Are we working?" << endl; // test line
	system("pause");


	clockingIn();
	dayOverview();
	loadFigure();
	getterDone();
	clockingOUT();

	//testFunction(); // for testing
}
