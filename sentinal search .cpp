#include <iostream>
#include <string>
using namespace std;
struct Friend {
 string name;
 string mobile;
};
int main() {
 Friend phonebook[100];
 int n;
 cout << "Enter number of friends: ";
 cin >> n;
 // Input friends
 for (int i = 0; i < n; i++) {
 cout << "\nEnter name: ";
 cin >> phonebook[i].name;
 cout << "Enter mobile number: ";
 cin >> phonebook[i].mobile;
 }
 // Sort friends by name
 for (int i = 0; i < n - 1; i++) {
 for (int j = 0; j < n - i - 1; j++) {
 if (phonebook[j].name > phonebook[j + 1].name) {
 swap(phonebook[j], phonebook[j + 1]);
 }
 }
 }
 // Display sorted phonebook
 cout << "\n--- Phone Book ---\n";
 for (int i = 0; i < n; i++) {
 cout << phonebook[i].name << " : "
 << phonebook[i].mobile << endl;
 }
 // Sentinel Search
 string searchName;
 cout << "\nEnter friend name to search: ";
 cin >> searchName;
 Friend last = phonebook[n];
 phonebook[n].name = searchName;
 int i = 0;
 while (phonebook[i].name != searchName) {
 i++;
 }
 // Check whether friend was actually present
 if (i < n) {
 cout << "\nFriend found!\n";
 cout << "Name: " << phonebook[i].name << endl;
 cout << "Mobile: " << phonebook[i].mobile << endl;
 phonebook[n] = last;
 }
 else {
 phonebook[n] = last;
 string mobile;
 cout << "\nFriend not found.\n";
 cout << "Enter mobile number: ";
 cin >> mobile;
 // Find correct position for insertion
 int pos = 0;
 while (pos < n && phonebook[pos].name < searchName) {
 pos++;
 }
 // Shift elements to the right
 for (int j = n; j > pos; j--) {
 phonebook[j] = phonebook[j - 1];
 }
 // Insert new friend
 phonebook[pos].name = searchName;
 phonebook[pos].mobile = mobile;
 n++;
 cout << "\nFriend inserted successfully!\n";
 }
 // Display updated phonebook
 cout << "\n--- Updated Phone Book ---\n";
 for (int i = 0; i < n; i++) {
 cout << phonebook[i].name << " : "
 << phonebook[i].mobile << endl;
 }
 return 0;
}