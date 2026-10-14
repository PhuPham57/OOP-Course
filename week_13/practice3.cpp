#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string cccd;      // CCCD
    string sdt;       // Số điện thoại
    string address;   // Địa chỉ
public:
    Employee() {
        cccd = "";
        sdt = "";
        address = "";
    }
    Employee(string c, string s, string a) {
        cccd = c;
        sdt = s;
        address = a;
    }

    void displayInfo() const {
        cout << "CCCD: " << cccd << endl;
        cout << "SDT: " << sdt << endl;
        cout << "Address: " << address << endl;
    }

    string getCCCD() const { return cccd; }
    string getSDT() const { return sdt; }
    string getAddress() const { return address; }

    void setCCCD(string c) { cccd = c; }
    void setSDT(string s) { sdt = s; }
    void setAddress(string a) { address = a; }
};

