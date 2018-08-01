#ifndef TEXTFILE_HPP
#define TEXTFILE_HPP
#include "myFile.hpp"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

//stores user define text
class myTextFile :public myFile {
public:
	myTextFile() :myFile("TextFile") {}
	void printData();
	void createFile();
	void runFile();
private:
	string data;
};

// print out data
void myTextFile::printData() {
	cout << data;
}

//gets text characters from user 
//stops receiving text when user ends line with character |
void myTextFile::createFile() {
	string myLine;
	getline(cin, myLine, '|');
	data += myLine;

}

//prints out data
void myTextFile::runFile() {
	cout << data; 
}

#endif