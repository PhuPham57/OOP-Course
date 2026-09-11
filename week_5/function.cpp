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

void showScore(string name, double score) {
    cout << "Student: " << name << endl;
    cout << "Score  : " << score << endl;
    cout << "Keep going!" << endl;
}

int maxValue(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {

    showMenu();
    
    cout << endl;
    cout << "Let's get started!" << endl;

    int studentID;
    cout << "Enter your student ID: ";
    cin >> studentID;
    
    showStudentID(studentID);

    string studentName;
    double studentScore;
    
    cout << "Enter student name: ";
    getline(cin, studentName);
    
    cout << "Enter score: ";
    cin >> studentScore;
    
    showScore(studentName, studentScore);

    int num1, num2;
    
    cout << "Enter first integer: ";
    cin >> num1;
    
    cout << "Enter second integer: ";
    cin >> num2;
    
    int largest = maxValue(num1, num2);
    
    cout << "The larger value is: " << largest << endl;

    return 0;
}