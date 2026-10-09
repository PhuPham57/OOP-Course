#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Date {
public:
    int year, month, day;

    Date() {
        year = 0;
        month = 0;
        day = 0;
    }

    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
};

class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;
    int categoryId;

    public:
    Fish() {
        id = 0;
        name = "";
        color = "";
        characteristic = "";
        categoryId = 0;
    }

    Fish(int i) {
        id = i;
        name = "";
        color = "";
        characteristic = "";
        categoryId = 0;
    }

    Fish(int i, string n) {
        id = i;
        name = n;
        color = "";
        characteristic = "";
        categoryId = 0;
    }

    Fish(int i, string n, string c) {
        id = i;
        name = n;
        color = c;
        characteristic = "";
        categoryId = 0;
    }

    Fish(int i, string n, string c, string ch) {
        id = i;
        name = n;
        color = c;
        characteristic = ch;
        categoryId = 0;
    }

    Fish(int i, string n, string c, string ch, int catId) {
        id = i;
        name = n;
        color = c;
        characteristic = ch;
        categoryId = catId;
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

    int getCategoryId() {
        return categoryId;
    }

    void setCategoryId(int catId) {
        categoryId = catId;
    }

    void displayFishInfo() {
        cout << "Fish: " << name << " - " << id << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Characteristic: " << characteristic << endl;
        cout << "Category ID: " << categoryId << endl;
    }

};

class Category {
private:
    int categoryId;
    string categoryName;
    string description;

public:
    Category() {
        categoryId = 0;
        categoryName = "";
        description = "";
    }

    Category(int id) {
        categoryId = id;
        categoryName = "";
        description = "";
    }

    Category(int id, string name) {
        categoryId = id;
        categoryName = name;
        description = "";
    }

    Category(int id, string name, string desc) {
        categoryId = id;
        categoryName = name;
        description = desc;
    }

    int getCategoryId() {
        return categoryId;
    }

    string getCategoryName() {
        return categoryName;
    }

    string getDescription() {
        return description;
    }

    void setCategoryId(int id) {
        categoryId = id;
    }

    void setCategoryName(string name) {
        categoryName = name;
    }

    void setDescription(string desc) {
        description = desc;
    }

    void displayCategoryInfo() {
        cout << endl << "Category: " << categoryName << " - " << categoryId << endl;
        cout << "Category ID: " << categoryId << endl;
        cout << "Category Name: " << categoryName << endl;
        cout << "Description: " << description << endl;
    }
};

class FishShop {
private:
    int id;
    string name;
    string address;
    string owner;
    Date startdate;
    Category categories[MAX];
    Fish fishes[MAX];
    int soDanhMuc;
    int soCa;

public:
    FishShop() {
        id = 0;
        name = "";
        address = "";
        owner = "";
        startdate = Date();
        soDanhMuc = 0;
        soCa = 0;
    }

    FishShop(int i, string n, string addr, string o, Date d) {
        id = i;
        name = n;
        address = addr;
        owner = o;
        startdate = d;
        soDanhMuc = 0;
        soCa = 0;
    }

        int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    string getAddress() {
        return address;
    }

    string getOwner() {
        return owner;
    }

    Date getStartdate() {
        return startdate;
    }

    int getSoDanhMuc() {
        return soDanhMuc;
    }

    int getSoCa() {
        return soCa;
    }

    Category getCategory(int index) {
        return categories[index];
    }

    Fish getFish(int index) {
        return fishes[index];
    }

        void setId(int i) {
        id = i;
    }

    void setName(string n) {
        name = n;
    }

    void setAddress(string addr) {
        address = addr;
    }

    void setOwner(string o) {
        owner = o;
    }

    void setStartdate(Date d) {
        startdate = d;
    }

    void setCategory(int index, Category c) {
        if (index >= 0 && index < soDanhMuc) {
            categories[index] = c;
        }
    }

    void setFish(int index, Fish f) {
        if (index >= 0 && index < soCa) {
            fishes[index] = f;
        }
    }

        void addCategory(Category c) {
        if (soDanhMuc < MAX) {
            categories[soDanhMuc++] = c;
        }
    }

