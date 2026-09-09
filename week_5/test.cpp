#include <iostream>

using namespace std;

int main()
{
    int N;

    do {
        cout << "Nhap so luong hoc sinh: ";
        cin >> N;
        if (N < 2 || N > 20) {
            cout << "So luong khong hop le! Vui long nhap tu 2 den 20.\n";
        }
    } while (N < 2 || N > 20);

    double scores[20];
    
    return 0;
}