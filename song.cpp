#include <string>
#include "song.h"

using namespace std;


song::song() {
song_name = "";
artist = "";
size=0;
}

song::song(string const name, string const author, int memsz){
    song_name=author;
    artist=name;
    size=memsz;
    }
string song::getSong()const{
    return song_name;
}

string song::getArtist ()const{
    return artist;
}

void song::setSize(int songsize){
    size=songsize;
}

int song::getSize()const{
    return size;
}

void song::setSong(const string song){
    song_name=song;
}

void song::setArtist(const string artist_name){
    artist=artist_name;
}

bool song::operator >(song const &rhs){
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

bool song::operator ==(song const &rhs){

	return(this->song_name==rhs.song_name && this->artist==rhs.artist && this->size==rhs.size);
}