    void addFish(Fish f) {
        if (soCa < MAX) {
            fishes[soCa++] = f;
        }
    }

    void displayFishShopInfo() {
        cout << "Fish Shop: " << name << " - " << id << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Owner: " << owner << endl;
        cout << "Start date: " << startdate.year << "/"
             << startdate.month << "/" << startdate.day << endl;
        cout << "So danh muc: " << soDanhMuc << endl;
        cout << "So ca: " << soCa << endl;

        for (int i = 0; i < soDanhMuc; i++) {
            categories[i].displayCategoryInfo();

            for (int j = 0; j < soCa; j++) {
                if (fishes[j].getCategoryId() == categories[i].getCategoryId()) {
                    fishes[j].displayFishInfo();
                }
            }
        }
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
    ca3.setColor("Do");
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

    danhSach[soLuong++] = Fish(6, "Ca vang", "Cam", "De nuoi", 3);
    danhSach[soLuong++] = Fish(7, "Ca than tien", "Bac", "Hien lanh", 2);
    danhSach[soLuong++] = Fish(8, "Ca neon", "Xanh", "Hien lanh", 1);
    danhSach[soLuong++] = Fish(9, "Ca dia", "Do", "Thong minh", 2);
    danhSach[soLuong++] = Fish(10, "Ca molly", "Den", "De nuoi", 1);
    danhSach[soLuong++] = Fish(11, "Ca platy", "Cam", "Nho gon", 1);
    danhSach[soLuong++] = Fish(12, "Ca rong", "Bac", "Nhay cao", 1);
    danhSach[soLuong++] = Fish(13, "Ca dia hoang", "Do", "Nhay cam", 2);
    danhSach[soLuong++] = Fish(14, "Ca betta", "Xanh", "Nang dong", 1);
    danhSach[soLuong++] = Fish(15, "Ca la han", "Do", "Hung han", 2);

    ca1.setCategoryId(1);
    danhSach[soLuong++] = ca1;

    ca2.setCategoryId(1);
    danhSach[soLuong++] = ca2;

    ca3.setCategoryId(1);
    danhSach[soLuong++] = ca3;

    ca4.setCategoryId(1);
    danhSach[soLuong++] = ca4;

    ca5.setCategoryId(3);
    danhSach[soLuong++] = ca5;

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

    Category danhMuc[3];
    danhMuc[0] = Category(1, "Ca nuoc ngot nhiet doi", "Ca nho nuoi trong be o nha");
    danhMuc[1] = Category(2, "Ca ho cichlid", "Ca lon, nang dong, hay giu long dia");
    danhMuc[2] = Category(3, "Ca ho", "Ca nuoi ngoai troi trong ho");
    int soDanhMuc = 3;

    cout << endl;
    cout << "TAT CA DANH MUC:" << endl;

    for (int i = 0; i < soDanhMuc; i++) {
        danhMuc[i].displayCategoryInfo();
    }

    int chon = 2;

    cout << endl;
    cout << "CA THUOC DANH MUC ID " << chon << endl;

    for (int i = 0; i < soDanhMuc; i++) {
        if (danhMuc[i].getCategoryId() == chon) {
            cout << "Category: " << danhMuc[i].getCategoryName() << endl;
        }
    }

    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].getCategoryId() == chon) {
            danhSach[i].displayFishInfo();
        }
    }

    //
    Date ngayMo(2026, 9, 10);
    FishShop cuaHang(1, "Cua hang ca canh PhuDZ", "120 Yen Lang, HN", "Pham Thien Phu", ngayMo);

    cuaHang.addCategory(Category(1, "Ca nuoc ngot nhiet doi", "Ca nho nuoi trong be o nha"));
    cuaHang.addCategory(Category(2, "Ca ho cichlid", "Ca lon, nang dong, hay giu long dia"));
    cuaHang.addCategory(Category(3, "Ca ho", "Ca nuoi ngoai troi trong ho"));
    cuaHang.addCategory(Category(4, "Ca bien", "Ca nuoc man nuoi trong be bien"));

    cuaHang.addFish(Fish(1, "Ca neon", "Xanh", "Hien lanh", 1));
    cuaHang.addFish(Fish(2, "Ca molly", "Den", "De nuoi", 1));
    cuaHang.addFish(Fish(3, "Ca platy", "Cam", "Nho gon", 1));
    cuaHang.addFish(Fish(4, "Ca guppy", "Xanh", "Nang dong", 1));
    cuaHang.addFish(Fish(5, "Ca betta", "Do", "Hung han", 1));
    cuaHang.addFish(Fish(6, "Ca tu quy", "Bac", "Hien lanh", 1));
    cuaHang.addFish(Fish(7, "Ca hong nhung", "Do", "De nuoi", 1));
    cuaHang.addFish(Fish(8, "Ca kiem", "Cam", "Nang dong", 1));
    cuaHang.addFish(Fish(9, "Ca ba mau", "Vang", "Hien lanh", 1));
    cuaHang.addFish(Fish(10, "Ca mun", "Den", "De nuoi", 1));

    cuaHang.addFish(Fish(11, "Ca dia", "Do", "Thong minh", 2));
    cuaHang.addFish(Fish(12, "Ca la han", "Do", "Hung han", 2));
    cuaHang.addFish(Fish(13, "Ca than tien", "Bac", "Hien lanh", 2));
    cuaHang.addFish(Fish(14, "Ca oscar", "Den", "Thong minh", 2));
    cuaHang.addFish(Fish(15, "Ca ro", "Vang", "Giu long dia", 2));
    cuaHang.addFish(Fish(16, "Ca vet", "Xanh", "Nang dong", 2));
    cuaHang.addFish(Fish(17, "Ca hoang de", "Vang", "Hung han", 2));
    cuaHang.addFish(Fish(18, "Ca dia xanh", "Xanh", "Thong minh", 2));
    cuaHang.addFish(Fish(19, "Ca tuong", "Bac", "Nhay cao", 2));
    cuaHang.addFish(Fish(20, "Ca thu", "Cam", "Nang dong", 2));

    cuaHang.addFish(Fish(21, "Ca koi do", "Do", "Hien lanh", 3));
    cuaHang.addFish(Fish(22, "Ca koi vang", "Vang", "Hien lanh", 3));
    cuaHang.addFish(Fish(23, "Ca koi den", "Den", "Song lau", 3));
    cuaHang.addFish(Fish(24, "Ca chep vang", "Vang", "De nuoi", 3));
    cuaHang.addFish(Fish(25, "Ca vang ho", "Cam", "De nuoi", 3));
    cuaHang.addFish(Fish(26, "Ca chep kieng", "Trang", "Hien lanh", 3));
    cuaHang.addFish(Fish(27, "Ca koi trang", "Trang", "Song lau", 3));
    cuaHang.addFish(Fish(28, "Ca koi cam", "Cam", "Hien lanh", 3));
    cuaHang.addFish(Fish(29, "Ca diec", "Bac", "Khoe manh", 3));
    cuaHang.addFish(Fish(30, "Ca tre", "Den", "Song lau", 3));

    cuaHang.addFish(Fish(31, "Ca he", "Cam", "Nhat gan", 4));
    cuaHang.addFish(Fish(32, "Ca tang xanh", "Xanh", "Nang dong", 4));
    cuaHang.addFish(Fish(33, "Ca buom", "Vang", "Nhat gan", 4));
    cuaHang.addFish(Fish(34, "Ca chim xanh", "Xanh", "Hien lanh", 4));
    cuaHang.addFish(Fish(35, "Ca mao tien", "Do", "Hung han", 4));
    cuaHang.addFish(Fish(36, "Ca ngua van", "Den", "Nang dong", 4));
    cuaHang.addFish(Fish(37, "Ca bong den", "Den", "Nho gon", 4));
    cuaHang.addFish(Fish(38, "Ca than tien bien", "Vang", "Hien lanh", 4));
    cuaHang.addFish(Fish(39, "Ca hoang de bien", "Xanh", "Dep mat", 4));
    cuaHang.addFish(Fish(40, "Ca nuc", "Bac", "Khoe manh", 4));

    cout << endl;
    cout << "THONG TIN CUA HANG: " << endl;
    cuaHang.displayFishShopInfo();

    return 0;
}