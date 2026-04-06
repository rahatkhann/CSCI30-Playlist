#pragma once

#include <iostream>
#include <string>
#include "Playlist.h"
#include <memory>

using namespace std;

class Album : public Playlist, public enable_shared_from_this<Album> {
private:
    string albumName;

public:
    Album(string name) : Playlist(), albumName(name) {

    }
    ~Album() {
        cout << "Destroying the Album : " << albumName << endl;
    }
    
    string getAlbumName() {
        return albumName;
    }

    shared_ptr<AudioStream> getTrack(int index) {
        if (index < 0 || index >= m_count) {
            throw logic_error("BAD INDEX: Invalid track index " + to_string(index));
        }
        return m_list[index];
    }

    void addSong(string title, string artist, int duration, shared_ptr<Album> album) {
        cout << "Adding song " << title << " to album: " << albumName << "..." << endl;
        try {
            shared_ptr<Song> newSong = make_shared<Song>(title, artist, duration);
            newSong->setAlbum(shared_from_this());
            addStream(newSong);
        } catch (runtime_error& e){
            cout << "  [Playlist]: Failed to add " << title << " -> " << e.what() << endl;
        }
    }
};