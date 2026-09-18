#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello C++";
    cout << s.length() << endl;
    cout << s.size() << endl;

    string s1 = "";
    string s2 = "Hi";
    cout << s1.empty() << endl;
    cout << s2.empty() << endl;
}