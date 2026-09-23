#include <iostream>

using namespace std;

struct Food
{
    string  id,
            name;
    double  price;
    int     quantity;

    void inputFood()
    {
        cin.ignore();

        cout << "Nhap ID mon an: ";
        getline(cin, id);

        cout << "Nhap ten mon an: ";
        getline(cin, name);

        cout << "Nhap gia: ";
        cin >> price;

        cout << "Nhap so luong: ";
        cin >> quantity;

        cin.ignore();
    }

    void viewFood()
    {
        cout << "ID: " << id << endl; 
        cout << "Ten mon: " << name << endl; 
        cout << "Don gia: " << price << endl;
        cout << "So luong: " << quantity << endl;
    }

    void viewFoodNoQuan()
    {
        cout << "ID: " << id << endl; 
        cout << "Ten mon: " << name << endl; 
        cout << "Don gia: " << price << endl;
    }

    void editPrice()
    {
        cout << "Gia hien tai: " << price << endl;
        cout << "Nhap gia moi: ";
        cin >> price;

        cout << "Cap nhat gia thanh cong!\n";
    }
};

struct Order
{
    string  id, 
            customerName, 
            address;
    Food    food;
    int     quantity;
    string  status;

    void inputOrder()
    {
        cout << "Nhap ID don hang: ";
        getline(cin, id);

        cout << "Nhap ten khach hang: ";
        getline(cin, customerName);

        cout << "Nhap dia chi don hang: ";
        getline(cin, address);

        cout << "\nNhap thong tin mon an:\n";
        food.inputFood();

        cout << "Nhap so luong: ";
        cin >> quantity;

        cout << "Nhap trang thai don hang: ";
        getline(cin, status);

        cin.ignore();
    }

    void viewOrder()
    {
        cout << "ID: " << id << endl;
        cout << "Ten khach hang: " << customerName << endl;
        cout << "Dia chi: " << address << endl;
        cout << "\nMon an:\n";
        food.viewFoodNoQuan();
        cout << "So luong: " << quantity;
    }

    void getBill()
    {
        cout << "\nTong tien cua don hang " << id <<": " << food.price * quantity;
    }
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
        orderCount = 0;
    }

    void addFood()
    {
        int n;
        cout << "\nThem mon an cho quan: \n";
        cout << "Nhap so luong mon an can them: ";
        cin >> n;
        cin.ignore();

        for(int i = foodCount; i < foodCount + n; i++)
        {
            cout << "\nNhap mon thu " << i + 1 << ":\n";
            foods[i].inputFood();
        }
        foodCount += n;
    }

    void viewFoods()
    {
        for(int i = 0; i < foodCount; i++)
        {
            cout << "\nMon an thu " << i << ":\n";
            foods[i].viewFood();
        }
    }

    Food foodByID(string id)
    { 
        for(int i = 0; i < foodCount; i++)
        {
            if(foods[i].id == id)
            {
                return foods[i];
            }
        }
        Food empty;
        return empty;
    }

    void findFoodByID(string id)
    {
        Food rel = foodByID(id);

        if(rel.id != "")
        {
            cout << "\nMon an co ma " << id << ":\n";
            rel.viewFood();
        }

        else
        {
            cout << "Khong tim thay mon an co ma " << id << "!\n";
        }
    }

    Food foodByName(string name)
    { 
        for(int i = 0; i < foodCount; i++)
        {
            if(foods[i].name == name)
            {
                return foods[i];
            }
        }
        Food empty;
        return empty;
    }

    void findFoodByName(string name)
    {
        Food rel = foodByName(name);

        if(rel.id != "")
        {
            cout << "\nMon an co ten " << name << ":\n";
            rel.viewFood();
        }

        else
        {
            cout << "Khong tim thay mon an co ten " << name << "!\n";
        }
    }

    void editFoodPrice(string id)
    {
        for(int i = 0; i < foodCount; i++)
        {
            if(foods[i].id == id)
            {
                foods[i].editPrice();
                return;
            }
        }

        cout << "Khong tim thay mon an co ma " << id << "!\n";
    }

    void editFoodQuantity(string id)
    {
        for(int i = 0; i < foodCount; i++)
        {
            if(foods[i].id == id)
            {
                cout << "So luong hien tai: " << foods[i].quantity << endl;
                cout << "Nhap so luong moi: ";
                cin >> foods[i].quantity;

                cout << "Cap nhat so luong thanh cong!\n";
                return;
            }
        }

        cout << "Khong tim thay mon an co ma " << id << "!\n";
    }

    bool checkFood(string id, int quantity)
    {
        for(int i = 0; i < foodCount; i++)
        {
            if(foods[i].id == id)
            {
                if(foods[i].quantity >= quantity)
                {
                    return true;
                }
                else
                {
                    cout << "Mon an co ton tai nhung khong du so luong!\n";
                    return false;
                }
            }
        }

        cout << "Mon an khong ton tai!\n";
        return false;
    }

    void addOrder()
    {
        int n;
        cout << "\nThem don hang cho quan: \n";
        cout << "Nhap so luong don hang can them: ";
        cin >> n;

        for(int i = orderCount; i < orderCount + n; i++)
        {
            cout << "\nNhap don hang thu " << i + 1 << ":\n";

            orders[i].inputOrder();

            if(checkFood(orders[i].food.id, orders[i].quantity))
            {
                cout << "Dat mon thanh cong!\n";
            }
        }

        orderCount += n;
    }

    void viewOrders()
    {
        for(int i = 0; i < orderCount; i++)
        {
            cout << "\nDon hang thu " << i << ":\n";
            orders[i].viewOrder();
        }
    }
};

int main()
{
    Restaurant restaurant;
    return 0;
}