//Jacob Isber and Dani Shekoury
//Project 1
//Revision 1.0
#include <iostream>
#include <string>
#include <fstream>
#include "user.hpp"

using namespace std;

int main(int argc, char* argv[]) {

	string line;
	ifstream fin;

	temp.title = "hello";
	cout << temp.title << endl;
	
	//Opens and checks the file.
	fin.open(argv[1]);
	if(fin.fail()) cout << "Could not open file" << endl;

	while(getline(fin, line)) { //Reads in each line from the text file.
	
		for(int i = 0; i < line.size(); i++) if(line[i] == '_') line[i] = ' ';	//Converts all "_" to a " " in a text file.
		
	}
	


	return 0;
}
