#include "Song.h"
#include "Album.h"

void Song::play() const {
    auto tempAlbum = albumPtr.lock();
    cout << "Now playing Song: "
         << getTitle()
         << " by "
         << getArtist()
         << " [Album: ";
    if (tempAlbum) {
        cout << tempAlbum->getAlbumName();
    } else {
        cout << "Album does not exist.";
    }
    cout << "]" << endl;
    playBuffer();
}