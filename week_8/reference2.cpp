#include <iostream>
using namespace std;

void swapValues(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 5, b = 10;
    cout << "Before: a = " << a << ", b = " << b << endl;
    swapValues(a, b);
    cout << "After: a = " << a << ", b = " << b << endl;
    return 0;
}