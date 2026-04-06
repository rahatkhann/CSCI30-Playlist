#pragma once

#include <iostream>
#include <string>
#include "supportFunctions.h"
#include "AudioBuffer.h"

using namespace std;

class AudioStream {
private:
    string title;
    string artist;
    int duration;
    AudioBuffer audioBuffer;

public:
    AudioStream(string tit, string art, int dur) : title(tit), artist(art), duration(dur), audioBuffer(dur, tit){
    
    }

    virtual ~AudioStream() {
        cout << "Destroying the AudioStream :" << title << endl;
    }

    string getTitle() const { return title; }
    string getArtist() const { return artist; }
    int getDuration() const { return duration; }

    void playBuffer() const {
        audioBuffer.play();
    }

    void print() const {
        cout << "The stream \"" << title
             << "\" is " << duration
             << " seconds, performed by "
             << artist << "." << endl;
    }

    virtual void play() const = 0;
};