#include <iostream>
#include <string>

#define MAX 100

using namespace std;

class Employee {
private:
    string id;
    string name;
public:
    Employee() : id(""), name("") {}
    Employee(string i, string n) : id(i), name(n) {}

    string getId() const { return id; }
    string getName() const { return name; }
    void setId(string i) { id = i; }
    void setName(string n) { name = n; }

    void display() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
};

class HourlyEmployee : public Employee {
private:
    int hours;
    double salaryPerHour;
    int month;
    int year;
public:
    HourlyEmployee() : Employee(), hours(0), salaryPerHour(0), month(1), year(2000) {}
    HourlyEmployee(string i, string n, int h, double s, int m, int y)
        : Employee(i, n), hours(h), salaryPerHour(s), month(m), year(y) {}

    int getHours() const { return hours; }
    double getSalaryPerHour() const { return salaryPerHour; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    void setHours(int h) { hours = h; }
    void setSalaryPerHour(double s) { salaryPerHour = s; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    // Salary of the given month and year (0 if the record is for another period)
    double calculateSalary(int m, int y) const {
        if (m == month && y == year) return hours * salaryPerHour;
        return 0;
    }

    void display() const {
        Employee::display();
        cout << "Type: Hourly" << endl;
        cout << "Hours: " << hours << endl;
        cout << "Salary per hour: " << salaryPerHour << endl;
        cout << "Month/Year: " << month << "/" << year << endl;
    }
};

class MonthlyEmployee : public Employee {
private:
    double monthlySalary;
    int month;
    int year;
public:
    MonthlyEmployee() : Employee(), monthlySalary(0), month(1), year(2000) {}
    MonthlyEmployee(string i, string n, double s, int m, int y)
        : Employee(i, n), monthlySalary(s), month(m), year(y) {}

    double getMonthlySalary() const { return monthlySalary; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    void setMonthlySalary(double s) { monthlySalary = s; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    double calculateSalary(int m, int y) const {
        if (m == month && y == year) return monthlySalary;
        return 0;
    }

    void display() const {
        Employee::display();
        cout << "Type: Monthly" << endl;
        cout << "Monthly salary: " << monthlySalary << endl;
        cout << "Month/Year: " << month << "/" << year << endl;
    }
};

class DailyEmployee : public Employee {
private:
    int numberOfDays;
    double salaryPerDay;
    int month;
    int year;
public:
    DailyEmployee() : Employee(), numberOfDays(0), salaryPerDay(0), month(1), year(2000) {}
    DailyEmployee(string i, string n, int d, double s, int m, int y)
        : Employee(i, n), numberOfDays(d), salaryPerDay(s), month(m), year(y) {}

    int getNumberOfDays() const { return numberOfDays; }
    double getSalaryPerDay() const { return salaryPerDay; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    void setNumberOfDays(int d) { numberOfDays = d; }
    void setSalaryPerDay(double s) { salaryPerDay = s; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    double calculateSalary(int m, int y) const {
        if (m == month && y == year) return numberOfDays * salaryPerDay;
        return 0;
    }

    void display() const {
        Employee::display();
        cout << "Type: Daily" << endl;
        cout << "Number of days: " << numberOfDays << endl;
        cout << "Salary per day: " << salaryPerDay << endl;
        cout << "Month/Year: " << month << "/" << year << endl;
    }
};

int main() {
    HourlyEmployee hourly[MAX];
    MonthlyEmployee monthly[MAX];
    DailyEmployee daily[MAX];
    int hourlyCount = 0, monthlyCount = 0, dailyCount = 0;

    hourly[hourlyCount++] = HourlyEmployee("H01", "Tran Thi B", 160, 50000, 10, 2026);
    hourly[hourlyCount++] = HourlyEmployee("H02", "Pham Van D", 100, 60000, 9, 2026);
    monthly[monthlyCount++] = MonthlyEmployee("M01", "Le Minh C", 17000000, 10, 2026);
    monthly[monthlyCount++] = MonthlyEmployee("M02", "Do Thi E", 9000000, 9, 2026);
    daily[dailyCount++] = DailyEmployee("D01", "Nguyen Van F", 22, 400000, 10, 2026);
    daily[dailyCount++] = DailyEmployee("D02", "Hoang Thi G", 20, 350000, 9, 2026);

    cout << "===== EMPLOYEE LIST =====" << endl;
    for (int i = 0; i < hourlyCount; i++) { hourly[i].display(); cout << endl; }
    for (int i = 0; i < monthlyCount; i++) { monthly[i].display(); cout << endl; }
    for (int i = 0; i < dailyCount; i++) { daily[i].display(); cout << endl; }

    int month, year;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    double total = 0;
    cout << "\n===== SALARY OF " << month << "/" << year << " =====" << endl;
    for (int i = 0; i < hourlyCount; i++) {
        double s = hourly[i].calculateSalary(month, year);
        cout << hourly[i].getName() << " (Hourly): " << s << endl;
        total += s;
    }
    for (int i = 0; i < monthlyCount; i++) {
        double s = monthly[i].calculateSalary(month, year);
        cout << monthly[i].getName() << " (Monthly): " << s << endl;
        total += s;
    }
    for (int i = 0; i < dailyCount; i++) {
        double s = daily[i].calculateSalary(month, year);
        cout << daily[i].getName() << " (Daily): " << s << endl;
        total += s;
    }
    cout << "Total salary: " << total << endl;

    return 0;
}