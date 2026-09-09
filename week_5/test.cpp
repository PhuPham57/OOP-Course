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
    
    cout << "\n       BAI TAP (1 -> 10)";
    cout << "[Bai 1]:\n";
    int excellentCount = 0;
    for (int i = 0; i < N; i++) {
        if (scores[i] >= 9.0) excellentCount++;
    }
    cout << "\nSo hoc sinh Xuat sac (>= 9.0): " << excellentCount << "\n";

    cout << "[Bai 2]:\n";
    double a, b;
    cout << "\nNhap diem toi thieu (a): ";
    cin >> a;
    cout << "Nhap diem toi da (b): ";
    cin >> b;
    int rangeCount = 0;
    for (int i = 0; i < N; i++) {
        if (scores[i] >= a && scores[i] <= b) rangeCount++;
    }
    cout << "-> So hoc sinh trong khoang [" << a << ", " << b << "]: " << rangeCount << "\n";
    
    double totalSum = 0;
    for (int i = 0; i < N; i++) totalSum += scores[i];
    double avgScore = totalSum / N;

    cout << "\n[Bai 3] Diem trung binh cua lop: " << avgScore << "\n";
    cout << "Cac hoc sinh tren trung binh:\n";
    for (int i = 0; i < N; i++) {
        if (scores[i] > avgScore) {
            cout << "  + Hoc sinh " << i + 1 << ": " << scores[i] << "\n";
        }
    }

    double highest = -1.0;
    double secondHighest = -1.0;
    for (int i = 0; i < N; i++) {
        if (scores[i] > highest) {
            secondHighest = highest;
            highest = scores[i];
        } else if (scores[i] > secondHighest && scores[i] < highest) {
            secondHighest = scores[i];
        }
    }
    cout << "\n[Bai 4] Diem cao nhat: " << highest << "\n";
    if (secondHighest != -1.0) {
        cout << "[Bai 4] Diem cao thu hai: " << secondHighest << "\n";
    } else {
        cout << "[Bai 4] Khong co diem cao thu hai (tat ca diem bang nhau).\n";
    }

    double searchVal;
    cout << "\n[Bai 5] Nhap diem can tim: ";
    cin >> searchVal;
    bool foundAny = false;
    cout << "Tim thay tai:\n";
    for (int i = 0; i < N; i++) {
        if (scores[i] == searchVal) {
            cout << "  + Hoc sinh " << i + 1 << "\n";
            foundAny = true;
        }
    }
    if (!foundAny) cout << "  (Khong tim thay hoc sinh nao co diem nay)\n";

    return 0;
}