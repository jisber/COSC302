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
	
	int tc= 0;
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
//	Music libr;
	bool found = 0;
	multimap<string,Artist>::iterator it;
	multimap<string,Album>::iterator ita;
	multimap<string,Song>::iterator its;

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
	

	it = library.find(tArtist.name);
	if(it == library.end()) {
		library.insert(pair<string,Artist>(tArtist.name, tArtist));
	}

	it = library.find(tArtist.name);
	it->second.name = tArtist.name;

	ita = it->second.albums.find(tAlbum.name);
	if(ita == it->second.albums.end()){
		it->second.albums.insert(pair<string,Album>(tAlbum.name, tAlbum));
	}
	
	ita = it->second.albums.find(tAlbum.name);
	ita->second.name = tAlbum.name;

	its = ita->second.songs.find(tSong.track);
	if(its == ita->second.songs.end()){
		ita->second.songs.insert(pair<string,Song>(tSong.track, tSong));
	}

	its = ita->second.songs.find(tSong.track);
	its->second.title = tSong.title;
	its->second.time = tSong.time;
	its->second.track = tSong.track;
		
/*	
	for(it = library.begin(); it != library.end(); it++) {
		cout << "First: " << it->first << endl;
		for(ita = it->second.albums.begin(); ita != it->second.albums.end(); ita++) {
			cout << "Second: \t" << ita->first << endl;
			for(its = ita->second.songs.begin(); its != ita->second.songs.end(); its++) {
				cout << "Third: \t\t" << its->first << endl;
			}
		}
	}


	
		for(it = library.begin(); it != library.end(); ++it) {
		cout << "First: " << it->first << endl;// "Second: " << it->second << endl;
	//	cout << tc << endl;
	//	tc++;
	}
	*/
	
	

	return;
}
