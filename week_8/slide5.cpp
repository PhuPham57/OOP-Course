#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "Hello";
    string s2 = "C++";
    cout << s1 << endl;
    cout << s2 << endl;

    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello, " << name << "!" << endl;

    string first = "Hello";
    string second = "World";
    string message = first + " " + second + "!";
    cout << message << endl;

    string s = "Hello C++";
    cout << "Length: " << s.length() << endl;

    string s = "Hello";
    cout << "First character: " << s[0] << endl;
    cout << "Third character: " << s[2] << endl;

    string text = "I love C++!";
    size_t pos = text.find("C++");
    if (pos != string :: npos) {
        cout << "Found at position: " << pos << endl;
    } else {
        cout << "Not found!" << endl;
    }
}
