#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Date {
public:
    int year, month, day;

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
};

class Student {
private:
    string name;
    string address;
    Date birthdate;
    string cccd;

public:
    // ===== Constructors =====

    Student() {
        name = "";
        address = "";
        birthdate = Date();
        cccd = "";
    }

    Student(string n) {
        name = n;
        address = "";
        birthdate = Date();
        cccd = "";
    }

    Student(string n, string addr) {
        name = n;
        address = addr;
        birthdate = Date();
        cccd = "";
    }

    Student(string n, string addr, Date d) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = "";
    }

    Student(string n, string addr, Date d, string id) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = id;
    }

    // ===== Set Student Info =====

    void setStudentInfo(string n) {
        name = n;
    }

    void setStudentInfo(string n, string addr) {
        name = n;
        address = addr;
    }

    void setStudentInfo(string n, string addr, Date d) {
        name = n;
        address = addr;
        birthdate = d;
    }

    void setStudentInfo(string n, string addr, Date d, string id) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = id;
    }

    // ===== Get Student Info =====

    void getStudentInfo() {
        cout << "====================" << endl;
        cout << "=== Student Info ===" << endl;
        cout << "====================" << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birthdate: "
             << birthdate.year << "/"
             << birthdate.month << "/"
             << birthdate.day << endl;
        cout << "CCCD: " << cccd << endl;
    }

    // ===== Search by CCCD =====

    static Student findStudentByCCCD(Student students[], int n, string id) {
        for (int i = 0; i < n; i++) {
            if (students[i].cccd == id) {
                return students[i];
            }
        }

        return Student();
    }

    // ===== Search by Name =====
    // Kết quả trả qua mảng result, số phần tử qua m

    static void findStudentsByName(Student students[], int n, string key, Student result[], int &m) {
        m = 0;

        for (int i = 0; i < n; i++) {
            if (students[i].name.find(key) != string::npos) {
                result[m] = students[i];
                m++;
            }
        }
    }

    // ===== Search by Age =====

    static void findStudentsByAge(Student students[], int n, int age, Student result[], int &m) {
        m = 0;

        int currentYear = 2026;

        for (int i = 0; i < n; i++) {
            if (students[i].birthdate.year != 0) {
                int studentAge = currentYear - students[i].birthdate.year;

                if (studentAge == age) {
                    result[m] = students[i];
                    m++;
                }
            }
        }
    }

    // ===== Search by Birth Year =====

    static void getStudentsByYear(Student students[], int n, int year, Student result[], int &m) {
        m = 0;

        for (int i = 0; i < n; i++) {
            if (students[i].birthdate.year == year) {
                result[m] = students[i];
                m++;
            }
        }
    }

    // ===== Search by Province =====

    static void getStudentsByProvince(Student students[], int n, string province, Student result[], int &m) {
        m = 0;

        for (int i = 0; i < n; i++) {
            if (students[i].address.find(province) != string::npos) {
                result[m] = students[i];
                m++;
            }
        }
    }

    // ===== Statistics by Birth Year =====

    static void statisticByYear(Student students[], int n, int years[], int soNam, int counts[]) {
        for (int i = 0; i < soNam; i++) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (students[j].birthdate.year == years[i]) {
                    count++;
                }
            }

            counts[i] = count;
        }
    }

    // ===== Statistics by Province =====

    static void statisticByProvince(Student students[], int n, string provinces[], int soTinh, int counts[]) {
        for (int i = 0; i < soTinh; i++) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (students[j].address.find(provinces[i]) != string::npos) {
                    count++;
                }
            }

            counts[i] = count;
        }
    }

    // ===== Print List =====

    static void printList(Student students[], int n) {
        for (int i = 0; i < n; i++) {
            students[i].getStudentInfo();
            cout << endl;
        }
    }
};

int main() {

    // ===== Create Students =====

    Student student1;

    Student student2("Huong");

    Student student3("An", "Vo Van Ngan");

    Date d(1989, 9, 12);
    Student student4("DoMIXI", "Ha Noi", d, "0007777056");

    Date d2(1996, 10, 26);
    Student student5("DungSenpai", "Da Nang", d2, "999993884");

    Date d3(2000, 5, 15);
    Student student6("Nguyen Van A",
                     "Thu Duc, Ho Chi Minh",
                     d3,
                     "123456789");

    Date d4(2001, 8, 20);
    Student student7("Tran Van B",
                     "Bien Hoa, Dong Nai",
                     d4,
                     "987654321");

    Date d5(2000, 11, 10);
    Student student8("Le Van C",
                     "Thu Dau Mot, Binh Duong",
                     d5,
                     "111222333");

    // ===== Put Students into Array =====

    Student students[MAX];
    int n = 0;

    students[n++] = student1;
    students[n++] = student2;
    students[n++] = student3;
    students[n++] = student4;
    students[n++] = student5;
    students[n++] = student6;
    students[n++] = student7;
    students[n++] = student8;

    // ===== Display Students =====

    cout << "========== ALL STUDENTS ==========" << endl;
    Student::printList(students, n);

    // ===== Search by CCCD =====

    cout << endl;
    cout << "========== SEARCH BY CCCD ==========" << endl;

    Student result = Student::findStudentByCCCD(
        students,
        n,
        "123456789"
    );

    result.getStudentInfo();

    // ===== Search by Name =====

    cout << endl;
    cout << "========== SEARCH BY NAME ==========" << endl;

    Student nameResult[MAX];
    int soKetQua = 0;

    Student::findStudentsByName(students, n, "Van", nameResult, soKetQua);

    Student::printList(nameResult, soKetQua);

    // ===== Statistics by Birth Year =====

    cout << endl;
    cout << "===== Statistics by Birth Year =====" << endl;

    int years[MAX];
    int soNam = 0;
    years[soNam++] = 2000;
    years[soNam++] = 2001;

    int yearCounts[MAX];
    Student::statisticByYear(students, n, years, soNam, yearCounts);

    for (int i = 0; i < soNam; i++) {
        cout << "Year " << years[i] << ": " << yearCounts[i] << " student(s)" << endl;

        Student yearList[MAX];
        int soNguoiTheoNam = 0;
        Student::getStudentsByYear(students, n, years[i], yearList, soNguoiTheoNam);
        Student::printList(yearList, soNguoiTheoNam);
    }

    // ===== Statistics by Province =====

    cout << endl;
    cout << "===== Statistics by Province =====" << endl;

    string provinces[MAX];
    int soTinh = 0;
    provinces[soTinh++] = "Ho Chi Minh";
    provinces[soTinh++] = "Dong Nai";
    provinces[soTinh++] = "Binh Duong";
    provinces[soTinh++] = "Ha Noi";
    provinces[soTinh++] = "Da Nang";

    int provinceCounts[MAX];
    Student::statisticByProvince(students, n, provinces, soTinh, provinceCounts);

    for (int i = 0; i < soTinh; i++) {
        cout << provinces[i] << ": " << provinceCounts[i] << " student(s)" << endl;

        Student provinceList[MAX];
        int soNguoiTheoTinh = 0;
        Student::getStudentsByProvince(students, n, provinces[i], provinceList, soNguoiTheoTinh);
        Student::printList(provinceList, soNguoiTheoTinh);
    }

    return 0;
}