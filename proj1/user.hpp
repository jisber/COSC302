#pragma once
#include <set>
#include <map>

using namespace std;

struct Song { 
	string title;
	int time;  // could also be a string
	int track;
};

struct Album {
	map <int, Song > songs;
	string name;
	int time;
	int nsongs;  // optional variable but makes it easier
};

struct Artist {
	map <string, Album > albums;
	string name;
	int time;
	int nsongs;
};
