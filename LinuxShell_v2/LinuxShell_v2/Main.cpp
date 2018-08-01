#include <iostream>
#include <sstream>
#include <string>
#include <deque>
#include "DirectoryTree.hpp"
using namespace std; 

//params: in (string)
//splits input into substrings using space as a delimiter
deque<string>splitSpace(string in); 

//parse deque to see whether commands are valid and which option to use
void command_cd(deque<string> &temp, DirectoryTree & tree); 
void command_ls(deque<string> &temp, DirectoryTree & tree);
void command_mkdir(deque<string> &temp, DirectoryTree & tree);
void command_meow_txt(deque<string> &temp, DirectoryTree & tree);
void command_meow_time(deque<string> &temp, DirectoryTree & tree);
void command_meow_music(deque<string> &temp, DirectoryTree & tree);
void command_run(deque<string> &temp, DirectoryTree & tree);
void command_pwd(deque<string> &temp, DirectoryTree & tree);
void command_rm(deque<string> &temp, DirectoryTree & tree);
void command_recur_print(deque<string> &temp, DirectoryTree & tree);




int main() {

	DirectoryTree dir; 
	string myLine; 
	string inStr; 
	deque<string> command; 

	cout << "Nipat Liampisan" << endl;
	cout << "  /\\_/\\" << endl; 
	cout << " ( o.o )" << endl; 
	cout << "  > - <" << endl; 


	while (1) {
		cout << "user@meow ~$ "; 
		getline(cin, myLine); 
		command = splitSpace(myLine); 
		inStr = command.front(); 
		if (inStr == "cd") {
			command_cd(command, dir); 
		}
		else if (inStr == "ls") {
			command_ls(command, dir);
		}
		else if (inStr == "mkdir") {
			command_mkdir(command, dir);
		}
		else if (inStr == "pwd") {
			command_pwd(command, dir);
		}
		else if (inStr == "rm") {
			command_rm(command, dir);
		}
		else if (inStr == "recur_ls") {
			command_recur_print(command, dir);
		}
		else if (inStr == "meow_txt") {
			command_meow_txt(command, dir); 
		}
		else if (inStr == "meow_time") {
			command_meow_time(command, dir);
		}
		else if (inStr == "meow_music") {
			command_meow_music(command, dir);
		}
		else if (inStr == "run") {
			command_run(command, dir); 
		}
		else if (inStr == "exit") {
			exit(1); 
		}
		else if (inStr == "") {

		}
		else
		{
			cout << "command not found" << endl; 
		}
	}

	system("pause"); 
	return 0; 
}

//params: string in
//uses string stream to read one string at a time
//pushes each string into the deque
// return: deque<string>
deque<string> splitSpace(string in) {
	deque<string> ret;
	istringstream iss(in);
	do
	{
		string subs;
		iss >> subs;
		ret.push_back(subs);
	} while (iss);
	return ret;
}

void command_cd(deque<string> &temp, DirectoryTree & tree) {
	if (temp.size() == 3) {
		temp.pop_front(); 
		if (temp.front() == "..") {
			tree.cd_prev();
		}
		else {
			tree.cd(temp.front()); 
		}
	}
	else {
		cout << "command error" << endl; 
	}
}
void command_ls(deque<string> &temp, DirectoryTree & tree) {
	if (temp.size() == 2) {
		tree.ls(); 
	}
	else {
		cout << "command error" << endl;
	}
}

void command_mkdir(deque<string> &temp, DirectoryTree & tree) {
	if (temp.size() == 3) {
		temp.pop_front();
		tree.mkdir(temp.front()); 
	}
	else {
		cout << "command error" << endl;
	}
}

void command_pwd(deque<string> &temp, DirectoryTree & tree) {
	if (temp.size() == 2) {
		tree.pwd();
	}
	else {
		cout << "command error" << endl;
	}
}
void command_rm(deque<string> &temp, DirectoryTree & tree) {
	if (temp.size() == 3) {
		temp.pop_front();
		tree.rm(temp.front());
	}
	else {
		cout << "command error" << endl;
	}
}
void command_recur_print(deque<string> &temp, DirectoryTree & tree) {
	if (temp.size() == 2) {
		tree.recur_print(); 
	}
	else {
		cout << "command error" << endl;
	}
}

void command_meow_txt(deque<string> &temp, DirectoryTree & tree) {
	if (temp.size() == 3) {
		temp.pop_front();
		tree.meow_txt(temp.front());
	}
	else {
		cout << "command error" << endl;
	}
}

void command_meow_time(deque<string> &temp, DirectoryTree & tree) {
	if (temp.size() == 3) {
		temp.pop_front();
		tree.meow_time(temp.front());
	}
	else {
		cout << "command error" << endl;
	}
}

void command_meow_music(deque<string> &temp, DirectoryTree & tree) {
	if (temp.size() == 3) {
		temp.pop_front();
		tree.meow_music(temp.front());
	}
	else {
		cout << "command error" << endl;
	}
}

void command_run(deque<string> &temp, DirectoryTree & tree) {
	if (temp.size() == 3) {
		temp.pop_front();
		tree.run(temp.front());
	}
	else {
		cout << "command error" << endl;
	}
}