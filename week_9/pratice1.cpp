#include <iostream>

using namespace std;

struct Food
{
    string  id,
            name;
    double  price;
    int     quantity;
};

struct Order
{
    string  id, 
            customerName, 
            address;
    Food    food;
    int     quantity;
    string  status;
};

struct Restaurant
{
    string  name,
            address,
            phone;
    Food    foods[100];
    int     foodCount;
    Order   orders[100];
    int     orderCount;

    void inputRes()
    {
        cout << "Nhap ten nha hang: ";
        getline(cin, name);
        cout << "Nhap dia chi nha hang: ";
        getline(cin, address);
        cout << "Nhap SDT nha hang: ";
        getline(cin, phone);
        foodCount = 0;
    }

    void addFood()
    {
        int n;
        cout << "Them mon an cho quan: \n";
        cout << "Nhap so luong mon an can them: ";
        cin >> n;
        cin.ignore();

        for(int i = foodCount; i < foodCount + n; i++)
        {
            cout << "\nNhap mon thu " << i + 1 << ":\n";

            cout << "Nhap ID mon an: ";
            getline(cin, foods[i].id);

            cout << "Nhap ten mon an: ";
            getline(cin, foods[i].name);

            cout << "Nhap gia: ";
            cin >> foods[i].price;

            cout << "Nhap so luong: ";
            cin >> foods[i].quantity;

            cin.ignore();
        }
        foodCount += n;
    }
};

int main()
{
    Restaurant restaurant;
    return 0;
}