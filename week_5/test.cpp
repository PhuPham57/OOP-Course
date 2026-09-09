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

    for (int i = 0; i < N; i++) {
        double score;
        do {
            cout << "Nhap diem cho hoc sinh " << i + 1 << ": ";
            cin >> score;
            if (score < 0 || score > 10) {
                cout << "Diem khong hop le! Vui long nhap trong khoảng tu 0 den 10: ";
            }
        } while (score < 0 || score > 10);
        scores[i] = score;
    }

    return 0;
}