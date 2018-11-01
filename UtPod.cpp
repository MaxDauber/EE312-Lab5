
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "song.h"
#include "UtPod.h"

using namespace std;
UtPod::UtPod(){	//the default constructor of the UtPod
	memSize=MAX_MEMORY;
	songs=NULL;

}


int UtPod::getNumSongs(){//function that will return the number of songs in the pod
    //return (numSongs);
    SongNode *temp= songs;
    int cnt;
    for (cnt=0; temp!= NULL;cnt++){
        temp=temp->next;
    }
    return (cnt);
}

UtPod::UtPod(int size){//the constructor of the pod that allows for the setting of a pod by size
    if(size>=512||size<=0){ memSize=MAX_MEMORY;}
    else {
        memSize = size;
    }
    songs= NULL;
};

int UtPod::addSong(song const &s){//adds a song to the pod's linked list
    if(getRemainingMemory()< s.getSize()){
        return (NO_MEMORY);
    }

    SongNode *temp= new SongNode;
    temp->s=s;
    temp->next= NULL;
    if(songs== NULL){//if no songs will set the head to this songnode
        songs=temp;
    }
    else{
        SongNode *p = songs;
        while(p->next!=NULL){//otherwise will add it to the back of the linked list
            p=p->next;
        }
        p->next=temp;
    }
    return (SUCCESS);
};

int UtPod::removeSong(song const &s){//removes a song from the list, only if its characteristics match one on the list
    if(getNumSongs()==0){//if no songs, nothing to delete
        return NOT_FOUND;}
    SongNode *trail= NULL;
    SongNode *p=songs;
    if(p->s==s&&p->next== NULL){//if only one song delete it and set head to null
        delete(p);
        songs= NULL;
        return (SUCCESS);
    }
    while(!(p->s==s) && p->next!= NULL){//waits until at  end of list or finds song
        trail=p;
        p=p->next;
    }
    if(trail!= NULL && p->s==s) {//if any song in the middle gotta link the one before it to the next one
        trail->next = p->next;
        delete (p);
        return(SUCCESS);
    }
    if(trail== NULL && p->next!=NULL && p->s==s){//if its the first song gotta set head to the next song
        songs=p->next;
        delete(p);
        return(SUCCESS);
    }
/*
    if(trail== NULL && p->next==NULL && p->s.getSong()==s.getSong()){
        delete(p);
        return(SUCCESS);
    }
*/

    if(p->next == NULL){//if the  song isnt found, its not found
        return (NOT_FOUND);
    }
};


void UtPod::shuffle(){//changes the order of the songs, through use of the random function and swapping the songs 
    if(getNumSongs()==0||getNumSongs()==1){
        return;}
    int numchanges=getNumSongs()+2;
    while(numchanges>0) {
	int change1=0;
	int change2=0;
	while(change1==change2){
        change1 = (rand() % (getNumSongs()));
        change2= (rand() %(getNumSongs()) );
	}
        SongNode *temp1 = songs;
        SongNode *temp2 = songs;
        song change;
        for (int i=0; i<change1 ; i++){
            temp1=temp1->next;
        }
        for(int i=0; i<change2; i++) {
            temp2=temp2->next;
        }
        change=temp1->s;
        temp1->s=temp2->s;
        temp2->s=change;
        numchanges--;
    }
};
void UtPod::showSongList(){//scrolls thru the song list and prints them all out
    if(songs== NULL) {
	cout <<"No Songs contained in this pod"<<endl;
        return;
    }
    SongNode *temp =songs;
    while(temp!= NULL) {
	cout << "The artist is: " << temp->s.getArtist();
	cout << " The song is: " << temp->s.getSong();
	cout << " The size is: " << temp->s.getSize() << endl;	
        temp=temp->next;
    }
};
void UtPod::sortSongList(){ // use a bubble sort because it is the easiest
    for(int x=0; x<this->getNumSongs(); x++){
        SongNode *temp = songs;
        SongNode *temp2 = NULL;
        bool change=false;
        for(int y=0; y<this->getNumSongs()-1;y++){
            temp2=temp;
            temp=temp->next;
            if(temp2->s > temp->s){
                song temp3;
                temp3=temp->s;
                temp->s=temp2->s;
                temp2->s=temp3;
                change=true;
            }
            }
            if(!change){
            x=this->getNumSongs();
        }
    }
};

int UtPod::getTotalMemory() {//returns memory of pod
    return memSize;
}

int UtPod::getRemainingMemory(){//traverses thru list and subtracts song size from total mem
    int remSize=memSize;
    SongNode *temp=songs;
    for(int i=0; i<getNumSongs(); i++){
        remSize-= temp->s.getSize();
        //cout << getNumSongs()<<endl;
        temp=temp->next;
    }
    return (remSize);
};
/* FUNCTION - void clearMemory
 * clears all the songs from memory

   input parms -

   output parms -
*/
void UtPod::clearMemory(){
    SongNode * temp=songs;
    SongNode *temp2= NULL;
    while(temp!= NULL){
        temp2=temp->next;
        delete(temp);
        temp=temp2;
    }
    songs= NULL;
}
void UtPod::help() {
    cout << "To terminate program type 'stop'"<<endl;
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
}



UtPod ::~UtPod(){
clearMemory();
};
