#include <iostream>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include "user.hpp"
using namespace std;

void GetString(string str){
//	Artist tArtist;
//	Album tAlbum;
//	Song tSong;

	stringstream ss(str);

	do{
		string word;
		ss >> word;

		cout << word << endl;
	} while(ss);

}
