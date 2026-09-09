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

    int passedCount = 0;
    int failedCount = 0;

    for (int i = 0; i < N; i++) {
        if (scores[i] >= 5.0) {
            passedCount++;
        } else {
            failedCount++;
        }
    }

    double passRate = ((double)passedCount / N) * 100;

    cout << "\n===== THONG KE =====\n";
    cout << "So hoc sinh Dau : " << passedCount << "\n";
    cout << "So hoc sinh Rot : " << failedCount << "\n";
    cout << "Ty le dau      : " << passRate << "%\n";

    double maxScore = scores[0];
    double minScore = scores[0];

    for (int i = 1; i < N; i++) {
        if (scores[i] > maxScore) maxScore = scores[i];
        if (scores[i] < minScore) minScore = scores[i];
    }

    cout << "\nDiem cao nhat : " << maxScore << "\n";
    cout << "Diem thap nhat: " << minScore << "\n";

    cout << "\n===== XEP LOAI =====\n";
    for (int i = 0; i < N; i++) {
        cout << "Hoc sinh " << i + 1 << ": " << scores[i] << " -> ";
        if (scores[i] >= 9.0) {
            cout << "Xuat sac\n";
        } else if (scores[i] >= 8.0) {
            cout << "Gioi\n";
        } else if (scores[i] >= 6.5) {
            cout << "Kha\n";
        } else if (scores[i] >= 5.0) {
            cout << "Trung binh\n";
        } else {
            cout << "Yeu\n";
        }
    }
    
    
    
    return 0;
}