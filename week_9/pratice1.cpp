#include <iostream>
#include <string>
#include <ctime>
#include <cctype>

using namespace std;

// =====================================================
// CAC HAM XU LY CHUOI
// =====================================================

// Chuyen chuoi thanh chu thuong
string toLowerString(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }

    return s;
}

// Xoa khoang trang dau va cuoi
string trim(string s)
{
    int dau = 0;
    int cuoi = s.length() - 1;

    while (dau <= cuoi && s[dau] == ' ')
        dau++;

    while (cuoi >= dau && s[cuoi] == ' ')
        cuoi--;

    if (dau > cuoi)
        return "";

    return s.substr(dau, cuoi - dau + 1);
}

// Chuan hoa ten:
// - Xoa khoang trang thua
// - Viet hoa chu cai dau moi tu
// - Cac chu con lai viet thuong
string normalizeName(string s)
{
    s = trim(s);

    string result = "";
    bool dauTu = true;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (c == ' ')
        {
            if (result.length() > 0 &&
                result[result.length() - 1] != ' ')
            {
                result += ' ';
            }

            dauTu = true;
        }
        else
        {
            c = tolower(c);

            if (dauTu)
            {
                c = toupper(c);
                dauTu = false;
            }

            result += c;
        }
    }

    // Xoa khoang trang cuoi
    if (result.length() > 0 &&
        result[result.length() - 1] == ' ')
    {
        result.erase(result.length() - 1);
    }

    return result;
}

// Chuyen ten thanh dang dung cho ma don
// Vi du: "Nguyen Van An" -> "nguyenvanan"
string makeIDName(string name)
{
    name = toLowerString(name);

    string result = "";

    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] != ' ')
        {
            result += name[i];
        }
    }

    return result;
}

// So sanh khong phan biet hoa thuong
bool equalIgnoreCase(string a, string b)
{
    a = toLowerString(trim(a));
    b = toLowerString(trim(b));

    return a == b;
}


// =====================================================
// YEU CAU 3: TAO MA DON HANG
// tenlowerkhongcach_SDT_DDMM_HHMM
// =====================================================

string createOrderID(string customerName, string phone)
{
    time_t now = time(0);
    tm *t = localtime(&now);

    string id = "";

    // Ten khach hang
    id += makeIDName(customerName);

    // _
    id += "_";

    // So dien thoai
    id += phone;

    // _
    id += "_";

    // DD
    if (t->tm_mday < 10)
        id += "0";

    id += to_string(t->tm_mday);

    // MM
    if (t->tm_mon + 1 < 10)
        id += "0";

    id += to_string(t->tm_mon + 1);

    // _
    id += "_";

    // HH
    if (t->tm_hour < 10)
        id += "0";

    id += to_string(t->tm_hour);

    // MM
    if (t->tm_min < 10)
        id += "0";

    id += to_string(t->tm_min);

    return id;
}


// =====================================================
// FOOD
// =====================================================

struct Food
{
    string name;

    // YEU CAU 2
    void inputFood()
    {
        cout << "Nhap ten mon an: ";
        getline(cin, name);

        name = normalizeName(name);

        cout << "Ten mon sau khi chuan hoa: "
             << name << endl;
    }
};


// =====================================================
// ORDER
// =====================================================

struct Order
{
    string id;
    string customerName;
    string phone;
    string foodName;

    int quantity;

    string status;

    void inputOrder()
    {
        cout << "Nhap ten khach hang: ";
        getline(cin, customerName);

        cout << "Nhap so dien thoai: ";
        getline(cin, phone);

        cout << "Nhap ten mon an: ";
        getline(cin, foodName);

        foodName = normalizeName(foodName);

        cout << "Nhap so luong: ";
        cin >> quantity;
        cin.ignore();

        // Trang thai mac dinh
        status = "Dang chuan bi";

        // Tao ma don hang
        id = createOrderID(customerName, phone);

        cout << "Ma don hang: "
             << id << endl;
    }

