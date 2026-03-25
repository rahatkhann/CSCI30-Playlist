#pragma once

#include <iostream>
#include <string>
#include "supportFunctions.h"

using namespace std;

class AudioBuffer {

private:
    void* data;

public:
    AudioBuffer(int duration, string title) {
        data = loadAudioResource(duration, title);
    }

    ~AudioBuffer() {
        if (data != nullptr) {
            freeAudioResource(data);
        }
    }

    void play() const {
        playAudioResource(data);
    }
};

