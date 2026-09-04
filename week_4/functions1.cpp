#include <iostream>
#include <string>
using namespace std; 
int main()
{
    std::cout << "Hello, C++!" << std::endl;
    return 0;
}

void inputStudent(){
    int n = 0; 
    string names[20];
    string ids[20];
    string phones[20]; 
    std :: cout << "Input the number of students:" << std::endl;
    std :: cin >> n; 

    if (n>0){
        for (int i = 0; i<n;i++){
            cout << "Enter information of student " << i + 1;
            cout << "Name:";
            cin >> names[i]; 
            cout << "ID: ";
            cin >> ids[i];
            cout << "Phone : ";
            cin >> phones[i];
        }
        cout << "Number of inputted students: " << n;

    }
    else{
        cout << "The number of students must be more than 0";
    }
    
}
