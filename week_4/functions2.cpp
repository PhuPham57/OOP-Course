#include <iostream>
#include <string>
using namespace std; 
int n = 0; 
string names[20];
string ids[20];
string phones[20]; 

void inputStudent()
{
    cout << "Input the number of students: ";
    cin >> n; 

    if (n > 0)
    {
        for (int i = 0; i<n;i++)
        {
            cout << "Enter information of student " << i + 1 << "\n";
            cout << "Name: ";
            getline(cin,names[i]);
            cout << "ID: ";
            getline(cin,ids[i]);
            cout << "Phone: ";
            getline(cin,phones[i]);
        }
        cout << "Number of inputted students: " << n;

    }

    else
    {
        cout << "The number of students must be more than 0";
    }
}

void outputStudents()
{
    for (int i = 0; i<n;i++)
    {
        cout << "Student: " << i + 1 << "\n";
        cout << "Name: " << names[i] << "\n";
        cout << "ID: " << ids[i] << "\n";
        cout << "Phone: " << phones[i] << "\n";
    }
}

int main()
{
    inputStudent();
    cout << n;
    outputStudents();
    return 0;
}