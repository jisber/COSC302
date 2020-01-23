//Jacob Isber and Dani Shekoury 1/23/20
//Project 1
//Revision 1.0
//This program reads in a file and sorts the information in the correct format. Specifically Artist, Albums, and Songs. 
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
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
		
	}
	
	libr.FillInfo();
	libr.Print();


	return 0;
}

//This function will take the information and store it into each indiviual struct
void Music::GetString(string temp) {

	istringstream str(temp);
	Song tSong;
	Artist tArtist;
	Album tAlbum;
	string time;
	multimap<string,Artist>::iterator it;
	multimap<string,Album>::iterator ita;
	multimap<int,Song>::iterator its;

	int track;
	int counter = 0;

//removes the underscore as well as store information into the struct
	do{
		string word;
		str >> word;

		for(size_t i = 0; i < word.size(); i++){ 
			if(word[i] == '_')
				word[i] = ' ';
		}
		
		if(counter == 0) tSong.title = word;
		else if(counter == 1) time = word;
		else if(counter == 2) tArtist.name = word;
		else if(counter == 3) tAlbum.name = word;
		else if(counter == 5){ 
			stringstream ss(word);
			ss >> track;
		}

		counter++;
	}while(str);

//Lines 76 - 101 access's the Artist/Album/Songs and store them in their areas
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
		ita->second.songs.insert(pair<int,Song>(track, tSong));
	}

	its = ita->second.songs.find(track);
	its->second.title = tSong.title;
	its->second.time = convert_time(time);
	its->second.track = track;
		
	return;
}

//This function fills what information we couldnt fill in the previous function as well as computes
void Music::FillInfo(){
	multimap<string,Artist>::iterator it;
	multimap<string,Album>::iterator ita;
	multimap<int,Song>::iterator its;
	int sTime = 0;
	int aTime = 0;
	int nSong = 0;

	for(it = library.begin(); it != library.end(); it++){
		aTime = 0;
		nSong = 0;
		for(ita = it->second.albums.begin(); ita != it->second.albums.end(); ita++) {
			sTime = 0;
			for(its = ita->second.songs.begin(); its != ita->second.songs.end(); its++) {
				sTime += its->second.time;
			}
			ita->second.time = sTime;
			ita->second.nsongs = ita->second.songs.size();
			nSong += ita->second.nsongs;
			aTime += ita->second.time;
		}
		it->second.time = aTime;
		it->second.nsongs = nSong;
	}


}
//This just prints in the correct format
void Music::Print(){
	multimap<string,Artist>::iterator it;
	multimap<string,Album>::iterator ita;
	multimap<int,Song>::iterator its;

	for(it = library.begin(); it != library.end(); it++){
		printf("%s: %d, %s\n", it->second.name.c_str(), it->second.nsongs, convert_time_back(it->second.time).c_str());
		for(ita = it->second.albums.begin(); ita != it->second.albums.end(); ita++) {
			printf("        %s: %d, %s\n", ita->second.name.c_str(), ita->second.nsongs, convert_time_back(ita->second.time).c_str());
			for(its = ita->second.songs.begin(); its != ita->second.songs.end(); its++) {
				printf("                %d. %s: %s\n", its->second.track, its->second.title.c_str(), convert_time_back(its->second.time).c_str());
			}
		}
	}
}

//Converts time. We sourced this method from stackoverflow then tweaked to be used in our program
int convert_time(string str) {
	stringstream ss(str);
	string hh,mm;
	getline(ss, hh, ':');
	getline(ss, mm, ';');

	int h,m;
	stringstream ssh(hh);
	ssh >> h;
	stringstream ssm(mm);
	ssm >> m;
	int minutes = ((h * 60) + m);;
	return minutes;
}

//This function converts time back to the original string format
string convert_time_back(int time){
	string str, hh, mm;
	int h, m;

	h = (time / 60);
	m = (time % 60);

	stringstream ssh;
	stringstream ssm;

	ssh << h;
	ssm << m;
	
	if(m < 10)
		str = ssh.str() + ":0" + ssm.str();
	else
		str = ssh.str() + ":" + ssm.str();

	return str;
}
