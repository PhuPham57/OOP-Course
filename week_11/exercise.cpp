#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

// Simple date helper
struct Date {
    int year{0}, month{0}, day{0};
    Date() = default;
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    string toString() const {
        ostringstream oss;
        oss << setw(4) << setfill('0') << year << '/'
            << setw(2) << setfill('0') << month << '/'
            << setw(2) << setfill('0') << day;
        return oss.str();
    }
};

class Student {
private:
    string name;
    string address;
    Date birthdate;
    bool hasBirth{false};
    string cccd;

public:
    // Constructors
    Student() : name(""), address(""), hasBirth(false), cccd("") {}
    explicit Student(const string& n)
        : name(n), address(""), hasBirth(false), cccd("") {}
    explicit Student(const Date& d)
        : name(""), address(""), hasBirth(true), birthdate(d), cccd("") {}
    Student(const string& n, const string& a)
        : name(n), address(a), hasBirth(false), cccd("") {}
    Student(const string& n, const string& a, const Date& d)
        : name(n), address(a), hasBirth(true), birthdate(d), cccd("") {}
    Student(const string& n, const string& a,
            const Date& d, const string& cc)
        : name(n), address(a), hasBirth(true),
          birthdate(d), cccd(cc) {}

    void setStudentInfo() {
        cout << "Nhap ten: ";
        getline(cin, name);
        cout << "Nhap dia chi: ";
        getline(cin, address);
        int y,m,d;
        cout << "Ngay sinh (yyyy mm dd): ";
        cin >> y >> m >> d;
        birthdate = Date(y,m,d); hasBirth=true; cin.ignore();
        cout << "CCCD: ";
        getline(cin, cccd);
    }

    // Static search helpers
    static Student getStudentInfo(const vector<Student>& list,
                                  const string& key_cccd) {
        for (const auto &s : list)
            if (s.cccd == key_cccd)
                return s;
        return Student(); // not found -> default empty
    }

    static vector<Student> getStudents(const vector<Student>& list,
                                       const string& sub) {
        vector<Student> res;
        for (const auto &s : list)
            if (s.name.find(sub)!=string::npos)
                res.push_back(s);
        return res;
    }

    static vector<Student> getStudentsByAge(const vector<Student>& list,
                                            int age,
                                            const Date& today=Date(2026,10,7)) {
        vector<Student> res;
        for (const auto &s : list) {
            if (!s.hasBirth) continue;
            int diff = today.year - s.birthdate.year;
            if (diff == age)
                res.push_back(s);
        }
        return res;
    }

    void print() const {
        cout << "Ten: "          << name
             << ", Dia chi: "     << address
             << ", Ngay sinh: "   << (hasBirth? birthdate.toString(): "N/A")
             << ", CCCD: "         << cccd << '\n';
    }
};

int main() {
    vector<Student> students = {
        Student(),
        Student("Huong"),
        Student("", "Vo Van Ngan", Date(2000,5,15))
    };

    string key="123456789";
    Student s = Student::getStudentInfo(students,key);
    if (!s.cccd.empty()) {
        cout << "\nThong tin sinh vien tim thay:\n";
        s.print();
    } else {
        cout << "\nKhong tim thay sinh vien voi CCCD: " << key << '\n';
    }

    auto vec_name = Student::getStudents(students,"Hu");
    cout << "\nSinh vien co ten chua 'Hu':\n";
    for (auto &st : vec_name) st.print();

    auto vec_age = Student::getStudentsByAge(students,26);
    cout << "\nSinh vien do tuoi 26:\n";
    for (auto &st : vec_age) st.print();
}
