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

    string message = "Hello, " + name + "!\nWelcome to C++ programming!";
    cout << message << endl;

    cout << "Initials: ";
    if (!fullName.empty()) {
        // In ký tự đầu tiên của họ
        cout << (char)toupper(fullName[0]);
        // Tìm các ký tự đứng sau khoảng trắng
        for (size_t i = 0; i < fullName.length() - 1; i++) {
            if (fullName[i] == ' ' && fullName[i + 1] != ' ') {
                cout << "." << (char)toupper(fullName[i + 1]);
            }
        }
    }
    cout << endl;

    string sentence, word;
    getline(cin, sentence);
    getline(cin, word);

    size_t pos = sentence.find(word);
    if (pos != string::npos) {
        cout << "The word \"" << word << "\" is found at position " << pos << "." << endl;
    } else {
        cout << "The word \"" << word << "\" is not found." << endl;
    }

    int birthYear;
    cin >> birthYear;

    string username = "";
    for (char c : fullName) {
        if (c != ' ') {
            username += tolower(c);
        }
    }
    
    // Nốstring fullName;
        int birthYear;
        
        getline(cin, fullName);
        cin >> birthYear;
    
        // Xử lý họ tên: bỏ khoảng trắng và đổi thành chữ thường
        string username = "";
        for (char c : fullName) {
            if (c != ' ') {
                username += tolower(c);
            }
        }
        
        // Nối thêm năm sinh bằng to_string()
        username += to_string(birthYear);
    
        cout << "Username: " << username << endl;i thêm năm sinh bằng to_string()
    username += to_string(birthYear);

    cout << "Username: " << username << endl;

    return 0;
}