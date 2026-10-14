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

class HourlyEmployee : public Employee {
private:
    int soGioLamViec;   // số giờ làm việc
    double donGia;      // đơn giá (vnd/giờ)
public:
    HourlyEmployee() : Employee() {
        soGioLamViec = 0;
        donGia = 0;
    }
    HourlyEmployee(string c, string s, string a, int soGio, double dg)
        : Employee(c, s, a) {
        soGioLamViec = soGio;
        donGia = dg;
    }

    void displayInfo() const {
        Employee::displayInfo();   // gọi hàm lớp cha
        cout << "So gio lam viec: " << soGioLamViec << endl;
        cout << "Don gia: " << donGia << endl;
        cout << "Luong: " << tinhLuong() << endl;
    }
    double tinhLuong() const { return soGioLamViec * donGia; }

    int getSoGioLamViec() const { return soGioLamViec; }
    double getDonGia() const { return donGia; }
    void setSoGioLamViec(int g) { soGioLamViec = g; }
    void setDonGia(double dg) { donGia = dg; }
};