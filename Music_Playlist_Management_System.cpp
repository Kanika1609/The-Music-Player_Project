#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class MusicPlaylist {
private:
    queue<string> playlist;
    stack<string> history;
    string current_song;

public:
    void addMusic() {
        cout << "Enter Music Name: ";
        string song;
        cin >> ws; // Eat up any leading whitespace characters
        getline(cin, song);
        playlist.push(song);
        cout << "Music added: " << song << endl;
    }

    void removeMusic() {
        if (playlist.empty()) {
            cout << "No Music is there to delete!" << endl;
            return;
        }

        cout << "Enter Music Name to delete: ";
        string song;
        cin >> ws;
        getline(cin, song);

        queue<string> temp;
        bool found = false;
        while (!playlist.empty()) {
            if (playlist.front() == song) {
                playlist.pop();
                found = true;
                cout << "Music deleted: " << song << endl;
                break;
            } else {
                temp.push(playlist.front());
                playlist.pop();
            }
        }

        while (!playlist.empty()) {
            temp.push(playlist.front());
            playlist.pop();
        }

        playlist = temp;

        if (!found) {
            cout << "No Music file found with the name: " << song << endl;
        }
    }

    void showPlaylist() {
        if (playlist.empty()) {
            cout << "Playlist is Empty!" << endl;
            return;
        }

        cout << "Displaying Playlist: " << endl;
        queue<string> temp = playlist;
        int i = 1;
        while (!temp.empty()) {
            cout << "Song " << i << ": " << temp.front() << endl;
            temp.pop();
            i++;
        }
    }

    void playNext() {
        if (playlist.empty()) {
            cout << "No songs in Playlist!" << endl;
            return;
        }

        if (!current_song.empty()) {
            history.push(current_song);
        }

        current_song = playlist.front();
        playlist.pop();
        cout << "Playing Next Song: " << current_song << endl;
    }

    void playPrevious() {
        if (history.empty()) {
            cout << "No previous song in history!" << endl;
            return;
        }

        playlist.push(current_song);
        current_song = history.top();
        history.pop();
        cout << "Playing Previous Song: " << current_song << endl;
    }

    void playFirst() {
        if (playlist.empty()) {
            cout << "Playlist is Empty!" << endl;
            return;
        }

        if (!current_song.empty()) {
            history.push(current_song);
        }

        current_song = playlist.front();
        cout << "Playing First Song: " << current_song << endl;
    }

    void playLast() {
        if (playlist.empty()) {
            cout << "Playlist is Empty!" << endl;
            return;
        }

        if (!current_song.empty()) {
            history.push(current_song);
        }

        queue<string> temp = playlist;
        while (temp.size() > 1) {
            temp.pop();
        }
        current_song = temp.front();
        cout << "Playing Last Song: " << current_song << endl;
    }

    void playSpecific() {
        if (playlist.empty()) {
            cout << "No music is there to be searched!" << endl;
            return;
        }

        cout << "Enter Music Name to play: ";
        string song;
        cin >> ws;
        getline(cin, song);

        queue<string> temp = playlist;
        bool found = false;
        while (!temp.empty()) {
            if (temp.front() == song) {
                if (!current_song.empty()) {
                    history.push(current_song);
                }
                current_song = temp.front();
                cout << "Music Found! Playing Music: " << current_song << endl;
                found = true;
                break;
            }
            temp.pop();
        }

        if (!found) {
            cout << "No Music file found with the name: " << song << endl;
        }
    }
};

int main() {
    MusicPlaylist mp;
    int choice;

    while (true) {
        cout << "\n-----Song Playlist Application-----\n";
        cout << "1. Add Music\n";
        cout << "2. Remove Music\n";
        cout << "3. Show Playlist\n";
        cout << "4. Play next file\n";
        cout << "5. Play previous file\n";
        cout << "6. Play first file\n";
        cout << "7. Play last file\n";
        cout << "8. Play specific file\n";
        cout << "9. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                mp.addMusic();
                break;
            case 2:
                mp.removeMusic();
                break;
            case 3:
                mp.showPlaylist();
                break;
            case 4:
                mp.playNext();
                break;
            case 5:
                mp.playPrevious();
                break;
            case 6:
                mp.playFirst();
                break;
            case 7:
                mp.playLast();
                break;
            case 8:
                mp.playSpecific();
                break;
            case 9:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
