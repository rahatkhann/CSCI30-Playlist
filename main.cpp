#include "Playlist.h"
#include "Album.h"
#include <iostream>
#include <memory>


using namespace std;

int main() {

    cout << "Testing menu:\n";
    cout << "Enter 1 for Playlist test\nEnter 2 for Album test\n";
    cout << "Enter 3 for Playlist and Album test\n";
    int choice;
    cin >> choice;

    unique_ptr<Playlist> myPlaylist;
    if (choice == 1 || choice == 3) {
        myPlaylist = make_unique<Playlist>();
        // 4 Songs
        myPlaylist->addSong("Starman", "David Bowie", 250, "Ziggy Stardust");
        myPlaylist->addSong("Bohemian Rhapsody", "Queen", 354, "A Night at the Opera");
        myPlaylist->addSong("Hotel California", "Eagles", 391, "Hotel California");
        myPlaylist->addSong("Blinding Lights", "The Weeknd", 200, "After Hours");

        // 2 Podcasts
        myPlaylist->addPodcast("The Daily", "Michael Barbaro", 1800, 1024, "NYT Staff");
        myPlaylist->addPodcast("Tech Overload", "Arun Maini", 1200, 45, "Tim Cook");

        myPlaylist->showPlaylist();

        if (choice == 1) {
            myPlaylist->playAll();
        }
    }

    shared_ptr<Album> abbeyRoad;
    if (choice == 2 || choice == 3) {
        abbeyRoad = make_shared<Album>("Abbey Road");
        abbeyRoad->addSong("Come Together", "The Beatles", 259, abbeyRoad);
        abbeyRoad->addSong("Something", "The Beatles", 183, abbeyRoad);
        abbeyRoad->addSong("Maxwell's Silver Hammer", "The Beatles", 207, abbeyRoad);
        
        if (choice == 2) {
            abbeyRoad->playAll();
        }
    }

    if (choice == 3) {
        myPlaylist->addStream(abbeyRoad->getTrack(1));
        myPlaylist->addStream(abbeyRoad->getTrack(0));

        myPlaylist->playAll();
    }
    return 0; 
}