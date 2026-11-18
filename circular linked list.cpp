
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string song, artist;
    float duration;
    Node* next;
};

Node* head = NULL;

void addSong() {
    Node* n = new Node;

    cout << "Song ID: ";
    cin >> n->id;

    cout << "Song Name: ";
    cin >> n->song;

    cout << "Artist: ";
    cin >> n->artist;

    cout << "Duration: ";
    cin >> n->duration;

    if (head == NULL) {
        head = n;
        n->next = head;
    }
    else {
        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
    }
}

void displayPlaylist() {
    if (head == NULL)
        return;

    Node* temp = head;

    do {
        cout << temp->id << " "
             << temp->song << " "
             << temp->artist << " "
             << temp->duration << endl;

        temp = temp->next;

    } while (temp != head);
}

int main() {
    addSong();
    addSong();

    cout << "\nPlaylist:\n";
    displayPlaylist();

    return 0;
}
