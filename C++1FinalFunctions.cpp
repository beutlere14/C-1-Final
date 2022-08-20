/*
Eli Beutler 
Function Definitions for C++1 Finals

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


//Varibles
string collectName; // used to collect players name
int timeHour = 5; // for the hour in a clock
int timeTenMinute = 0; // for the tens in a clock should only show if it is 0
int timelesserMinute = 0; // for the single digets in a clock
int lazinzessOrVeryDirty = 10; //for any extra amount of time needed to do something at random


string lookOfDay; // for if it is a delivery day or not


string randomAnswer; // for any and all local questions
int randomNumber; // for generating random number


//References
string& playerName = collectName;
string& dayStatus = lookOfDay;
int& lazy = lazinzessOrVeryDirty;


//Vectors and Arrays
string weekDays[7] = { "Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday" , "Saturday" , "Sunday" };
vector<string> workLoad;
vector<int> workTimeRandom; //Any randomization in how long somethign will take
vector<int> workTimeAlways; // the minimum something shoould take


//functions
void printClock() {
	clockCheck();

	// to have the extra 0 digit
	if (timelesserMinute < 10) {
		cout << "Current time is " << timeHour << ":" << timeTenMinute << timelesserMinute << endl;
	}

	// if the 0 digit is not needed.
	if (timelesserMinute > 10) {
		cout << "Current time is " << timeHour << ":" << timelesserMinute << endl;
	}
}


void clockCheck() { // used to make sure time is beign added up correctly.
	while (timelesserMinute >= 60) {
		int a = 60;
		timelesserMinute = timelesserMinute - a;

		int b = 1;
		timeHour = timeHour + b;

	}

}

void clockingIn() {
	//string playerName;
	//cout << "Welcome to JoJo's Bizarre Adventure. Could you tell us your name fellow JoBro?" << endl;

	//INTRO
	cout << "You are now clocking in for your shift at In-N-Out. Your job is that of a 5am to 10am cleaner. You generally work with one other person." << endl;
	cout << "Much of how this works is random. You will be allowed to pick for yourself in many instances. Or pick a random option anyway. Your goal is to finish by 10:00am." << endl;
	system("pause");
	cout << "All of that out of the way, what is your name again?" << endl;
	getline(cin, collectName); //allows you to get the entire line of string.
	cout << "Lovely, it is nice to meet you again " << playerName << "!" << endl;
	system("pause");

	cout << endl;
	cout << endl;

	//return playerName;

	cout << "Now to decide when you clocked in, pick: ON TIME , LITTLE LATE , or RANDOM" << endl;
	getline(cin, randomAnswer); //allows you to get the entire line of string.

	if (randomAnswer == "ON TIME") {
		randomNumber = rand() % 1 + 1;


		if (randomNumber == 1){
			cout << "You manage to be the first one inside. You turn off the alarm and clock in." << endl;
		}

		if (randomNumber == 2){
			cout << "Your coworker is already inside and has already turned off the alarm. You manage to clock in on time." << endl;
		}

	}
	if (randomAnswer == "LITTLE LATE") {

		randomNumber = rand() % 20 + 1;
		cout << "You manage to get to work an clock in. You are a bit late however." << endl;
		timelesserMinute = timelesserMinute + randomNumber;

	}
	if (randomAnswer == "RANDOM") {
		randomNumber = rand() % 61;
		cout << "You have arrived at work and clocked in." << endl;
		timelesserMinute = timelesserMinute + randomNumber;

	}

	printClock();
	system("pause");

	cout << endl;
	cout << endl;

}


void dayOverview() {
	cout << playerName << ", now that you are all clocked in. Let's look how things will be functioning for us." << endl;

	randomNumber = rand() % 100 + 1;

	if (randomNumber <40) {
		dayStatus = "Normal";
		randomNumber = rand() % 7;

		cout << "Today is a " << dayStatus << " day. It is also a " << weekDays[randomNumber] << " so lets get to it." << endl;


	}
	if (randomNumber > 39 && randomNumber <80) {
		dayStatus = "Delivery";
		randomNumber = rand() % 7;

		cout << "Today is a " << dayStatus << " day. It is also a " << weekDays[randomNumber] << " so lets get to it." << endl;
	}

	if (randomNumber > 79) {
		dayStatus = "Steam Clean";
		randomNumber = rand() % 7;

		cout << "Today is a " << dayStatus << " day. It is also a " << weekDays[randomNumber] << " so lets get to it." << endl;

	}

	system("pause");

	cout << endl;
	cout << endl;
}

void loadFigure() {
	if (dayStatus == "Normal") {
		workLoad.push_back("Trash and stretching"); //0
		workTimeAlways.push_back(10);
		workTimeRandom.push_back(5);

		workLoad.push_back("One of you does Mat and Mat side of Floors. The other Fryer Oil and Side Scrubbing"); //1
		workTimeAlways.push_back(45);
		workTimeRandom.push_back(15);

		workLoad.push_back("Fryer Side of Floors"); //2
		workTimeAlways.push_back(15);
		workTimeRandom.push_back(5);

		workLoad.push_back("Drains"); //3
		workTimeAlways.push_back(10);
		workTimeRandom.push_back(5);

		workLoad.push_back("Wipe Down"); //4
		workTimeAlways.push_back(25);
		workTimeRandom.push_back(25);

		workLoad.push_back("10 minute break"); //5
		workTimeAlways.push_back(10);
		workTimeRandom.push_back(1);

		workLoad.push_back("One of you does Green Machine.The other does Sweep side of things."); //6
		workTimeAlways.push_back(40);
		workTimeRandom.push_back(20);

		workLoad.push_back("Windows"); //7
		workTimeAlways.push_back(30);
		workTimeRandom.push_back(10);

		workLoad.push_back("One of you does the final sweep and mop. While the other organizes the back of house"); //8
		workTimeAlways.push_back(20);
		workTimeRandom.push_back(20);

		lazy = 10;
	}


	if (dayStatus == "Delivery") {
		workLoad.push_back("Delivery"); //0
		workTimeAlways.push_back(40);
		workTimeRandom.push_back(20);

		workLoad.push_back("Trash and stretching"); //1
		workTimeAlways.push_back(10);
		workTimeRandom.push_back(5);

		workLoad.push_back("One of you does Mat and Mat side of Floors. The other Fryer Oil and Side Scrubbing"); //2
		workTimeAlways.push_back(45);
		workTimeRandom.push_back(15);

		workLoad.push_back("Fryer Side of Floors"); //3
		workTimeAlways.push_back(15);
		workTimeRandom.push_back(5);

		workLoad.push_back("Wipe Down"); //4
		workTimeAlways.push_back(25);
		workTimeRandom.push_back(25);

		workLoad.push_back("10 minute break"); //5
		workTimeAlways.push_back(10);
		workTimeRandom.push_back(1);

		workLoad.push_back("One of you does Green Machine.The other does Sweep side of things."); //6
		workTimeAlways.push_back(40);
		workTimeRandom.push_back(20);

		workLoad.push_back("Windows"); //7
		workTimeAlways.push_back(30);
		workTimeRandom.push_back(10);

		workLoad.push_back("One of you does the final sweep and mop. While the other organizes the back of house"); //8
		workTimeAlways.push_back(20);
		workTimeRandom.push_back(20);

		workLoad.push_back("White and brown boxes in locker room from delivery."); //9
		workTimeAlways.push_back(10);
		workTimeRandom.push_back(20);


		lazy = 8;
	}


	if (dayStatus == "Steam Clean") {
		workLoad.push_back("Trash and stretching"); //0
		workTimeAlways.push_back(10);
		workTimeRandom.push_back(5);

		workLoad.push_back("Cleaning Lockers and Trash Cans"); //1
		workTimeAlways.push_back(60);
		workTimeRandom.push_back(30);

		workLoad.push_back("Fryer oil and Side Scrubbing"); //2
		workTimeAlways.push_back(45);
		workTimeRandom.push_back(15);

		workLoad.push_back("Floors in the back by the Lockers"); //3
		workTimeAlways.push_back(20);
		workTimeRandom.push_back(5);

		workLoad.push_back("Random Detailing"); //4
		workTimeAlways.push_back(45);
		workTimeRandom.push_back(15);

		workLoad.push_back("10 Minute Break"); //5
		workTimeAlways.push_back(10);
		workTimeRandom.push_back(1);

		workLoad.push_back("One of you does Green Machine.The other does Sweep side of things."); //6
		workTimeAlways.push_back(40);
		workTimeRandom.push_back(20);

		workLoad.push_back("Windows"); //7
		workTimeAlways.push_back(30);
		workTimeRandom.push_back(10);

		workLoad.push_back("One of you does the final sweep and mop. While the other organizes the back of house."); //8
		workTimeAlways.push_back(20);
		workTimeRandom.push_back(20);



		lazy = 12;
	}

	cout << "Given that today is a " << dayStatus << " day. This is what our worklist looks like:" << endl;
	cout << endl;
	for (int i = 0; i < workLoad.size(); i++){ // prints out list of work needed to be done
		cout << workLoad.at(i) << ", " << ' ' << endl;
}

	system("pause");

	cout << endl;
	cout << endl;
}




void getterDone(){
	for (int i = 0; i < workLoad.size(); i++) { // to get it to work for the number of tasks at hand
		cout << workLoad.at(i) << ", " << ' ' << endl;

		int a = workTimeAlways.at(i) + workTimeRandom.at(i); // used for total time needed on a task.

		cout << "The current task is: " << workLoad.at(i) << endl;
		cout << "It should take " << workTimeAlways.at(i) << " to " << a << " minutes; excluding any level of laziness." << endl;

		system("pause");
		cout << endl;
		int b = rand() % workTimeRandom.at(i) + rand() % lazy + workTimeAlways.at(i); // the true total amount of time you spent working on the task
		
		cout << playerName <<", you spent " << b << " minutes on this task." << endl;
		timelesserMinute = timelesserMinute + b;

		printClock();
		
		system("pause");
		cout << endl;
		cout << endl;

	}

}

void clockingOUT() {
	if (timelesserMinute < 10) { // so the filler 0 shows

		if (timeHour == 9) {// done early
			cout << "Amazing job " << playerName << "!!! You got done way ahead of time! You finished at " << timeHour << ":" << timeTenMinute << timelesserMinute << ". Have a wonderful rest of your day." << endl;
		}

		if (timeHour == 10 && timelesserMinute == 0) { //done right on time
			cout << "Amazing job " << playerName << "! You finished at " << timeHour << ":" << timeTenMinute << timelesserMinute << ", perfectly on schedule. Have a wonderful rest of your day." << endl;
		}

		if (timeHour == 10 && timelesserMinute < 30) { // a bit late
			cout << "Okay, " << playerName << ". You got done in a reasonable ammount of time. " << timeHour << ":" << timeTenMinute << timelesserMinute << ". Have a wonderful rest of your day, but we got to work a bit faster and aim for that 10:00." << endl;
		}

		if (timeHour == 10 && timelesserMinute <= 59 && timelesserMinute >= 30) { //done very late
			cout << "Yikes " << playerName << "! You finished at " << timeHour << ":" << timeTenMinute << timelesserMinute << ", you really need to work on going faster. The goal is 10:00." << endl;
		}

		if (timeHour == 11) { //done very very late
			cout << "Yikes " << playerName << "! You finished at " << timeHour << ":" << timeTenMinute << timelesserMinute << ", you really need to work on going faster. You should never be here past 11:00. The goal is 10:00." << endl;
		}

		system("pause");
		cout << endl;
		cout << endl;

		cout << playerName << "clocks out at " << timeHour << ":" << timeTenMinute << timelesserMinute << "." << endl;
	}

	if (timelesserMinute >= 10) { // so the filler 0 doesn't show

		if (timeHour == 9) {// done early
			cout << "Amazing job " << playerName << "!!! You got done way ahead of time! You finished at " << timeHour << ":" << timelesserMinute << ". Have a wonderful rest of your day." << endl;
		}

		if (timeHour == 10 && timelesserMinute == 0) { //done right on time
			cout << "Amazing job " << playerName << "! You finished at " << timeHour << ":"  << timelesserMinute << ", perfectly on schedule. Have a wonderful rest of your day." << endl;
		}

		if (timeHour == 10 && timelesserMinute < 30) { // a bit late
			cout << "Okay, " << playerName << ". You got done in a reasonable ammount of time. " << timeHour << ":"  << timelesserMinute << ". Have a wonderful rest of your day, but we got to work a bit faster and aim for that 10:00." << endl;
		}

		if (timeHour == 10 && timelesserMinute <= 59 && timelesserMinute >= 30) { //done very late
			cout << "Yikes " << playerName << "! You finished at " << timeHour << ":"  << timelesserMinute << ", you really need to work on going faster. The goal is 10:00." << endl;
		}

		if (timeHour == 11) { //done very very late
			cout << "Yikes " << playerName << "! You finished at " << timeHour << ":"  << timelesserMinute << ", you really need to work on going faster. You should never be here past 11:00. The goal is 10:00." << endl;
		}

		system("pause");
		cout << endl;
		cout << endl;

		cout << playerName << "clocks out at " << timeHour << ":"  << timelesserMinute << "." << endl;
	}



}







void testFunction() {
	cout <<  playerName << endl;
	printClock();
}