#pragma once

#include <iostream>
#include "AudioStream.h"
#include <stdexcept>

using namespace std;

class Playlist {
private:
    AudioStream* m_list[100];
    int m_count;

public:
    Playlist() : m_count(0) {
        for (int i = 0; i < 100; i++) {
            m_list[i] = nullptr;
        }
    }

    ~Playlist() {
        for (int i = 0; i < m_count; i++) {
            delete m_list[i];
        }
    }

    void addStream(AudioStream* s) {
        if (m_count < 100) {
            m_list[m_count] = s;
            m_count++;
        }
    }

    void showPlaylist() const {
        cout << "--- Listing Your Playlist ---" << endl;
        for (int i = 0; i < m_count; i++) {
            cout << i << ":";
            m_list[i]->print();
        }
    }

    void playAll() const {
        cout << "--- Playing Your Playlist ---" << endl;
        for (int i = 0; i < m_count; i++) {
            m_list[i]->play();
        }
    }

    void swapSongs(int index1, int index2) {
        if (m_count < 2) {
            throw logic_error("LOGIC ERROR: Playlist must contain atleast 2 items.");
        }
        if (index1 < 0 || index1 >= m_count || index2 < 0 || index2 >= m_count) {
            throw range_error("RANGE ERROR: Invalid swap values " + to_string(index1) + ", " + to_string(index2));
        }

        AudioStream* temp = m_list[index1];
        m_list[index1] = m_list[index2];
        m_list[index2] = temp;
    }
};
