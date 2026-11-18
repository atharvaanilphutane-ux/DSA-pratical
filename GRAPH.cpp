
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    string str;
    deque<char> dq;

    cout << "Enter a string: ";
    cin >> str;

    // Insert characters into deque
    for (char ch : str)
    {
        dq.push_back(ch);
    }

    bool palindrome = true;

    // Compare front and rear characters
    while (dq.size() > 1)
    {
        if (dq.front() != dq.back())
        {
            palindrome = false;
            break;
        }

        dq.pop_front();
        dq.pop_back();
    }

    if (palindrome)
        cout << str << " is a Palindrome.";
    else
        cout << str << " is not a Palindrome.";

    return 0;
}
