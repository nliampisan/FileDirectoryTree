#ifndef MUSICFILE_HPP
#define MUSICFILE_HPP
#include "myFile.hpp"
#include <iostream>
#include <string>
#include <Windows.h>//beep
using namespace std;

//stores musical notes in a string format
class myMusicFile :public myFile {
public:
	myMusicFile() :myFile("TextFile") {}
	void printData();
	void createFile();
	void runFile();
private:
	string data;
};

//prints out the actual string value of data
void myMusicFile::printData() {
	cout << data;
}

//gets user to input a line of characters as data 
void myMusicFile::createFile() {
	cout << "Enter musical notes in one line: " << endl;
	getline(cin, data);
}

//goes through the data and deciphers each character for the 
// appropriate beep sound
void myMusicFile::runFile() {
	for (int i = 0; i < data.length(); i++) {
		switch (data[i]) {
		case('0'):
			Beep(523, 500);
			break;
		case('1'):
			Beep(587, 500);
			break;
		case('2'):
			Beep(659, 500);
			break;
		case('3'):
			Beep(698, 500);
			break;
		default:
			Beep(784, 500);
			break;

		}

	}
}

#endif