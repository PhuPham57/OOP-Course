#include <iostream>
#include <string>

#define MAX 100

using namespace std;

// ================= DRINKS =================
class Drinks {
protected:
    string name;
    int day, month, year;
    int quantity;
    double price;

public:
    Drinks() {
        name = "";
        day = month = year = 0;
        quantity = 0;
        price = 0;
    }
    Drinks(string n, int d, int m, int y, int q, double p) {
        name = n;
        day = d;
        month = m;
        year = y;
        quantity = q;
        price = p;
    }

    bool isSameDate(int d, int m, int y) const {
        return day == d && month == m && year == y;
    }

    virtual double calculateRevenue() const {
        return quantity * price;
    }

    virtual void displayInfo() const {
        cout << name << " | " << day << "/" << month << "/" << year
             << " | Quantity: " << quantity
             << " | Price: " << price
             << " | Revenue: " << calculateRevenue() << endl;
    }

    virtual ~Drinks() {}
};

class Coffee : public Drinks {
public:
    Coffee(int d, int m, int y, int q, double p)
        : Drinks("Coffee", d, m, y, q, p) {}
};

class Tea : public Drinks {
public:
    Tea(int d, int m, int y, int q, double p)
        : Drinks("Tea", d, m, y, q, p) {}
};

class Smoothies : public Drinks {
public:
    Smoothies(int d, int m, int y, int q, double p)
        : Drinks("Smoothies", d, m, y, q, p) {}
};

class Juices : public Drinks {
public:
    Juices(int d, int m, int y, int q, double p)
        : Drinks("Juices", d, m, y, q, p) {}
};

// ================= FOODS =================
class Foods {
protected:
    string name;
    int day, month, year;
    int quantity;
    double price;

public:
    Foods() {
        name = "";
        day = month = year = 0;
        quantity = 0;
        price = 0;
    }
    Foods(string n, int d, int m, int y, int q, double p) {
        name = n;
        day = d;
        month = m;
        year = y;
        quantity = q;
        price = p;
    }

    bool isSameDate(int d, int m, int y) const {
        return day == d && month == m && year == y;
    }

    virtual double calculateRevenue() const {
        return quantity * price;
    }

    virtual void displayInfo() const {
        cout << name << " | " << day << "/" << month << "/" << year
             << " | Quantity: " << quantity
             << " | Price: " << price
             << " | Revenue: " << calculateRevenue() << endl;
    }

    virtual ~Foods() {}
};

class Cake : public Foods {
public:
    Cake(int d, int m, int y, int q, double p)
        : Foods("Cake", d, m, y, q, p) {}
};

class Breads : public Foods {
public:
    Breads(int d, int m, int y, int q, double p)
        : Foods("Breads", d, m, y, q, p) {}
};

// ================= REVENUE BY DAY =================
double drinksRevenueByDay(Drinks* list[], int n, int d, int m, int y) {
    double total = 0;
    for (int i = 0; i < n; i++)
        if (list[i]->isSameDate(d, m, y))
            total += list[i]->calculateRevenue();
    return total;
}

double foodsRevenueByDay(Foods* list[], int n, int d, int m, int y) {
    double total = 0;
    for (int i = 0; i < n; i++)
        if (list[i]->isSameDate(d, m, y))
            total += list[i]->calculateRevenue();
    return total;
}

int main() {
    // Danh sách đồ uống đã bán
    Coffee c1(16, 10, 2026, 30, 25000);
    Tea t1(16, 10, 2026, 20, 20000);
    Smoothies s1(16, 10, 2026, 10, 35000);
    Juices j1(17, 10, 2026, 15, 30000);

    Drinks* drinks[MAX];
    int drinksCount = 0;
    drinks[drinksCount++] = &c1;
    drinks[drinksCount++] = &t1;
    drinks[drinksCount++] = &s1;
    drinks[drinksCount++] = &j1;

    // Danh sách đồ ăn đã bán
    Cake k1(16, 10, 2026, 12, 40000);
    Breads b1(16, 10, 2026, 25, 15000);
    Breads b2(17, 10, 2026, 18, 15000);

    Foods* foods[MAX];
    int foodsCount = 0;
    foods[foodsCount++] = &k1;
    foods[foodsCount++] = &b1;
    foods[foodsCount++] = &b2;

    int d, m, y;
    char slash;
    cout << "Enter date (dd/mm/yyyy): ";
    cin >> d >> slash >> m >> slash >> y;

    cout << "\nRevenue of " << d << "/" << m << "/" << y << endl;
    cout << "- Drinks: " << drinksRevenueByDay(drinks, drinksCount, d, m, y) << endl;
    cout << "- Foods: " << foodsRevenueByDay(foods, foodsCount, d, m, y) << endl;

    return 0;
}