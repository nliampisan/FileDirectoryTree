#ifndef MYFILE_HPP
#define MYFILE_HPP

#include <iostream>
#include <string>
using namespace std; 

//abstract class for interfacing 3 types of files
class myFile {
public: 
	myFile() :descript(""){}
	myFile(string d):descript(d){}
	virtual void printData() = 0; 
	virtual void createFile() = 0; 
	virtual void runFile() = 0; 

private: 
	string descript; 
};

#endif


