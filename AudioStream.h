#pragma once

#include <iostream>
#include <string>

using namespace std;

class AudioStream {
private:
    string title;
    string artist;
    int duration;

public:
    AudioStream(string tit, string art, int dur)
        : title(tit), artist(art), duration(dur) {}

    virtual ~AudioStream() {}

    string getTitle() const { return title; }
    string getArtist() const { return artist; }
    int getDuration() const { return duration; }

    void print() const {
        cout << "The stream \"" << title
             << "\" is " << duration
             << " seconds, performed by "
             << artist << "." << endl;
    }

    virtual void play() const = 0;
};