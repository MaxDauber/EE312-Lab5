
#include <string>
#include <iostream>
#include "song.h"
#include "UtPod.h"

using namespace std;
int UtPod::getNumSongs(){
    //return (numSongs);
    SongNode *temp= songs;
    int cnt;
    for (cnt=0; temp!= nullptr;cnt++){
        temp=temp->next;
    }
    return (cnt);
}

UtPod::UtPod(int size){
    if(size>=512||size<=0){ memSize=MAX_MEMORY;}
    else {
        memSize = size;
    }
    songs= nullptr;
};

int UtPod::addSong(song const &s){
    if(getRemainingMemory()< s.getSize()){
        return (NO_MEMORY);
    }

    auto *temp= new SongNode;
    temp->s=s;
    temp->next= nullptr;
    if(songs== nullptr){
        songs=temp;
    }
    else{
        SongNode *p = songs;
        while(p->next!=nullptr){
            p=p->next;
        }
        p->next=temp;
    }
    return (SUCCESS);
};

int UtPod::removeSong(song const &s){
    if(getNumSongs()==0){
        return NOT_FOUND;}
    SongNode *trail= nullptr;
    SongNode *p=songs;
    if(p->s.getSong()==s.getSong()&&p->next== nullptr){
        delete(p);
        songs= nullptr;
        return (SUCCESS);
    }
    while(p->s.getSong()!=s.getSong() && p->next!= nullptr){
        trail=p;
        p=p->next;
    }
    if(trail!= nullptr && p->s.getSong()==s.getSong()) {
        trail->next = p->next;
        delete (p);
        return(SUCCESS);
    }
    if(trail== nullptr && p->next!=nullptr && p->s.getSong()==s.getSong()){
        songs=p->next;
        delete(p);
        return(SUCCESS);
    }
/*
    if(trail== nullptr && p->next==nullptr && p->s.getSong()==s.getSong()){
        delete(p);
        return(SUCCESS);
    }
*/

    if(p->next == nullptr){
        return (NOT_FOUND);
    }
};


void UtPod::shuffle(){
    if(getNumSongs()==0){
        return;}
    int numchanges=(rand()%1009);
    while(numchanges>0) {
        int change1 = (rand() % (getNumSongs()-1));
        int change2= (rand() %(getNumSongs()-1) );
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
void UtPod::showSongList(){
    if(songs== nullptr) {
        return;
    }
    SongNode *temp =songs;
    while(temp!= nullptr) {
        cout << "song is: " << temp->s.getSong()<< " artist is: "<< temp->s.getArtist()<<"size is: " <<temp->s.getSize()<<endl;
        temp=temp->next;
    }
};
void UtPod::sortSongList(){ // use a bubble sort because it is the easiest
    for(int x=0; x<this->getNumSongs(); x++){
        SongNode *temp = songs;
        SongNode *temp2 = nullptr;
        bool change=false;
        for(int y=0; y<this->getNumSongs()-1;y++){
            temp2=temp;
            temp=temp->next;
            if(temp->s.getArtist() < temp2->s.getArtist()){
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

int UtPod::getTotalMemory() {
    return memSize;
}

int UtPod::getRemainingMemory(){
    int remSize=memSize;
    SongNode *temp=songs;
    for(int i=0; i<getNumSongs(); i++){
        remSize-= temp->s.getSize();
        cout << getNumSongs()<<endl;
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
    SongNode *temp2= nullptr;
    while(temp!= nullptr){
        temp2=temp->next;
        delete(temp);
        temp=temp2;
    }
    songs= nullptr;
}
void UtPod::help() {
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
}



UtPod ::~UtPod()=default;