#include <iostream>
using namespace std;

void giaiPhuongTrinhBac1(double a, double b) {
    if (a == 0) {
        if (b == 0) {
            cout << "Phuong trinh co vo so nghiem" << endl;
        } else {
            cout << "Phuong trinh vo nghiem" << endl;
        }
    } else {
        double x = -b / a;
        cout << "Phuong trinh co nghiem x = " << x << endl;
    }
}

int main() {
    double a, b;
    cout << "Nhap a va b: ";
    cin >> a >> b;
    
    giaiPhuongTrinhBac1(a, b);
    return 0;
}