    void viewOrder()
    {
        cout << "Ma don: " << id << endl;
        cout << "Khach hang: " << customerName << endl;
        cout << "So dien thoai: " << phone << endl;
        cout << "Mon an: " << foodName << endl;
        cout << "So luong: " << quantity << endl;
        cout << "Trang thai: " << status << endl;
    }
};


// =====================================================
// RESTAURANT
// =====================================================

struct Restaurant
{
    string name;

    Food foods[100];
    int foodCount;

    Order orders[100];
    int orderCount;


    // =================================================
    // YEU CAU 1
    // Nhap va hien thi ten cua hang
    // =================================================

    void inputRestaurant()
    {
        cout << "Nhap ten cua hang: ";
        getline(cin, name);

        name = trim(name);

        cout << "\nChao mung den voi ["
             << name
             << "]!\n";

        foodCount = 0;
        orderCount = 0;
    }


    // =================================================
    // THEM MON AN
    // =================================================

    void addFoods()
    {
        int n;

        cout << "\nNhap so luong mon an: ";
        cin >> n;
        cin.ignore();

        for (int i = 0; i < n; i++)
        {
            cout << "\n--- Mon an thu "
                 << i + 1
                 << " ---\n";

            foods[foodCount].inputFood();

            foodCount++;
        }
    }


    // =================================================
    // HIEN THI MON AN
    // =================================================

    void viewFoods()
    {
        cout << "\n===== DANH SACH MON AN =====\n";

        for (int i = 0; i < foodCount; i++)
        {
            cout << i + 1 << ". "
                 << foods[i].name
                 << endl;
        }
    }


    // =================================================
    // YEU CAU 4
    // Kiem tra mon an
    // =================================================

    bool checkFood(string name)
    {
        name = normalizeName(name);

        for (int i = 0; i < foodCount; i++)
        {
            if (equalIgnoreCase(
                    foods[i].name,
                    name))
            {
                return true;
            }
        }

        return false;
    }

    void checkFoodInput()
    {
        string name;

        cout << "\nNhap ten mon an can kiem tra: ";
        getline(cin, name);

        if (checkFood(name))
        {
            cout << "Mon an co trong danh sach!\n";
        }
        else
        {
            cout << "Mon an khong co trong danh sach!\n";
        }
    }


    // =================================================
    // THEM DON HANG
    // =================================================

    void addOrders()
    {
        int n;

        cout << "\nNhap so luong don hang: ";
        cin >> n;
        cin.ignore();

        for (int i = 0; i < n; i++)
        {
            cout << "\n===== DON HANG "
                 << i + 1
                 << " =====\n";

            orders[orderCount].inputOrder();

            // Kiem tra mon an co trong danh sach
            if (checkFood(orders[orderCount].foodName))
            {
                cout << "Mon an hop le!\n";
                cout << "Them don hang thanh cong!\n";

                orderCount++;
            }
            else
            {
                cout << "Mon an khong co trong danh sach!\n";
                cout << "Khong them don hang!\n";
            }
        }
    }


    // =================================================
    // HIEN THI DON HANG
    // =================================================

    void viewOrders()
    {
        cout << "\n===== DANH SACH DON HANG =====\n";

        if (orderCount == 0)
        {
            cout << "Chua co don hang.\n";
            return;
        }

        for (int i = 0; i < orderCount; i++)
        {
            cout << "\n--- Don hang "
                 << i + 1
                 << " ---\n";

            orders[i].viewOrder();
        }
    }


    // =================================================
    // YEU CAU 6
    // Thay doi trang thai don hang
    // =================================================

