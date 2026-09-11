#include <iostream>
using namespace std;

// Function definition
void showMenu() {
    cout << "===== MENU =====" << endl;
    cout << "1. Display students" << endl;
    cout << "2. Show statistics" << endl;
    cout << "3. Exit" << endl;
}

void showStudentID(int studentID) {
    cout << "Student ID: " << studentID << endl;
}

int main() {
    // Call the function
    showMenu();
    
    cout << endl;
    cout << "Let's get started!" << endl;

    int studentID;
    cout << "Enter your student ID: ";
    cin >> studentID;
    
    // Call the function
    showStudentID(studentID);
    
    return 0;
}