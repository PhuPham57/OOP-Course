#include <iostream>
using namespace std;

struct ScoreInfo {
    double sum;
    double average;
    int count;
    double maxScore;
    double minScore;
};

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

ScoreInfo analyzeScores(const double scores[], int size) {
    ScoreInfo result;
    result.sum = 0;
    result.count = size;
    
    if (result.count == 0) {
        result.average = 0;
        result.maxScore = 0;
        result.minScore = 0;
        return result;
    }
    
    result.minScore = scores[0];
    result.maxScore = scores[0];
    
    for (int i = 0; i < size; ++i) {
        double s = scores[i];
        result.sum += s;
        if (s > result.maxScore) result.maxScore = s;
        if (s < result.minScore) result.minScore = s;
    }
    
    result.average = result.sum / result.count;
    return result;
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

    double scores[] = {8.5, 7.0, 9.5, 6.0, 8.0};
    int size = sizeof(scores) / sizeof(scores[0]);
    
    ScoreInfo info = analyzeScores(scores, size);
    
    cout << "Total: " << info.sum << endl;
    cout << "Average: " << info.average << endl;
    cout << "Max score: " << info.maxScore << endl;
    cout << "Min score: " << info.minScore << endl;

    return 0;
}