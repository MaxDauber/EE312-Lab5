/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include <string>
#include "song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    int sizeofpod;
    cout<<"Please enter a desired size of memory for your utPod"<<endl;
    cin>>sizeofpod;
    UtPod t(sizeofpod);
    t.help();
    cout << " To terminate program type 'stop'";
    cout << "The multiple options you can do are:" << endl;
    cout << "add a song by writing 'addsong' " << endl;
    cout << "Show the song list write 'showsongs'" << endl;
    cout << "remove a song type 'rmsong'"<<endl;
    cout << "shuffle the songs type 'shuffle'"<<endl;
    cout << "sort the songs type 'sort'"<<endl;
    cout << "show the total memory write 'totmem"<<endl;
    cout << "show rem memory write 'remmem"<<endl;
    cout << "delete all songs write 'explode'"<<endl;
    cout <<"To ask for help again write 'help"<<endl;
    string action;
    while(action!="stop") {
        cin>>action;
        if(action=="addsong") {
            string name;
            string artist;
            int sizeofsong;
            cout << "enter title of song: ";
            cin >> name;
            cout << "\n enter name of the artise: ";
            cin >> artist;
            cout << "\n enter the size of the song (in MB): ";
            cin >> sizeofsong;
            song s(name,artist,sizeofsong);
            t.addSong(s);
        }
        t.showSongList();




}


/*
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
*/


}