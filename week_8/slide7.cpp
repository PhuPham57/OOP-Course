#include <iostream>
#include <string>
using namespace std;

int main() {
    string fullName, studentId, email, hometown;

    // Đọc thông tin từ người dùng
    getline(cin, fullName);
    getline(cin, studentId);
    getline(cin, email);
    getline(cin, hometown);

    // Hiển thị hồ sơ sinh viên
    cout << "===== STUDENT PROFILE =====\n";
    cout << "Full name  : " << fullName << endl;
    cout << "Student ID : " << studentId << endl;
    cout << "Email      : " << email << endl;
    cout << "Hometown   : " << hometown << endl;
    cout << "===========================\n";

    string name;
    getline(cin, name);

    // Kết hợp chuỗi bằng toán tử +
    string message = "Hello, " + name + "!\nWelcome to C++ programming!";
    cout << message << endl;

    return 0;
}