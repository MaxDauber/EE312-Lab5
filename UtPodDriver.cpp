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
{   string sizesong;
    bool error=false;
    int sizeofpod;
    cout<<"Please enter a desired size of memory for your utPod"<<endl;
    getline(cin,sizesong);
    sizeofpod=atoi(sizesong.c_str());//converts cin to an integer to construct pod
    UtPod t(sizeofpod);
    t.help();
    string action;
    int result;
    while(action!="stop") {//driver waits for the user command to stop, else will check for the user input to see if it matches anything
	error=true;// if the command doesnt match a real command will print out error code at the end
        cout<<"\nenter a command :";
        getline(cin,action);
	cout<<endl;
        string name;
        string artist;
        int sizeofsong;
        if(action=="addsong") {// creates song with the user input then adds the song to  the pod
            cout << "enter title of song: ";
            getline (cin,name);
            cout << "enter name of the artise: ";
            getline(cin,artist);
            cout << "enter the size of the song (in MB): ";
	    getline(cin,sizesong);
	    sizeofsong=atoi(sizesong.c_str());
	    while(sizeofsong<1) {
		cout<<"invalid size,try again"<<endl;
		cout << " enter the size of the song (in MB): ";
		getline(cin,sizesong);
		sizeofsong=atoi(sizesong.c_str());
		}
            song s(artist,name,sizeofsong);
            result=t.addSong(s);
            cout << "result = " << result << endl;
	    error=false;
        }
        if(action=="showsongs"){
            t.showSongList();
	    error=false;
        }
        if(action=="rmsong"){
            cout << "enter title of song: ";
            getline (cin,name);
            cout << "enter name of the artise: ";
            getline(cin,artist);
            cout << "enter the size of the song (in MB): ";
	    getline(cin,sizesong);
	    sizeofsong=atoi(sizesong.c_str());	
            song s(artist,name,sizeofsong);
            result=t.removeSong(s);
            cout << "result = " << result << endl;
	    error=false;
        }
        if(action=="shuffle"){
            t.shuffle();
            t.showSongList();
 	    error=false;
        }
        if(action=="sort") {
            t.sortSongList();
            t.showSongList();
	    error=false;		
        }
        if(action=="totmem"){
            result=t.getTotalMemory();
            cout << "result = " << result << endl;
	    error=false;
        }
        if(action=="remmem"){
            result=t.getRemainingMemory();
            cout << "result = " << result << endl;
 	    error=false;
        }
        if(action=="explode"){
            t.clearMemory();
	    error=false;
        }
        if(action=="stop"){
            t.clearMemory();
	    error=false;
        }
        if(action=="help"){
            t.help();
	    error=false;
        }
	if(error==true){
            cout<<"We cannot read your action please enter a new command or ask for help, by typing 'help'"<<endl;
		}
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
