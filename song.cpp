#include <string>
#include "song.h"

using namespace std;


song::song() { //default constructor
song_name = "";
artist = "";
size=0;
}

song::song(string const name, string const author, int memsz){//constructor when names are properly passed in
    song_name=author;
    artist=name;
    size=memsz;
    }
string song::getSong()const{//returns the name of the song
    return song_name;
}

string song::getArtist ()const{//returns the artist of the song
    return artist;
}

void song::setSize(int songsize){//changes the size of the song
    size=songsize;
}

int song::getSize()const{//returns the size of the song
    return size;
}

void song::setSong(const string song){//changes the name of the song
    song_name=song;
}

void song::setArtist(const string artist_name){//changes the artist of the song
    artist=artist_name;
}

bool song::operator >(song const &rhs){// operator allows for comparing of songs, to find the proper order to sort by
	if(this->artist > rhs.artist){
		return(true);
	}
	else if(this->artist == rhs.artist){
		if(this->song_name > rhs.song_name){
			return(true);
		}
	 	else if(this->song_name ==rhs.song_name){
			if(this->size > rhs.size){
				return(true);	
			}	
		}
	}
	return false;
			
}

bool song::operator ==(song const &rhs){// returns if songs are the same or not

	return(this->song_name==rhs.song_name && this->artist==rhs.artist && this->size==rhs.size);
}
