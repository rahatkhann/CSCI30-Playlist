#include "Playlist.h"
#include "Song.h"
#include "Podcast.h"
#include <iostream>


using namespace std;

int main() {
    Playlist myPlaylist;

    // NOTE: WHEN YOU SUBMIT FOR TESTING, USE THE SAME STREAM DATA AS BELOW.
    //   When you are testing the logic_error you will need to temporarily modify the code below so that
    //   it does not add any streams to the playlist 

    myPlaylist.addStream(new Song("Starman", "David Bowie", 250, "Ziggy Stardust"));
    myPlaylist.addStream(new Song("Bohemian Rhapsody", "Queen", 354, "A Night at the Opera"));
    myPlaylist.addStream(new Song("Hotel California", "Eagles", 391, "Hotel California"));
    myPlaylist.addStream(new Song("Blinding Lights", "The Weeknd", 200, "After Hours"));
    myPlaylist.addStream(new Podcast("The Daily", "Michael Barbaro", 1800, 1024, "NYT Staff"));
    myPlaylist.addStream(new Podcast("Tech Overload", "Arun Maini", 1200, 45, "Tim Cook"));

    int idx1, idx2;

    myPlaylist.showPlaylist();

    cout << "\nEnter two indices to swap: ";
    cin >> idx1 >> idx2;

    cout << "\nAttempting to swap index " << idx1 << " and " << idx2 << "..." << endl;
    myPlaylist.swapSongs(idx1, idx2); 
        
    myPlaylist.showPlaylist();
    

    return 0; 
}