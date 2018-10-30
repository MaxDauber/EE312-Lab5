/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t(512);

    song s1("Deatles", "Hey Jude1", 5);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
    
    t.showSongList();
          
    song s2("Zeatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    
    t.showSongList();
       
    song s3("Aeatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
       
    song s4("Teatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
       
    song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    cout << t.getRemainingMemory()<<endl;

    cout<< t.getNumSongs();

    t.sortSongList();
    t.showSongList();
    cout<<"\n \n \n";
    t.shuffle();
    t.showSongList();

    song s6("Sicko Mode", "Travis Scott", 3);
    result = t.removeSong(s6);
    cout << "delete result = " << result << endl;
    t.showSongList();
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
 
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
    

}