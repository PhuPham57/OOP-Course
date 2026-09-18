#include <iostream>
#include <string>
using namespace std;

int main() {
    string fullName, studentId, email, hometown;

    cout << "Enter full name: ";
    getline(cin, fullName);
    cout << "Enter student ID: ";
    getline(cin, studentId);
    cout << "Enter email: ";
    getline(cin, email);
    cout << "Enter hometown: ";
    getline(cin, hometown);

    cout << "\n===== STUDENT PROFILE =====\n";
    cout << "Full name  : " << fullName << endl;
    cout << "Student ID : " << studentId << endl;
    cout << "Email      : " << email << endl;
    cout << "Hometown   : " << hometown << endl;
    cout << "===========================\n";

    
    return 0;
}