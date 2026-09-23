#include <iostream>

using namespace std;

struct Food
{
    string  id,
            name;
    double  price;
    int     quantity;

    // Nhap thong tin mon an
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

    // Hien thi day du thong tin mon an
    void viewFood()
    {
        cout << "ID: " << id << endl;
        cout << "Ten mon: " << name << endl;
        cout << "Don gia: " << price << endl;
        cout << "So luong: " << quantity << endl;
    }

    // Hien thi thong tin mon an, khong hien thi so luong
    void viewFoodNoQuan()
    {
        cout << "ID: " << id << endl;
        cout << "Ten mon: " << name << endl;
        cout << "Don gia: " << price << endl;
    }

    // Cap nhat gia mon an
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

    // Nhap thong tin don hang
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

    // Hien thi thong tin don hang
    void viewOrder()
    {
        cout << "ID: " << id << endl;
        cout << "Ten khach hang: " << customerName << endl;
        cout << "Dia chi: " << address << endl;

        cout << "\nMon an:\n";
        food.viewFoodNoQuan();

        cout << "So luong: " << quantity << endl;
    }

    // Tinh va hien thi tong tien cua don hang
    void getBill()
    {
        cout << "\nTong tien cua don hang " << id << ": "
             << food.price * quantity << endl;
    }

    // Cap nhat trang thai don hang
    void editStatus()
    {
        cout << "Don hang so " << id << endl;
        cout << "Trang thai hien tai: " << status << endl;
        cout << "Nhap trang thai moi: ";

        cin.ignore();
        getline(cin, status);

        cout << "Cap nhat trang thai thanh cong!\n";
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


    // Nhap thong tin nha hang
    // Dong thoi khoi tao so luong mon an va don hang
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


    // Them mon an vao danh sach mon an cua nha hang
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


    // Hien thi danh sach tat ca mon an
    void viewFoods()
    {
        for(int i = 0; i < foodCount; i++)
        {
            cout << "\nMon an thu " << i << ":\n";

            foods[i].viewFood();
        }
    }


    // Tim mon an theo ID
    Food foodByID(string id)
    {
        for(int i = 0; i < foodCount; i++)
        {
            if(foods[i].id == id)
            {
                return foods[i];
            }
        }

        // Neu khong tim thay thi tra ve Food rong
        Food empty;
        return empty;
    }


    // Tim va hien thi mon an theo ID
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
            cout << "Khong tim thay mon an co ma "
                 << id << "!\n";
        }
    }


    // Tim mon an theo ten
    Food foodByName(string name)
    {
        for(int i = 0; i < foodCount; i++)
        {
            if(foods[i].name == name)
            {
                return foods[i];
            }
        }

        // Neu khong tim thay thi tra ve Food rong
        Food empty;
        return empty;
    }


    // Tim va hien thi mon an theo ten
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
            cout << "Khong tim thay mon an co ten "
                 << name << "!\n";
        }
    }


    // Tim mon an theo ID va cap nhat gia
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

        cout << "Khong tim thay mon an co ma "
             << id << "!\n";
    }


    // Tim mon an theo ID va cap nhat so luong
    void editFoodQuantity(string id)
    {
        for(int i = 0; i < foodCount; i++)
        {
            if(foods[i].id == id)
            {
                cout << "So luong hien tai: "
                     << foods[i].quantity << endl;

                cout << "Nhap so luong moi: ";
                cin >> foods[i].quantity;

                cout << "Cap nhat so luong thanh cong!\n";

                return;
            }
        }

        cout << "Khong tim thay mon an co ma "
             << id << "!\n";
    }


    // Kiem tra mon an co ton tai va co du so luong hay khong
    bool checkFood(string id, int quantity)
    {
        for(int i = 0; i < foodCount; i++)
        {
            // Kiem tra ID mon an
            if(foods[i].id == id)
            {
                // Kiem tra so luong
                if(foods[i].quantity >= quantity)
                {
                    return true;
                }
                else
                {
                    cout << "Mon an co ton tai "
                         << "nhung khong du so luong!\n";

                    return false;
                }
            }
        }

        cout << "Mon an khong ton tai!\n";

        return false;
    }


    // Them don hang vao danh sach
    // Dong thoi kiem tra mon an co ton tai va du so luong
    void addOrder()
    {
        int n;

        cout << "\nThem don hang cho quan: \n";
        cout << "Nhap so luong don hang can them: ";
        cin >> n;

        for(int i = orderCount; i < orderCount + n; i++)
        {
            cout << "\nNhap don hang thu "
                 << i + 1 << ":\n";

            orders[i].inputOrder();

            // Kiem tra mon an trong don hang
            if(checkFood(orders[i].food.id,
                         orders[i].quantity))
            {
                cout << "Dat mon thanh cong!\n";
            }
        }

        orderCount += n;
    }


    // Hien thi danh sach tat ca don hang
    void viewOrders()
    {
        for(int i = 0; i < orderCount; i++)
        {
            cout << "\nDon hang thu " << i << ":\n";

            orders[i].viewOrder();
        }
    }


    // Tim don hang theo ID
    Order orderByID(string id)
    {
        // Duyet trong danh sach don hang
        for(int i = 0; i < orderCount; i++)
        {
            if(orders[i].id == id)
            {
                return orders[i];
            }
        }

        // Neu khong tim thay thi tra ve Order rong
        Order empty;
        return empty;
    }


    // Tim va hien thi don hang theo ID
    void findOrderByID(string id)
    {
        Order rel = orderByID(id);

        if(rel.id != "")
        {
            cout << "\nDon hang co ma "
                 << id << ":\n";

            rel.viewOrder();
        }
        else
        {
            cout << "Khong tim thay don hang co ma "
                 << id << "!\n";
        }
    }


    // Tim don hang theo ID va cap nhat trang thai
    void editOrderStatus(string id)
    {
        for(int i = 0; i < orderCount; i++)
        {
            if(orders[i].id == id)
            {
                orders[i].editStatus();

                return;
            }
        }

        cout << "Khong tim thay don hang co ma "
             << id << "!\n";
    }


    // Tinh tong doanh thu cua cac don hang da hoan thanh
    void revenue()
    {
        double total = 0;

        for(int i = 0; i < orderCount; i++)
        {
            if(orders[i].status == "Hoan thanh")
            {
                total += orders[i].food.price
                       * orders[i].quantity;
            }
        }

        cout << "\nTong doanh thu cac don da hoan thanh: "
             << total << endl;
    }
};


int main()
{
    Restaurant restaurant;

    restaurant.inputRes();

    restaurant.addFood();

    restaurant.viewFoods();

    string id, name;

    cout << "\nNhap ID mon an can tim: ";
    getline(cin, id);
    restaurant.findFoodByID(id);

    cout << "\nNhap ten mon an can tim: ";
    getline(cin, name);
    restaurant.findFoodByName(name);

    cout << "\nNhap ID mon an can cap nhat gia: ";
    getline(cin, id);
    restaurant.editFoodPrice(id);

    cout << "\nNhap ID mon an can cap nhat so luong: ";
    getline(cin, id);
    restaurant.editFoodQuantity(id);

    restaurant.addOrder();

    restaurant.viewOrders();

    cout << "\nNhap ID don hang can tim: ";
    getline(cin, id);
    restaurant.findOrderByID(id);

    cout << "\nNhap ID don hang can cap nhat trang thai: ";
    getline(cin, id);
    restaurant.editOrderStatus(id);

    for(int i = 0; i < restaurant.orderCount; i++)
    {
        restaurant.orders[i].getBill();
    }

    restaurant.revenue();

    return 0;
}