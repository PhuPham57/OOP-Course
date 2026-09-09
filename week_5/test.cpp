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

    cout << "\n===== DANH SACH DIEM =====\n";
    for (int i = 0; i < N; i++) {
        cout << "Hoc sinh " << i + 1 << ": " << scores[i] << "\n";
    }

    cout << "\n===== KET QUA =====\n";
    for (int i = 0; i < N; i++) {
        cout << "Hoc sinh " << i + 1 << ": " << scores[i] << " -> ";
        if (scores[i] >= 5.0) {
            cout << "DAU\n";
        } else {
            cout << "ROT\n";
        }
    }

    return 0;
}