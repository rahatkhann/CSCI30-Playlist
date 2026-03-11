#pragma once

#include <iostream>
#include <string>
#include "AudioStream.h"

using namespace std;

class Podcast : public AudioStream {
private:
    int episodeNumber;
    string guest;

public:
    Podcast(string tit, string art, int dur, int epNum, string guestName)
        : AudioStream(tit, art, dur),
          episodeNumber(epNum),
          guest(guestName) {}

void play() const override {
    cout << "Now playing Podcast: "
         << getTitle()
         << endl;

    cout << " Episode #"
         << episodeNumber
         << ", featuring"
         << endl
         << " "
         << guest
         << "."
         << endl;
}
};