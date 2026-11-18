
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name, phone;
    int duration;
    Node* next;
};

Node* head = NULL;

void addCall() {
    Node* n = new Node;

    cout << "Name: ";
    cin >> n->name;

    cout << "Phone: ";
    cin >> n->phone;

    cout << "Duration: ";
    cin >> n->duration;

    n->next = NULL;

    if (head == NULL)
        head = n;
    else {
        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = n;
    }
}

void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->name << " "
             << temp->phone << " "
             << temp->duration << endl;

        temp = temp->next;
    }
}

int main() {
    addCall();
    addCall();

    cout << "\nCall Log:\n";
    display();

    return 0;
}
