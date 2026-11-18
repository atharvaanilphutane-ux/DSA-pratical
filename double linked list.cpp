
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int pnr, age, train, seat;
    string name;
    Node *prev, *next;
};

Node *head = NULL, *tail = NULL;

void addReservation() {
    Node* n = new Node;

    cout << "PNR: ";
    cin >> n->pnr;

    cout << "Name: ";
    cin >> n->name;

    cout << "Age: ";
    cin >> n->age;

    cout << "Train No: ";
    cin >> n->train;

    cout << "Seat No: ";
    cin >> n->seat;

    n->prev = n->next = NULL;

    if (head == NULL) {
        head = tail = n;
    }
    else {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
}

void displayForward() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->pnr << " "
             << temp->name << " "
             << temp->age << " "
             << temp->train << " "
             << temp->seat << endl;

        temp = temp->next;
    }
}

void displayBackward() {
    Node* temp = tail;

    while (temp != NULL) {
        cout << temp->pnr << " "
             << temp->name << endl;

        temp = temp->prev;
    }
}

int main() {
    addReservation();
    addReservation();

    cout << "\nForward:\n";
    displayForward();

    cout << "\nBackward:\n";
    displayBackward();

    return 0;
}
