#include "Playlist.h"
#include "Song.h"
#include "Podcast.h"

int main() {
    Playlist myPlaylist;

    // Direct heap allocation passed to the Playlist
    myPlaylist.addStream(new Song("Starman", "David Bowie", 250, "Ziggy Stardust"));
    myPlaylist.addStream(new Podcast("The Daily", "Michael Barbaro", 1800, 1024, "NYT Staff"));
    myPlaylist.addStream(new Song("Blinding Lights", "The Weeknd", 200, "After Hours"));

    myPlaylist.showPlaylist();

    myPlaylist.playAll();

    return 0; // Playlist destructor handles memory cleanup
}