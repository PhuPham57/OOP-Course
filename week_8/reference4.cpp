#include <iostream>
using namespace std;

void changeValue(int x) {
    x = 100;    // pass by reference
}

void changeRef(int& x) {
    x = 200;    // pass by value
}

int main() {
    int a = 5;
    changeValue(a);
    cout << "After changeValue: " << a << endl;
    changeRef(a);
    cout << "After changeRef: " << a << endl;
    return 0;
}