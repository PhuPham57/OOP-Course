#include <iostream>
using namespace std;

// Function definition
void showMenu() {
    cout << "===== MENU =====" << endl;
    cout << "1. Display students" << endl;
    cout << "2. Show statistics" << endl;
    cout << "3. Exit" << endl;
}

int main() {
    // Call the function
    showMenu();
    
    cout << endl;
    cout << "Let's get started!" << endl;
    return 0;
}