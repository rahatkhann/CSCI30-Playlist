#pragma once

#include <iostream>
#include <string>
#include "AudioStream.h"

using namespace std;

class Song : public AudioStream {
private:
    string albumName;

public:
    Song(string tit, string art, int dur, string album)
        : AudioStream(tit, art, dur), albumName(album) {}

void play() const override {
    cout << "Now playing Song: "
         << getTitle()
         << " by "
         << getArtist()
         << endl;

    cout << " from the album "
         << albumName
         << "."
         << endl;
}
};