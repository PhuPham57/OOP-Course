#include <iostream>
#include <string>

#define MAX 100

using namespace std;

class Employee {
protected:
    string ID;   // CCCD
    string phone;       // Số điện thoại
    string address;     // Địa chỉ
public:
    Employee() {
        ID = "";
        phone = "";
        address = "";
    }
    Employee(string c, string p, string a) {
        ID = c;
        phone = p;
        address = a;
    }

    void displayInfo() const {
        cout << "CCCD: " << ID << endl;
        cout << "SDT: " << phone << endl;
        cout << "Address: " << address << endl;
    }

    string getCitizenId() const { return ID; }
    string getPhone() const { return phone; }
    string getAddress() const { return address; }

    void setCitizenId(string c) { ID = c; }
    void setPhone(string p) { phone = p; }
    void setAddress(string a) { address = a; }
};

class HourlyEmployee : public Employee {
private:
    int workingHours;   // số giờ làm việc
    double unitPrice;   // đơn giá (vnd/giờ)
public:
    HourlyEmployee() : Employee() {
        workingHours = 0;
        unitPrice = 0;
    }
    HourlyEmployee(string c, string p, string a, int hours, double price)
        : Employee(c, p, a) {
        workingHours = hours;
        unitPrice = price;
    }

    void displayInfo() const {
        Employee::displayInfo();   // gọi hàm lớp cha
        cout << "So gio lam viec: " << workingHours << endl;
        cout << "Don gia: " << unitPrice << endl;
        cout << "Luong: " << calculateSalary() << endl;
    }
    // Lương = số giờ * đơn giá
    double calculateSalary() const { return workingHours * unitPrice; }

    int getWorkingHours() const { return workingHours; }
    double getUnitPrice() const { return unitPrice; }
    void setWorkingHours(int hours) { workingHours = hours; }
    void setUnitPrice(double price) { unitPrice = price; }
};

class MonthlyEmployee : public Employee {
private:
    double baseSalary;         // lương cơ bản
    double allowance;          // phụ cấp
    double bonusCoefficient;   // hệ số thưởng
public:
    MonthlyEmployee() : Employee() {
        baseSalary = 0;
        allowance = 0;
        bonusCoefficient = 0;
    }
    MonthlyEmployee(string c, string p, string a, double base, double allow, double bonus)
        : Employee(c, p, a) {
        baseSalary = base;
        allowance = allow;
        bonusCoefficient = bonus;
    }

    void displayInfo() const {
        Employee::displayInfo();   // gọi hàm lớp cha
        cout << "Luong co ban: " << baseSalary << endl;
        cout << "Phu cap: " << allowance << endl;
        cout << "He so thuong: " << bonusCoefficient << endl;
        cout << "Luong: " << calculateSalary() << endl;
    }
    // Lương = lương cơ bản + phụ cấp + (lương cơ bản * hệ số thưởng)
    double calculateSalary() const { return baseSalary + allowance + baseSalary * bonusCoefficient; }

    double getBaseSalary() const { return baseSalary; }
    double getAllowance() const { return allowance; }
    double getBonusCoefficient() const { return bonusCoefficient; }
    void setBaseSalary(double base) { baseSalary = base; }
    void setAllowance(double allow) { allowance = allow; }
    void setBonusCoefficient(double bonus) { bonusCoefficient = bonus; }
};

// Tính lương theo loại (t = 1: Hourly, t = 2: Monthly)
double getSalary(Employee* p, int t) {
    if (t == 1) return static_cast<HourlyEmployee*>(p)->calculateSalary();
    return static_cast<MonthlyEmployee*>(p)->calculateSalary();
}

// Hiển thị thông tin theo loại
void showInfo(Employee* p, int t) {
    if (t == 1) static_cast<HourlyEmployee*>(p)->displayInfo();
    else static_cast<MonthlyEmployee*>(p)->displayInfo();
}

// Tổng quỹ lương
double totalSalary(Employee* list[], int type[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++)
        total += getSalary(list[i], type[i]);
    return total;
}

