#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vehicle {
private:
    string ID;
    string brand;
    double pricePerDay;

public:
    Vehicle() : ID(""), brand(""), pricePerDay(0) {}
    Vehicle(string i, string b, double p) : ID(i), brand(b), pricePerDay(p) {}
    virtual ~Vehicle() {}

    string getId() const { return ID; }
    string getBrand() const { return brand; }
    double getPricePerDay() const { return pricePerDay; }

    void setId(string i) { ID = i; }
    void setBrand(string b) { brand = b; }
    void setPricePerDay(double p) { pricePerDay = p; }

    virtual void displayInfo() const {
        cout << "ID: " << ID << endl;
        cout << "Brand: " << brand << endl;
        cout << "Price per day: " << pricePerDay << endl;
    }

    virtual double calculateRentalFee(int days) const {
        return days * pricePerDay;
    }
};