    void changeOrderStatus()
    {
        string id;

        cout << "\nNhap ma don hang: ";
        getline(cin, id);

        for (int i = 0; i < orderCount; i++)
        {
            if (orders[i].id == id)
            {
                int choice;

                cout << "Trang thai hien tai: "
                     << orders[i].status
                     << endl;

                cout << "\n1. Dang chuan bi\n";
                cout << "2. Dang giao\n";
                cout << "3. Hoan thanh\n";
                cout << "4. Da huy\n";

                cout << "Nhap lua chon: ";
                cin >> choice;
                cin.ignore();

                if (choice == 1)
                {
                    orders[i].status = "Dang chuan bi";
                }
                else if (choice == 2)
                {
                    orders[i].status = "Dang giao";
                }
                else if (choice == 3)
                {
                    orders[i].status = "Hoan thanh";
                }
                else if (choice == 4)
                {
                    orders[i].status = "Da huy";
                }
                else
                {
                    cout << "Lua chon khong hop le!\n";
                    return;
                }

                cout << "Cap nhat trang thai thanh cong!\n";
                return;
            }
        }

        cout << "Khong tim thay don hang!\n";
    }


    // =================================================
    // YEU CAU 7
    // Tim don hang theo ten khach hang
    // Khong phan biet hoa thuong
    // =================================================

    void findOrdersByCustomer()
    {
        string keyword;

        cout << "\nNhap tu khoa ten khach hang: ";
        getline(cin, keyword);

        keyword = toLowerString(trim(keyword));

        bool found = false;

        cout << "\n===== KET QUA TIM KIEM =====\n";

        for (int i = 0; i < orderCount; i++)
        {
            string customer =
                toLowerString(orders[i].customerName);

            if (customer.find(keyword) != string::npos)
            {
                cout << "\nMa don: "
                     << orders[i].id << endl;

                cout << "Khach hang: "
                     << orders[i].customerName << endl;

                cout << "SDT: "
                     << orders[i].phone << endl;

                cout << "Mon an: "
                     << orders[i].foodName << endl;

                cout << "So luong: "
                     << orders[i].quantity << endl;

                cout << "Trang thai: "
                     << orders[i].status << endl;

                found = true;
            }
        }

        if (!found)
        {
            cout << "Khong tim thay don hang!\n";
        }
    }


    // =================================================
    // YEU CAU 9
    // Thong ke mon an ban chay
    // =================================================

    void statisticFood()
    {
        string name;

        cout << "\nNhap ten mon an can thong ke: ";
        getline(cin, name);

        name = normalizeName(name);

        int count = 0;

        for (int i = 0; i < orderCount; i++)
        {
            if (equalIgnoreCase(
                    orders[i].foodName,
                    name))
            {
                count++;
            }
        }

        cout << "\nMon an: "
             << name << endl;

        cout << "Da xuat hien trong "
             << count
             << " don hang.\n";
    }


    // =================================================
    // YEU CAU 10
    // Tao thong bao giao hang
    // =================================================

    void createDeliveryNotification()
    {
        string customerName;
        string orderID;
        string address;

        cout << "\nNhap ten khach hang: ";
        getline(cin, customerName);

        cout << "Nhap ma don hang: ";
        getline(cin, orderID);

        cout << "Nhap dia chi giao hang: ";
        getline(cin, address);

        cout << "\n===== THONG BAO GIAO HANG =====\n";

        cout << "Don hang ["
             << orderID
             << "] cua ["
             << customerName
             << "] dang duoc giao den ["
             << address
             << "]. Cam on ban!\n";
    }
};


// =====================================================
// MAIN
// =====================================================

int main()
{
    Restaurant restaurant;

    // Bai 1
    restaurant.inputRestaurant();

    // Bai 2
    restaurant.addFoods();
    restaurant.viewFoods();

    // Bai 4
    restaurant.checkFoodInput();

    // Bai 3
    restaurant.addOrders();
    restaurant.viewOrders();

    // Bai 6
    restaurant.changeOrderStatus();

    // Bai 7
    restaurant.findOrdersByCustomer();

    // Bai 9
    restaurant.statisticFood();

    // Bai 10
    restaurant.createDeliveryNotification();

    return 0;
}