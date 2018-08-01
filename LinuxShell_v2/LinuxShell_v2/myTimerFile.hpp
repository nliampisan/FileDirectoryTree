#ifndef TIMERFILE_HPP
#define TIMERFILE_HPP
#include "myFile.hpp"
#include <iostream>
#include <string>
#include <thread>
#include <Windows.h>//beep
#include <cstdio>//clock
#include <ctime>// clock
using namespace std;

//counts down from a user defined time
class myTimerFile :public myFile {
public:
	myTimerFile() :myFile("TimerFile"), seconds(0) {}
	void printData();
	void createFile();
	void runFile();
private:
	int seconds;
};

//prints out seconds
void myTimerFile::printData() {
	cout << seconds;
}
//gets integer input from user 
// this is the number of seconds from which to count up until
void myTimerFile::createFile() {
	cout << "Enter an integer for the timer:";
	cin >> seconds;
}

//first loop runs for x seconds
//background changes to red
//second loop runs for 4 seconds 
//background returns to normal
void myTimerFile::runFile() {
	std::clock_t start;
	start = std::clock();
	int duration;
	while (1) {
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		if (duration> seconds) {
			break;
		}
		cout << duration << endl;
	}
	system("color cA");
	clock_t start2;
	start2 = std::clock();
	while (1) {
		if ((clock() - start2) / (double)CLOCKS_PER_SEC> 4) {
			break;
		}

	}
	system("color 0A");
}


#endif