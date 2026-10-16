#include <iostream>
#include <string>

#define MAX 100

using namespace std;

class Employee {
private:
    string cccd;
    string phone;
    string address;

public:
    Employee() {
        cccd = "";
        phone = "";
        address = "";
    }
    Employee(string c, string p, string a) {
        cccd = c;
        phone = p;
        address = a;
    }

    virtual double calculateSalary(int month, int year) = 0;
    virtual double calculateYearlySalary(int year) = 0;   // thêm

    virtual void displayInfo() {
        cout << "CCCD: " << cccd << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
    }

    virtual ~Employee() = default;
};

class HourlyEmployee : public Employee {
private:
    double salaryPerHour;
    int months[MAX], years[MAX], hours[MAX];   // mỗi bản ghi: tháng, năm, số giờ
    int count;

public:
    HourlyEmployee() : Employee() {
        salaryPerHour = 0;
        count = 0;
    }

    HourlyEmployee(string c, string p, string a, double s)
        : Employee(c, p, a) {
        salaryPerHour = s;
        count = 0;
    }

    void addRecord(int m, int y, int h) {
        if (count >= MAX) return;
        months[count] = m;
        years[count] = y;
        hours[count] = h;
        count++;
    }

    double calculateSalary(int m, int y) override {
        double total = 0;
        for (int i = 0; i < count; i++)
            if (months[i] == m && years[i] == y)
                total += hours[i] * salaryPerHour;
        return total;
    }

    double calculateYearlySalary(int y) override {
        double total = 0;
        for (int i = 0; i < count; i++)
            if (years[i] == y)
                total += hours[i] * salaryPerHour;
        return total;
    }
};

class MonthlyEmployee : public Employee {
private:
    double monthlySalary;
    int months[MAX], years[MAX];   // mỗi bản ghi: tháng, năm có đi làm
    int count;

public:
    MonthlyEmployee(string c, string p, string a, double s)
        : Employee(c, p, a) {
        monthlySalary = s;
        count = 0;
    }

    void addRecord(int m, int y) {
        if (count >= MAX) return;
        months[count] = m;
        years[count] = y;
        count++;
    }

    double calculateSalary(int m, int y) override {
        double total = 0;
        for (int i = 0; i < count; i++)
            if (months[i] == m && years[i] == y)
                total += monthlySalary;
        return total;
    }

    double calculateYearlySalary(int y) override {
        double total = 0;
        for (int i = 0; i < count; i++)
            if (years[i] == y)
                total += monthlySalary;
        return total;
    }
};

class DailyEmployee : public Employee {
private:
    double salaryPerDay;
    int months[MAX], years[MAX], days[MAX];   // mỗi bản ghi: tháng, năm, số ngày
    int count;

public:
    DailyEmployee(string c, string p, string a, double s)
        : Employee(c, p, a) {
        salaryPerDay = s;
        count = 0;
    }

    void addRecord(int m, int y, int d) {
        if (count >= MAX) return;
        months[count] = m;
        years[count] = y;
        days[count] = d;
        count++;
    }

    double calculateSalary(int m, int y) override {
        double total = 0;
        for (int i = 0; i < count; i++)
            if (months[i] == m && years[i] == y)
                total += days[i] * salaryPerDay;
        return total;
    }

    double calculateYearlySalary(int y) override {
        double total = 0;
        for (int i = 0; i < count; i++)
            if (years[i] == y)
                total += days[i] * salaryPerDay;
        return total;
    }
};

int main() {
    HourlyEmployee h("001", "0901", "HCM", 50000);
    h.addRecord(10, 2026, 160);
    h.addRecord(11, 2026, 150);

    MonthlyEmployee m("002", "0902", "Dong Nai", 15000000);
    m.addRecord(10, 2026);
    m.addRecord(11, 2026);

    DailyEmployee d("003", "0903", "Ha Noi", 400000);
    d.addRecord(1, 2026, 26);
    d.addRecord(2, 2026, 24);
    d.addRecord(12, 2026, 30);

    // Con trỏ lớp cha trỏ đến đối tượng lớp con
    Employee* employees[] = {&h, &m, &d};

    cout << "--- Luong thang 10/2026 ---" << endl;
    for (Employee* e : employees)
        cout << e->calculateSalary(10, 2026) << endl;

    cout << "--- Luong ca nam 2026 ---" << endl;
    for (Employee* e : employees)
        cout << e->calculateYearlySalary(2026) << endl;

    return 0;
}