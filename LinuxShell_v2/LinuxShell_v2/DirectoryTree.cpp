#include "DirectoryTree.hpp"
#include "myFile.hpp"
#include "myTextFile.hpp"
#include "myTimerFile.hpp"
#include "myMusicFile.hpp"

// params: none
// creates a directory tree with a root node 
// and sets current node to root
DirectoryTree::DirectoryTree() {
	root = new node("root"); 
	curr_ptr = root; 
}

//params: none
// recursively frees all dynamically allocated memory
// uses postorder traversal 
DirectoryTree::~DirectoryTree() {
	recur_del(root); 
}


//params: filename (string) 
// checks if folder already exists or not
// then creates a node with an NULL file ptr with specified fname
void DirectoryTree::mkdir(string fname) {
	node * temp = search_file(fname);
	if (temp == NULL) {
		node * temp = new node(fname);
		temp->parent = curr_ptr;
		curr_ptr->children.push_back(temp);
	}
	else {
		cout << "directory already exists" << endl;
	}

}

//params: filename(string)
//checks if directory exists or not
//changes the current_ptr of directory
// pushes a node into path_name vector
void DirectoryTree::cd(string fname) {
	node * temp = search_file(fname); 
	if (temp != NULL && temp->file_ptr == NULL) {
		curr_ptr = temp; 
		path_name.push_back(curr_ptr->name); 
	}
	else {
		cout << "no such directory exists" << endl; 
	}
}


//params: none
//changes the current ptr to the parent of the current node
//pops a node into path_name vector 
void DirectoryTree::cd_prev() {
	if (curr_ptr == root) {
		return; 
	}
	else{
		curr_ptr = curr_ptr->parent; 
		path_name.pop_back(); 
	}
}

//params: none
//loops through all files and prints out the filename
void DirectoryTree::ls() {
	for (auto it = curr_ptr->children.begin(); it != curr_ptr->children.end(); it++) {
		cout << (*it)->name << " "; 
	}
	cout << endl; 
}

//params: none
// prints out all the strings in the path_name vector
void DirectoryTree::pwd() {
	if (curr_ptr == root) {
		cout << "/" << endl; 
		return; 
	}
	for (auto it = path_name.begin(); it != path_name.end(); it++) {
		cout << "/" << *it; 
	}
	cout << endl; 
	//cout << curr_ptr->name << endl;
}

//params: filename(string)
//searches for a file or directory matching fname
// if found recursively delete the director or simply remove file
void DirectoryTree::rm(string fname) {

	node * target = NULL;
	for (auto it = curr_ptr->children.begin(); it != curr_ptr->children.end(); it++) {
		if ((*it)->name == fname) {
			target = *it; 
			curr_ptr->children.erase(it); 
			break; 
		}
	}
	if (target != NULL) {
		recur_del(target);
	}
	else {
		cout << "no such file or directory exists" << endl;
	}

	
}


void DirectoryTree::recur_print() {
	recur_print_helper(root, 0); 
}

void DirectoryTree::recur_print_helper(node *target, int level) {
	if (target == NULL) {
		return;
	}
	else {
		for (auto it = target->children.begin(); it != target->children.end(); it++) {
			for (int i = 0; i < level; i++)
				cout << "\t";
			cout << (*it)->name << endl; 
			recur_print_helper(*it, level+1);
		}
	}
}


void DirectoryTree::recur_del(node * target) {
	if (target == NULL) {
		return; 
	}
	else{
		for (auto it = target->children.begin(); it != target->children.end(); it++) {
			recur_del(*it);
			free(*it);
			*it = NULL; 
		}
	}
}


node* DirectoryTree::search_file(string fname) {
	for (auto it = curr_ptr->children.begin(); it != curr_ptr->children.end(); it++) {
		if ((*it)->name == fname) {
			return *it; 
		}
	}
	return NULL; 
}

void DirectoryTree::meow_txt(string fname) {
	node * temp = search_file(fname);
	if (temp == NULL) {
		node * temp = new node(fname);
		myFile * newFile = new myTextFile(); 
		newFile->createFile(); 
		temp->file_ptr = newFile; 
		temp->parent = curr_ptr;
		curr_ptr->children.push_back(temp);
	}
	else {
		cout << "filename already exists" << endl;
	}
}
void DirectoryTree::meow_time(string fname) {
	node * temp = search_file(fname);
	if (temp == NULL) {
		node * temp = new node(fname);
		myFile * newFile = new myTimerFile();
		newFile->createFile();
		temp->file_ptr = newFile;
		temp->parent = curr_ptr;
		curr_ptr->children.push_back(temp);
	}
	else {
		cout << "filename already exists" << endl;
	}
}
void DirectoryTree::meow_music(string fname) {
	node * temp = search_file(fname);
	if (temp == NULL) {
		node * temp = new node(fname);
		myFile * newFile = new myMusicFile();
		newFile->createFile();
		temp->file_ptr = newFile;
		temp->parent = curr_ptr;
		curr_ptr->children.push_back(temp);
	}
	else {
		cout << "filename already exists" << endl;
	}
}

void DirectoryTree::run(string fname) {
	node * temp = search_file(fname);
	if (temp != NULL && temp->file_ptr != NULL) {
		temp->file_ptr->runFile(); 
	}
	else {
		cout << "no such file or directory exists" << endl;
	}
}
