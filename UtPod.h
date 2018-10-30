//DOCUMENT HERE

#ifndef UTPOD_H
#define UTPOD_H
#include <iostream>
#include "song.h"

//UtPod class declaration
class UtPod
{
   private:
      static const int MAX_MEMORY = 512;
      static const int SUCCESS = 0;
      static const int NO_MEMORY = -1;
      static const int NOT_FOUND = -2;
      
      struct SongNode
      {
         song s;
         SongNode *next;
      };
      
      SongNode *songs;  //the head pointer
      
      int memSize;
      int totalSize;
      int numSongs;
   
   public:
      UtPod()= default;
      UtPod(int size);
      int addSong(song const &s);
      int removeSong(song const &s);
      void shuffle();
      void showSongList();
      void sortSongList();
      int getTotalMemory();
      int getRemainingMemory();
      int getNumSongs();
      ~UtPod();


    //operator < (&rhs);

 
};



#endif