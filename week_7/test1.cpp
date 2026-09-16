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

    void inputComputer()
    {
        cout << "Nhap ID: ";
        cin.ignore();
        getline(cin, id);

        cout << "Nhap ten may: ";
        getline(cin, tenMay);

        cout << "Nhap he dieu hanh: ";
        getline(cin, hdh);

        cout << "Nhap nam san xuat: ";
        cin >> year;

        cout << "\nThong tin USER:\n";

        cout << "Nhap username: ";
        cin.ignore();
        getline(cin, user.username);

        cout << "Nhap password: ";
        getline(cin, user.pwd);
    }
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
            danhSachMay[i].inputComputer();   
        }
    }

    int getComputerCount()
    {
        return soLuong;
    }

    void showLabInfo()
    {
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
        if(c.id != "")
        {
        cout << "Thong tin may:\n ";
        cout << "ID: " << c.id << endl;
        cout << "Ten may: " << c.tenMay << endl;
        cout << "OS: " << c.hdh << endl;
        cout << "Model: " << c.model << endl;
        cout << "Year: " << c.year << endl;
        }
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