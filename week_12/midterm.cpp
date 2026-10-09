#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;

    public:
    Fish() {
        id = 0;
        name = "";
        color = "";
        characteristic = "";
    }

    Fish(int i) {
        id = i;
        name = "";
        color = "";
        characteristic = "";
    }

    Fish(int i, string n) {
        id = i;
        name = n;
        color = "";
        characteristic = "";
    }

    Fish(int i, string n, string c) {
        id = i;
        name = n;
        color = c;
        characteristic = "";
    }

    Fish(int i, string n, string c, string ch) {
        id = i;
        name = n;
        color = c;
        characteristic = ch;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    string getColor() {
        return color;
    }

    string getCharacteristic() {
        return characteristic;
    }

    void setId(int i) {
        id = i;
    }

    void setName(string n) {
        name = n;
    }

    void setColor(string c) {
        color = c;
    }

    void setCharacteristic(string ch) {
        characteristic = ch;
    }

    void displayFishInfo() {
        cout << "Fish: " << name << " - " << id << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Characteristic: " << characteristic << endl;
    }

};

int main() {
    Fish ca1;
    Fish ca2(2);
    Fish ca3(3, "Ca lau kieng");
    Fish ca4(4, "Ca koi", "Xanh duong");
    Fish ca5(5, "Ca cha ba", "Den", "Hien");

    cout << "DANH SACH CA:" << endl;
    ca1.displayFishInfo();
    ca2.displayFishInfo();
    ca3.displayFishInfo();
    ca4.displayFishInfo();
    ca5.displayFishInfo();

    ca3.setName("Ca do");
    ca3.setColor("Red");
    ca3.setCharacteristic("Du");

    cout << endl;
    cout << "THONG TIN SAU KHI CAP NHAT:" << endl;
    cout << "ID: " << ca3.getId() << endl;
    cout << "Name: " << ca3.getName() << endl;
    cout << "Color: " << ca3.getColor() << endl;
    cout << "Characteristic: " << ca3.getCharacteristic() << endl;

    cout << endl;

    ca3.displayFishInfo();

        Fish danhSach[MAX];
    int soLuong = 0;

    danhSach[soLuong++] = ca1;
    danhSach[soLuong++] = ca2;
    danhSach[soLuong++] = ca3;
    danhSach[soLuong++] = ca4;
    danhSach[soLuong++] = ca5;

    danhSach[soLuong++] = Fish(6, "Ca vang", "Cam", "De nuoi");
    danhSach[soLuong++] = Fish(7, "Ca than tien", "Bac", "Hien lanh");
    danhSach[soLuong++] = Fish(8, "Ca neon", "Xanh", "Hien lanh");
    danhSach[soLuong++] = Fish(9, "Ca dia", "Do", "Thong minh");
    danhSach[soLuong++] = Fish(10, "Ca molly", "Den", "De nuoi");
    danhSach[soLuong++] = Fish(11, "Ca platy", "Cam", "Nho gon");
    danhSach[soLuong++] = Fish(12, "Ca rong", "Bac", "Nhay cao");
    danhSach[soLuong++] = Fish(13, "Ca dia hoang", "Do", "Nhay cam");
    danhSach[soLuong++] = Fish(14, "Ca betta", "Xanh", "Nang dong");
    danhSach[soLuong++] = Fish(15, "Ca la han", "Do", "Hung han");

    cout << endl;
    cout << "NHOM CA THEO MAU" << endl;

    for (int i = 0; i < soLuong; i++) {
        bool daIn = false;

        for (int j = 0; j < i; j++) {
            if (danhSach[j].getColor() == danhSach[i].getColor()) {
                daIn = true;
                break;
            }
        }

        if (daIn) {
            continue;
        }

        string mau = danhSach[i].getColor();

        if (mau == "") {
            cout << endl << "Color: (No color)" << endl;
        }
        else {
            cout << endl << "Color: " << mau << endl;
        }

        for (int k = 0; k < soLuong; k++) {
            if (danhSach[k].getColor() == mau) {
                cout << "  - [" << danhSach[k].getId() << "] "
                     << danhSach[k].getName() << endl;
            }
        }
    }

    return 0;
}