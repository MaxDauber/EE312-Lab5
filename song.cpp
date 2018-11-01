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
    return true;
    
}

bool song::operator ==(song const &rhs){
    return true;
}