// Tìm vị trí nhân viên lương cao nhất
int findMax(Employee* list[], int type[], int n) {
    int index = 0;
    for (int i = 1; i < n; i++)
        if (getSalary(list[i], type[i]) > getSalary(list[index], type[index])) index = i;
    return index;
}

// Tìm vị trí nhân viên lương thấp nhất
int findMin(Employee* list[], int type[], int n) {
    int index = 0;
    for (int i = 1; i < n; i++)
        if (getSalary(list[i], type[i]) < getSalary(list[index], type[index])) index = i;
    return index;
}

// Đếm số nhân viên từng loại
void countByType(int type[], int n, int &hourlyCount, int &monthlyCount) {
    hourlyCount = 0;
    monthlyCount = 0;
    for (int i = 0; i < n; i++) {
        if (type[i] == 1) hourlyCount++;
        else monthlyCount++;
    }
}

// Lọc nhân viên có lương lớn hơn ngưỡng nhập vào
void filterSalaryAbove(Employee* list[], int type[], int n, double threshold) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (getSalary(list[i], type[i]) > threshold) {
            showInfo(list[i], type[i]);
            cout << endl;
            found = true;
        }
    }
    if (!found) cout << "Khong co nhan vien nao." << endl;
}

// Sắp xếp giảm dần theo lương (đổi chỗ cả list và type)
void sortDescending(Employee* list[], int type[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (getSalary(list[i], type[i]) < getSalary(list[j], type[j])) {
                Employee* tempPtr = list[i];
                list[i] = list[j];
                list[j] = tempPtr;

                int tempType = type[i];
                type[i] = type[j];
                type[j] = tempType;
            }
        }
    }
}

int main() {

    Employee e1("079123456789", "Nguyen Van A", "Ho Chi Minh");
    HourlyEmployee h1("079876543210", "Tran Thi B", "Ha Noi", 160, 50000);
    MonthlyEmployee m1("079987654321", "Le Minh C", "Da Nang", 15000000, 2000000, 1.2);

    cout << "--- Thong tin Employee ---" << endl;
    e1.displayInfo();
    cout << "\n--- Thong tin HourlyEmployee ---" << endl;
    h1.displayInfo();
    cout << "\n--- Thong tin MonthlyEmployee ---" << endl;
    m1.displayInfo();

    HourlyEmployee h2("079111111111", "Pham Van D", "Hue", 100, 60000);
    MonthlyEmployee m2("079222222222", "Do Thi E", "Can Tho", 8000000, 1000000, 0.5);

    Employee* list[MAX];
    int type[MAX];   // 1: Hourly, 2: Monthly
    int n = 0;
    list[n] = &h1; type[n] = 1; n++;
    list[n] = &m1; type[n] = 2; n++;
    list[n] = &h2; type[n] = 1; n++;
    list[n] = &m2; type[n] = 2; n++;

    cout << "\nTong quy luong: " << totalSalary(list, type, n) << endl;

    int maxIndex = findMax(list, type, n);
    int minIndex = findMin(list, type, n);
    cout << "\n--- Nhan vien luong cao nhat ---" << endl;
    showInfo(list[maxIndex], type[maxIndex]);
    cout << "\n--- Nhan vien luong thap nhat ---" << endl;
    showInfo(list[minIndex], type[minIndex]);

    int hourlyCount, monthlyCount;
    countByType(type, n, hourlyCount, monthlyCount);
    cout << "\nSo HourlyEmployee: " << hourlyCount << endl;
    cout << "So MonthlyEmployee: " << monthlyCount << endl;

    double threshold;
    cout << "\nNhap nguong luong: ";
    cin >> threshold;
    filterSalaryAbove(list, type, n, threshold);

    sortDescending(list, type, n);
    cout << "\n--- Danh sach sau khi sap xep giam dan ---" << endl;
    for (int i = 0; i < n; i++) {
        showInfo(list[i], type[i]);
        cout << endl;
    }

    return 0;
}