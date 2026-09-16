#include <iostream>
#include <string>

using namespace std;

#define MAX 100

struct User
{
    string username;
    string pwd;
};

struct Computer
{
    string id;
    string tenMay;
    string hdh;
    User user;
    string model;
    int year;
};

struct Lab
{
    string maPhong;
    string chucNang;
    Computer danhSachMay[MAX];
    int soLuong;

    void inputLab()
    {

        cout << "Nhap ma phong: ";
        getline(cin, maPhong);
        cout << "Nhap chuc nang: ";
        getline(cin, chucNang);

        cout << "\nNhap so luong may tinh: ";
        cin >> soLuong;
        
        for (int i = 0; i < soLuong; i++)
        {
            cout << "May tinh so " << i + 1 << ":\n";
            
            cout << "Nhap ID: ";
            cin.ignore();
            getline(cin, danhSachMay[i].id);

            cout << "Nhap ten may: ";
            getline(cin, danhSachMay[i].tenMay);

            cout << "Nhap he dieu hanh: ";
            getline(cin, danhSachMay[i].hdh);

            cout << "\nThong tin USER:\n";

            cout << "Nhap username: ";
            cin.ignore();
            getline(cin, danhSachMay[i].user.username);

            cout << "Nhap password: ";
            getline(cin, danhSachMay[i].user.pwd);
            
        }
    }

    int getComputerCount()
    {
        return soLuong;
    }

    void showLabInfo() {
        cout << "\nThong tin phong:\n";
        cout << "Ma Phong: " << maPhong << endl;
        cout << "Chuc Nang: " << chucNang << endl;
        cout << "So luong may: " << getComputerCount() << endl;
    }

    Computer getComputerInf(string id_)
    {
        for (int i = 0; i < soLuong; i++)
        {
            if(danhSachMay[i].id == id_)
            {
                return danhSachMay[i];
            }
        }
        cout << "Khong tim thay may co ID " << id_ << endl;
        return Computer();
    }

    void getComputerInfo(string id)
    {
        Computer c = getComputerInf(id);
        if(c.id == "")
        {
        cout << "Thong tin may:\n ";
        cout << "ID: " << c.id << endl;
        cout << "Ten may: " << c.tenMay << endl;
        cout << "OS: " << c.hdh << endl;
        cout << "Model: " << c.model << endl;
        cout << "Year: " << c.year << endl;
        }
    }

    User getUserInfo(string id)
    {
        for (int i = 0; i < soLuong; i++)
        {
            if(danhSachMay[i].id == id)
            {
                return danhSachMay[i].user;
            }
        }
        cout << "Khong tim thay may co ID " << id;
        return User();
    }
};

int main()
{
    int n;
    Lab phong;

    phong.inputLab();

    phong.showLabInfo();

    phong.getComputerInfo("1");

    phong.getUserInfo("1");

    return 0;
}