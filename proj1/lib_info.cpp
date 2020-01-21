//Jacob Isber and Dani Shekoury
//Project 1
//Revision 1.0
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

	string line;
	ifstream fin;

	fin.open(argv[1]);

	if(fin.fail()) cout << "Could not open file" << endl;

	while(getline(fin, line)) {
		
		

			
	}



	return 0;
}
