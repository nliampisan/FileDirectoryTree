#ifndef DIRECTORYTREE_HPP
#define DIRECTORYTREE_HPP

#include "myFile.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std; 


class node {
public:
	node():name(""),parent(NULL),file_ptr(NULL){}
	node(string fname):name(fname),parent(NULL),file_ptr(NULL){}
	string name; 
	node * parent; 
	myFile * file_ptr; 
	vector<node*> children; 
};

// n-ary tree 
class DirectoryTree {
public: 
	//default cctor
	DirectoryTree(); 
	//destructor
	~DirectoryTree(); 
	// for running a file depending on the type(polymorphism)
	void run(string fname); 
	void cat(string fname);
	//change the shell working directory
	void cd(string fname);
	//go to the parent of the current directory
	void cd_prev(); 
	//list all files in the current directory
	void ls();
	// create a text file
	void meow_txt(string fname); 
	// create a timer file
	void meow_time(string fname); 
	// create a music file
	void meow_music(string fname); 
	// create a directory
	void mkdir(string fname); 
	// print current working directory
	void pwd(); 
	// recursively remove file or folder
	void rm(string fname); 
	// print all nodes in directory tree
	void recur_print(); 
private:
	vector<string> path_name; 
	node * root; 
	node * curr_ptr;
	void recur_del(node * target); 
	void recur_print_helper(node *target, int level);
	node* search_file(string fname); 
};


#endif