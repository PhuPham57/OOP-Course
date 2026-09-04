#include <iostream>
#include <string>
using namespace std; 
int n = 0; 
string names[20];
string ids[20];
string phones[20]; 
void inputStudent(){
    std :: cout << "Input the number of students:" << std::endl;
    std :: cin >> n; 
    if (n>0){
        for (int i = 0; i<n;i++){
            cout << "Enter information of student " << i + 1 << "\n";
            cout << "Name: \n";
            getline(cin,names[i]);
            cout << "ID: \n";
            getline(cin,ids[i]);
            cout << "Phone : \n ";
            getline(cin,phones[i]);
        }
        cout << "Number of inputted students: " << n;

    }
    else{
        cout << "The number of students must be more than 0";
    }
}

void outputStudents(){
    for (int i = 0; i<n;i++){
        cout << "Student: " << i + 1 << "\n";
        cout << "Name: \n" << names[i] << "\n";
        cout << "ID: \n" << ids[i] << "\n";
        cout << "Phone: \n" << phones[i] << "\n";
    }
}
int main()
{
    std::cout << "Hello, C++!" << std::endl;
    inputStudent();
    cout << n;
    outputStudents();
    return 0;
}