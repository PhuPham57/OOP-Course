#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

public:
    Date() {
        year = 0;
        month = 0;
        day = 0;
    }

    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    void print() {
        cout << year << "/" << month << "/" << day;
    }

    int getYear() {
        return year;
    }

    int getMonth() {
        return month;
    }

    int getDay() {
        return day;
    }
};


class Student {
private:
    string name;
    string address;
    Date birthdate;
    bool hasBirth;
    string cccd;

public:
    // Constructor mac dinh
    Student() {
        name = "";
        address = "";
        hasBirth = false;
        cccd = "";
    }

    // Constructor 1 tham so
    Student(string n) {
        name = n;
        address = "";
        hasBirth = false;
        cccd = "";
    }

    // Constructor Date
    Student(Date d) {
        name = "";
        address = "";
        birthdate = d;
        hasBirth = true;
        cccd = "";
    }

    // Constructor 2 tham so
    Student(string n, string a) {
        name = n;
        address = a;
        hasBirth = false;
        cccd = "";
    }

    // Constructor 3 tham so
    Student(string n, string a, Date d) {
        name = n;
        address = a;
        birthdate = d;
        hasBirth = true;
        cccd = "";
    }

    // Constructor 4 tham so
    Student(string n, string a, Date d, string cc) {
        name = n;
        address = a;
        birthdate = d;
        hasBirth = true;
        cccd = cc;
    }

    void setStudentInfo() {
        cout << "Nhap ten: ";
        getline(cin, name);

        cout << "Nhap dia chi: ";
        getline(cin, address);

        int y, m, d;

        cout << "Nhap ngay sinh (yyyy mm dd): ";
        cin >> y >> m >> d;

        birthdate = Date(y, m, d);
        hasBirth = true;

        cin.ignore();

        cout << "Nhap CCCD: ";
        getline(cin, cccd);
    }

    string getCCCD() {
        return cccd;
    }

    // Tim sinh vien theo CCCD
    static Student getStudentInfo(
        vector<Student> students,
        string key_cccd
    ) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].cccd == key_cccd) {
                return students[i];
            }
        }

        return Student();
    }

    // Tim sinh vien theo ten
    static vector<Student> getStudents(
        vector<Student> students,
        string sub
    ) {
        vector<Student> result;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].name.find(sub) != string::npos) {
                result.push_back(students[i]);
            }
        }

        return result;
    }

    // Tim sinh vien theo tuoi
    static vector<Student> getStudentsByAge(
        vector<Student> students,
        int age
    ) {
        vector<Student> result;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].hasBirth == false) {
                continue;
            }

            int studentAge = 2026 - students[i].birthdate.getYear();

            if (studentAge == age) {
                result.push_back(students[i]);
            }
        }

        return result;
    }

    void print() {
        cout << "Ten: " << name << endl;
        cout << "Dia chi: " << address << endl;

        cout << "Ngay sinh: ";
        if (hasBirth) {
            birthdate.print();
        }
        else {
            cout << "N/A";
        }

        cout << endl;
        cout << "CCCD: " << cccd << endl;
    }
};


int main() {

    vector<Student> students;

    students.push_back(Student());
    students.push_back(Student("Huong"));
    students.push_back(
        Student("", "Vo Van Ngan", Date(2000, 5, 15))
    );

    // Tim sinh vien theo CCCD
    string key = "123456789";

    Student s = Student::getStudentInfo(
        students,
        key
    );

    if (s.getCCCD() != "") {
        cout << "\nThong tin sinh vien tim thay:\n";
        s.print();
    }
    else {
        cout << "\nKhong tim thay sinh vien voi CCCD: "
             << key << endl;
    }

    // Tim sinh vien theo ten
    vector<Student> vec_name =
        Student::getStudents(students, "Hu");

    cout << "\nSinh vien co ten chua 'Hu':\n";

    for (int i = 0; i < vec_name.size(); i++) {
        vec_name[i].print();
        cout << endl;
    }

    // Tim sinh vien theo tuoi
    vector<Student> vec_age =
        Student::getStudentsByAge(students, 26);

    cout << "\nSinh vien do tuoi 26:\n";

    for (int i = 0; i < vec_age.size(); i++) {
        vec_age[i].print();
        cout << endl;
    }

    return 0;
}