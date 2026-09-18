#include <iostream>
using namespace std;

int main() {
    int x = 3;
    int& y = x;
    x = 7;
    y = 2;
    cout << x << "" << y << endl;
    return 0;
}