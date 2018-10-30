
#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std;

class song {
private:
      string song_name;
      string artist;
      int size;

public:
    song()= default;
    song(string const name, string const author, int memsz);

    string getSong () const;

    void setSong(const string song);

    void setArtist(const string artist_name);

    string getArtist() const;

    void setSize(int songsize);

    int getSize() const;

    bool operator >(song const &rhs);
  //  bool operator ==(song const &rhs);


    ~song();
};











#endif