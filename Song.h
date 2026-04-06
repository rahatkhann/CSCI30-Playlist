#pragma once

#include <iostream>
#include <string>
#include "AudioStream.h"
#include <memory>
// #include "Album.h"

class Album;

using namespace std;

class Song : public AudioStream {
private:
    weak_ptr<Album> albumPtr;

public:
    Song(string tit, string art, int dur)
        : AudioStream(tit, art, dur){}
    ~Song() {
        cout << " Destroying Song " << getTitle() << endl;
    }

void setAlbum(shared_ptr<Album> album) {
    albumPtr = album;
}

void play() const override; 

};