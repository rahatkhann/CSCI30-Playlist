#include "Playlist.h"
#include "Song.h"
#include "Podcast.h"
#include <iostream>
#include <stdexcept>
#include "Song.h"
#include "Podcast.h"

using namespace std;

int main() {
    Playlist myPlaylist;

    // Direct heap allocation passed to the Playlist
    myPlaylist.addSong("Starman", "David Bowie", 250, "Ziggy Stardust");
    myPlaylist.addSong("Bohemian Rhapsody", "Queen", 354, "A Night at the Opera");
    myPlaylist.addSong("Hotel California", "Eagles", 391, "Hotel California");
    myPlaylist.addSong("Blinding Lights", "The Weeknd", 200, "After Hours");
    myPlaylist.addPodcast("The Daily", "Michael Barbaro", 1800, 1024, "NYT Staff");
    myPlaylist.addPodcast("Tech Overload", "Arun Maini", 1200, 45, "Tim Cook");

    int idx1, idx2;

    myPlaylist.showPlaylist();
    myPlaylist.playAll();

    return 0; // Playlist destructor handles memory cleanup
}