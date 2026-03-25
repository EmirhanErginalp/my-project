#include <iostream>
#include <string>

using namespace std;

struct Song {
    string title;
    string artist;
    int ratings[3];
    Song *next;
    Song *prev;
};

class Playlist {
public:
    Song *head;
    Song *tail;
    Song *current;

    Playlist() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }

    void addSong(string t, string a, int r[]) {
        Song *newSong = new Song;
        newSong->title = t;
        newSong->artist = a;
        for (int i = 0; i < 3; i++) {
            newSong->ratings[i] = r[i];
        }
        newSong->next = nullptr;
        newSong->prev = nullptr;

        if (head == nullptr) {
            head = newSong;
            tail = newSong;
            current = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
    }

    void nextSong() {
        if (current != nullptr && current->next != nullptr) {
            current = current->next;
        }
    }

    void prevSong() {
        if (current != nullptr && current->prev != nullptr) {
            current = current->prev;
        }
    }

    void removeCurrent() {
        if (current == nullptr) return;

        Song *toDelete = current;

        if (toDelete->prev != nullptr) {
            toDelete->prev->next = toDelete->next;
        } else {
            head = toDelete->next;
        }

        if (toDelete->next != nullptr) {
            toDelete->next->prev = toDelete->prev;
            current = toDelete->next;
        } else {
            tail = toDelete->prev;
            current = tail;
        }

        delete toDelete;
    }

    void display() {
        Song *temp = head;
        while (temp != nullptr) {
            if (temp == current) {
                cout << "-> ";
            } else {
                cout << "   ";
            }

            cout << temp->title << " - " << temp->artist << " [Ratings: ";
            for (int i = 0; i < 3; i++) {
                cout << temp->ratings[i] << (i < 2 ? ", " : "");
            }
            cout << "]" << endl;

            temp = temp->next;
        }
        cout << "--------------------------" << endl;
    }
};

int nain(){
Playlist myPlaylist;

int r1[] = {3,2,7};
myPlaylist.addSong("Song 1","Artist 1",r1);
int r2[] = {10,10,10};
myPlaylist.addSong("Song 2","Artist 2",r2);
int r3[] = {7,6,8};
myPlaylist.addSong("Song 3","Artist 3",r3);
int r4[] = {1,1,1};
myPlaylist.addSong("Song 4","Artist 4",r4);

myPlaylist.display();
myPlaylist.nextSong();

cout << "Next Song." << endl;

myPlaylist.display();
myPlaylist.removeCurrent();

cout << "Deleting Song." << endl;

myPlaylist.display();

return 0;

}