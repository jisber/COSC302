//Jacob Isber and Dani Shekoury
//Project 1
//Revision 1.0
#include <iostream>
#include <string>
#include <fstream>
#include "user.hpp"
#include <sstream>

 

using namespace std;

int main(int argc, char* argv[]) {

	string line;
	ifstream fin;
	Music libr;

	if(argc > 2) { cout << "Too many arguments" << endl; return -1;}

	//Opens and checks the file.
	fin.open(argv[1]);
	if(fin.fail()) cout << "Could not open file" << endl;

	while(getline(fin, line)) { //Reads in each line from the text file.
		
		libr.GetString(line);

	
	//	for(int i = 0; i < line.size(); i++) if(line[i] == '_') line[i] = ' ';	//Converts all "_" to a " " in a text file.
		
	}
	


	return 0;
}

void Music::GetString(string temp) {

	istringstream str(temp);
	Song tSong;
	Artist tArtist;
	Album tAlbum;

	int counter = 0;

	do{
		string word;
		str >> word;

		for(int i = 0; i < word.size(); i++){
			if(word[i] == '_')
				word[i] = ' ';
		}
		
		if(counter == 0) tSong.title = word;
		else if(counter == 1) tSong.time = word;
		else if(counter == 2) tArtist.name = word;
		else if(counter == 3) tAlbum.name = word;
		else if(counter == 5) tSong.track = word;
		


		counter++;
	}while(str);
		
		cout << tSong.title << " " << tSong.track << " " << tSong.time << endl;
	//	cout << tSong.title << " " << tArtist.name << " " << tAlbum.name << " " << tSong.track << " TEST" << endl;
	return;
}
