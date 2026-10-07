#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Simple date helper
struct Date {
    int year{0}, month{0}, day{0};
    Date() = default;
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    string toString() const { char buf[11]; sprintf(buf,"%04d/%02d/%02d",year,month,day); return string(buf); }
};

class Student {
private:
    string name;
    string address;
    bool hasBirth{false};
    Date birthdate;
    string cccd;               // căn cước công dân

public:
    // Constructors (1‑4 tham số)
    Student() : name(""), address(""), hasBirth(false), cccd("") {}
    explicit Student(const string& n) : name(n), address(""), hasBirth(false), cccd("") {}
    explicit Student(const Date& d)  : name(""), address(""), hasBirth(true), birthdate(d), cccd("") {}
    Student(const string& n, const string& a) : name(n), address(a), hasBirth(false), cccd("") {}
    Student(const string& n, const string& a, const Date& d)
        : name(n), address(a), hasBirth(true), birthdate(d), cccd("") {}
    Student(const string& n, const string& a, const Date& d,
            const string& cc) : name(n), address(a), hasBirth(true),
                               birthdate(d), cccd(cc) {}

    void setStudentInfo() {
        cout << "Nhap ten: "; getline(cin, name);
        cout << "Nhap dia chi: "; getline(cin, address);
        int y,m,d; cout << "Ngay sinh (yyyy mm dd): ";
        cin >> y >> m >> d;
        birthdate = Date(y,m,d); hasBirth=true; cin.ignore();
        cout << "CCCD: "; getline(cin, cccd);
    }

    static int getStudentInfo(const vector<Student>& list,
                               const string& key_cccd) {
        for (size_t i=0;i<list.size();++i)
            if (list[i].cccd==key_cccd) return static_cast<int>(i);
        return -1;
    }
    static vector<int> getStudents(const vector<Student>& list,
                                   const string& sub) {
        vector<int> res; 
        for (size_t i=0;i<list.size();++i)
            if (list[i].name.find(sub)!=string::npos) res.push_back(i);
        return res;
    }
    static vector<int> getStudentsByAge(const vector<Student>& list,
                                        int age,
                                        const Date& today=Date(2026,10,7)) {
        vector<int> res; 
        for (size_t i=0;i<list.size();++i)
            if (list[i].hasBirth && today.year-list[i].birthdate.year==age) res.push_back(i);
        return res;
    }

    void print() const {
        cout << "Ten: "          << name
             << ", Dia chi: "     << address
             << ", Ngay sinh: "   << (hasBirth? birthdate.toString(): "N/A")
             << ", CCCD: "        << cccd << '\n';
    }
};

int main() {
    vector<Student> students = {
        Student(),
        Student("Huong"),
        Student("", "Vo Van Ngan", Date(2000,5,15))
    };

    string key="123456789";
    int idx=Student::getStudentInfo(students,key);
    if(idx>=0){ cout<<"\nThong tin sinh vien tim thay:\n"; students[idx].print();}
    else{ cout<<"\nKhong tim thay sinh vien voi CCCD: "<<key<<'\n';}

    auto ids_name = Student::getStudents(students,"Hu");
    cout<<"\nSinh vien co ten chua 'Hu':\n";
    for(int i:ids_name) students[i].print();

    auto ids_age = Student::getStudentsByAge(students,26);
    cout<<"\nSinh vien do tuoi 26:\n";
    for(int i:ids_age) students[i].print();
}